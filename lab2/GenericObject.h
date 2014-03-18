/* Ditu Alexandru 333CA Tema2 EGC */
#pragma once
#include "Framework\Object3D.h"
#include "Framework\Polygon2D.h"
class GenericObject
{
protected:
	vector <Object3D*> elements;
	Point3D position;
	Point3D center;
	vector <Point2D> border;
	float speed;
	bool show;
	int type;

public:
	GenericObject(void);
	~GenericObject(void);

	
	void createObject();
	Object3D* getElement(unsigned int i);
	unsigned int getNoOfElements();
	Point3D getCenter();
	Point3D getPosition();
	void setCenter(Point3D center);
	void setPosition(Point3D newPosition);
	float getPosX();
	float getPosY();
	float getPosZ();
	void setPosX(float pos);
	void setPosY(float pos);
	void setPosZ(float pos);
	void setBorder();
	vector <Point2D> getBorder();
	float getSpeed();
	void setSpeed(float speed);
	void dontShow();
	void doShow();
	bool isShowable();
	void setType(int type);
	int getType();
};

