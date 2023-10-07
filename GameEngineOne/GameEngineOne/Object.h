#pragma once

#ifndef _OBJ_
#define _OBJ_


class Object
{
	bool bInitialized;

public:

	Object();

	~Object();

	void Destroy();

	void Initialize() { bInitialized = true; }

	bool IsInitialized() { return bInitialized; }

	void  Load();
	

};

#endif // !_OBJ_
