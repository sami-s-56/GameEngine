#include "RenderSystem.h"
#include "json.hpp"
#include <fstream>

RenderSystem::RenderSystem()
{
	Initialize();
}

RenderSystem::~RenderSystem()
{
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
	}
}

void RenderSystem::Destroy()
{
}

void RenderSystem::Update()
{
}

void RenderSystem::Load()
{
}
