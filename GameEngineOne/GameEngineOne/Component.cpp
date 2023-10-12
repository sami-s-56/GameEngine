#include "Component.h"
#include <iostream>

Component::Component(int _id) : id(_id)
{
	std::cout << "Component " << id << "Constructor" << std::endl;
	
}

Component::~Component()
{
	
	std::cout << "Component " << id << "Destructor" << std::endl;
}

void Component::Initialize()
{
	std::cout << "Component " << id << "Initialize()" << std::endl;
}

void Component::Destroy()
{
	std::cout << "Component " << id << "Destroy()" << std::endl;
}

void Component::Update()
{
	std::cout << "Component " << id << "Update()" << std::endl;
}

void Component::Load()
{
	std::cout << "Component " << id << "Load()" << std::endl;
	
}
