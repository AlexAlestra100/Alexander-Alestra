package com.mycompany.a2;

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
	private static Ant ant;	
	
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
    * returns the consumption rate
    */
    private int getConsumptionRate() { 
    	return this.foodConsumptionRate;
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
	 * This will return a new ant when called if there isn't an existing one
	 * @return ant Ant type
	 */
	public static Ant getAnt()
	{
		if(ant == null)
			ant = new Ant();
		return ant;
	}
	
	/**
	 * Will calculate the food level subtracting the consumption from the food level
	 */
	public void calcFoodLevel() {
		this.foodLevel = this.foodLevel - foodConsumptionRate;
		if(this.foodLevel < 0) {
				this.foodLevel = 0;
		}
	}
    
	/**
	 * This will increase the ants current speed by 5
	 */
    public void accelerate() {
		int currentSpeed = getSpeed();
		int maxSpeed = this.maximumSpeed;
		int health = this.getHealthLevel();
		maxSpeed = maxSpeed * (health / 10);
		if(currentSpeed >= maxSpeed) {
			this.setSpeed(maxSpeed);
		}
		else {
			this.setSpeed(currentSpeed + 1);
		}	
	}
    
    /**
     * This will decrease the ants current speed by 5
     */
    public void brake() {
		int currSpeed = getSpeed();
		if(currSpeed - 1 < 0)
			this.setSpeed(0);
		else
			this.setSpeed(currSpeed - 1);
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
		if(this.foodLevel < 0) {
			this.foodLevel = 0;
		}
	}
	
	/*
	 * Updates the heading via the current heading
	 */
	public void updateHeading(int heading)
	{ 
		int currHeading = this.getHeading();
		currHeading = currHeading + heading;
		this.setHeading(currHeading);
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
	
	/*
	 * This will be called when the ant needs to move every tik
	 */
	public void move()
	{
		if(this.foodLevel <= 0 || this.healthLevel <= 0) {
			System.out.println("Starved to death.");
		}
		else {
			super.move();
		}
	}
	
	/**
	 *
	 */
	private Ant() {
		super(10,250,250,255,0,0,0,10);
		maximumSpeed = 15;
		foodConsumptionRate = 1;
		foodLevel = 30;
		healthLevel = 10;
		lastFlagReached = 1;
	}
	
	/**
	 * Resets ants stats when killed
	 */
	public void reset()
	{
		ant = null;
		getAnt();
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