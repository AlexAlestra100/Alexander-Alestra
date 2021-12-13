package com.mycompany.a4.commands;
import com.mycompany.a4.GameWorld;
import com.codename1.ui.Command;
import com.codename1.ui.events.ActionEvent;

public class Accelerate extends Command{
	private GameWorld gw;
	
	public Accelerate(GameWorld gw) {
		super("Accelerate");
		this.gw = gw;
	}
	
	public void actionPerformed(ActionEvent event) {
		gw.accelerate();
		System.out.println("Accelerating!");
	}
}
