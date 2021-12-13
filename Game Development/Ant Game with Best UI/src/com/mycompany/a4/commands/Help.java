package com.mycompany.a4.commands;
import com.codename1.ui.events.ActionEvent;
import com.codename1.ui.Command;
import com.codename1.ui.Dialog;

public class Help extends Command{
	public Help() {
		super("Help");
	}
	
	public void actionPerformed(ActionEvent event) {
		String commands =
				"a: Accelerate\n" +
				"b: Break\n" + 
				"l: Turn Left\n" +
				"r: Turn Right\n" + 
				"f: Collide with Food\n" +
				"g: Collide with Spider\n" + 
				"t: Tick";
				
		Dialog.show("List Of Commands",commands, "OK",null);
	}
}
