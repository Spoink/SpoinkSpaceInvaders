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

	private: 
		SDL_Surface* m_image;
		std::shared_ptr<SDL_Rect> m_position;
		bool m_destroy;
};

#endif RENDEROBJECT_H