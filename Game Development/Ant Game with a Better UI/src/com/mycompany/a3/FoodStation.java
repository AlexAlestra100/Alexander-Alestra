package com.mycompany.a3;
import java.util.Random;

import com.codename1.charts.util.ColorUtil;
import com.codename1.ui.Graphics;
import com.codename1.ui.geom.Point;

/**
 * The food station is fixed and can be varied in size
 * @author Alexander Alestra
 *
 */
public class FoodStation extends Fixed{
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
    public FoodStation(int size, float x, float y,int r,int g, int b, GameWorld gw) {
		super(size, x, y, r,g,b, gw);
		this.setCapacity(size);
	}
    
    /**
     * Will get the location, color, and draw them out.
     * @param g
     * @param pCmpRelScrn
     */
    public void draw(Graphics g, Point pCmpRelScrn) {
    	int stringX = (int)Math.round(this.getX() +15) + pCmpRelScrn.getX();
		int stringY = (int)Math.round(this.getY() +10) + pCmpRelScrn.getY();
		int x = (int)this.getX() + pCmpRelScrn.getX();
		int y = (int)this.getY() + pCmpRelScrn.getY();
		int s = this.getSize();
		int xSet[] = {(x + s/2), (x - s/2), ( x + s/2), (x - s/2)};
		int ySet[] = {(y + s/2), (y + s/2), ( y - s/2), (y - s/2)};
		if(super.isSelected() && super.getWorld().isPaused()) {
			g.drawPolygon(xSet, ySet, 3);
		}
		else {
			g.fillPolygon(xSet, ySet, 3);
		}
		g.setColor(ColorUtil.BLACK);
		g.drawString("" + this.getCapacity(), stringX, stringY);
		g.setColor(ColorUtil.rgb(0, 255, 0));
	}
	
    /**
     * Prints out collisions if one happens
     */
	@Override
	public void handleCollision(GameObject otherObject) {
		System.out.println("Objects collide into Food Stations");
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
