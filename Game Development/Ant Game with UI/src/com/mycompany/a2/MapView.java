package com.mycompany.a2;
import java.util.Observable;
import java.util.Observer;
import com.codename1.charts.util.ColorUtil;
import com.codename1.ui.Container;
import com.codename1.ui.plaf.Border;

/**
 * This will set the Map view settings for the gui
 * @author Alexander Alestra
 *
 */
public class MapView extends Container implements Observer{
	public MapView(Observable obj) {
		this.getAllStyles().setBorder(Border.createLineBorder(5, ColorUtil.rgb(255,0,0)));
		this.setWidth(1000);
		this.setHeight(1000);
		obj.addObserver(this);
	}
	
	@Override
	public void update(Observable observable, Object data) {
		((GameWorld) observable).printMap();
	}
}
