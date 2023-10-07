#include "Entity.h"

Entity::Entity(const std::string _name) : name(_name)
{
}

Entity::~Entity()
{
}

void Entity::Initialize()
{
}

void Entity::Destroy()
{
}

void Entity::Update()
{
}

void Entity::Load()
{
}

void Entity::AddComponent(Component* _component)
{
}

void Entity::RemoveComponent(Component* _component)
{
}

std::string Entity::GetName() const
{
	return name;
}
