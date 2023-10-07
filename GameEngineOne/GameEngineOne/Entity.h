#pragma once

#ifndef _ENTITY_
#define _ENTITY_

#include <string>
#include <list>

class Component;

class Entity
{
	std::list<Component*> compList;
	std::string name;

public:

	Entity(const std::string _name);

	~Entity();

	void Initialize();

	void Destroy();

	void Update();

	void Load();

	void AddComponent(Component* _component);

	void RemoveComponent(Component* _component);

	std::string GetName() const;

};

#endif // !_ENTITY_


