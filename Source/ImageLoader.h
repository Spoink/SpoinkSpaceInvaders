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
			PlayerMissile,
			BigShip,
			EnemyOne,
			EnemyTwo,
			EnemyThree,
			EnemyFour,
			CoverOne,
			CoverTwo,
			CoverThree
		};
		
		static SDL_PixelFormat* PixelFormat;
		
		static SDL_Surface* GetImage(Image image);

		void Initialize();
		void Shutdown();

	private:
		static std::vector<SDL_Surface*> m_images;

		static SDL_Surface* LoadImage(string path);
};
