package com.mycompany.a1;
import com.codename1.charts.util.ColorUtil;

/**
 * The ant class sets up the only object that is steerable
 * @author Alexander Alestra
 *
 */
public class Ant extends Movable implements ISteerable {
	private int maximumSpeed;
	private int foodLevel;
	private int foodConsumptionRate;
	private int healthLevel;
	private int lastFlagReached;
	private int life;
	
	/**
	 * This will get the life value of the ant
	 * @return life value of ant
	 */
	public int getLife() {
		return life;
	}
	
	/**
	 * This method will set the life for a given ant
	 * @param arelife is the life that is set for the ant
	 */
	public void setlife(int arelife) {
		this.life = arelife;
	}
	
	/**
	 * This will get the food level of the ant
	 * @return the food level of the given ant
	 */
    public int getFoodLevel() {
		return foodLevel;
	}
    
    /**
     * This method will set the food level of the ant
     * @param foodLevel is the value and the 
     * amount of ticks the ant can go
     */
    public void setFoodLevel(int foodLevel) {
		this.foodLevel = foodLevel;
	}
    
    /**
     * This is the health the ant has per given life
     * @return the health value
     */
	public int getHealthLevel() {
		return healthLevel;
	}
	
	/**
	 * This will set the health level of the ant
	 * @param healthLevel is the amount of health
	 * the ant should have
	 */
	public void setHealthLevel(int healthLevel) {
		this.healthLevel = healthLevel;
	}
	
	/**
	 * The most recent flag the ant has reached
	 * @return is the last flag
	 */
	public int getLastFlagReached() {
		return lastFlagReached;
	}
	
	/**
	 * This will set the flag that was reached
	 * @param lastFlagReached is the value 1-9 of the flag
	 * reached
	 */
	public void setLastFlagReached(int lastFlagReached) {
		this.lastFlagReached = lastFlagReached;
	}
	
	/**
	 * This is the maximum speed that the ant
	 * cannot surpass
	 * @return the value of the max speed
	 */
	public int getMaximumSpeed() {
		return maximumSpeed;
	}
	
	/**
	 * This method will set the value of the max speed
	 * @param maximumSpeed is the value of the
	 * fastest speed the ant can go
	 */
	public void setMaximumSpeed(int maximumSpeed) {
		this.maximumSpeed = maximumSpeed;	
	}

	/**
	 * 
	 */
	public Ant() {
		super(ColorUtil.rgb(100, 0, 0), 20, 30, 0);
		this.maximumSpeed = 50;
		this.foodConsumptionRate = 1;
		this.foodLevel = 30;
		this.healthLevel = 10;
		this.lastFlagReached = 1;
		this.setLocation(0, 0);
		this.life = 3;
	}
    
	/**
	 * This will increase the ants current speed by 5
	 */
    public void accelerate() {
		int currentSpeed = getSpeed();
		if(!isMaximumSpeed()) {
			this.setSpeed(currentSpeed += 5);
		}	
	}
    
    /**
     * This will decrease the ants current speed by 5
     */
    public void brake() {
		int currSpeed = getSpeed();
		if(currSpeed > 0) {
			this.setSpeed(currSpeed -= 5);
		}
	}
    
    /**
     * This is a check to show that the speed has
     * reached the max speed
     * @return a true or false based on the check
     */
    public boolean isMaximumSpeed() {
		if(this.getSpeed() >= maximumSpeed) {
			System.out.println("This is the max speed");
			return true;
		}
		return false;	
	}
	
    /**
     * This method will check the health level and update the
     * max speed proportional to the health of the ant
     */
	public void checkHealthLevel() {
		if(healthLevel > 0) {
			if(healthLevel != 10) {
				int perc = (int)((this.healthLevel * .10) * this.getMaximumSpeed());
				this.setMaximumSpeed(perc);
				this.setSpeed(this.getMaximumSpeed());
			}
			else {
				this.setSpeed(this.getMaximumSpeed());
			}
		}
		else if (healthLevel == 0) {
			this.setSpeed(0);	
		}	
	}
	
	/**
	 * When the ant runs into a food station it will
	 * add the amount of food in the station and add
	 * it to the food level
	 * @param fod is the capacity of the food station
	 */
	public void addFood(int fod) {
		this.setFoodLevel(this.getFoodLevel() + fod);
	}
	
	/**
	 * Decrements the health level of the ant
	 * by two
	 */
	public void decreaseHealthLevel() {
		this.healthLevel -= 2;
	}
	
	/**
	 * This will subtract the food consuption rate from the
	 * food level
	 */
	public void foodLevelTick() {
		this.setFoodLevel(this.getFoodLevel() - this.foodConsumptionRate);
	}

	/**
	 * This method will set the current heading but subtract 5
	 * degrees to it
	 */
	public void turnLeft() {
		this.setHeading(this.getHeading() - 5);
	}
	
	/**
	 * This method will set the current heading but add 5
	 * degrees to it
	 */
	public void turnRight() {
		this.setHeading(this.getHeading() + 5);
	}
	
	/**
	 * This method will check the boundary of the ant
	 * if it is out of bounds it will reverse in the other direction
	 * given the side the ant passed
	 */
	@Override
	public void checkBoundary() {
		if(this.getX() > 1000) {
//			System.out.println("Out of X axis bounds above 1000, turning around");
			this.setHeading(270);
		}
		if(this.getX() <= -1) {
//			System.out.println("Out of X axis bounds below 0, turning around");
			this.setHeading(90);
		}
		if(this.getY() > 1000) {
//			System.out.println("Out of Y axis bounds above 1000, turning around");
			this.setHeading(180);
		}
		if(this.getY() < -1) {
//			System.out.println("Out of Y axis bounds below 0, turning around");
			this.setHeading(0);
		}
	}
	
	/**
	 * This method is for when the ant loses a life and must be reset
	 * It will reset the health level, color, food level, and 
	 * decrement the life the ant has.
	 * @param x is the x-axis of the location of the last flag
	 * @param y is the y-axis of the location of the last flag
	 * @param flagNum will update the last flag that has been reached if dies
	 * near a flag
	 */
	public void resetAnt(float x, float y, int flagNum) {
		this.setLocation(x, y);
		this.setHeading(0);
		this.setColor(ColorUtil.rgb(100, 0, 0));
		this.maximumSpeed= 50;
		this.foodConsumptionRate = 1;
		this.foodLevel = 30;
		this.healthLevel = 10;
		this.lastFlagReached = flagNum;
		this.life--;
	}
	
	/**
	 * Overwrites the string method to return different values
	 * It will return the location, color, heading, speed,
	 * size, max speed, food level consuption
	 */
	@Override
	public String toString() {
		return ("Ant: loc=" + Math.round(this.getX() * 10.0) / 10.0 + "," + Math.round(this.getY() * 10.0) / 10.0 +
				" Color=" + this.getColortoString() +
				" Heading=" + this.getHeading() +
				" Speed=" + this.getSpeed() +
				" Size=" + this.getSize() +
				" Max Speed=" + this.getMaximumSpeed() +
				" Food Level Consumption=" + this.foodConsumptionRate);
	}
}