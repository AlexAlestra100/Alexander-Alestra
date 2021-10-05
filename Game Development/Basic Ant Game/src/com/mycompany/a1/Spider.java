package com.mycompany.a1;
import java.util.Random;
import com.codename1.charts.util.ColorUtil;

/**
 * The class spider is a concrete class to be added in gameworld as an object
 * @author Alexander Alestra
 *
 */
public class Spider extends Movable {
	private static Random random = new Random();
	private static final int minSize = 10;
	private static final int maxSize = 50;
	
	/**
	 * This will overwrite move in Movable to let the heading be random
	 */
	@Override
	public void move() {
		this.setHeading(super.getHeading() + random.nextInt(5 - (-5)) - 5);
		super.move();
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
	public Spider() {
		super(ColorUtil.BLACK, new Random().nextInt(maxSize - minSize) + minSize, random.nextInt(25), random.nextInt(360));
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
