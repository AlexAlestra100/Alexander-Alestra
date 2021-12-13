package com.mycompany.a4;
import java.util.Random;

import com.codename1.charts.util.ColorUtil;
import com.codename1.ui.Graphics;
import com.codename1.ui.geom.Point;
import com.codename1.ui.Transform;

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
		float oldX = this.getLocation().getX();
		float oldY = this.getLocation().getY();
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
		if(this.getLocation().getX() > 1000 || this.getLocation().getX() < 0) {
			this.setHeading(random.nextInt(180));
			
		}
		if(this.getLocation().getY() > 1000 || this.getLocation().getY() < 0 ) {
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
	public void draw(Graphics g, Point pCmpRelPrnt, Point pCmpRelScrn) {
	
		Transform gXform = Transform.makeIdentity();
		  
  	  	g.getTransform(gXform);
  	  	
  	  	Transform gPform = gXform.copy();
  	  	
  	  	gXform.translate(pCmpRelScrn.getX(), pCmpRelScrn.getX());
  	  	gXform.translate(getMyTranslation().getTranslateX(), getMyTranslation().getTranslateY());
  	  	gXform.concatenate(getMyRotation());
  	  	gXform.scale(getMyScale().getScaleX(), getMyScale().getScaleY());
  	  	gXform.translate(-pCmpRelScrn.getX(), -pCmpRelScrn.getY());
  	  	g.setTransform(gXform);
		
		int x = (int)this.getLocation().getX() + pCmpRelScrn.getX();
		int y = (int)this.getLocation().getY() + pCmpRelScrn.getY();
		int s = this.getSize();
		int[] xSet = {x - (s/2), x, x + (s/2)};
		int[] ySet = {y - (s/2), y + (s/2), y - (s/2)};
		
		g.setColor(this.getColor());
		g.fillPolygon(xSet, ySet, 3);
		
		g.setTransform(gPform);
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
		return ("Spider: loc=" + Math.round(this.getLocation().getX() * 10.0) / 10.0  + "," + Math.round(this.getLocation().getY() * 10.0) / 10.0 +
    			" Color=" + this.getColortoString() + 
    			" Size=" + this.getSize() +
    			" Heading="+ this.getHeading() +
    			" Speed=" + this.getSpeed());
	}
}
