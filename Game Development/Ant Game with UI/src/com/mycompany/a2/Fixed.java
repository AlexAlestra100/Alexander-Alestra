package com.mycompany.a2;

/**
 * Will only let color and size pass through to game object
 * since any object that is fixed cannot move. 
 * 
 * Location is random
 * 
 * @author Alexander Alestra
 *
 */
public abstract class Fixed extends GameObject{

	public void setLocation(float x, float y) { }
	
	public Fixed(int size, float x, float y, int r,int g, int b) {
		super(size, x, y, r, g, b);
	}
}