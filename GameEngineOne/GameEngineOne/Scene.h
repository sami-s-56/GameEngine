#pragma once

#ifndef _SCENE_
#define _SCENE_

#include <list>
#include <string> 

class Entity;

class Scene
{
	std::string Name;
	std::list<Entity*> entityList;

public:

	Scene(std::string& name);

	~Scene();

	void Initialize();

	void Destroy();

	void Update();

	void Load();

	void AddEntity(Entity*& _entity);

	void RemoveEntity(Entity*& _entity);

};

#endif // !_SCENE_

