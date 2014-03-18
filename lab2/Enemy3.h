/* Ditu Alexandru 333CA Tema2 EGC */
#pragma once
#include "GenericObject.h"
#include "Wheel.h"
class Enemy3 : public GenericObject
{
protected:
	Wheel *bigWheel;
	float radius, height;
	float angle;
public:
	Enemy3(void);
	~Enemy3(void);
	void createObject();
	void setAngle(float angle);
	float getAngle();
	void incAngle();

};

