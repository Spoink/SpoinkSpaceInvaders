#ifndef GUI_H
#define GUI_H

#include "Global.h"

#include "TextManager.h"
#include "ImageLoader.h"

class Gui
{
	public:
		enum Color
		{
			Black,
			White
		};
		
		Gui();
		~Gui();

		static Gui* Instance;
		static std::shared_ptr<RenderObject> Label(std::string text, int xpos, int ypos, Color color);
		static std::shared_ptr<RenderObject> Sprite(ImageLoader::Image image, int xpos, int ypos);

		static void RemoveGuiObject(std::shared_ptr<RenderObject> guiObj);

	private:
		std::unique_ptr<TextManager> m_textManager;

		static SDL_Color GetColor(Color color);
};

#endif GUI_H