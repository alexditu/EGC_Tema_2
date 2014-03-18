/* Ditu Alexandru 333CA Tema2 EGC */
#include "Collision.h"
#include "Framework\Point2D.h"


Collision::Collision(void)
{
}


Collision::~Collision(void)
{
}

float Collision::min (float x, float y) {
	if (x < y)
		return x;
	else
		return y;
}

float Collision::max (float x, float y) {
	if (x > y)
		return x;
	else
		return y;
}

bool Collision::segmentIntersection(Point2D p1, Point2D p2, Point2D p3, Point2D p4) {
	
	float m;
	float xi, yi; // coordonatele punctului de intersectie
	float aux1, aux2;

	m = (p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x);
	
	if (m == 0) {
		return false;
	}
	aux1 = p1.x * p2.y - p1.y * p2.x;
	aux2 = p3.x * p4.y - p3.y * p4.x;
	xi = ((p3.x - p4.x) * aux1 - (p1.x - p2.x) * aux2) / m;
	yi = ((p3.y - p4.y) * aux1 - (p1.y - p2.y) * aux2) / m;

	if (xi < min(p1.x, p2.x) || xi > max(p1.x, p2.x) || yi < min(p1.y, p2.y) || yi > max(p1.y, p2.y)) {
		return false;
	}
	if (xi < min(p3.x, p4.x) || xi > max(p3.x, p4.x) || yi < min(p3.y, p4.y) || yi > max(p3.y, p4.y)) {
		return false;
	}
	return true;
}
