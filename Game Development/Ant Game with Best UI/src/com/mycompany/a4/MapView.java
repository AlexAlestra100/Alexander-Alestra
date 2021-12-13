package com.mycompany.a4;
import java.util.Observable;
import java.util.Observer;
import com.codename1.charts.util.ColorUtil;
import com.codename1.ui.Container;
import com.codename1.ui.Graphics;
import com.codename1.ui.geom.Point;
import com.codename1.ui.plaf.Border;
import com.codename1.ui.Transform;

/**
 * This will set the Map view settings for the gui
 * @author Alexander Alestra
 *
 */
public class MapView extends Container implements Observer{
	private GameWorld gw;
	Transform worldToND, ndToDisplay, theVTM;
	
	public MapView(Observable obj) {
		this.getAllStyles().setBorder(Border.createLineBorder(5, ColorUtil.rgb(255,0,0)));
//		this.setWidth(1000);
//		this.setHeight(1000);
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
		
		worldToND = buildWorldToNDXform(gw.getWidth(), gw.getHeight(), gw.getWinLeft(), gw.getWinBottom());
		ndToDisplay = buildNDToDisplayXform(this.getWidth(), this.getHeight());
		theVTM = ndToDisplay.copy();
		theVTM.concatenate(worldToND);
		
		Transform gXform = Transform.makeIdentity();
		g.getTransform(gXform);
		gXform.translate(getAbsoluteX(), getAbsoluteY());
		gXform.concatenate(theVTM);
		gXform.translate(-getAbsoluteX(), -getAbsoluteY());
		g.setTransform(gXform);
		
		Point pCmpRelPrnt = new Point(this.getX(), this.getY());
		Point pCmpRelScrn = new Point(getAbsoluteX(), getAbsoluteY());
		gw.getAnt().draw(g, pCmpRelPrnt, pCmpRelScrn);
		Iterator objs = gw.getObjectsCollection().getIterator();
		while(objs.hasNext())
				objs.next().draw(g, pCmpRelPrnt, pCmpRelScrn);
		
		g.resetAffine();
	}
	
	private Transform buildWorldToNDXform(float winWidth, float winHeight, float winLeft, float winBottom) {
		Transform tmpXfrom = Transform.makeIdentity();
		tmpXfrom.scale( (1/winWidth) , (1/winHeight) );
		tmpXfrom.translate(-winLeft,-winBottom);
		return tmpXfrom;
	}
	
	private Transform buildNDToDisplayXform (float displayWidth, float displayHeight) { 
		Transform tmpXfrom = Transform.makeIdentity();
		tmpXfrom.translate(0, displayHeight);
		tmpXfrom.scale(displayWidth, -displayHeight);
		return tmpXfrom;
	}
}
