/* Ditu Alexandru 333CA Tema2 EGC */
#pragma once
#include "GenericObject.h"
#include "Paralelipiped.h"
class Enemy4 : public GenericObject
{
protected:
	Paralelipiped *cube;
	float size;
	float speed;
	bool show;
public:
	Enemy4(void);
	~Enemy4(void);

	void createObject();
};

