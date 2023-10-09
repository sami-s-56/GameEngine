#pragma once

#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <string>

class Engine
{

private:

	class RenderSystem* renderSys;
	class AssetManager* assetMgr;
	class InputManager* inputMgr;
	class SceneManager* sceneMgr;


	std::string GameFile;

	static Engine* engine;

public:
	

	Engine();

	~Engine();

	void Initialize();

	void Destroy();

	void GameLoop();

	void Load();

	static Engine* GetEngine() { return engine; }

	std::string GetEngineFileName() const;
};

#endif // !_ENGINE_H_
