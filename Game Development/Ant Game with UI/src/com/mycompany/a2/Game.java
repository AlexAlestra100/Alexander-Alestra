package com.mycompany.a2;
import com.codename1.charts.util.ColorUtil;
import com.codename1.ui.CheckBox;
import com.codename1.ui.Component;
import com.codename1.ui.Container;
import com.codename1.ui.Form;
import com.codename1.ui.Toolbar;
import com.codename1.ui.layouts.BorderLayout;
import com.codename1.ui.layouts.BoxLayout;
import com.mycompany.a2.commands.*;

/**
 * this class implements the  Game method to start the game
 * @author Alexander Alestra
 *
 */
public class Game extends Form{
	private GameWorld gw;
    private MapView mapView;
    private ScoreView scoreView;

    /**
     * Given by prof. to set up game
     */
    public Game()
    {
        gw = new GameWorld();
        mapView = new MapView(gw);
        scoreView = new ScoreView(gw);
        initUI();
        gw.setWidth(mapView.getWidth());
        gw.setHeight(mapView.getHeight());
		gw.init();
		this.show();
    }
    
    /**
     * Initializes the layout and binds all the buttons to their respected functions
     */
    private void initUI()
    {
        //init layout
        this.setLayout(new BorderLayout());
        
        //configure form
        this.add(BorderLayout.NORTH, scoreView);
        this.add(BorderLayout.CENTER, mapView);
        
        //instantiate commands
        Accelerate accelCMD = new Accelerate(gw);
        About aboutCMD = new About();
        Brake brakeCMD = new Brake(gw);
        CollisionSpider spiderCollisionCMD = new CollisionSpider(gw);
        Exit exitCMD = new Exit();
        CollisionFoodStation findFoodCMD = new CollisionFoodStation(gw);
        CollisionFlag findFlagCMD = new CollisionFlag(gw);
        Help helpCMD = new Help();
        TurnLeft leftCMD = new TurnLeft(gw);
        TurnRight rightCMD = new TurnRight(gw);
        Sound soundCMD = new Sound(gw);
        GameTick tickCMD = new GameTick(gw);
        
        //add listeners for certain keys
        addKeyListener('a', accelCMD);
        addKeyListener('b', brakeCMD);
        addKeyListener('l', leftCMD);
        addKeyListener('r', rightCMD);
        addKeyListener('f', findFoodCMD);
        addKeyListener('g', spiderCollisionCMD);
        addKeyListener('t', tickCMD);
        
        //create buttons
        CustomButton accelerate = new CustomButton(accelCMD);
        CustomButton brake = new CustomButton(brakeCMD);
        CustomButton turnLeft = new CustomButton(leftCMD);
        CustomButton turnRight = new CustomButton(rightCMD);
        CustomButton collisionFlag = new CustomButton(findFlagCMD);
        CustomButton collisionFoodStation = new CustomButton(findFoodCMD);
        CustomButton collisionSpider = new CustomButton(spiderCollisionCMD);
        CustomButton gameTick = new CustomButton(tickCMD);
        
        //init sidebar (burger button and help)
    	//create tool bar and add title
    	Toolbar toolbar = new Toolbar();
		setToolbar(toolbar);
		toolbar.setTitle("OnTarget Game");
		
		//checkbox for sound
		CheckBox checkBox = new CheckBox();
		checkBox.getAllStyles().setBgTransparency(255);
		checkBox.getAllStyles().setBgColor(ColorUtil.LTGRAY);
		checkBox.setCommand(soundCMD);
		toolbar.addComponentToSideMenu(checkBox);
		
		//add about and exit to side bar
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
		bottomContainer.add(collisionFlag);
		bottomContainer.add(collisionSpider);
		bottomContainer.add(collisionFoodStation);
		bottomContainer.add(gameTick);
		
		//shift bottom container
		bottomContainer.getAllStyles().setPadding(Component.LEFT,500);
		
		//add containers to form
		this.add(BorderLayout.WEST,leftContainer);
		this.add(BorderLayout.EAST, rightContainer);
		this.add(BorderLayout.SOUTH, bottomContainer);
    }
}