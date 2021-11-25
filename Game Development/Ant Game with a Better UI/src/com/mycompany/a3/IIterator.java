package com.mycompany.a3;

public interface IIterator {
	
	//returns next object
	public GameObject next();
	
	//returns true or false
	public boolean hasNext();
	
	//returns current item
	public GameObject current();
		
	//removes an object if we find match
	public void remove(GameObject o);
	
}
