/* Ditu Alexandru 333CA Tema2 EGC */
#pragma once
#include "Framework\Point2D.h"
class Collision
{
public:
	Collision(void);
	~Collision(void);

	bool segmentIntersection (Point2D p1, Point2D p2, Point2D p3, Point2D p4);
	float min (float x, float y); // min dintre 2 valori
	float max (float x, float y); // max dintre 2 valori
};

