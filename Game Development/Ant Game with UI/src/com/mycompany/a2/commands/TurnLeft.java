package com.mycompany.a2.commands;
import com.mycompany.a2.GameWorld;
import com.codename1.ui.Command;
import com.codename1.ui.events.ActionEvent;

public class TurnLeft extends Command{
	private GameWorld gw;
	
	public TurnLeft(GameWorld gw) {
		super("Turn Left");
		this.gw = gw;
	}
	
	public void actionPerformed(ActionEvent event) {
		gw.turnLeft();
		System.out.println("Turning Left");
	}
}
