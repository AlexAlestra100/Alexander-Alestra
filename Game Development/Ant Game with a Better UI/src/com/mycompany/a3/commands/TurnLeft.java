package com.mycompany.a3.commands;
import com.mycompany.a3.GameWorld;
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
