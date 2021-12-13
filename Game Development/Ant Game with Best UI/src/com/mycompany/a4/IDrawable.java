package com.mycompany.a4;
import com.codename1.ui.Graphics; 
import com.codename1.ui.geom.Point;

/**
 * Draws the point of object
 * @author Alexander Alestra
 *
 */
public interface IDrawable {
	public void draw(Graphics g, Point pCmpRelPrnt, Point pCmpRelScrn);
}
