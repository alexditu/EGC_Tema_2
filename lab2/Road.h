/* Ditu Alexandru 333CA Tema2 EGC */
#pragma once
#include "GenericObject.h"
class Road : public GenericObject
{
protected:
	float *width1, *length1;
	Object3D *road1, *road2;
	vector <Point3D> sideCenterPosition;
	int a;
public:
	Road(void);
	~Road(void);

	void createObject();
	int getA();
	Point3D getSideCenterPosition(int i); // intoarce coordonatele centrului benzii 1,2 sau 3
	float getMinX();
	float getMaxX();
};

