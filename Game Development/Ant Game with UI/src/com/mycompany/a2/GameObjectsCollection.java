package com.mycompany.a2;
import java.util.Vector;

/**
 * This will collect all the game objects and insert them into a vector
 * @author Alexander Alestra
 *
 */
public class GameObjectsCollection implements ICollection{
	private Vector<GameObject> gameObjects = new Vector<GameObject>();
	
	/**
	 * Creates new vector type gameobjects
	 */
	public GameObjectsCollection() {
		gameObjects = new Vector<GameObject>();
	}
	
	/**
	 * adds the object into the vector
	 */
	public void add(GameObject obj) { 
		gameObjects.add(obj); 
	}
	
	/**
	 * Will returnt the new GameObjectIterator
	 */
	public Iterator getIterator() {
		return new GameObjectIterator();
	}
	
	/**
	 *  Iterates through gameobject
	 * @author Alexander Alestra
	 *
	 */
	private class GameObjectIterator implements Iterator{
		private int i = -1;
		
		/**
		 * Will go to the next object
		 */
		public GameObject next() {
			return gameObjects.get(++i);
		}
		
		/**
		 * Will see if there is a next
		 */
		public boolean hasNext() {
			if((i == gameObjects.size() - 1) || gameObjects.size() <= 0)
				return false;
			else
				return true;
		}
		
		/**
		 * Will return the current object
		 */
		public GameObject current() {
			return gameObjects.get(i);
		}
		
		/**
		 * Will remove gameobject
		 */
		public void remove(GameObject obj) {
			gameObjects.remove(obj);
		}
	}
}
