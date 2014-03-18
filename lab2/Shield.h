/* Ditu Alexandru 333CA Tema2 EGC */
#pragma once
#include "GenericObject.h"
class Shield : public GenericObject
{
protected:
	float ceva;
	Object3D *shield;
public:
	Shield(void);
	~Shield(void);
	void createObject();
	Object3D* getObject();
};

