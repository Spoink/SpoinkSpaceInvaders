#include "EnemySquad.h"
#include "Gui.h"

EnemySquad::EnemySquad() 
{
	SpawnEnemies();
}

EnemySquad::~EnemySquad() {}

void EnemySquad::Update()
{
	bool hasHitWall = false;
	for(unsigned int i = 0; i < m_listOfEnemies.size(); i++)
	{ 
		m_listOfEnemies[i]->Update();
		if(m_listOfEnemies[i]->HasHitBounderies())
		{ hasHitWall = true; }
	}

	if(hasHitWall)
	{
		int moveDir = m_listOfEnemies[0]->GetMoveDir() == 1 ? -1 : 1;
		for(unsigned int i = 0; i < m_listOfEnemies.size(); i++)
		{ m_listOfEnemies[i]->SetMoveDir(moveDir); }	
	}
}

void EnemySquad::SpawnEnemies()
{
	unsigned int enemyCount = 55;
	int xOffset = 100;
	int yOffset = 100;

	for(unsigned int i = 0; i < enemyCount; i++)
	{ 
		int xpos = ((i % 11) * 55) + xOffset;
		int ypos = ((i / 11) * 55) + yOffset;
		std::shared_ptr<RenderObject> graphics;
		if(i < 11)
		{ graphics = Gui::Sprite(ImageLoader::EnemyOne, xpos, ypos); }
		else if(i < 33)
		{ graphics = Gui::Sprite(ImageLoader::EnemyTwo, xpos, ypos); }
		else if(i < 44)
		{ graphics = Gui::Sprite(ImageLoader::EnemyThree, xpos, ypos); }
		else 
		{ graphics = Gui::Sprite(ImageLoader::EnemyFour, xpos, ypos); }

		m_listOfEnemies.push_back(std::unique_ptr<Enemy>(new Enemy(graphics)));
	}	
}