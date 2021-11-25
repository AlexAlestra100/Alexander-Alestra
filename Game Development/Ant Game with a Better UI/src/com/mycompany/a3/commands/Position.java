package com.mycompany.a3.commands;
import com.codename1.ui.Command;
import com.codename1.ui.events.ActionEvent;
import com.mycompany.a3.GameWorld;

public class Position extends Command{
	private GameWorld gw;

	public Position(GameWorld gw) {
		super("Position");
		this.gw = gw;
	}
	
	public void actionPerformed(ActionEvent event) {
		if(gw.isPaused()) {
			gw.reposition();
		}
	}

}