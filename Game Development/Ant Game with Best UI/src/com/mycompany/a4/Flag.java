package com.mycompany.a4;
import com.codename1.charts.util.ColorUtil;
import com.codename1.ui.Graphics;
import com.codename1.ui.geom.Point;
import com.codename1.ui.Transform;

/**
 * The flag class is simple and has
 * location, size, sequence number, and location
 * 
 * @author Alexander Alestra
 *
 */
public class Flag extends Fixed {
    private int sequenceNumber;
    
    /**
     * Will overwrite set color in gameobject
     */
    @Override
    public void setColor(int r, int g, int b){
    	System.out.println("Cannot be changed");
    }
    
    /**
     * gets the sequence number that is set
     * @return the sequence number that is 1-9
     */
    public int getSequenceNumber(){
        return this.sequenceNumber;
    }
    
    /**
     * This will set the sequence number
     * @param sequenceNumber is the number that the flag will be assigned 1-9
     */
    public void setSequenceNumber(int sequenceNumber) {
    	this.sequenceNumber = sequenceNumber;
    }
    
    /**
     * This will set the flag with a color and a set size of 10 in the gameobject
     * The location is sent as 0,0 but will be randomized in game object
     * Assigns what number the flag is
     * @param sequenceNumber
     */
    public Flag(int size, float x, float y, int r, int g, int b, int sequenceNumber, GameWorld gw) {
		super(size, x, y, r,g,b, gw);
		this.sequenceNumber = sequenceNumber;
//		top = new Point(0, size/2);
//		bottomLeft = new Point(-size/2, -size/2);
//		bottomRight = new Point(size/2, size/2);
	}
    
    /**
     * gets point of object, size, and then draws shape.
     * @param g
     * @param pCmpRelScrn
     */
    public void draw(Graphics g, Point pCmpRelPrnt, Point pCmpRelScrn) {
    	int stringX = (int)Math.round(this.getLocation().getX() - 10) + pCmpRelPrnt.getX();
  	  	int stringY = (int)Math.round(this.getLocation().getY() - 10) + pCmpRelPrnt.getY();
		
//		//get relative point of object
//		int x = (int)this.getX() + pCmpRelScrn.getX();
//		int y = (int)this.getY() + pCmpRelScrn.getY();
//		int s = this.getSize();
//		int[] xSet = { x, (x - 20), (x + 20), x };
//		int[] ySet = { (y + 30), (y - 30), (y - 30), (y + 30) };
//		if(super.isSelected() && super.getWorld().isPaused()) {
//			g.drawPolygon(xSet, ySet, 3);
//		}
//		else {
//			g.fillPolygon(xSet, ySet, 3);
//		}
//		//		g.setColor(this.getColor());
  	  	
  	  	Transform gXform = Transform.makeIdentity();
  
  	  	g.getTransform(gXform);
  	  	
  	  	Transform gPform = gXform.copy();
  	  	
  	  	gXform.translate(pCmpRelScrn.getX(), pCmpRelScrn.getX());
  	  	gXform.translate(getMyTranslation().getTranslateX(), getMyTranslation().getTranslateY());
  	  	gXform.concatenate(getMyRotation());
  	  	gXform.scale(getMyScale().getScaleX(), getMyScale().getScaleY());
  	  	gXform.translate(-pCmpRelScrn.getX(), -pCmpRelScrn.getY());
  	  	g.setTransform(gXform);
		
		int x = (int)this.getLocation().getX() + pCmpRelPrnt.getX();
		int y = (int)this.getLocation().getY() + pCmpRelPrnt.getY();
		int s = this.getSize();
		int[] xSet = {x - (s/2), x, x + (s/2)};
		int[] ySet = {y - (s/2), y + (s/2), y - (s/2)};
		g.setColor(this.getColor());
		if(super.isSelected() && super.getWorld().isPaused()) {
			g.drawPolygon(xSet, ySet, 3);
		}
		else {
			g.fillPolygon(xSet, ySet, 3);
		}
		
		g.setColor(ColorUtil.BLACK);
		
		gXform.translate(pCmpRelScrn.getX(), pCmpRelScrn.getX());
		gXform.scale(-1, 1);
		gXform.translate(-pCmpRelScrn.getX(), -pCmpRelScrn.getY());
		
//		g.setTransform(gXform);
		
		g.drawString("" + this.getSequenceNumber(), stringX, stringY);
		
		g.setTransform(gPform);
	}

	@Override
	public void handleCollision(GameObject otherObject) {
		System.out.println("Objects collide into flags only!");
	}
    
    /**
     * Overwrites the string method to return the flag's stats
	 * Such as location, color, size, and sequence number
     */
    @Override
    public String toString() {
    	return ("Flag: loc=" + Math.round(this.getLocation().getX() * 10.0) / 10.0  + "," + Math.round(this.getLocation().getY() * 10.0) / 10.0 +
    			" Color=" + this.getColortoString() + 
    			" Size=" + this.getSize() +
    			" Sequence number=" + this.getSequenceNumber());
    }
}