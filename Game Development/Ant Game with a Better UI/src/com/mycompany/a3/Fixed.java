package com.mycompany.a3;

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
	private boolean selected;

	public void setLocation(float x, float y) { }
	
	Fixed(int size, float x, float y, int r,int g, int b,  GameWorld gw) {
		super(size, x, y, r, g, b, gw);
	}
	
	public boolean isSelected() {
		return selected;
	}

	public void setSelected(boolean s) {
		this.selected = s;
	}
}