#include "GameOver.h"

#include "Events.h"
#include "Highscore.h"

GameOver::GameOver() 
{ m_name = "AAA"; }

GameOver::~GameOver() {}

void GameOver::Initialize(int score)
{
	m_score = score;
	int place = Highscore::Instance->GetHighscorePlace(m_score);

	m_header = Gui::Label("Game Over!", 330, 20, Gui::Color::White);
	m_letterSelector = Gui::Sprite(ImageLoader::Image::LetterSelector, 372, 82);
	PrintPlayerName();
	m_scoreLabel = Gui::Label("Score: " + std::to_string(m_score), 300, 120, Gui::Color::White);
	
	PrintHighscorePlace(place);
	m_subHeader = Gui::Label("Press space to continue", 280, 300, Gui::Color::White);

	m_namePos = 0;
	m_isDone = false;
}

void GameOver::Update()
{
	if(Events::Instance->IsKeyDown(KeyCode::Key_Space))
	{ m_isDone = true; }
	else if(Events::Instance->IsKeyDown(KeyCode::Key_Up))
	{ ShiftNameUpwards(); }
	else if(Events::Instance->IsKeyDown(KeyCode::Key_Down))
	{ ShiftNameDownwards(); }
	else if(Events::Instance->IsKeyDown(KeyCode::Key_Left))
	{ ShiftNameLeft(); }
	else if(Events::Instance->IsKeyDown(KeyCode::Key_Right))
	{ ShiftNameRight(); }
}

void GameOver::Shutdown()
{
	Highscore::Instance->AddToHighscore(m_name, m_score);

	Gui::RemoveGuiObject(m_header);
	Gui::RemoveGuiObject(m_nameLabel);
	Gui::RemoveGuiObject(m_scoreLabel);
	Gui::RemoveGuiObject(m_letterSelector);
	Gui::RemoveGuiObject(m_highscoreLabel);
	Gui::RemoveGuiObject(m_subHeader);
}

bool GameOver::IsDone()
{ return m_isDone; }

void GameOver::PrintHighscorePlace(int place)
{
	if(place == -1)
	{ return; }

	std::string placeEnding = "th";
	if(place == 1)
	{ placeEnding = "st"; }
	else if(place == 2)
	{ placeEnding = "nd"; }
	else if(place == 3)
	{ placeEnding = "rd"; }

	m_highscoreLabel = Gui::Label("Highscore Place: " + std::to_string(place) + placeEnding, 300, 160, Gui::Color::White); 	
}

void GameOver::PrintPlayerName()
{ m_nameLabel = Gui::Label("Name: " + m_name, 300, 80, Gui::Color::White); }

void GameOver::ShiftNameUpwards()
{
	m_name[m_namePos]--;
	
	if(m_name[m_namePos] < 65)
	{ m_name[m_namePos] = 'Z'; }

	Gui::RemoveGuiObject(m_nameLabel);
	PrintPlayerName();
}

void GameOver::ShiftNameDownwards()
{
	m_name[m_namePos]++;
	if(m_name[m_namePos] > 90)
	{ m_name[m_namePos] = 'A'; }

	Gui::RemoveGuiObject(m_nameLabel);
	PrintPlayerName();
}

void GameOver::ShiftNameLeft()
{
	m_namePos--;
	if(m_namePos < 0)
	{ m_namePos = 2; }

	m_letterSelector->SetPosition(372 + (m_namePos * 15), 82);
}

void GameOver::ShiftNameRight()
{
	m_namePos++;
	if(m_namePos > 2)
	{ m_namePos = 0; }

	m_letterSelector->SetPosition(372 + (m_namePos * 15), 82);
}