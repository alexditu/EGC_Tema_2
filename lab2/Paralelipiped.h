/* Ditu Alexandru 333CA Tema2 EGC */
#pragma once
#include "Framework\Object3D.h"

class Paralelipiped
{
protected:

	Object3D *paralelipiped;

public:
	Paralelipiped(void);
	~Paralelipiped(void);

	Paralelipiped(float size);
	Paralelipiped(float size, Color color);
	Paralelipiped(vector<Point3D*> vertices, Color color, bool fill);
	Paralelipiped(vector<Point3D*> vertices, Color color);
	Paralelipiped(vector<Point3D*> vertices);
	Object3D* getParalelipiped();
};

