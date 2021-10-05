package com.mycompany.a1;
import com.codename1.ui.Form;
import com.codename1.ui.events.ActionListener;
import com.codename1.ui.Label;
import com.codename1.ui.TextField;
import com.codename1.ui.events.ActionEvent; 
import java.lang.String;

/**
 * this class implements the  Game method to start the game
 * @author Alexander Alestra
 *
 */
public class Game extends Form{
	private GameWorld gw;
	private char inputKey;
	
	/**
	 * This sets the input key to the desired key chosen
	 * @param key the key chosen
	 */
	private void setKey(char key)
	{
		this.inputKey=key;
	}
	/**
	 * Returns the input key
	 * @return the input key set
	 */
	private char getKey() {
		return this.inputKey;
	}
	
	/**
	 * Creates a new instance of GameWorld, then initializes it, and then executes the play function 
	 */
	public Game() {
		gw = new GameWorld();
		gw.init();
		play();
	}
	/**
	 * Will use active listener to accept keys for the switch statement below
	 * to allow the user  to play the game
	 */
	private void play() {
		Label myLabel=new Label("Enter a Command:");
		this.addComponent(myLabel);
		final TextField myTextField=new TextField();
		this.addComponent(myTextField);
		this.show();
		myTextField.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent evt) {
				String sCommand=myTextField.getText().toString();
				myTextField.clear();
				if(sCommand.length() != 0)
					switch (sCommand.charAt(0)) {
						case 'a':
							gw.accelerate(); 
							break;
						case 'b':
							gw.brake();
							break;
						case 'l':
							gw.turnLeftAnt();
							break;
						case 'r':
							gw.turnRightAnt();
							break;
						// Case 1 -9
						case '1':
							gw.collisonFlag(1);
							break;
						case '2':
							gw.collisonFlag(2);
							break;
						case '3':
							gw.collisonFlag(3);
							break;
						case '4':
							gw.collisonFlag(4);
							break;
						case '5':
							gw.collisonFlag(5);
							break;
						case '6':
							gw.collisonFlag(6);
							break;
						case '7':
							gw.collisonFlag(7);
							break;
						case '8':
							gw.collisonFlag(8);
							break;
						case '9':
							gw.collisonFlag(9);
							break;
						case 'f':
							gw.collisionFoodStation();
							break;
						case 'g':
							gw.collisionSpider();
							break;
						case 't':
							gw.gameTick();
							break;
						case 'd':
							gw.printCurrent();
							break;
						case 'm':
							gw.printMap();
							break;
						case 'x':
							setKey(sCommand.charAt(0));
							System.out.println("Are you sure to exit game?");
							break;
						case 'y':
							if(getKey() == 'x')
								gw.exit();
							else {
								System.out.println("Invalid input");
							}
							break;
						case 'n':
							if(getKey() == 'x') 
								System.out.println("Game continue");
							else {
								System.out.println("Invalid input");
							}
							break;
						default:
							System.out.println("\nYour Input is invalid.Please enter valid command!!!\n");
							break;
					} //switch
				} //actionPerformed
			} //new ActionListener()
		); //addActionListener
	} //play
}