package com.mycompany.a3;
import com.codename1.charts.util.ColorUtil;
import com.codename1.ui.CheckBox;
import com.codename1.ui.Component;
import com.codename1.ui.Container;
import com.codename1.ui.Form;
import com.codename1.ui.Toolbar;
import com.codename1.ui.layouts.BorderLayout;
import com.codename1.ui.layouts.BoxLayout;
import com.mycompany.a3.commands.*;
import com.codename1.ui.util.UITimer;

/**
 * this class implements the Game method to start the game
 * @author Alexander Alestra
 *
 */
public class Game extends Form implements Runnable
{
    private GameWorld gw;
    private MapView mapView;
    private ScoreView scoreView;
    
    //commands
    private Accelerate accCMD;
    private About aboutCMD;
    private Brake brakeCMD;
    private Exit exitCMD;
    private Help helpCMD;
    private TurnLeft leftCMD;
    private TurnRight rightCMD;
    private SoundCMD soundCMD;
    private Pause pauseCMD;
    private Position positionCMD;
    
    //buttons
    private CustomButton accelerate;
    private CustomButton brake;
    private CustomButton turnLeft;
    private CustomButton turnRight;
    private CustomButton position;
    private CustomButton pause;
    	
    //checkboxes
    private CheckBox checkBox;
    
    //timer and default tick rate
    private UITimer timer;
	private final int GAME_TICK = 20;
    
	/**
     * Given by prof. to set up game
     * then expanded on
     */
    public Game() {
    	//instantiate new GameWorld and 2 views, map and scoreview
        gw = new GameWorld();
        mapView = new MapView(gw);
        scoreView = new ScoreView(gw);
                         
        //setup menu
        initUI();
        
        System.out.println(mapView.getWidth());
        
        //set world size
        gw.setWidth(mapView.getWidth());
        gw.setHeight(mapView.getHeight());
        
        //set tickrate
        gw.setTickrate(GAME_TICK);
        
        //call init method to build world
		gw.init();
		
		//display
		this.show();
		
		//initialize timer
		timer  =  new UITimer(this);
		timer.schedule(GAME_TICK, true, this);
		
		revalidate();
    }
    
    /**
     * Initializes the layout and binds all the buttons to their respected functions
     */
    private void initUI()
    {
        //init layout
        this.setLayout(new BorderLayout());
        
        //configure form
        this.add(BorderLayout.CENTER,mapView);
        this.add(BorderLayout.NORTH, scoreView);
        
        //instantiate commands
        accCMD = new Accelerate(gw);
        aboutCMD = new About();
        brakeCMD = new Brake(gw);
        exitCMD = new Exit();
        helpCMD = new Help();
        leftCMD = new TurnLeft(gw);
        rightCMD = new TurnRight(gw);
        soundCMD = new SoundCMD(gw);
        pauseCMD = new Pause(gw, this);
        positionCMD = new Position(gw);
        
        //add listeners for certain keys
        addKeyListener('a', accCMD);
        addKeyListener('b', brakeCMD);
        addKeyListener('l', leftCMD);
        addKeyListener('r', rightCMD);
        addKeyListener('p', pauseCMD);
        
        //create buttons
        accelerate = new CustomButton(accCMD);
        brake = new CustomButton(brakeCMD);
        turnLeft = new CustomButton(leftCMD);
        turnRight = new CustomButton(rightCMD);
        pause = new CustomButton(pauseCMD);
        position = new CustomButton(positionCMD);
              
        //init sidebar (burger button and help)
    	//create tool bar and add title
    	Toolbar toolbar = new Toolbar();
		setToolbar(toolbar);
		toolbar.setTitle("OnTarget Game");
		
		//checkbox for sound
		checkBox = new CheckBox();
		checkBox.getAllStyles().setBgTransparency(255);
		checkBox.getAllStyles().setBgColor(ColorUtil.LTGRAY);
		checkBox.setCommand(soundCMD);
		toolbar.addComponentToSideMenu(checkBox);
		
		//add acc, about, and exit to side bar
		toolbar.addCommandToSideMenu(aboutCMD);
		toolbar.addCommandToSideMenu(exitCMD);
		
		//initialize help in side bar
		toolbar.addCommandToRightBar(helpCMD);
		
		//init containers
		Container leftContainer = new Container((new BoxLayout(BoxLayout.Y_AXIS)));
		Container rightContainer = new Container((new BoxLayout(BoxLayout.Y_AXIS)));
		Container bottomContainer = new Container((new BoxLayout(BoxLayout.X_AXIS)));
		
		//init left side
		leftContainer.add(accelerate);
		leftContainer.add(turnLeft);

		//init right side
		rightContainer.add(brake);
		rightContainer.add(turnRight);

		//init bottom side
		bottomContainer.add(pause);
		bottomContainer.add(position);
		
		//disable position button and command
		//positionCMD.setEnabled(false);
		position.setEnabled(false);
		
		//shift bottom container
		bottomContainer.getAllStyles().setPadding(Component.LEFT, 850);
		
		//add containers to form
		this.add(BorderLayout.WEST,leftContainer);
		this.add(BorderLayout.EAST, rightContainer);
		this.add(BorderLayout.SOUTH, bottomContainer);
    }

    /**
     * Controls the tick rate when running
     */
	@Override // do gametick
	public void run() {
		gw.gameTick();
		
	}

	/**
	 * If pause is pressed it will do the following
	 */
	public void pressedPause() {
		System.out.println("Pressed play/pause");
		
		if(!gw.isPaused()) {
			//update button text
			pause.setText("Play");
			
			//pause timer
			timer.cancel();
			
			//disable all commands
			disableCommands();
			
			//enable position button and command
			position.setEnabled(true);
			
			//pause sound
			gw.turnOffSound();
			
		}
		else {
			//set button text
			pause.setText("Pause");
			
			//unpause timer
			timer.schedule(GAME_TICK, true, this);
			
			//re-enable commands
			enableCommands();
			
			//disable position button and command
			position.setEnabled(false);
			//position.setEnabled(false);
			
			//play sound
			gw.turnOnSound();
		}
	}
	
	/**
	 * Disables the commands
	 */
	private void disableCommands() {
		System.out.println("Disabling Commands");
		
		 removeKeyListener('a', accCMD);
		 removeKeyListener('b', brakeCMD);
		 removeKeyListener('l', leftCMD);
		 removeKeyListener('r', rightCMD);
		 
		 accelerate.setEnabled(false);
		 brake.setEnabled(false);
		 turnLeft.setEnabled(false);
		 turnRight.setEnabled(false);
		 checkBox.setEnabled(false);
	}
	
	/**
	 * Enables the commands for use
	 */
	private void enableCommands() {
		addKeyListener('a', accCMD);
		addKeyListener('b', brakeCMD);
		addKeyListener('l', leftCMD);
		addKeyListener('r', rightCMD);
        
		accelerate.setEnabled(true);
		brake.setEnabled(true);
		turnLeft.setEnabled(true);
		turnRight.setEnabled(true);
		checkBox.setEnabled(true);
	}
}