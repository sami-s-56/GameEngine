#pragma once

#ifndef _COMP_
#define _COMP_

class Component
{
	int id;

public:

	Component(int _id);

	~Component();

	void Initialize();

	void Destroy();

	void Update();

	void Load();

	int GetComponentId() { return id; }

};

#endif // !_COMP_

