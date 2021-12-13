package com.mycompany.a4;
import java.util.Observable;
import java.util.Random;

/**
 * GameWorld will create instances of all  the game objects needed
 * to populate the game world
 * @author Alexander Alestra
 *
 */
public class GameWorld extends Observable{
	private GameObjectsCollection gameObjects;
	private Sound collideSpider;
	private Sound collideFood;
	private Sound collideCorrectFlag;
	private BackgroundSound bgSound;
	Random rand = new Random();
	private int clock = 0;
	private Ant ant;
	private boolean sound = true;
	private int lives = 3;
	private boolean pause;
	private float maxWidth = 931/2;
	private float maxHeight = 639/2;
	private int tickrate;
	private float winLeft = 0, winBottom = 0;
	
	public float getWinLeft() {
		return winLeft;
	}

	public void setWinLeft(float winLeft) {
		this.winLeft = winLeft;
	}

	public float getWinBottom() {
		return winBottom;
	}

	public void setWinBottom(float winBottom) {
		this.winBottom = winBottom;
	}

	/**
	 * Game tick is will update the movement of the spider while also
	 * checking the boundary
	 * 
	 * Then it will check the food level of the ant and boundary
	 * if the ant has run out of food it will reset to  the last
	 * reached flag
	 * 
	 * Else it will move the ant and remove some food level
	 */
	public void gameTick() {
		if(!pause) {
			clock++;
			System.out.println("Ticking.." + clock);
			ant.calcFoodLevel();
			this.checkLifeStats();
			ant.move();
			this.updateAllMovables();
			System.out.println("Tick: " + clock);
			this.doUpdate();
		}
	};
	
	/**
	 * Check the life of the ant
	 */
	private void checkLifeStats() {
		this.checkForWin();
		if(ant.getHealthLevel() <= 0 || ant.getFoodLevel() <= 0) {
			this.gameOver();			
		}
	}
	
	/**
	 * Check to see if the ant has been to all the flags
	 */
	private void checkForWin() {
		if(ant.getLastFlagReached() == 4) {
			System.out.println("Game over you win! Total time: " + this.clock);
			System.exit(0);
		}
	}
	
	/**
	 * This will create the vectors of gameobjects and iterate over them
	 * @param <T>
	 * @param someClass
	 * @return
	 */
	@SuppressWarnings("rawtypes") 
	private <T> GameObject getObjectByClassType(Class someClass) {
        Iterator it = gameObjects.getIterator();
        while(it.hasNext()) {
        	if(someClass.equals(it.next().getClass())) {
        		return it.current();
        	}
        }
		return null;
	}
	
	/**
	 * Collision with a food station will check to see the first available food station
	 * it will then check to see if the station has already been used
	 * if it hasn't the ant will get more food and the station will change color
	 */
	public void collisionFoodStation() {
		FoodStation station = (FoodStation) this.getObjectByClassType(FoodStation.class);
		int capacity = station.getCapacity();
		if(capacity == 0) {
			System.out.println("This food station is empty");
			return;
		}
		else {
			System.out.println("Eating..");
		}
		
		int currFood = ant.getFoodLevel();
		ant.setFoodLevel(capacity + currFood);
		station.setColor(0,200,0);
		station.setCapacity(0);
		
		this.doUpdate(collideFood);
	}
	
	/**
	 * Collsion with the flag will check if the flag is indeed next
	 * next it will update the last reached flag
	 * 
	 * If it is not then it will say you passed it
	 * 
	 * If the flag is equal to the last flag then the ant won
	 * 
	 * @param c is the next flag in the array that the ant has collided with
	 */
	public void collisionFlag(int val) {
		int lastFlag = ant.getLastFlagReached();
		if(++lastFlag == val) {
			ant.setLastFlagReached(val);
			if(sound) {
				collideCorrectFlag.play();
			}
			System.out.println("Checkpoint " + val + " Reached!");
		}
		this.doUpdate();
	}
	
	/**
	 * Collision with spider will force the ant to take damage
	 * 
	 * It first searches for the ant
	 * then checks to see if it has zero life level
	 * then it will check to see if the amount of lives
	 * not zero
	 * 
	 * This will force the ant to respawn from the last flag reached
	 * 
	 * The ladder will force a game over
	 * 
	 * If the ant has plenty of health level then it will reduce the health
	 * update the max speed it can go
	 * then change the color of the ant
	 */
	public void collisionSpider() {
		System.out.println("Collision with a Spider");
		Spider spooder = (Spider) this.getObjectByClassType(Spider.class);
		gameObjects.getIterator().remove(spooder);
		ant.setHealthLevel((ant.getHealthLevel() - 1));
		ant.setColor(ant.getColor() - 20, 0, 0);
		this.createSpider();
		checkLifeStats();
		this.doUpdate(collideSpider);
	}
	
	/**
	 * Collects gameObjects amd retirms them
	 * @return
	 */
	public GameObjectsCollection getObjectsCollection() {
		return gameObjects;
	}
	
	/**
	 * Will be called if a live needs to be removed adn also if game over is needed
	 */
	private void gameOver() {
		this.lives--;
		if(this.lives == 0) {
			System.out.println("Game Over, You Failed!");
			System.exit(0);
		}
		gameObjects = new GameObjectsCollection();
		ant.reset(this);
		this.init();		
	}
	
	/**
	 * Turn left will for the ant to turn 5 degrees to the left
	 *
	 */
	public void turnLeft() {
		System.out.println("Turning to the left");
		ant.updateHeading(-2);
		this.doUpdate();
	}
	
	/**
	 * Turn right will for the ant to turn 5 degrees to the right
	 */
	public void turnRight() {
		System.out.println("Turning to the right"); 
		ant.updateHeading(+2);
		this.doUpdate();
	}
	
	/**
	 * This will update all the moveables so they can update their location/heading each tick
	 * 
	 * PS by keeping ant outside of the collections
	 * we save on RAM and CPU time and don't have to
	 * iterate through 2 for loops. Also this naturally
	 * avoids duplicate collisions.
	 */
	private void updateAllMovables() {
        Iterator it = gameObjects.getIterator();
        while(it.hasNext()) {
        	GameObject temp = it.next();
        	if(temp instanceof Movable) {
				 temp = (Movable) temp;
				if(temp instanceof Spider) {
					Spider spider = (Spider) temp;
					int heading = this.randInt(0,5);
					spider.setHeading(heading + spider.getHeading());
					spider.move((int)maxHeight, (int)maxWidth);
				}
				else {
					((Movable) temp).move();
				}
        	}
        	if(ant.collidesWith(temp)) {
        		ant.handleCollision(temp);
        	}
        }
	}
	
	/**
	 * Will create the spiders
	 */
	private void createSpider() {
		int size = this.randInt(80,100);
		float x = this.randFloat(0, 1000);
		float y = this.randFloat(0, 1000);
		int heading = this.randInt(0,360);
		int speed = this.randInt(5,10);
		Spider smollbean = new Spider(size, x, y, 0, 0, 0, heading, speed, this);
		this.gameObjects.add(smollbean);
	}
	
	/**
	 * Will create food stations
	 */
	private void createFoodStation()
	{
		//get random values for int size, int x, int y,int color
		int size = this.randInt(50,150);
		float x = this.randFloat(0, 1000);
		float y = this.randFloat(0, 1000);
		
		//initialize food station
		FoodStation fd = new FoodStation(size, x, y, 0, 200, 0, this);
		
		//save foodstation in vector array
		this.gameObjects.add(fd);
	}

	/**
	 * Creates a random int number
	 * @param min
	 * @param max
	 * @return the random int
	 */
	private int randInt(int min, int max) {
		return (int) (rand.nextInt(max - min) + 1) + min;
	}
	
	/**
	 * Creates a random float
	 * @param startR
	 * @param endR
	 * @return float
	 */
	private float randFloat(int startRange, int endRange) {
		return (startRange + (rand.nextFloat() * (endRange - startRange)));
	}
	
	/**
	 * Sets the number of lives
	 * @param lives
	 */
	public void setLives(int lives) {
		this.lives = lives;
	}
	
	/**
	 * Will set ant
	 * @param ant
	 */
	public void setAnt(Ant ant) {
		this.ant = ant;
	}

	public void setClock(int clock) {
		this.clock = clock;
	}

	/**
	 * Will get the number of lives
	 * @return lives
	 */
	public int getLives() {
		return lives;
	}

	/**
	 * Will retrieve ant
	 * @return ant
	 */
	public Ant getAnt() {
		return ant;
	}

	/**
	 * Will get the clock
	 * @return clock
	 */
	public int getClock() {
		return clock;
	}
	
	/**
	 * Brake method will slow down the ant
	 * 
	 * Similar to accalerate
	 */
	public void brake() {
		System.out.println("Braking...");
		ant.brake();
		this.doUpdate();
	}
	
	/**
	 * This method will accelerate the ant forward until it hits its max
	 * 
	 * It will go through the array to find the ant then call accelerate
	 * in ant
	 */
	public void accelerate() { 
		System.out.println("Accelerating...");
		ant.accelerate();
		this.doUpdate();
	}
	
	/**
	 * Initializing all the objects
	 */
	public void init() {
		ant = Ant.getAnt(this);
		gameObjects = new GameObjectsCollection();
		gameObjects.add(new Flag(100, 250, 250, 0, 100, 200, 1, this));
		gameObjects.add(new Flag(100, 250, 500, 0, 100, 200, 2, this));
		gameObjects.add(new Flag(100, 500, 500, 0, 100, 200, 3, this));
		gameObjects.add(new Flag(100, 1000, 1000, 0, 100, 200, 4, this));
		this.createSpider();
		this.createSpider();
		this.createFoodStation();
		this.createFoodStation();
		collideSpider = new Sound("smash.wav");
		collideFood = new Sound("nomnom.wav");
		collideCorrectFlag = new Sound("wootwoot.wav");
		bgSound = new BackgroundSound("nature.wav");
		if(sound) {
			bgSound.play();
		}
		this.setChanged();
		this.notifyObservers(this);
	}

	/**
	 * Prints the string of all the concrete classes in the array
	 */
	public void printMap()
	{
		System.out.println("Printing Map...");
		System.out.println(ant.toString());
		Iterator it = gameObjects.getIterator();
		while(it.hasNext()) {
			System.out.println(it.next().toString());
		}
	}

	/**
	 * Literally is only for the sound button to be used
	 * @return sound
	 */
	public boolean getSound() {
		return sound;
	}

	/**
	 * Literally is only for the sound button to be used
	 * @param sound
	 */
	public void setSound(boolean sound) {
		this.sound = sound;
		this.doUpdate();
	}

	/**
	 * Set the width of the game
	 * @param width
	 */
	public void setWidth(float width) {
		this.maxWidth = width;
	}
	
	public float getWidth() {
		return maxWidth;
	}

	/**
	 * Set the height of the game
	 * @param height
	 */
	public void setHeight(float height) {
		this.maxHeight = height;
	}
	
	public float getHeight() {
		return maxHeight;
	}
	
	/**
	 * Will set changes and then notify the observer
	 */
	private void doUpdate() {
		this.setChanged();
		this.notifyObservers();
	}
	
	/**
	 * 
	 * @param sound
	 */
	private void doUpdate(Sound sound) {
		if(this.getSound()) {
			sound.play();
		}
		this.setChanged();
		this.notifyObservers();
	}

	/**
	 * returns the boolean of pause
	 * @return
	 */
	public boolean isPaused() {
		return pause;
	}

	/**
	 * Will get the boolean of pause
	 * @param pause
	 */
	public void pause(boolean pause) {
		this.pause = pause;
	}

	public int getTickrate() {
		return tickrate;
	}

	/**
	 * Will set the tick rate
	 * @param tickrate
	 */
	public void setTickrate(int tickrate) {
		this.tickrate = tickrate;
	}
	
	/**
	 * Similar as getTickRate but the calcuation inside may change later
	 * @return
	 */
	public int getElapsedTime() {
		return tickrate;
	}

	/**
	 * Will print out repositioning
	 */
	public void reposition() {
		System.out.println("Repositioning...");
	}
	
	/**
	 * Turn off sound when paused
	 */
	public void turnOffSound()	{
		bgSound.pause();
	}
	
	/**
	 * Will play the sounds if sound it on
	 */
	public void turnOnSound() {
		bgSound.play();
	}
}
