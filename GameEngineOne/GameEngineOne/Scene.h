#pragma once

#ifndef _SCENE_
#define _SCENE_

#include <list>

class Entity;

class Scene
{
	std::list<Entity*> entityList;

public:

	Scene();

	~Scene();

	void Initialize();

	void Destroy();

	void Update();

	void Load();

	void AddEntity(Entity*& _entity);

	void RemoveEntity(Entity*& _entity);

};

#endif // !_SCENE_

