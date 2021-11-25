package com.mycompany.a2.commands;
import com.mycompany.a2.GameWorld;
import com.codename1.ui.Command;
import com.codename1.ui.events.ActionEvent;
import com.codename1.ui.CheckBox;

public class Sound extends Command{
	private GameWorld gw;

	public Sound(GameWorld gw) {
		super("Sound: ON or OFF");
		this.gw = gw;
	}
	
	public void actionPerformed(ActionEvent event) {
		System.out.println("Sound!");
		CheckBox box = (CheckBox) event.getComponent();
		if(box.isSelected())
			gw.setSound(true);
		else
			gw.setSound(false);
	}
}
