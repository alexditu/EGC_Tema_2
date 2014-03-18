/* Ditu Alexandru 333CA Tema2 EGC */
#pragma once
#include "Framework\Object3D.h"
#include "GenericObject.h"

class Enemy2 : public GenericObject
{
protected:
	Object3D *pyramid;
	float height, length, width;

public:
	Enemy2(void);
	~Enemy2(void);

	void createObject();
};

