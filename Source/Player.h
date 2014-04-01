#ifndef PLAYER_H
#define PLAYER_H

#include "Global.h"
#include "Gui.h"

#include "Missile.h"

class Player
{
public:
	Player();
	~Player();

	void Update();
	int GetLives();

private:
	std::shared_ptr<RenderObject> m_graphics;
	std::shared_ptr<CollisionObject> m_collisionObject;
	std::vector<std::unique_ptr<Missile>> m_listOfMissiles;

	int m_startX;
	int m_startY;
	float m_speed;
	float m_xpos;
	float m_ypos;
	float m_fireRate;
	float m_lastFire;
	int m_lives;

	void MoveToLeft();
	void MoveToRight();
	void SetPosition(float xpos, float ypos);
	void FireMissile();
	void LoseLife();
};

#endif PLAYER_H