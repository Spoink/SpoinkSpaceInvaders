#include "EnemySquad.h"
#include "Gui.h"

EnemySquad::EnemySquad() 
{
	SpawnEnemies();
}

EnemySquad::~EnemySquad() {}

void EnemySquad::Update()
{
	CleanupList();

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
		Enemy::EnemyType enemyType = Enemy::EnemyType::EnemyType_One;

		if(i < 11)
		{ 
			graphics = Gui::Sprite(ImageLoader::EnemyOne, xpos, ypos); 
			enemyType = Enemy::EnemyType::EnemyType_One;
		}
		else if(i < 33)
		{ 
			graphics = Gui::Sprite(ImageLoader::EnemyTwo, xpos, ypos); 
			enemyType = Enemy::EnemyType::EnemyType_Two;
		}
		else if(i < 44)
		{ 
			graphics = Gui::Sprite(ImageLoader::EnemyThree, xpos, ypos); 
			enemyType = Enemy::EnemyType::EnemyType_Three;
		}
		else 
		{ 
			graphics = Gui::Sprite(ImageLoader::EnemyFour, xpos, ypos); 
			enemyType = Enemy::EnemyType::EnemyType_Four;
		}

		m_listOfEnemies.push_back(std::unique_ptr<Enemy>(new Enemy(enemyType, graphics)));
	}	
}

void EnemySquad::CleanupList()
{
	for(int i = m_listOfEnemies.size() - 1; i > -1; i--)
	{ 
		if(!m_listOfEnemies[i]->IsAlive())
		{ m_listOfEnemies.erase(m_listOfEnemies.begin() + i); }
	}
}