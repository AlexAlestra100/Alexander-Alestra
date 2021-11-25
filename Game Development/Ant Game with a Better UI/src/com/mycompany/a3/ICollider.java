package com.mycompany.a3;

/**
 * Collider
 * @author Alexander Alestra
 *
 */
public interface ICollider {
	public boolean collidesWith(GameObject otherObject);
	public void handleCollision(GameObject otherObject);
}
