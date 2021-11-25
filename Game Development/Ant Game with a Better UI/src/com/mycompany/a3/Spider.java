package com.mycompany.a3;
import java.util.Random;
import com.codename1.ui.Graphics;
import com.codename1.ui.geom.Point;

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
	public Spider(int size, float x, float y, int r,int g, int b, int heading, int speed, GameWorld gw) {
		super(size, x, y,r,g,b,heading,speed, gw);
	}
	
	/**
	 * Will Draw out the spider using its location, sizem and color
	 */
	public void draw(Graphics g, Point pCmpRelScrn) {
		int x = (int)this.getX() + pCmpRelScrn.getX();
		int y = (int)this.getY() + pCmpRelScrn.getY();
		int s = this.getSize();
		int[] xSet = { (x + s/2), (x - s/2), x };
		int[] ySet = {(y + s/2), (y + s/2), (y - s/2) };
		g.drawPolygon(xSet, ySet, 3);
		g.setColor(this.getColor());
	}
	
	/**
	 * Collision with spider
	 */
	@Override
	public void handleCollision(GameObject otherObject) {
		System.out.println("Objects collide into Spiders and the other way around");
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
