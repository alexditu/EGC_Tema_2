/* Ditu Alexandru 333CA Tema2 EGC */
#include "Enemy1.h"


Enemy1::Enemy1(void)
{
	createObject();
}


Enemy1::~Enemy1(void)
{
}

void Enemy1::createObject() {
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

	cube = new Paralelipiped(vertices, Color(0,0.5,0.5), true);
	elements.push_back(cube->getParalelipiped());

	setCenter(Point3D(0,0,0));
	setPosition(Point3D(0,0,0));
	setSpeed(10);
	setBorder();
	setType(1);
}



