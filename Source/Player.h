#ifndef PLAYER_H
#define PLAYER_H

#include "Global.h"
#include "Gui.h"

class Player
{
public:
	Player();
	~Player();

	void Update();

private:
	std::shared_ptr<RenderObject> m_graphics;
	float m_speed;
	float m_xpos;
	float m_ypos;

	void MoveToLeft();
	void MoveToRight();
};

#endif PLAYER_H