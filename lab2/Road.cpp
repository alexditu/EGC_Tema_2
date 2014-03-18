/* Ditu Alexandru 333CA Tema2 EGC */
#include "Road.h"


Road::Road(void)
{
	createObject();
}


Road::~Road(void)
{
}

void Road::createObject() {
	width1 = new float[2];
	length1 = new float[2];

	width1[0] = -600;
	width1[1] = 600;
	length1[0] = 300;
	length1[1] = -1000;

	vector <Point3D*> vertices;
	vector <Face*> faces;
	vector <int> contour;

	vertices.clear();
	faces.clear();

	//varfurile de jos
	vertices.push_back(new Point3D(width1[0],0,length1[0]));
	vertices.push_back(new Point3D(width1[1],0,length1[0]));
	vertices.push_back(new Point3D(width1[1],0,length1[1]));
	vertices.push_back(new Point3D(width1[0],0,length1[1]));
	//varfurile de sus
	vertices.push_back(new Point3D(width1[0],0,length1[0]));
	vertices.push_back(new Point3D(width1[1],0,length1[0]));
	vertices.push_back(new Point3D(width1[1],0,length1[1]));
	vertices.push_back(new Point3D(width1[0],0,length1[1]));
	
	//cele 6 fete
	//fata jos
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(3);
	faces.push_back(new Face(contour));
	//fata sus
	contour.clear();
	contour.push_back(4);
	contour.push_back(5);
	contour.push_back(6);
	contour.push_back(7);
	faces.push_back(new Face(contour));
	//fata fata
	contour.clear();
	contour.push_back(0);
	contour.push_back(1);
	contour.push_back(5);
	contour.push_back(4);
	faces.push_back(new Face(contour));
	//fata dreapta
	contour.clear();
	contour.push_back(1);
	contour.push_back(2);
	contour.push_back(6);
	contour.push_back(5);
	faces.push_back(new Face(contour));
	//fata spate
	contour.clear();
	contour.push_back(2);
	contour.push_back(3);
	contour.push_back(7);
	contour.push_back(6);
	faces.push_back(new Face(contour));
	//fata stanga
	contour.clear();
	contour.push_back(3);
	contour.push_back(0);
	contour.push_back(4);
	contour.push_back(7);
	faces.push_back(new Face(contour));

	road1 = new Object3D(vertices,faces,Color(0.3,0.3,0.3),true);
	elements.push_back(road1);

	// setare pozitii pentru fiecare banda:
	sideCenterPosition.push_back(Point3D(400,0, -1500));
	sideCenterPosition.push_back(Point3D(0,0, -1500));
	sideCenterPosition.push_back(Point3D(-400,0, -1500));

}

Point3D Road::getSideCenterPosition(int i) {
	return sideCenterPosition[i];
}

float Road::getMinX() {
	return width1[0];
}
	
float Road::getMaxX() {
	return width1[1];
}