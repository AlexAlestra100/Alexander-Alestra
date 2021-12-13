package com.mycompany.a4;

/**
 * To iterate, retrieve, check, and remove gameobject
 * @author Alexander Alestra
 *
 */
public interface Iterator {
	public GameObject next();
	public boolean hasNext();
	public GameObject current();
	public void remove(GameObject o);
}
