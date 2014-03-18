/* Ditu Alexandru 333CA Tema2 EGC */
#include "Enemy2.h"


Enemy2::Enemy2(void)
{
	createObject();
}


Enemy2::~Enemy2(void)
{
}

void Enemy2::createObject() {
	vector <Point3D*> vertices;
	vector <Face*> faces;
	vector <int> contour;
	height = 150;
	width = 80;
	length = 80;

	vertices.push_back(new Point3D(0,height,0));
	vertices.push_back(new Point3D(-width, 0, length));
	vertices.push_back(new Point3D(+width, 0, length));
	vertices.push_back(new Point3D(width, 0, -length));
	vertices.push_back(new Point3D(-width, 0, -length));

	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	faces.push_back(new Face(contour));

	contour.clear();
	contour.push_back(0);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));
	
	contour.clear();
	contour.push_back(0);
	contour.push_back(3);
	contour.push_back(4);
	faces.push_back(new Face(contour));

	contour.clear();
	contour.push_back(0);
	contour.push_back(4);
	contour.push_back(1);
	faces.push_back(new Face(contour));

	pyramid = new Object3D(vertices,faces,Color(1,1,0),false);
	elements.push_back(pyramid);

	setCenter(Point3D(0,0,0));
	setPosition(Point3D(0,0,0));
	setSpeed(10);
	setBorder();
	setType(2);
}
