/* Ditu Alexandru 333CA Tema2 EGC */
#include "Strip.h"


Strip::Strip(void)
{
	createObject();
}


Strip::~Strip(void)
{
}

void Strip::createObject() {
	speed = 5;
	vector <Point3D*> vertices;
	length = 30;
	width = 10;

	vertices.clear();
	vertices.push_back(new Point3D(-width,0,length));
	vertices.push_back(new Point3D(width,0,length));
	vertices.push_back(new Point3D(width,0,-length));
	vertices.push_back(new Point3D(-width,0,-length));
	//varfurile de sus
	vertices.push_back(new Point3D(-width,0,length));
	vertices.push_back(new Point3D(width,0,length));
	vertices.push_back(new Point3D(width,0,-length));
	vertices.push_back(new Point3D(-width,0,-length));
	strip = new Paralelipiped(vertices, Color(1,1,1), true);

}

void Strip::setPosition(Point3D pos) {
	position = pos;
}
	
Point3D Strip::getPosition() {
	return position;
}

Object3D* Strip::getObject3D() {
	return strip->getParalelipiped();
}

float Strip::getSpeed() {
	return speed;
}