package com.mycompany.a4.commands;
import com.mycompany.a4.GameWorld;
import com.codename1.ui.Command;
import com.codename1.ui.events.ActionEvent;
import com.codename1.ui.CheckBox;

public class SoundCMD extends Command{
	private GameWorld gw;

	public SoundCMD(GameWorld gw) {
		super("Sound: ON or OFF");
		this.gw = gw;
	}
	
	public void actionPerformed(ActionEvent event) {
		System.out.println("Sound!");
		CheckBox box = (CheckBox) event.getComponent();
		if(box.isSelected())
			gw.setSound(false);
		else
			gw.setSound(true);
	}
}