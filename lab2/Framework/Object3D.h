#pragma once
#include <vector>
#include "Point3D.h"
#include "Point2D.h"


using namespace std;

class Face
{
public:
	vector<int> contour;
	

public:
	Face(vector <int> list)
	{
		for (unsigned int i = 0; i < list.size(); i++)
			contour.push_back(list[i]);
		
	}
};

class Object3D
{
public:
	vector<Point3D*> vertices;
	vector<Point3D*> transf_vertices;
	vector<Face*> faces;
	Color color;
	bool fill;
	float m[4];

public:
	float* getWindow() {
		float xmin, xmax, ymin, ymax;
		xmin = xmax = transf_vertices.at(0)->x;
		ymin = ymax = transf_vertices.at(0)->y;

		for (unsigned int i = 0; i < transf_vertices.size(); i++) {
			if (transf_vertices.at(i)->x < xmin) {
				xmin = transf_vertices.at(i)->x;
			}
			if (transf_vertices.at(i)->x > xmax) {
				xmax = transf_vertices.at(i)->x;
			}

			if (transf_vertices.at(i)->y < ymin) {
				ymin = transf_vertices.at(i)->y;
			}

			if (transf_vertices.at(i)->y > ymax) {
				ymax = transf_vertices.at(i)->y;
			}
		}

		m[0] = xmin;
		m[1] = xmax;
		m[2] = ymin;
		m[3] = ymax;

		return m;
	}
	Object3D(vector <Point3D*> listV,vector <Face*> listF)
	{
		unsigned int i;
		for (i = 0; i < listV.size(); i++)
		{
			vertices.push_back(new Point3D(listV[i]->x,listV[i]->y,listV[i]->z));
			transf_vertices.push_back(new Point3D(listV[i]->x,listV[i]->y,listV[i]->z));
		}
		for (i = 0; i < listF.size(); i++)
			faces.push_back(new Face(listF[i]->contour));
		
		color.r = 0;
		color.g = 0;
		color.b = 0;

		fill = false;
	}

	Object3D(vector <Point3D*> listV,vector <Face*> listF, Color _color,bool _fill)
	{
		unsigned int i;
		for (i = 0; i < listV.size(); i++)
		{
			vertices.push_back(new Point3D(listV[i]->x,listV[i]->y,listV[i]->z));
			transf_vertices.push_back(new Point3D(listV[i]->x,listV[i]->y,listV[i]->z));
		}
		for (i = 0; i < listF.size(); i++)
			faces.push_back(new Face(listF[i]->contour));
		
		color.r = _color.r;
		color.g = _color.g;
		color.b = _color.b;

		fill = _fill;
	}

	~Object3D()
	{}

	// functie ce imi intoarce punctul minim din planul XOZ (pentru a putea calcula
	// coliziunile intre obiecte
	Point2D getMinPoint() {
		Point2D min;

		min.x = vertices[0]->x;
		min.y = vertices[0]->z;

		for (unsigned int i = 1; i < vertices.size(); i++) {
			if (min.x > vertices[i]->x) {
				min.x = vertices[i]->x;
			}
			if (min.y > vertices[i]->z) {
				min.y = vertices[i]->z;
			}
		}

		return min;
	}

	// functie ce imi intoarce punctul maxim din planul XOZ (pentru a putea calcula
	// coliziunile intre obiecte) al obiectului curent
	Point2D getMaxPoint() {
		Point2D max;

		max.x = vertices[0]->x;
		max.y = vertices[0]->z;

		for (unsigned int i = 1; i < vertices.size(); i++) {
			if (max.x < vertices[i]->x) {
				max.x = vertices[i]->x;
			}
			if (max.y < vertices[i]->z) {
				max.y = vertices[i]->z;
			}
		}

		return max;
	}

};