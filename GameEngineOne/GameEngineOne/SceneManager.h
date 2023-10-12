#pragma once

#ifndef _S_MGR_
#define _S_MGR_

#include <iostream>
#include <list>


class Scene;

class SceneManager
{

private:
	
	std::list<Scene*> sceneList;

public:

	SceneManager();

	~SceneManager();

	void Initialize();

	void Destroy();

	void Update();

	void AddScene(Scene*& _scene);

	void RemoveScene(Scene*& _scene);

	void Load();

};


#endif // !_S_MGR_