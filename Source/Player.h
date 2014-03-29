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

private:
	std::shared_ptr<RenderObject> m_graphics;
	std::vector<std::unique_ptr<Missile>> m_listOfMissiles;

	float m_speed;
	float m_xpos;
	float m_ypos;
	float m_fireRate;
	float m_lastFire;

	void MoveToLeft();
	void MoveToRight();
	void FireMissile();
};

#endif PLAYER_H