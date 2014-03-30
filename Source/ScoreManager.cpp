#include "Settings.h"
#include "SoundManager.h"

#include "ScoreManager.h"

ScoreManager* ScoreManager::Instance;

void ScoreManager::Initialize()
{
	m_currentScore = 0;
	m_gameOver = false;
	Instance = this;
}

void ScoreManager::Shutdown() {}

void ScoreManager::AddScore(int score)
{ m_currentScore += score; }

int ScoreManager::GetScore()
{ return m_currentScore; }

bool ScoreManager::IsGameOver()
{ return m_gameOver; }

void ScoreManager::Cleanup()
{
	m_currentScore = 0;
	m_gameOver = false;
}