#pragma once

#ifndef _RENDER_
#define _RENDER_

#include<string>


class RenderSystem
{
private:
	std::string name;
	int width, height;
	bool fullScreen;

	class SDL_Window* window = nullptr;
	class SDL_Renderer* renderer = nullptr;

public:
	RenderSystem();

	~RenderSystem();

	void Initialize();

	void Destroy();

	void Update();

	void Load();
};

#endif // !_RENDER_
