#include "TextManager.h"

SDL_PixelFormat* TextManager::PixelFormat = NULL;

TextManager::TextManager()
{ 
	TTF_Init();

	m_mainFont = TTF_OpenFont("Assets/Fonts/Arial.ttf", 24); 
    if( m_mainFont == NULL )
    { printf( "Failed to load font! SDL_ttf Error: %s\n", TTF_GetError() ); }
}

TextManager::~TextManager()
{
	TTF_CloseFont(m_mainFont);
	m_mainFont = NULL;

	TTF_Quit();
}

std::shared_ptr<RenderObject>TextManager::GetRenderedText(std::string text, int xpos, int ypos, SDL_Color color)
{
	SDL_Surface* tempText = TTF_RenderText_Solid(m_mainFont, text.c_str(), color);
	
	if(tempText == NULL)
    { return NULL; }

	SDL_Surface* finalText = SDL_ConvertSurface(tempText, PixelFormat, NULL);
	SDL_FreeSurface(tempText);

	std::shared_ptr<RenderObject> renderObj = std::shared_ptr<RenderObject>(new RenderObject(finalText, xpos, ypos));
	return renderObj;
}