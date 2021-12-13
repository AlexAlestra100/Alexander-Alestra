package com.mycompany.a4.commands;
import com.codename1.ui.Command;
import com.codename1.ui.events.ActionEvent;
import com.mycompany.a4.Game;
import com.mycompany.a4.GameWorld;

public class Pause extends Command{
	private GameWorld gw;
	private Game game;

	public Pause(GameWorld gw, Game game) {
		super("Pause");
		this.gw = gw;
		this.game = game;
	}
	
	public void actionPerformed(ActionEvent event) {
		game.pressedPause();
		gw.pause(!gw.isPaused());
	}

}