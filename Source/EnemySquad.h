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
	int m_startEnemyCount;
	float m_nextMissile;

	void SpawnEnemies();
	void CleanupList();
	void MissileAction();
};

#endif ENEMYSQUAD_H