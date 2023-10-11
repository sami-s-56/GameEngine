#include "Scene.h"
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "Engine.h"
#include "Entity.h"

Scene::Scene(std::string& _name) : Name(_name)
{
	std::cout << "Scene " << _name << "Constructor" << std::endl;
	Initialize();
}

Scene::~Scene()
{
	Destroy();

	std::cout << "Scene " << Name << "Destructor" << std::endl;

	for (Entity* entity : entityList) {
		delete entity;
	}
	entityList.clear();
}

void Scene::Initialize()
{
	std::cout << "Scene" << Name << "Initialize()" << std::endl;
}

void Scene::Destroy()
{
	std::cout << "Scene" << Name << "Destroy()" << std::endl;
}

void Scene::Update()
{
	std::cout << "Scene" << Name << "Update()" << std::endl;
	for (Entity* e : entityList)
	{
		e -> Update();
	}
}

void Scene::Load(json::JSON obj)
{
	std::cout << "Scene" << Name << "Load()" << std::endl;

	/*std::ifstream inputStream(Engine::GetEngine()->GetEngineFileName());
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON document = json::JSON::Load(str);*/

	if (obj.hasKey("Entities")) 
	{
		json::JSON json_subobjects = obj["Entities"];
			for (auto& json_subobject : json_subobjects.ArrayRange())
			{
				Entity* e = new Entity(json_subobject["Name"].ToString());
				AddEntity(e);
				e->Load(json_subobject);
			}
	}
}

void Scene::AddEntity(Entity*& _entity)
{
	entityList.push_back(_entity);
}

void Scene::RemoveEntity(Entity*& _entity)
{
	entityList.remove(_entity);
}
