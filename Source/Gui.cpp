#include "Gui.h"

#include "Renderer.h"
#include "ImageLoader.h"

Gui* Gui::Instance = NULL;

Gui::Gui() 
{ 
	Instance = this;
	m_textManager = std::unique_ptr<TextManager>(new TextManager());
}

Gui::~Gui() 
{ m_textManager = NULL; }

std::shared_ptr<RenderObject> Gui::Label(std::string text, int xpos, int ypos, Color color)
{ 
	SDL_Color sdlColor = GetColor(color);
	std::shared_ptr<RenderObject> label = Instance->m_textManager->GetRenderedText(text, xpos, ypos, sdlColor); 
	Renderer::AddToQueue(label);
	return label;
}

std::shared_ptr<RenderObject> Gui::Sprite(ImageLoader::Image image, int xpos, int ypos)
{
	SDL_Surface* imageObj = ImageLoader::GetImage(image);
	std::shared_ptr<RenderObject> sprite = std::shared_ptr<RenderObject>(new RenderObject(imageObj, xpos, ypos));
	Renderer::AddToQueue(sprite);
	return sprite;
}

void Gui::RemoveGuiObject(std::shared_ptr<RenderObject> guiObj)
{ 
	if(guiObj == NULL)
	{ return; }

	guiObj->SetDestroy();
	Renderer::CleanUpQueue();
}

SDL_Color Gui::GetColor(Color color)
{
	if(color == Black)
	{ 
		SDL_Color sdlColor = { 0, 0, 0 };
		return sdlColor;
	}
	else if(color == White)
	{
		SDL_Color sdlColor = { 255, 255, 255 };
		return sdlColor;
	}

	SDL_Color sdlColor = { 0,0,0 };
	return sdlColor;
}