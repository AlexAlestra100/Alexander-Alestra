package com.mycompany.a2.commands;
import com.mycompany.a2.GameWorld;
import com.codename1.ui.Command;
import com.codename1.ui.events.ActionEvent;

public class CollisionFoodStation extends Command{
	private GameWorld gw;
	
	public CollisionFoodStation(GameWorld gw) {
		super("Collide with Food Station");
		this.gw = gw;
	}
	
	public void actionPerformed(ActionEvent event) {
		gw.collisionFoodStation();
		System.out.println("Collision with food station");
	}
}
