package com.mycompany.a2.commands;
import com.mycompany.a2.GameWorld;
import com.codename1.ui.Command;
import com.codename1.ui.events.ActionEvent;
import com.codename1.ui.TextField;
import com.codename1.ui.Dialog;

public class CollisionFlag extends Command{
	private GameWorld gw;
	
	public CollisionFlag(GameWorld gw) {
		super("Collide with Flag");
		this.gw = gw;
	}
	
	public void actionPerformed(ActionEvent event) {
		TextField num = new TextField();
		Command ok = new Command("OK");
		Command cancel = new Command("Cancel");
		Command confirm = Dialog.show("Enter Flag Number: ", num, ok, cancel);
		if(confirm == ok) {
			Integer input = Integer.parseInt(num.getText());
			if(input != 0 && input < 10) {
				gw.collisionFlag(input);
			}
			else {
				Dialog.show("Incorrect Input", "Enter a single digit");
			}
				
		}
	}
}