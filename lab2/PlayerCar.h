/* Ditu Alexandru 333CA Tema2 EGC */
#pragma once
#include "Framework\Object3D.h"
#include "GenericObject.h"
#include "Wheel.h"

class PlayerCar : public GenericObject
{
protected:
	float speed;
	float angle;
	vector <Wheel*> wheels;
	vector <Point2D> offset;
	float wheelAngle;
	int lives;
	long int totalDistance;
	float width, height, length;
	int topSpeed;
	long int score;
public:
	PlayerCar(void);
	~PlayerCar(void);

	void createObject();
	void setSpeed(float speed);
	float getSpeed();
	void setAngle(float angle);
	float getAngle();
	Wheel* getWheel(int i);
	Point2D getOffset(int i);
	void setWheelAngle(float angle);
	float getWheelAngle();
	void setLives(int lives);
	int getLives();
	void setTotalDistance(long int totalDistance);
	long int getTotalDistance();
	float getWidth();
	void setTopSpeed(int newTopSpeed);
	int getTopSpeed();
	void setScore(long int score);
	long int getScore();
};

