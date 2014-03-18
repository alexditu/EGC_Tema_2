/* Ditu Alexandru 333CA Tema2 EGC */
#pragma once
#include "Paralelipiped.h"
#include "GenericObject.h"
#include "Framework\Point3D.h"
class Strip
{
	Paralelipiped *strip;
	float length, width;
	Point3D position;
	float speed;
public:
	Strip(void);
	~Strip(void);

	void createObject();
	void setPosition(Point3D pos);
	Point3D getPosition();
	Object3D* getObject3D();
	float getSpeed();
};

