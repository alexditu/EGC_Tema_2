/* Ditu Alexandru 333CA Tema2 EGC */
#include "Wheel.h"


Wheel::Wheel(void)
{
}


Wheel::~Wheel(void)
{
}

Wheel::Wheel(float radius, float height, Color color) {
	vector <Point3D*> vertices;
	vector <Face*> faces;
	vector <int> contour;

	vertices.clear();
	faces.clear();

	float alpha;
	for (int i = 0; i < 8; i ++) {
		alpha = i * PI / 4;
		vertices.push_back(new Point3D(radius * cos(alpha), 0, radius * sin(alpha)));
	}
	for (int i = 0; i < 8; i ++) {
		alpha = i * PI / 4;
		vertices.push_back(new Point3D(radius * cos(alpha), height, radius * sin(alpha)));
	}

	for (int i = 0; i < 8; i++) {
		contour.clear();
		int a,b,c,d;
		a = i;
		if (i == 0)
			b = 7;
		else
			b = i - 1;
		c = b + 8;
		d = a + 8;
		contour.push_back(a);
		contour.push_back(b);
		contour.push_back(c);
		contour.push_back(d);
		faces.push_back(new Face(contour));
	}

	wheel = new Object3D(vertices,faces,color,false);
}

Wheel::Wheel(float radius, float height, float px, float py, float pz, Color color) {
	vector <Point3D*> vertices;
	vector <Face*> faces;
	vector <int> contour;

	vertices.clear();
	faces.clear();

	double alpha;
	for (int i = 0; i < 8; i ++) {
		alpha = i * PI / 4;
		vertices.push_back(new Point3D(radius * cos(alpha) + px, 0 + py, radius * sin(alpha) + pz));
	}
	for (int i = 0; i < 8; i ++) {
		alpha = i * PI / 4;
		vertices.push_back(new Point3D(radius * cos(alpha) + px, height + py, radius * sin(alpha) + pz));
	}

	for (int i = 0; i < 8; i++) {
		contour.clear();
		int a,b,c,d;
		a = i;
		if (i == 0)
			b = 7;
		else
			b = i - 1;
		c = b + 8;
		d = a + 8;
		contour.push_back(a);
		contour.push_back(b);
		contour.push_back(c);
		contour.push_back(d);
		faces.push_back(new Face(contour));
	}

	wheel = new Object3D(vertices,faces,color,false);
}

Object3D* Wheel::getWheel() {
	return wheel;
}

float Wheel::getHeight() {
	return height;
}

float Wheel::getRadius() {
	return radius;
}

void Wheel::setHeight() {
	this->height = height;
}

void Wheel::setRadius() {
	this->radius = radius;
}