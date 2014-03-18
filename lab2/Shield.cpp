/* Ditu Alexandru 333CA Tema2 EGC */
#include "Shield.h"


Shield::Shield(void)
{
	createObject();
}


Shield::~Shield(void)
{
}


void Shield::createObject() {
	vector <Point3D*> vertices;
	vector <Face*> faces;
	vector <int> contour;

	vertices.clear();
	faces.clear();

	float w1, h1, h2, l, w2;
	w1 = 40;
	w2 = w1 + 20;
	h1 = 100;
	h2 = h1 - 20;
	l = 20;

	vertices.push_back(new Point3D(-w1,h1,0));
	vertices.push_back(new Point3D(w1,h1,0));
	vertices.push_back(new Point3D(w2,h2,0));
	vertices.push_back(new Point3D(0,0,0));
	vertices.push_back(new Point3D(-w2,h2,0));

	vertices.push_back(new Point3D(-w1,h1,-l));
	vertices.push_back(new Point3D(w1,h1,-l));
	vertices.push_back(new Point3D(w2,h2,-l));
	vertices.push_back(new Point3D(0,0,-l));
	vertices.push_back(new Point3D(-w2,h2,-l));

	
	

	// partea din fata
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	contour.push_back(4);
	faces.push_back(new Face(contour));

	// partea din spate
	contour.clear();
	contour.push_back(5);
	contour.push_back(9);
	contour.push_back(8);
	contour.push_back(7);
	contour.push_back(6);
	faces.push_back(new Face(contour));

	// fata de sus
	contour.clear();
	contour.push_back(0);
	contour.push_back(5);
	contour.push_back(6);
	contour.push_back(1);
	faces.push_back(new Face(contour));

	// partea din dreapta sus
	contour.clear();
	contour.push_back(1);
	contour.push_back(6);
	contour.push_back(7);
	contour.push_back(2);
	faces.push_back(new Face(contour));

	// partea din dreapta jos
	contour.clear();
	contour.push_back(2);
	contour.push_back(7);
	contour.push_back(8);
	contour.push_back(3);
	faces.push_back(new Face(contour));

	// partea din stanga jos
	contour.clear();
	contour.push_back(9);
	contour.push_back(4);
	contour.push_back(3);
	contour.push_back(8);
	faces.push_back(new Face(contour));

	// partea din stanga sus
	contour.clear();
	contour.push_back(5);
	contour.push_back(0);
	contour.push_back(4);
	contour.push_back(9);
	faces.push_back(new Face(contour));

	

	

	shield = new Object3D(vertices,faces,Color(0,0,1),true);
	elements.push_back(shield);
	setBorder();
	setType(4);

}

Object3D* Shield::getObject() {
	return shield;
}