package com.mycompany.a3;
import java.util.Observable;
import java.util.Observer;
import com.codename1.charts.util.ColorUtil;
import com.codename1.ui.Component;
import com.codename1.ui.Container;
import com.codename1.ui.Label;
import com.codename1.ui.plaf.Style;

/**
 * This will create and populate the stats bar on top
 * @author Alexander Alestra
 *
 */
public class ScoreView extends Container implements Observer{
	private Label  soundValue;
	private Label  timeValue;
	private Label  livesLeft;
	private Label  lastFlagReached;
	private Label  foodLevel;
	private Label  healthLevel;
	private static final int COLOR = ColorUtil.BLUE;
	private static final int leftPad = 2;
	private static final int rightPad = 2;
	
	/**
	 * Will revieve object and use it to populate the stats bar with the correct format
	 * @param obj
	 */
	public ScoreView (Observable obj)
	{
		obj.addObserver(this);
		this.getAllStyles().setPadding(Component.LEFT, 200);
		this.add(labelMaker("Time:",COLOR));
		timeValue = labelMaker("", COLOR ,  leftPad,  rightPad);
		this.add(timeValue);
		this.add(labelMaker("Lives Left:", COLOR));
		livesLeft = labelMaker("", COLOR ,  leftPad,  rightPad);
		this.add(livesLeft);
		this.add(labelMaker("Last Flag Reached:", COLOR));
		lastFlagReached = labelMaker("", COLOR ,  leftPad,  rightPad);
		this.add(lastFlagReached);
		this.add(labelMaker("Food Level:", COLOR));
		foodLevel = labelMaker("", COLOR ,  leftPad,  rightPad);
		this.add(foodLevel);
		this.add(labelMaker("Health Level:", COLOR));
		healthLevel = labelMaker("", COLOR ,  leftPad,  rightPad);
		this.add(healthLevel);
		this.add(labelMaker("Sound:", COLOR));
		soundValue = labelMaker("", COLOR ,  leftPad,  rightPad);
		this.add(soundValue);		
	}
	
	/**
	 * Updates the status bar
	 */
	@Override
	public void update(Observable observable, Object data) {
		GameWorld gw = (GameWorld) observable;
		Ant ant = gw.getAnt();
		timeValue.setText(gw.getClock() + "  ");
		livesLeft.setText(String.valueOf(gw.getLives()));
		lastFlagReached.setText(String.valueOf(ant.getLastFlagReached()));;;
		foodLevel.setText(String.valueOf(ant.getFoodLevel()));
		healthLevel.setText(String.valueOf(ant.getHealthLevel()));
		String soundDisplay;
		if(gw.getSound() == true) {
			soundDisplay = "ON";
		}
		else {
			soundDisplay = "OFF";
		}
		soundValue.setText(soundDisplay);
		
	}

	/**
	 * Making labels with no padding
	 * @param name
	 * @param color
	 * @return
	 */
	private Label labelMaker(String name, int color) {
		Label temp = new Label(name);
		temp.getAllStyles().setFgColor(color);
		return temp;
	}
	
	/**
	 * Making labels with padding
	 * @param name
	 * @param color
	 * @param leftP
	 * @param rightP
	 * @return
	 */
	private Label labelMaker(String name, int color, int leftP, int rightP) {
		Label temp = new Label(name);
		Style styles = temp.getAllStyles();
		styles.setFgColor(color);
		styles.setPadding(LEFT, leftP);
		styles.setPadding(RIGHT, rightP);
		
		return temp;
	}
}