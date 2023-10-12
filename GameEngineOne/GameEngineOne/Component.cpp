#include "Component.h"
#include <iostream>

Component::Component(int _id) : id(_id)
{
	std::cout << "Component " << id << "Constructor";
	
}

Component::~Component()
{
	
	std::cout << "Component " << id << "Destructor";
}

void Component::Initialize()
{
	std::cout << "Component " << id << "Initialize()";
}

void Component::Destroy()
{
	std::cout << "Component " << id << "Destroy()";
}

void Component::Update()
{
	std::cout << "Component " << id << "Update()";
}

void Component::Load()
{
	std::cout << "Component " << id << "Load()";
	
}
