#include "InputManager.h"
#include <iostream>

InputManager::InputManager()
{
	std::cout << "Input Manager Constructor" << std::endl;
	Initialize();
}

InputManager::~InputManager()
{
	std::cout << "Input Manager Destructor" << std::endl;
}

void InputManager::Initialize()
{
	std::cout << "Input Manager Initialize()" << std::endl;
}

void InputManager::Destroy()
{
	std::cout << "Input Manager Destroy()" << std::endl;
}

void InputManager::Update()
{

}

void InputManager::Load()
{
	std::cout << "Input Manager Load()" << std::endl;
}
