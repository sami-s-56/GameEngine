#include "Entity.h"
#include "Component.h"

Entity::Entity(const std::string _name) : name(_name)
{
	std::cout << "Entity" << name << "Constructor()" << std::endl;
}

Entity::~Entity()
{
	std::cout << "Entity" << name << "Destructor()" << std::endl;
	for (Component* c : compList)
	{
		delete(c);
	}
	compList.clear();
}

void Entity::Initialize()
{
	std::cout << "Entity" << name << "Initialize()" << std::endl;

	for (Component* c : compList)
	{
		c->Initialize();
	}
}

void Entity::Destroy()
{
	std::cout << "Entity" << name << "Destroy()" << std::endl;


	for (Component* c : compList)
	{
		c->Destroy();
	}
}

void Entity::Update()
{
	for (Component* c : compList)
	{
		c->Update();
	}
}

void Entity::Load(json::JSON& json_Object)
{
	if (json_Object.hasKey("Components"))
	{
		json::JSON json_subObjects = json_Object["Components"];

		for (auto& json_subobject : json_subObjects.ArrayRange())
		{
			Component* c = new Component(json_subobject["id"].ToInt());
			AddComponent(c);
			c->Load();
		}

	}
}

void Entity::AddComponent(Component* _component)
{
	compList.push_back(_component);
}

void Entity::RemoveComponent(Component* _component)
{
	compList.remove(_component);
}

std::string Entity::GetName() const
{
	return name;
}
