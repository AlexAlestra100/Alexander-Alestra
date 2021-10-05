package com.mycompany.a1;
import java.util.Random;
import com.codename1.charts.util.ColorUtil;
import java.util.ArrayList;

/**
 * GameWorld will create instances of all  the game objects needed
 * to populate the game world
 * @author Alexander Alestra
 *
 */
public class GameWorld {
	private int timer;
	private ArrayList<GameObject> gameObject;
	private int flagCount;
	private int foodStationCount;
	private int spiderCount;
	private boolean gameOver;
	Random random = new Random();
	
	public GameWorld(){}
	
	/**
	 * init will initialize the variables as well as call
	 * addGameObjects
	 */
	public void init(){
		this.timer = 0;
		gameObject = new ArrayList<GameObject>();
		this.flagCount = 0;
		this.foodStationCount = 0;
		this.spiderCount = 0;
		this.gameOver = false;
		addGameObjects();
	}
	
	/**
	 * This method will initialize how many  of each object  is  required to
	 * populate the world at a bare minimum but can add more wih random
	 * 
	 * It uses for loops to go through how many of each game object is chosen to spawn
	 * 
	 * At the end the ant will be spawned
	 * 
	 */
	public void addGameObjects() {
		int flagObject = 4 + random.nextInt(5);
		int spideObject = 2 + random.nextInt(5);
		int foodObject = 2 + random.nextInt(5);
		
		for(int i = 1; i < flagObject; i++) {
			gameObject.add(new Flag(i));
			if(i == 1) {
				((Flag) gameObject.get(i - 1)).setX(0);
				((Flag) gameObject.get(i - 1)).setY(0);
				flagCount++;
			}
			else {
				flagCount++;
			}
		}
		for(int i = 0; i < foodObject; i++) {
			gameObject.add(new FoodStation());
			foodStationCount++;
		}
		for(int i = 0; i < spideObject ; i++) {
			gameObject.add(new Spider());
			spiderCount++;
		}
		gameObject.add(new Ant());
	}
	
	/**
	 * This method will accelerate the ant forward until it hits its max
	 * 
	 * It will go through the array to find the ant then call accelerate
	 * in ant
	 */
	public void accelerate() {
		System.out.println("The Ant accalerated");
		for(int i = 0; i < gameObject.size(); i++) {
			if(gameObject.get(i) instanceof Ant) {
				((Ant) gameObject.get(i)).accelerate();
			}
		}
	}
	
	/**
	 * Brake method will slow down the ant
	 * 
	 * Similar to accalerate
	 */
	public void brake() {
		System.out.println("The Ant braked");
		for(int i = 0; i < gameObject.size(); i++) {
			if(gameObject.get(i) instanceof Ant) {
				((Ant) gameObject.get(i)).brake();
			}
		}
	}
	
	/**
	 * Turn left will for the ant to turn 5 degrees to the left
	 *
	 */
	public void turnLeftAnt() {
		System.out.println("The Ant turned left");
		for(int i = 0; i < gameObject.size(); i++) {
			if(gameObject.get(i) instanceof Ant) {
				((Ant) gameObject.get(i)).turnLeft();
			}
		}
	}
	
	/**
	 * Turn right will for the ant to turn 5 degrees to the right
	 */
	public void turnRightAnt() {
		System.out.println("The Ant turned right");
		for(int i = 0; i < gameObject.size(); i++) {
			if(gameObject.get(i) instanceof Ant) {
				((Ant) gameObject.get(i)).turnRight();
			}
		}
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
		System.out.println("Collision between Spider and Ant have occured");
		for(int i = 0; i < gameObject.size(); i++) {
			if(gameObject.get(i) instanceof Ant) {
				if(((Ant) gameObject.get(i)).getHealthLevel() == 0) {
					System.out.println("You Ant is dead");
					if(((Ant) gameObject.get(i)).getLife() != 0) {
						int tLastFlag = ((Ant) gameObject.get(i)).getLastFlagReached();
						for(int j = 0; j < gameObject.size(); j++) {
							if(gameObject.get(j) instanceof Flag) {
								if(tLastFlag == (((Flag) gameObject.get(j)).getSequenceNumber())) {
									float flagX = (((Flag) gameObject.get(j)).getX());
									float flagY = (((Flag) gameObject.get(j)).getY());
									((Ant) gameObject.get(i)).resetAnt(flagX, flagY, tLastFlag);
								}
							}
						}
						
						}
					else {
						System.out.println("Game is over");
						System.exit(0);
					}
				}
				else {
					((Ant) gameObject.get(i)).decreaseHealthLevel();
					((Ant) gameObject.get(i)).checkHealthLevel();
					int r = ColorUtil.red(((Ant) gameObject.get(i)).getColor()) + 20;
					((Ant) gameObject.get(i)).setColor(ColorUtil.rgb((r), 0, 0));
					}
			}
		}
	}
	
	/**
	 * Collision with a food station will check to see the first available food station
	 * it will then check to see if the station has already been used
	 * if it hasn't the ant will get more food and the station will change color
	 */
	public void collisionFoodStation() {
		System.out.println("Collision with food station");
		for(int i = 0; i < gameObject.size(); i++) {
			if(gameObject.get(i) instanceof Ant) {
				for(int j = 0; j < gameObject.size(); j++) {
					if(gameObject.get(j) instanceof FoodStation) {
						if(((FoodStation) gameObject.get(j)).getCapacity() != 0) {
							int temp = ((FoodStation) gameObject.get(j)).getCapacity();
							((Ant) gameObject.get(i)).addFood(temp);  
							((FoodStation) gameObject.get(j)).setCapacity(0);
							((FoodStation) gameObject.get(j)).setColor(ColorUtil.rgb(0, 200, 0));
							gameObject.add(new FoodStation());
							break;
						}
					}
				}
			}
		}
	}
	
	/**
	 * Collsion with the flag will check if the flag is indeed next
	 * next it will update the last reached flag
	 * 
	 * If it is not then it will say yyou passed it
	 * 
	 * If the flag is equal to the last flag then the ant won
	 * 
	 * @param c is the next flag in the array that the ant has collided with
	 */
	public void collisonFlag(int c) {
		System.out.println("Ant has collided to a flag");
		for(int i = 0; i < gameObject.size(); i++) {
			if(gameObject.get(i) instanceof Ant) {
				int temp = ((Ant) gameObject.get(i)).getLastFlagReached();
				temp++;
				if(temp == c) {
					System.out.println("Ant has made it to the next flag");
					((Ant) gameObject.get(i)).setLastFlagReached(c);
				}
				else {
					System.out.println("Had passed or haven't reached yet");
				}
				if(temp == flagCount) {
					System.out.println("Congrats you won the game");
					System.exit(0);
				}
			}
		}
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
	public void gameTick()
	{
		System.out.println("Game has ticked");
		timer++;
		for(int i = 0; i < gameObject.size(); i++) {
			if(gameObject.get(i) instanceof Spider) {
				((Spider) gameObject.get(i)).checkBoundary();
				((Spider) gameObject.get(i)).move();
			}
			if(gameObject.get(i) instanceof Ant) {
				((Ant) gameObject.get(i)).checkBoundary();
				if(((Ant) gameObject.get(i)).getFoodLevel() == 0){
					System.out.println("You lost a life");
					int tLastFlag = ((Ant) gameObject.get(i)).getLastFlagReached();
					for(int j = 0; j < gameObject.size(); j++) {
						if(gameObject.get(j) instanceof Flag) {
							if(tLastFlag == (((Flag) gameObject.get(j)).getSequenceNumber())) {
								float flagX = (((Flag) gameObject.get(j)).getX());
								float flagY = (((Flag) gameObject.get(j)).getY());
								System.out.println("In reset loop");
								((Ant) gameObject.get(i)).resetAnt(flagX, flagY, tLastFlag);
							}
						}
					}
				}
				else {
					((Ant) gameObject.get(i)).move();
					((Ant) gameObject.get(i)).foodLevelTick();
				}
			}
		}
	}
	
	/**
	 * Prints the string of all the concrete classes in the array
	 */
	public void printMap() {
		System.out.println("Map is printed");
		for (int i = 0; i < gameObject.size(); i++) {
			System.out.println(gameObject.get(i).toString());
		}
	}
	
	/**
	 * This will print the current life, time, last flag reached, food level,
	 * and current health
	 */
	public void printCurrent() {
		System.out.println("Current Stats");
		for(int i = 0; i < gameObject.size(); i++) {
			if(gameObject.get(i) instanceof Ant) {
				int life = ((Ant) gameObject.get(i)).getLife();
				int timer = getTime();
				int lastFlagReach = ((Ant) gameObject.get(i)).getLastFlagReached();
				int currentFood = ((Ant) gameObject.get(i)).getFoodLevel();
				int currentHealth = ((Ant) gameObject.get(i)).getHealthLevel();
				System.out.println("The life left is: " + life);
				System.out.println("The timer has elapsed is: " + timer);
				System.out.println("The last flag reached is: " + lastFlagReach);
				System.out.println("The current food level is: " + currentFood);
				System.out.println("The current health is: " + currentHealth);
			}
		}
	}
	
	/**
	 * Getter for time
	 * @return returns the amount of ticks for time
	 */
	public int getTime() {
		return this.timer;
	}
	
	/**
	 * Will exit game
	 */
	public void exit() {
		System.exit(0);
	}
}