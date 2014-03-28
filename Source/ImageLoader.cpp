#include "ImageLoader.h"

SDL_PixelFormat* ImageLoader::PixelFormat = NULL;
std::vector<SDL_Surface*>  ImageLoader::m_images;

SDL_Surface* ImageLoader::GetImage(Image image)
{ return m_images[image]; }

void ImageLoader::Initialize()
{
	IMG_Init(IMG_INIT_PNG);

	m_images = std::vector<SDL_Surface*>();
	m_images.push_back(LoadImage("Assets/Images/MenuSelector.png"));
	m_images.push_back(LoadImage("Assets/Images/LetterSelector.png"));
	m_images.push_back(LoadImage("Assets/Images/Player.png"));
	m_images.push_back(LoadImage("Assets/Images/BigShip.png"));
	m_images.push_back(LoadImage("Assets/Images/Enemy_0.png"));
	m_images.push_back(LoadImage("Assets/Images/Enemy_1.png"));
	m_images.push_back(LoadImage("Assets/Images/Enemy_2.png"));
	m_images.push_back(LoadImage("Assets/Images/Enemy_3.png"));
}

void ImageLoader::Shutdown()
{
	for(unsigned int i = 0; i < m_images.size(); i++)
	{ SDL_FreeSurface(m_images[i]); }
	IMG_Quit(); 
}

SDL_Surface* ImageLoader::LoadImage(string path)
{
    SDL_Surface* finalSurface = NULL;
    SDL_Surface* tempSurface = IMG_Load(path.c_str());
    if(tempSurface == NULL)
    { return NULL; }
	
	finalSurface = SDL_ConvertSurface(tempSurface, tempSurface->format, NULL);
    SDL_FreeSurface(tempSurface);

    return finalSurface;
}
