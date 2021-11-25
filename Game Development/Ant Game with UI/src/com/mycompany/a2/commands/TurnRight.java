package com.mycompany.a2.commands;
import com.mycompany.a2.GameWorld;
import com.codename1.ui.Command;
import com.codename1.ui.events.ActionEvent;

public class TurnRight extends Command{
	private GameWorld gw;
	
	public TurnRight(GameWorld gw) {
		super("Turn Right");
		this.gw = gw;
	}
	
	public void actionPerformed(ActionEvent event) {
		gw.turnRight();
		System.out.println("Turning Right");
	}
}
