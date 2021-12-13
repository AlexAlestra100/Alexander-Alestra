package com.mycompany.a4;
import java.io.InputStream;
import com.codename1.media.Media;
import com.codename1.media.MediaManager;
import com.codename1.ui.Display;

/**
 * Here we use the file names to find the sound files and are able to play them
 * @author Alexander Alestra
 *
 */
public class Sound {
	private Media m;
	
	public Sound(String fileName) {
		try {
			InputStream stream = Display.getInstance().getResourceAsStream(getClass(),"/"+fileName);			
			m = MediaManager.createMedia(stream, "audio/wav");
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public void play() {
		m.setTime(0);
		m.play();
	}
}