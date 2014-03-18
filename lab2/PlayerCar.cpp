/* Ditu Alexandru 333CA Tema2 EGC */
#include "PlayerCar.h"
#include "Paralelipiped.h"


PlayerCar::PlayerCar(void)
{
	createObject();
}


PlayerCar::~PlayerCar(void)
{
}

void PlayerCar::createObject() {
	vector <Point3D*> vertices;

	width = 60;
	height = 40;
	length = 60;
	//varfurile de jos
	vertices.push_back(new Point3D(-width,0,length));
	vertices.push_back(new Point3D(width,0,length));
	vertices.push_back(new Point3D(width,0,-length));
	vertices.push_back(new Point3D(-width,0,-length));
	//varfurile de sus
	vertices.push_back(new Point3D(-width,height,length));
	vertices.push_back(new Point3D(width,height,length));
	vertices.push_back(new Point3D(width,height,-length));
	vertices.push_back(new Point3D(-width,height,-length));

	Paralelipiped *p = new Paralelipiped(vertices,Color(0.5,0,0));
	elements.push_back(p->getParalelipiped());

	// al II-lea paralelipiped
	width = 60; height = 40; length = 30;
	vertices.clear();
	//varfurile de jos
	vertices.push_back(new Point3D(-width,height,length));
	vertices.push_back(new Point3D(width,height,length));
	vertices.push_back(new Point3D(width,height,-length));
	vertices.push_back(new Point3D(-width,height,-length));
	//varfurile de sus
	vertices.push_back(new Point3D(-width,2*height,length));
	vertices.push_back(new Point3D(width,2*height,length));
	vertices.push_back(new Point3D(width,2*height,-length));
	vertices.push_back(new Point3D(-width,2*height,-length));

	p = new Paralelipiped(vertices,Color(0.5,0,0));
	elements.push_back(p->getParalelipiped());

	setCenter(Point3D (0,0,0));
	setPosition(Point3D (0,0,0));

	setSpeed(0);
	setAngle(0);
	

	Wheel *w = new Wheel(20, 20, width, 0, length, Color(0,0,0));
	wheels.push_back(w);
	elements.push_back(w->getWheel());
	offset.push_back(Point2D(width, length));

	w = new Wheel(20, 20, width, 0, -length, Color(0,0,0));
	wheels.push_back(w);
	elements.push_back(w->getWheel());
	offset.push_back(Point2D(width, -length));

	w = new Wheel(20, 20, -width, 0, length, Color(0,0,0));
	wheels.push_back(w);
	elements.push_back(w->getWheel());
	offset.push_back(Point2D(-width, length));

	w = new Wheel(20, 20, -width, 0, -length, Color(0,0,0));
	wheels.push_back(w);
	elements.push_back(w->getWheel());
	offset.push_back(Point2D(-width, -length));

	setWheelAngle(0);
	setLives(3);
	setTotalDistance(10000);
	setTopSpeed(20);
	setScore(0);

	setBorder();
}

void PlayerCar::setSpeed(float speed) {
	this->speed = speed;
}

float PlayerCar::getSpeed() {
	return speed;
}

void PlayerCar::setAngle(float angle) {
	this->angle = angle;
}

float PlayerCar::getAngle() {
	return angle;
}

Wheel* PlayerCar::getWheel(int i) {
	return wheels[i];
}

Point2D PlayerCar::getOffset(int i) {
	return offset[i];
}

void PlayerCar::setWheelAngle(float angle) {
	wheelAngle = angle;
}
	
float PlayerCar::getWheelAngle() {
	return wheelAngle;
}

void PlayerCar::setLives(int lives) {
	this->lives = lives;
}
	
int PlayerCar::getLives() {
	return this->lives;
}

void PlayerCar::setTotalDistance(long int totalDistance) {
	this->totalDistance = totalDistance;
}
	
long int PlayerCar::getTotalDistance() {
	return this->totalDistance;
}

float PlayerCar::getWidth() {
	return width;
}

void PlayerCar::setTopSpeed(int newTopSpeed) {
	this->topSpeed = newTopSpeed;
}

int PlayerCar::getTopSpeed() {
	return this->topSpeed;
}

void PlayerCar::setScore(long int score) {
	this->score = score;
}

long int PlayerCar::getScore() {
	return this->score;
}