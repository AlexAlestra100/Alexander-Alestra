package com.mycompany.a2.commands;
import com.mycompany.a2.GameWorld;
import com.codename1.ui.Command;
import com.codename1.ui.events.ActionEvent;

public class GameTick extends Command{
	private GameWorld gw;
	
	public GameTick(GameWorld gw) {
		super("Tick Game");
		this.gw = gw;
	}
	
	public void actionPerformed(ActionEvent event) {
		gw.gameTick();
		System.out.println("Game has ticked");
	}
}
