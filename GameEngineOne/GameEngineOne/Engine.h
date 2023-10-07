#pragma once

#ifndef _ENGINE_H_
#define _ENGINE_H_

class Engine
{

private:

	class RenderSystem* renderSys;
	class AssetManager* assetMgr;
	class InputManager* inputMgr;
	class SceneManager* sceneMgr;

public:

	Engine();

	~Engine();

	void Initialize();

	void Destroy();

	void GameLoop();

	void Load();
};

#endif // !_ENGINE_H_
