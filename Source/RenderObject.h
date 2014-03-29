#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include "Global.h"

class RenderObject
{
	public:
		RenderObject(SDL_Surface* image, int xpos, int ypos);
		~RenderObject();

		SDL_Surface* GetImage();
		std::shared_ptr<SDL_Rect> GetRect();

		void SetPosition(int xpos, int ypos);
		void SetDestroy();
		bool ShouldDestroy();
		bool IsVisible();
		void ToggleVisibility(bool isVisible);

	private: 
		SDL_Surface* m_image;
		std::shared_ptr<SDL_Rect> m_position;
		bool m_destroy;
		bool m_isVisible;
};

#endif RENDEROBJECT_H