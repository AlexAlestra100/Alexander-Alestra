package com.mycompany.a4;
import java.util.Random;

import com.codename1.charts.util.ColorUtil;
import com.codename1.ui.Graphics;
import com.codename1.ui.geom.Point;
import com.codename1.ui.Transform;

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
    	
    	int stringX = (int)Math.round(this.getLocation().getX() +15) + pCmpRelPrnt.getX();
		int stringY = (int)Math.round(this.getLocation().getY() +10) + pCmpRelPrnt.getY();
		int x = (int)this.getLocation().getX() + pCmpRelPrnt.getX();
		int y = (int)this.getLocation().getY() + pCmpRelPrnt.getY();
		int s = this.getSize();
		int xSet = (x - s/2);
		int ySet = (y - s/2);
		g.setColor(ColorUtil.rgb(0, 255, 0));
		if(super.isSelected() && super.getWorld().isPaused()) {
			g.drawRect(xSet, ySet, s, s);
		}
		else {
			g.fillRect(xSet, ySet, s, s);
		}
		g.setColor(ColorUtil.BLACK);
		
		gXform.translate(pCmpRelScrn.getX(), pCmpRelScrn.getX());
		gXform.scale(-1, 1);
		gXform.translate(-pCmpRelScrn.getX(), -pCmpRelScrn.getY());
		
//		g.setTransform(gXform);
		
		g.drawString("" + this.getCapacity(), stringX, stringY);
		
		g.setTransform(gPform);
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
    	return ("FoodStation: loc=" + Math.round(this.getLocation().getX() * 10.0) / 10.0  + "," + Math.round(this.getLocation().getY() * 10.0) / 10.0 +
    			" Color=" + this.getColortoString() + 
    			" Size=" + this.getSize() +
    			" Capacity=" + this.getCapacity());
    }
}
