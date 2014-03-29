#ifndef ENEMYSQUAD_H
#define ENEMYSQUAD_H

#include "Global.h"
#include "Enemy.h"

class EnemySquad
{
public:
	EnemySquad();
	~EnemySquad();

	void Update();

private:
	std::vector<std::unique_ptr<Enemy>> m_listOfEnemies;

	void SpawnEnemies();
};

#endif ENEMYSQUAD_H