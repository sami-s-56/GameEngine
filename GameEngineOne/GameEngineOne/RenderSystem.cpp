#include "RenderSystem.h"
#include "json.hpp"
#include "SDL.h"
#include "SDL_image.h"
#include <fstream>

RenderSystem::RenderSystem()
{
	std::cout << "Render System Constructor" << std::endl;
	Initialize();
}

RenderSystem::~RenderSystem()
{
	std::cout << "Render System Destructor" << std::endl;
}

void RenderSystem::Initialize()
{
	std::ifstream inputStream("GameSettings.json");
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON document = json::JSON::Load(str);

	if (document.hasKey("RenderSystem"))
	{
		std::cout << "Render System Found " << "\n";
		json::JSON subObject = document["RenderSystem"];
		if (subObject.hasKey("Name"))
		{
			name = subObject["Name"].ToString();
			std::cout << "Name: " << name << "\n";
		}
		if (subObject.hasKey("width"))
		{
			width = subObject["width"].ToInt();
			std::cout << "Width: " << width << "\n";
		}
		if (subObject.hasKey("height"))
		{
			height = subObject["height"].ToInt();
			std::cout << "Height: " << height << "\n";
		}
		if (subObject.hasKey("fullscreen"))
		{
			fullScreen = subObject["Name"].ToBool();
			std::cout << "FullScreen: " << fullScreen << "\n";
		}
	}

	window = SDL_CreateWindow("SDL Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}

void RenderSystem::Destroy()
{
	std::cout << "Render System Destroy" << std::endl;
}

void RenderSystem::Update()
{
}

void RenderSystem::Load()
{
	
}
