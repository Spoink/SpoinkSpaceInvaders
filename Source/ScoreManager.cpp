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
{ 
	m_currentScore += score; 
	if(m_currentScore < 0)
	{ m_currentScore = 0; }
}

int ScoreManager::GetScore()
{ return m_currentScore; }

void ScoreManager::SetGameOver()
{ m_gameOver = true; }

bool ScoreManager::IsGameOver()
{ return m_gameOver; }

void ScoreManager::Cleanup()
{
	m_currentScore = 0;
	m_gameOver = false;
}