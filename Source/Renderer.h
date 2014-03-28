#ifndef RENDERER_H
#define RENDERER_H

#include "Global.h"
#include "RenderObject.h"

class Renderer
{
    public:
        void Initialize();
        void Update();
        void Shutdown();

		static void AddToQueue(std::shared_ptr<RenderObject> image);
		static void CleanUpQueue();

    private:
        SDL_Window* m_window;
        SDL_Surface* m_mainSurface;
		unsigned int m_backgroundColor;

		static std::vector<std::shared_ptr<RenderObject>> renderQueue;
};

#endif RENDERER_H