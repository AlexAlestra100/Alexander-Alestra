package com.mycompany.a4;
import com.codename1.charts.models.Point;
import com.codename1.ui.Graphics;

/**
 * Was not completed due to time contraint and other classes with lots of work. :(
 * @author Alexander Alestra
 *
 */
public interface ISelectable {
	public void setSelected(boolean y);
	public boolean isSelected();
//	public boolean contains(Point pPtrRelPrnt, Point pCmpRelPrint);
	public void draw(Graphics g, Point pCmpRelPrnt, Point pCmpRelScrn);
}
