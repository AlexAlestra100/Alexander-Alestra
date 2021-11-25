package com.mycompany.a2;
import java.util.Observable;
import java.util.Random;

/**
 * GameWorld will create instances of all  the game objects needed
 * to populate the game world
 * @author Alexander Alestra
 *
 */
public class GameWorld extends Observable {
	private GameObjectsCollection gameObjects;
	private int lives = 3;
	private boolean sound = false;
	private Ant ant;
	private int clock = 0;
	Random rand = new Random();
	private int maxWidth;
	private int maxHeight;
	
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
	private float randFloat(int startR, int endR) {
		return (startR + (rand.nextFloat() * (endR - startR)));
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
	
	/**
	 * Will set clock (Ticks)
	 * @param clock
	 */
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
	 * Initializing all the objects
	 */
	public void init()
	{		
		//ant lives outside of collection for convenience
		ant = Ant.getAnt();
		
		gameObjects = new GameObjectsCollection();
						
		//add flags int size, float x, float y, int color, int sequenceNumber
		gameObjects.add(new Flag(10, 250, 250, 0, 255, 0, 1));
		gameObjects.add(new Flag(10, 250, 500, 0, 255, 0, 2));
		gameObjects.add(new Flag(10, 500, 500, 0, 255, 0, 3));
		gameObjects.add(new Flag(10, 500, 750, 0, 255, 0, 4));
		
		System.out.println("FLAG: " + ant.getLastFlagReached());
				
		//add spiders
		this.createSpider();
		this.createSpider();
		
		//add food stations
		this.createFoodStation();
		this.createFoodStation();
		
		this.setChanged();
		this.notifyObservers(this);
	}
	
	/**
	 * This will create the vectors of gameobjects and iterate over them
	 * @param <T>
	 * @param someClass
	 * @return
	 */
	@SuppressWarnings("rawtypes") 
	private <T> GameObject getObjectByClassType(Class someClass)
	{
		//init iterator
        Iterator it = gameObjects.getIterator();
        
        //iterate over list until an object is found that matches the class type pass in;
        while(it.hasNext())
        	if(someClass.equals(it.next().getClass()))
        		return it.current();

        //if nothing is found return null
		return null;
	}
	
	/**
	 * Will create food stations
	 */
	private void createFoodStation() {
		int size = this.randInt(10,50);
		float x = this.randFloat(0, 1000);
		float y = this.randFloat(0, 1000);
		FoodStation fd = new FoodStation(size, x, y, 100 ,100, 100);
		this.gameObjects.add(fd);
	}
	
	/**
	 * Will create the spiders
	 */
	private void createSpider() {
		int size = this.randInt(10,50);
		float x = this.randFloat(0, 1000);
		float y = this.randFloat(0, 1000);
		int heading = this.randInt(0,360);
		int speed = this.randInt(5,10);
		Spider smollbean = new Spider(size, x, y, 0, 0, 255, heading, speed);
		this.gameObjects.add(smollbean);
	}
	
	/**
	 * This will update all the moveables so they can update their location/heading each tick
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
					spider.move(maxHeight, maxWidth);
				}
				else {
					((Movable) temp).move();
				}
        	}
        }
	}
	
	/**
	 * This method will accelerate the ant forward until it hits its max
	 * 
	 * It will go through the array to find the ant then call accelerate
	 * in ant
	 */
	public void accelerate() {
		System.out.println("Accelerating");
		ant.accelerate();
		this.doUpdate();
	}
	
	/**
	 * Brake method will slow down the ant
	 * 
	 * Similar to accalerate
	 */
	public void brake() {
		System.out.println("Braking");
		ant.brake();
		this.doUpdate();
	}
	
	/**
	 * Turn left will for the ant to turn 5 degrees to the left
	 *
	 */
	public void turnLeft() {
		System.out.println("Turning to the left");
		ant.updateHeading(-5);
		this.doUpdate();
	}
	
	/**
	 * Turn right will for the ant to turn 5 degrees to the right
	 */
	public void turnRight() {
		System.out.println("Turning to the right");
		ant.updateHeading(+5);
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
		System.out.println("Collision with Spider");
		Spider spider = (Spider) this.getObjectByClassType(Spider.class);
		gameObjects.getIterator().remove(spider);
		if(ant.getSpeed() != 0) {
			ant.setSpeed(ant.getSpeed() - 1);
			ant.setMaximumSpeed(ant.getMaximumSpeed() - 1);
		}
		ant.setHealthLevel((ant.getHealthLevel() - 1));
		ant.setColor(ant.getColor() - 20, 0, 0);
		this.createSpider();
		checkLifeStats();
		this.doUpdate();
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
			System.out.println("Food Station Empty!");
			return;
		}
		else {
			System.out.println("Collision with Food Station");
		}
		int currFood = ant.getFoodLevel();
		ant.setFoodLevel(capacity + currFood);
		station.setColor(144,238,144);
		station.setCapacity(0);
		this.doUpdate();
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
	public void collisionFlag(int c) {
		int flagNum = Integer.parseInt(String.valueOf(c));
		int lastFlag = ant.getLastFlagReached();
		if(lastFlag < flagNum) {
			ant.setLastFlagReached(flagNum);
			System.out.println("Flag Reached: " + flagNum);
		}
		this.doUpdate();
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
		this.clock++;
		this.checkForWin();
		ant.calcFoodLevel();
		this.checkLifeStats();
		ant.move();
		this.updateAllMovables();
		System.out.println("Game ticks: " + clock);
		this.doUpdate();
	}
	
	/**
	 * Method to just force update
	 */
	private void doUpdate() {
		this.setChanged();
		this.notifyObservers();
	}
	
	/**
	 * Prints the string of all the concrete classes in the array
	 */
	public void printMap() {
		System.out.println("Printing Map...");
		
		//print ant details
		System.out.println(ant.toString());
		System.out.println("Last Flag: " + ant.getLastFlagReached());
		//print every object in the game as well
		Iterator it = gameObjects.getIterator();
		
		while(it.hasNext())
			System.out.println(it.next().toString());
	}
	
	/**
	 * Will be called if a live needs to be removed adn also if game over is needed
	 */
	private void roundOver() {
		this.lives--;
		if(this.lives == 0) {
			System.out.println("Game Over!");
			System.exit(0);
		}
		gameObjects = new GameObjectsCollection();
		ant.reset();
		this.init();		
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
	 * Check the life of the ant
	 */
	private void checkLifeStats(){
		if(ant.getHealthLevel() <= 0 || ant.getFoodLevel() <= 0)
			this.roundOver();			
	}
	
	/**
	 * Set the width of the game
	 * @param width
	 */
	public void setWidth(int width) {
		this.maxWidth = width;
	}

	/**
	 * Set the height of the game
	 * @param height
	 */
	public void setHeight(int height) {
		this.maxHeight = height;
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
}
