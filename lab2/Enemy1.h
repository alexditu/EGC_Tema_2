/* Ditu Alexandru 333CA Tema2 EGC */
#pragma once
#include "GenericObject.h"
#include "Paralelipiped.h"
class Enemy1 : public GenericObject
{
protected:
	Paralelipiped *cube;
	float size;
	float speed;
	bool show;

public:
	Enemy1(void);
	~Enemy1(void);

	void createObject();
};

