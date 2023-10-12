#include "Engine.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "RenderSystem.h"
#include "AssetManager.h" 
#include "json.hpp"
#include <fstream>

Engine* Engine::engine = nullptr;

Engine::Engine()
{
	std::cout << "Engine Constructor" << std::endl;

	if (engine == nullptr)
	{
		Engine::engine = this;
	}
	else 
	{
		delete(this);
	}

	Initialize();
	
	sceneMgr = new SceneManager();
	assetMgr = new AssetManager();
	renderSys = new RenderSystem();
	inputMgr = new InputManager();


}

Engine::~Engine()
{
	
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

	std::string s;

	if (document.hasKey("Engine"))
	{
		std::cout << "Engine Found "  << "\n";
		json::JSON subObject = document["Engine"];
		if (subObject.hasKey("DefaultFile"))
		{
			s = subObject["DefaultFile"].ToString();
			GameFile = s;
			std::cout << "SubItem: " << subObject["DefaultFile"].ToString() << "\n";
		}
	}

}

void Engine::Destroy()
{
	std::cout << "Engine Destroy()" << std::endl;

	sceneMgr->Destroy();
	renderSys->Destroy();
	assetMgr->Destroy();
	inputMgr->Destroy();
}

void Engine::GameLoop()
{
	std::cout << "Engine Loop()" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		sceneMgr->Update();
		assetMgr->Update();
		renderSys->Update();
		inputMgr->Update();
	}

}

void Engine::Load()
{
	std::cout << "Engine Load()" << std::endl;

}

std::string Engine::GetEngineFileName() const
{
	return GameFile;
}
