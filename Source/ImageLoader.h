#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>

using namespace std;

class ImageLoader
{
    public:
        enum Image
		{
			MenuSelector,
			LetterSelector,
			Player,
			BigShip,
			EnemyOne,
			EnemyTwo,
			EnemyThree,
			EnemyFour
		};
		
		static SDL_PixelFormat* PixelFormat;
		
		static SDL_Surface* GetImage(Image image);

		void Initialize();
		void Shutdown();

	private:
		static std::vector<SDL_Surface*> m_images;

		static SDL_Surface* LoadImage(string path);
};