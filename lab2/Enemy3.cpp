/* Ditu Alexandru 333CA Tema2 EGC */
#include "Enemy3.h"


Enemy3::Enemy3(void)
{
	createObject();
}


Enemy3::~Enemy3(void)
{
}

void Enemy3::createObject() {
	radius = 100;
	height = 150;
	bigWheel = new Wheel(radius, height, Color(1,0,0));
	elements.push_back(bigWheel->getWheel());
	setAngle(0);
	setBorder();
	setType(3);
}

void Enemy3::setAngle(float angle) {
	this->angle = angle;
}

float Enemy3::getAngle() {
	return angle;
}

void Enemy3::incAngle() {
	angle += 0.2;
}