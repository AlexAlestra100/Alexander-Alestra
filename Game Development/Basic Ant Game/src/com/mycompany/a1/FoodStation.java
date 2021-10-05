package com.mycompany.a1;
import java.util.Random;
import com.codename1.charts.util.ColorUtil;

/**
 * The food station is fixed and can be varied in size
 * @author Alexander Alestra
 *
 */
public class FoodStation extends Fixed{
	private static final int minSize = 10;
	private static final int maxSize = 30;
    private int capacity;
    Random random = new Random();
    
    /**
     * Sets the capacity of given food station
     * @param capacity the amount  of food it can hold
     */
    public void setCapacity(int capacity){
        this.capacity = capacity;
    }
    
    /**
     * Gets the capacity of given food station
     * @return the capacity
     */
    public int getCapacity(){
        return capacity;
    }
    
    /**
     * This will set the food stations color and size randomly
     * The capacity is the same as it's size
     */
    public FoodStation() {
    	super(ColorUtil.rgb(0, 100, 0), new Random().nextInt(maxSize - minSize) + minSize);
    	this.capacity = this.getSize();
    }

    /**
     * Overwrites the string method to return the food station stats
	 * Such as location, color, size, and capacity
     */
    public String toString() {
    	return ("FoodStation: loc=" + Math.round(this.getX() * 10.0) / 10.0  + "," + Math.round(this.getY() * 10.0) / 10.0 +
    			" Color=" + this.getColortoString() + 
    			" Size=" + this.getSize() +
    			" Capacity=" + this.getCapacity());
    }
}
