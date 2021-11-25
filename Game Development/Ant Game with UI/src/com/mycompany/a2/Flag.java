package com.mycompany.a2;

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
    public Flag(int size, float x, float y, int r, int g, int b, int sequenceNumber)
	{
		super(size, x, y, r,g,b);
		this.sequenceNumber = sequenceNumber;
	}
    
    /**
     * Overwrites the string method to return the flag's stats
	 * Such as location, color, size, and sequence number
     */
    @Override
    public String toString() {
    	return ("Flag: loc=" + Math.round(this.getX() * 10.0) / 10.0  + "," + Math.round(this.getY() * 10.0) / 10.0 +
    			" Color=" + this.getColortoString() + 
    			" Size=" + this.getSize() +
    			" Sequence number=" + this.getSequenceNumber());
    }
}