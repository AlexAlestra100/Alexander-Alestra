package com.mycompany.a3;
import java.util.Observable;
import java.util.Observer;
import com.codename1.charts.util.ColorUtil;
import com.codename1.ui.Container;
import com.codename1.ui.Graphics;
import com.codename1.ui.geom.Point;
import com.codename1.ui.plaf.Border;

/**
 * This will set the Map view settings for the gui
 * @author Alexander Alestra
 *
 */
public class MapView extends Container implements Observer{
	private GameWorld gw;
	
	public MapView(Observable obj) {
		this.getAllStyles().setBorder(Border.createLineBorder(5, ColorUtil.rgb(255,0,0)));
		this.setWidth(1000);
		this.setHeight(1000);
		obj.addObserver(this);
		this.gw = (GameWorld) obj;
	}
	
	/**
	 * Will call repaint
	 */
	@Override
	public void update(Observable observable, Object data) {
		this.repaint();
	}
	
	/**
	 * Will repaint the gui with the correct points
	 */
	public void paint(Graphics g) {
		super.paint(g);
		Point pCmpRelPrnt = new Point(this.getX(), this.getY());
		gw.getAnt().draw(g, pCmpRelPrnt);
		Iterator objs = gw.getObjectsCollection().getIterator();
		while(objs.hasNext())
				objs.next().draw(g, pCmpRelPrnt);
	}
}
