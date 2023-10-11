#include "SceneManager.h"
#include "Engine.h"
#include "Scene.h"
#include <fstream>

SceneManager::SceneManager()
{
	std::cout << "Scene Manager Constructor" << std::endl;

	Initialize();
}

SceneManager::~SceneManager()
{
	Destroy();
	std::cout << "Scene Manager Destructor";
}

void SceneManager::Initialize()
{
	std::cout << "Scene Manager Initialize()" << std::endl;

	sceneList = std::list<Scene*>();
	
	std::ifstream inputStream(Engine::GetEngine()->GetEngineFileName());
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON document = json::JSON::Load(str);
	
	std::string sName;

	if (document.hasKey("SceneManager"))
	{
		std::cout << "Scene Manager Found!" << std::endl;

		json::JSON json_subobjects = document["SceneManager"];

		for (auto& json_subobject : json_subobjects.ArrayRange())
		{
			if (json_subobject.hasKey("name"))
			{
				sName = json_subobject["name"].ToString();

				Scene* scene = new Scene(sName);

				AddScene(scene);

				LoadScene(scene, json_subobject);
			}
		}
	}

	
}

void SceneManager::Destroy()
{
	std::cout << "Scene Manager Destroy" << std::endl;
}

void SceneManager::Update()
{
	for (Scene* s : sceneList)
	{
		s->Update();
	}
}

void SceneManager::AddScene(Scene*& _scene)
{
	sceneList.push_back(_scene);
}

void SceneManager::RemoveScene(Scene*& _scene)
{
	sceneList.remove(_scene);
}

void SceneManager::LoadScene(Scene*& _scene, json::JSON& obj)
{
	_scene->Load(obj);
}
