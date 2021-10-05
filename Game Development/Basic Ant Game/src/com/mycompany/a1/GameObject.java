package com.mycompany.a1;
import com.codename1.charts.models.Point;
import java.util.Random;
import com.codename1.charts.util.ColorUtil;

/**
 * Class GameObject sets up the location using the X and Y axis points
 * It will make sure that the object is within parameters
 * It will also be the one to actually set the size and color instead of
 * passing it to a parent class
 * @author Alexander Alestra
 *
 */
public abstract class GameObject {
	private final int size;
	private int color;
	private Point location;
	final private int gameWorldWidth = 1000;
	final private int gameWorldHeight = 1000;
	
	/**
	 * Setting up the X axis point to where it
	 * must be within the 1000 and 0 mark
	 * @param x is the x-axis point of the object
	 */
	public void setX(float x) {
		if(0 <= x && x <= gameWorldWidth) {
			location.setX(x);
		}
		else {
			location.setX(new Random().nextInt(gameWorldWidth - 0) + 0);
		}
	}
	
	/**
	 * This will retrieve the x point for the given object
	 * @return the objects x coordinate
	 */
	public float getX() {
		return location.getX();
	}
	
	/**
	 * Setting up the Y axis point to where it
	 * must be within the 1000 and 0 mark
	 * @param y is the y-axis point of the object
	 */
	public void setY(float y) {
		if(0 <= y && y <= gameWorldHeight) {
			location.setY(y);
		}
		else {
			location.setY(new Random().nextInt(gameWorldHeight - 0) + 0);
		}
	}
	
	/**
	 * This will retrieve the y point for the given object
	 * @return the objects y coordinate
	 */
	public float getY() {
		return location.getY();
	}
	
	/**
	 * This setter will set the color of the object
	 * @param color rgb value of the object
	 */
	public void setColor(int color) {
		this.color = color;
	}
	
	/**
	 * This will get the given object's color
	 * @return rgb value of the object's color
	 */
	public int getColor() {
		return color;
	}
	
	/**
	 * This will get the given object's size from the child
	 * classes that will be passed
	 * @return the size of the given object
	 */
	public int getSize() {
		return size;
	}
	
	/**
	 * This will get the x and y location of the object
	 * then it will set it as a new point called location
	 * @param x is the x point of the object
	 * @param y is the y point of the object
	 */
	public void setLocation(float x, float y) {
		this.location = new Point(x,y);
	}
	
	/**
	 * This will get the color that is passed as an rgb value.
	 * @return it will return as an rgb value
	 */
	public String getColortoString() {
		return "["+ ColorUtil.red(this.color) + "," + ColorUtil.green(this.color) + "," + ColorUtil.blue(this.color)+"]";
	}
	
	/**
	 * The game object will set the object's color and size
	 * then will set the location
	 * @param color is the color given
	 * @param size is the size given
	 */
	public GameObject(int color, int size) {
		this.color = color;
		this.size = size;
		Random rnd = new Random();
		float x = (float)rnd.nextDouble() *  1000;
		float y = (float)rnd.nextDouble() * 1000;
		this.location  = new Point(x,y);
	}
}
