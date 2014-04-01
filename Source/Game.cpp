#include "Game.h"

#include "Settings.h"
#include "Gui.h"
#include "Events.h"
#include "SoundManager.h"
#include "Highscore.h"

#pragma region Base

void Game::Initialize()
{
	m_scoreManager = std::unique_ptr<ScoreManager>(new ScoreManager());
	m_scoreManager->Initialize();

	m_player = std::unique_ptr<Player>(new Player());
	m_squad = std::unique_ptr<EnemySquad>(new EnemySquad());
	m_collisionManager = std::unique_ptr<CollisionManager>(new CollisionManager());
	m_specialEnemy = std::unique_ptr<SpecialEnemy>(new SpecialEnemy());

	for(int i = 0; i < 4; i++)
	{ m_listOfCovers.push_back(std::unique_ptr<Cover>(new Cover(64 + (i*200), 470))); }

	m_scoreText = std::shared_ptr<RenderObject>(Gui::Label("Score: ", 40, 40, Gui::Color::White));
	m_scoreLabel = std::shared_ptr<RenderObject>(Gui::Label("0", 120, 40, Gui::Color::White));

	m_livesLabel = std::shared_ptr<RenderObject>(Gui::Label("Lives: ", 550, 40, Gui::Color::White));
	m_livesSprite = std::shared_ptr<RenderObject>(Gui::Sprite(ImageLoader::Player, 620, 30));
	m_livesNumberLabel = std::shared_ptr<RenderObject>(Gui::Label("x3", 680, 40, Gui::Color::White));

	m_oldScore = 0;
	m_oldLives = m_player->GetLives();
	m_gotoMenu = false;

	SoundManager::Instance->PlayMusic(SoundManager::Music::MainLoop, true);
}

void Game::Update()
{
	if(m_scoreManager->IsGameOver())
	{ return; }

	if(Events::Instance->IsKeyDown(KeyCode::Key_Escape))
	{ 
		m_gotoMenu = true; 
		SoundManager::Instance->PlayClip(SoundManager::Sounds::ButtonClick, false);
	}

	m_player->Update();
	m_squad->Update();
	m_specialEnemy->Update();

	for(unsigned int i = 0; i < m_listOfCovers.size(); i++)
	{ m_listOfCovers[i]->Update(); }

	m_collisionManager->Update();
	UpdateScore();
	UpdateLives();
}

void Game::Shutdown()
{
	Gui::RemoveGuiObject(m_scoreLabel);
	Gui::RemoveGuiObject(m_scoreText);
	Gui::RemoveGuiObject(m_livesLabel);
	Gui::RemoveGuiObject(m_livesSprite);
	Gui::RemoveGuiObject(m_livesNumberLabel);

	m_scoreManager->Cleanup();
	m_scoreManager->Shutdown(); 

	SoundManager::Instance->StopMusic();
	m_player.reset();
	m_squad.reset();
	m_collisionManager.reset();
	m_specialEnemy.reset();
	m_listOfCovers.clear();
}

bool Game::GotoMenu()
{ return m_gotoMenu; }

#pragma endregion

#pragma region Privates

void Game::UpdateScore()
{
	if(m_oldScore == m_scoreManager->GetScore())
	{ return; }

	Gui::RemoveGuiObject(m_scoreLabel);
	m_oldScore = m_scoreManager->GetScore();
	m_scoreLabel = Gui::Label("" + std::to_string(m_oldScore), 120, 40, Gui::Color::White);
}

void Game::UpdateLives()
{
	if(m_oldLives == m_player->GetLives())
	{ return; }

	Gui::RemoveGuiObject(m_livesNumberLabel);
	m_livesNumberLabel = std::shared_ptr<RenderObject>(Gui::Label("x" + std::to_string(m_player->GetLives()), 680, 40, Gui::Color::White));
	m_oldLives = m_player->GetLives();
}

#pragma endregion