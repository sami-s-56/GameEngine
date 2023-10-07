#include "Engine.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "RenderSystem.h"
#include "AssetManager.h" 
#include "json.hpp"
#include <fstream>

Engine::Engine()
{
	std::cout << "Engine Constructor" << std::endl;

	sceneMgr = new SceneManager();
	assetMgr = new AssetManager();
	renderSys = new RenderSystem();
	inputMgr = new InputManager();

	Initialize();
}

Engine::~Engine()
{
	Destroy();

	delete(sceneMgr);
	delete(renderSys);
	delete(assetMgr);
	delete(inputMgr);

	std::cout << "Engine Destructor" << std::endl;
}

void Engine::Initialize()
{
	std::cout << "Engine Initialize()" << std::endl;

	std::ifstream inputStream("GameSettings.json");
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON document = json::JSON::Load(str);

	if (document.hasKey("Engine"))
	{
		std::cout << "Engine Found "  << "\n";
		json::JSON subObject = document["Engine"];
		if (subObject.hasKey("DefaultFile"))
		{
			std::cout << "SubItem: " << subObject["DefaultFile"].ToString() << "\n";
		}
	}

}

void Engine::Destroy()
{
	std::cout << "Engine Destroy()" << std::endl;
}

void Engine::GameLoop()
{
	std::cout << "Engine Loop()" << std::endl;
}

void Engine::Load()
{
	std::cout << "Engine Load()" << std::endl;
}
