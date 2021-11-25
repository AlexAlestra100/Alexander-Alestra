package com.mycompany.a2;
import java.util.Random;

/**
 * The class spider is a concrete class to be added in gameworld as an object
 * @author Alexander Alestra
 *
 */
public class Spider extends Movable {
	private static Random random = new Random();
	
	/**
	 * This will overwrite move in Movable to let the heading be random
	 */
	public void move(int maxHeight, int maxWidth) {
		float deltaX = (float) Math.cos(this.getRadians() * this.getSpeed());
		float deltaY = (float) Math.sin(this.getRadians() * this.getSpeed());
		float oldX = this.getX();
		float oldY = this.getY();
		if(deltaX+oldX > maxWidth || deltaY+oldY > maxHeight) {
			this.setHeading(-this.getHeading());
		}
		super.move();
	}
	
	/**
	 * Make sure the color of spider cannot be set
	 * @param r red value
	 * @param g green value
	 * @param b blue value
	 */
	public void setColor(int r, int g, int b)
	{
		System.out.println("Cannot set color");
	}
	
	/**
	 * This method will check to see if the spider is in boundary
	 * if not it will randomly be chosen a different heading in the opposite
	 * direction
	 */
	@Override
	public void checkBoundary() {
		if(this.getX() > 1000 || this.getX() < 0) {
			this.setHeading(random.nextInt(180));
			
		}
		if(this.getY() > 1000 || this.getY() < 0 ) {
			this.setHeading(random.nextInt(180));
		}
	}
	
	/**
	 * This sets the Spiders color and size randomly
	 */
	public Spider(int size, float x, float y, int r,int g, int b, int heading, int speed)
	{
		super(size, x, y,r,g,b,heading,speed);
	}
	
	/**
	 * Overwrites the string method to return the spiders stats
	 * Such as location, color, size, heading, and speed
	 */
	@Override
	public String toString() {
		return ("Spider: loc=" + Math.round(this.getX() * 10.0) / 10.0  + "," + Math.round(this.getY() * 10.0) / 10.0 +
    			" Color=" + this.getColortoString() + 
    			" Size=" + this.getSize() +
    			" Heading="+ this.getHeading() +
    			" Speed=" + this.getSpeed());
	}
}
