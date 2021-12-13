package com.mycompany.a4.commands;
import com.codename1.ui.events.ActionEvent;
import com.codename1.ui.Command;
import com.codename1.ui.Dialog;

public class About extends Command{
	public About() {
		super("About");
	}
	
	public void actionPerformed(ActionEvent event) {
		Dialog.show("Developer: Alexander Alestra", "CSC 133 Fall 2021", "OK", null);
	}
}
