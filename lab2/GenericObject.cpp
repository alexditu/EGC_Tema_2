/* Ditu Alexandru 333CA Tema2 EGC */
#include "GenericObject.h"


GenericObject::GenericObject(void)
{
}


GenericObject::~GenericObject(void)
{
}


Object3D* GenericObject::getElement(unsigned int i) {
	return elements[i];
}

unsigned int GenericObject::getNoOfElements() {
	return elements.size();
}

Point3D GenericObject::getCenter() {
	return center;
}

Point3D GenericObject::getPosition() {
	return position;
}

void GenericObject::setCenter(Point3D center) {
	this->center = center;
}

void GenericObject::setPosition(Point3D newPosition) {
	this->position = newPosition;
}

float GenericObject::getPosX() {
	return position.x;
}
	
float GenericObject::getPosY() {
	return position.y;
}

float GenericObject::getPosZ() {
	return position.z;
}

void GenericObject::setPosX(float pos) {
	position.x = pos;
}

void GenericObject::setPosY(float pos) {
	position.y = pos;
}
	
void GenericObject::setPosZ(float pos) {
	position.z = pos;
}

// aflu amprenta/umbra obiectului curent pentru a putea face coliziunile
// nu ma intereseaza decat pa axa XOZ, deoarece este suficient
// pentru a detecta daca 2 obiecte se intersecteaza
// de aceea am nevoie doar de un obiect 2D pentru a calcula umbra obiectului
void GenericObject::setBorder() {
	Point2D min, max;
	min = elements[0]->getMinPoint();
	max = elements[0]->getMaxPoint();

	// aflu min si max dintre toate formele/figurile acestui obiect
	for (int i = 0; i < elements.size(); i++) {
		if (min.x > elements[i]->getMinPoint().x) {
			min.x = elements[i]->getMinPoint().x;
		}
		if (min.y > elements[i]->getMinPoint().y) {
			min.y = elements[i]->getMinPoint().y;
		}
		if (max.x < elements[i]->getMaxPoint().x) {
			max.x = elements[i]->getMaxPoint().x;
		}
		if (max.y < elements[i]->getMaxPoint().y) {
			min.y = elements[i]->getMaxPoint().y;
		}
	}

	// creez chenarul ce incadreaza obiectul (border);
	border.push_back(Point2D(min.x, min.y));
	border.push_back(Point2D(max.x, min.y));
	border.push_back(Point2D(max.x, max.y));
	border.push_back(Point2D(min.x, max.y));

}

vector <Point2D> GenericObject::getBorder() {
	return border;
}

float GenericObject::getSpeed() {
	return speed;
}

void GenericObject::setSpeed(float speed) {
	this->speed = speed;
}

void GenericObject::dontShow() {
	this->show = false;
}
	
void GenericObject::doShow() {
	this->show = true;
}

bool GenericObject::isShowable() {
	return this->show;
}

void GenericObject::setType(int type) {
	this->type = type;
}

int GenericObject::getType() {
	return type;
}
