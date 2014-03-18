/* Ditu Alexandru 333CA Tema2 EGC */
#include "Enemy4.h"


Enemy4::Enemy4(void)
{
	createObject();
}


Enemy4::~Enemy4(void)
{
}

void Enemy4::createObject() {
	size = 100;
	

	float width, length, height;
	width = 175;
	length = 50;
	height = 60;

	vector<Point3D*> vertices;
	vertices.push_back(new Point3D(-width, 0, length));
	vertices.push_back(new Point3D(width, 0, length));
	vertices.push_back(new Point3D(width, 0, -length));
	vertices.push_back(new Point3D(-width, 0, -length));

	vertices.push_back(new Point3D(-width, height, length));
	vertices.push_back(new Point3D(width, height, length));
	vertices.push_back(new Point3D(width, height, -length));
	vertices.push_back(new Point3D(-width, height, -length));

	cube = new Paralelipiped(vertices, Color(1,0.5,0), true);
	elements.push_back(cube->getParalelipiped());

	setCenter(Point3D(0,0,0));
	setPosition(Point3D(0,0,0));
	setSpeed(10);
	setBorder();
	setType(5);
}