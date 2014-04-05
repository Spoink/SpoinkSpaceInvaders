#include "MainMenu.h"

#include "Events.h"
#include "SoundManager.h"
#include "Highscore.h"

MainMenu::MainMenu() {}

MainMenu::~MainMenu() {}

void MainMenu::Initialize()
{
	m_startGame = false;
	m_exitGame = false;
	m_menuOption = 0;
	
	m_header = Gui::Label("Faust Invaders", 320, 20, Gui::Color::White);
	m_menuSelector = Gui::Sprite(ImageLoader::Image::MenuSelector, 320, 145);
	m_menuOptionOne = Gui::Label("Play", 380, 150, Gui::Color::White);
	m_menuOptionTwo = Gui::Label("Exit", 380, 200, Gui::Color::White);
	m_subHeader = Gui::Label("Press space to select", 300, 400, Gui::Color::White);

	GenerateHighscore();
}

void MainMenu::Update()
{
	if(Events::Instance->IsKeyDown(KeyCode::Key_Space))
	{
		if(m_menuOption == 0)
		{ m_startGame = true; }
		else
		{ m_exitGame = true; }

		SoundManager::Instance->PlayClip(SoundManager::Sounds::ButtonClick, false);
	}
	else if(Events::Instance->IsKeyDown(KeyCode::Key_Up))
	{ ChooseNextMenuOption(); }
	else if(Events::Instance->IsKeyDown(KeyCode::Key_Down))
	{ ChooseNextMenuOption(); }
	else if(Events::Instance->IsKeyDown(KeyCode::Key_Escape))
	{ m_exitGame = true; }
}

void MainMenu::Shutdown()
{
	Gui::RemoveGuiObject(m_header);
	Gui::RemoveGuiObject(m_subHeader);
	Gui::RemoveGuiObject(m_menuOptionOne);
	Gui::RemoveGuiObject(m_menuOptionTwo);
	Gui::RemoveGuiObject(m_menuSelector);
	Gui::RemoveGuiObject(m_highscoreLabel);

	for(unsigned int i = 0; i < m_highscoreObjects.size(); i++)
	{ Gui::RemoveGuiObject(m_highscoreObjects[i]); }
}

bool MainMenu::ShouldStart()
{ return m_startGame; }

bool MainMenu::ShouldExit()
{ return m_exitGame; }

void MainMenu::GenerateHighscore()
{
	std::vector<HighscoreData> highscore = Highscore::Instance->GetHighscore();	
	m_highscoreObjects.clear();

	m_highscoreLabel = Gui::Label("Highscore", 40, 40, Gui::Color::White);
	for(unsigned int i = 0; i < highscore.size(); i++)
	{ 
		HighscoreData data = highscore[i];
		std::shared_ptr<RenderObject> obj = Gui::Label(data.Name + ": " + std::to_string(data.Score), 40, 80 + (i * 30), Gui::Color::White);
		m_highscoreObjects.push_back(obj);
	}
}

void MainMenu::ChooseNextMenuOption()
{ 
	m_menuOption++;
	if(m_menuOption > 1)
	{ m_menuOption = 0; }

	int xpos = 0;
	int ypos = 0;
	if(m_menuOption == 0)
	{ 
		xpos = m_menuOptionOne->GetRect()->x;
		ypos = m_menuOptionOne->GetRect()->y;
	}
	else if(m_menuOption == 1)
	{ 
		xpos = m_menuOptionTwo->GetRect()->x;
		ypos = m_menuOptionTwo->GetRect()->y;
	}

	m_menuSelector->SetPosition(xpos - 60, ypos - 5); 
	SoundManager::Instance->PlayClip(SoundManager::Sounds::ButtonClick, false);
}
