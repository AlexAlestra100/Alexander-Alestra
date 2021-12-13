package com.mycompany.a4;

/**
 * Collider
 * @author Alexander Alestra
 *
 */
public interface ICollider {
	public boolean collidesWith(GameObject otherObject);
	public void handleCollision(GameObject otherObject);
}
