package com.mycompany.a2.commands;
import com.codename1.ui.events.ActionEvent;
import com.codename1.ui.Command;
import com.codename1.ui.Dialog;

public class Exit extends Command{
	public Exit() {
		super("Exit");
	}
	
	public void actionPerformed(ActionEvent event) {
		Command exit = new Command("Yes");
    	Command noExit = new Command("No");
    	Command input = Dialog.show("Exit","Are you sure you?", exit, noExit);
    	if(input == exit) {
    		System.exit(0);
    	}
	}
}
