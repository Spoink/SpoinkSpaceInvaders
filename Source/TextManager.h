#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H

#include "Global.h"
#include "RenderObject.h"

class TextManager
{
	public:
		TextManager();
		~TextManager();

		static SDL_PixelFormat* PixelFormat;

		std::shared_ptr<RenderObject> GetRenderedText(std::string text, int xpos, int ypos, SDL_Color color);

	private:
		TTF_Font* m_mainFont;
};

#endif TEXTMANAGER_H