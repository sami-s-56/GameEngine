#include "AssetManager.h"
#include <iostream>

AssetManager::AssetManager()
{
	std::cout << "Asset Manager Constructor" << std::endl;
	Initialize();
}

AssetManager::~AssetManager()
{
	Destroy();
	std::cout << "Asset Manager Destructor" << std::endl;
}

void AssetManager::Initialize()
{
	std::cout << "Asset Manager Initialize()" << std::endl;
}

void AssetManager::Destroy()
{
	std::cout << "Asset Manager Destroy()" << std::endl;
}

void AssetManager::Update()
{
}

void AssetManager::Load()
{
	std::cout << "Asset Manager Load()" << std::endl;
}
