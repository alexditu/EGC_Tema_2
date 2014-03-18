/* Ditu Alexandru 333CA Tema2 EGC */
#pragma once
#include "Framework\Object3D.h"
#define PI 3.14159265358979323846

class Wheel
{
protected:
	Object3D *wheel;
	float radius, height;
public:
	Wheel(void);
	~Wheel(void);

	Wheel (float radius, float height, Color color);
	Wheel (float radius, float height, float px, float py, float pz, Color color);
	Object3D* getWheel();
	float getHeight();
	float getRadius();
	void setHeight();
	void setRadius();
};

