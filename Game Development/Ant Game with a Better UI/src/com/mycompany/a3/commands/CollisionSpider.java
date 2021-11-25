package com.mycompany.a3.commands;
import com.mycompany.a3.GameWorld;
import com.codename1.ui.Command;
import com.codename1.ui.events.ActionEvent;

public class CollisionSpider extends Command{
	private GameWorld gw;
	
	public CollisionSpider(GameWorld gw) {
		super("Collide with Spider");
		this.gw = gw;
	}
	
	public void actionPerformed(ActionEvent event) {
		gw.collisionSpider();
		System.out.println("Collision between Spider and Ant have occured");
	}
}
