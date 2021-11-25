package com.mycompany.a3;

/**
 * Interface to add object and get one if need be
 * @author Alexander Alestra
 *
 */
public interface ICollection {
	public void add(GameObject obj);
	Iterator getIterator();
}
