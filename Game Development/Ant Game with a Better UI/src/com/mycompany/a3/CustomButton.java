package com.mycompany.a3;
import com.codename1.ui.plaf.Border;
import com.codename1.ui.plaf.Style;
import com.codename1.charts.util.ColorUtil;
import com.codename1.ui.Button;
import com.codename1.ui.Command;

/**
 * Created a custom button class so I can just call a new version without having to type it out multiple times
 * @author Alexander Alestra
 *
 */
public class CustomButton extends Button {
	private Command cmd;
	
	/**
	 * Takes in the cmd command and creates the button from it.
	 * @param cmd
	 */
	public CustomButton(Command cmd) {
		super();
		this.cmd = cmd;
		this.setFocusable(false);
		Style style = this.getAllStyles();
		style.setBorder(Border.createLineBorder(3,ColorUtil.rgb(0, 0, 0)));
		style.setFgColor(ColorUtil.WHITE);
		style.setPadding(TOP,2);
		style.setPadding(BOTTOM,2);
		style.setBgTransparency(255);
		style.setBgColor(ColorUtil.rgb(0, 0, 255));
		this.setCommand(cmd);
	}
	
	/**
	 * Returns the specific cmd
	 */
	public Command getCommand() {
		return this.cmd;
	}
}