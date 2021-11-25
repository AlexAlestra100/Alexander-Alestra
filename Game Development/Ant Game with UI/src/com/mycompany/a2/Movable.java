package com.mycompany.a2;
import java.lang.Math;

/**
 * This will allow any of the concrete classes move within
 * the game world
 * @author Alexander Alestra
 *
 */
public abstract class Movable extends GameObject {
	private int heading;
	private int speed;
	
	/**
	 * This method will set the color, size, speed, and heading
	 * for a given object
	 * @param color is the rgb value of a movable object
	 * @param size is the size of the movable object
	 * @param speed is the distance traveled in one tick
	 * @param heading is the direction the object is heading
	 */
	public Movable(int size, float x, float y, int r,int g, int b, int heading, int speed)
	{
		super(size, x, y, r,g,b);
		this.speed = speed;
		this.heading = heading;
	}
	
	/**
	 * Sets the speed of the object
	 * @param speed is the amount of distance can be
	 * crossed in one tick
	 */
	public void setSpeed(int speed) {
		this.speed = speed;
	}
	
	/**
	 * This will get the speed of the current object
	 * @return will return the given speed
	 */
	public int getSpeed() {
		return speed;
	}
	
	/**
	 * This will set the heading within 360 degrees going clockwise
	 * @param heading will be set to 360+given heading
	 * after deviding the remainder will be left
	 */
	public void setHeading(int heading) {
		this.heading = (360 + heading) % 360;
	}
	
	/**
	 * This will retieve the heading from the given object
	 * @return will return the heading
	 */
	public int getHeading() {
		return heading;
	}
	
	/**
	 * Overwritten by the child classes
	 */
	public void checkBoundary() { }
	
	/**
	 * Move method will set the location of the object based on the heading
	 * and the new X and Y coordinates
	 */
	public void move()
	{
		//get deltas (expected change over time for x and y)
		float deltaX = (float) Math.cos(this.getRadians() * this.speed);
		float deltaY = (float) Math.sin(this.getRadians() * this.speed);
		
		//get old location and add deltas
		float oldX = this.getX();
		float oldY = this.getY();
		
		//update location of object with old locations + expected change (delta)
		this.setLocation((oldX+=deltaX),(oldY+=deltaY));
	}
	
	/**
	 * Handy method to calculate the ints in radians
	 * @return the answer
	 */
	protected double getRadians() {
		return Math.toRadians(90 - this.heading);
	}
}
