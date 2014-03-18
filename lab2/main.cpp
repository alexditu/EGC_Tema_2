/* Ditu Alexandru 333CA Tema2 EGC */
#include "Framework/DrawingWindow.h"
#include "Framework/Visual2D.h"
#include "Framework/Transform2D.h"
#include "Framework/Transform3D.h"
#include "Framework/Line2D.h"
#include "Framework/Rectangle2D.h"
#include "Framework/Circle2D.h"
#include "Framework/Polygon2D.h"
#include "GenericObject.h"
#include "PlayerCar.h"
#include "Road.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Enemy4.h"
#include "Shield.h"
#include "Collision.h"
#include "Wheel.h"
#include "Strip.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>


#define PI 3.14159265358979323846
#define inf 1000000
using namespace std;

Visual2D *v2d1, *v2d2;
Object3D *road;

// buffer pentru memorat ce tasta e apasata
bool *keyStates = new bool[256];
bool *specialKeyStates = new bool[256];

// punctul fata de care fac proiectia perspectiva pentru toate obiectele
// (aproape toate)
float xc = 0, yc = 500, zc = 550;
float ty = 250;
float mv = 0.2;

float n=10;
float pasTaste = 2, rotAngle = 0;

int elipsedTime = 0;

PlayerCar car;
Road drum;
Enemy1 enemy1;
Collision collision;
vector <GenericObject*> enemies;
Strip *strip;
vector <Strip> strips;

// variabile pentru afisaj:
Text *tDistance, *tScore, *tLives, *tTime, *tGameOver, *tSpeedBonus;
string sDistance, sScore, sLives, sTime;
long int crtDistance = 0; // distanta curenta parcursa de masina
long int crtScore = 0;
clock_t startTime;
clock_t crtTime;

bool gameOver = false;
Enemy2 *en2 = new Enemy2();

bool speedBonus = false;
clock_t startSpeedBonus;

//functia care permite adaugarea de obiecte
void DrawingWindow::init()
{
	srand(time(NULL));
	glutFullScreen();
	v2d1 = new Visual2D(-WINDOW_X,-WINDOW_Y,WINDOW_X, WINDOW_Y, 0, 0,DrawingWindow::width,DrawingWindow::height); 
	v2d1->tipTran(true);
	addVisual2D(v2d1);

	// initializari pentru afisaj: scor, vieti, distanta parcursa:
	sDistance	= "Distance:  ";
	sLives		= "Lives:  ";
	sScore		= "Score:  0";
	sTime		= "Time:  ";

	sLives.append(to_string(car.getLives()));
	tDistance = new Text(sDistance, Point2D(-1200,700), Color(1, 1, 1), BITMAP_TIMES_ROMAN_24);
	tLives = new Text(sLives, Point2D(-1200, 650), Color(1, 1, 1), BITMAP_TIMES_ROMAN_24);
	tScore = new Text(sScore, Point2D(900, 700), Color(1, 1, 1), BITMAP_TIMES_ROMAN_24);
	tTime = new Text(sTime, Point2D(900, 650), Color(1, 1, 1), BITMAP_TIMES_ROMAN_24);
	tGameOver = new Text("", Point2D(0, 650), Color(1, 1, 1), BITMAP_TIMES_ROMAN_24);
	tSpeedBonus = new Text("", Point2D(0, 650), Color(1, 1, 1), BITMAP_TIMES_ROMAN_24);

	addText_to_Visual2D(tDistance, v2d1);
	addText_to_Visual2D(tLives, v2d1);
	addText_to_Visual2D(tScore, v2d1);
	addText_to_Visual2D(tTime, v2d1);
	addText_to_Visual2D(tGameOver, v2d1);
	addText_to_Visual2D(tSpeedBonus, v2d1);

	// adaugare masina in teren:
	for (unsigned int i = 0; i < car.getNoOfElements(); i++) {
		addObject3D_to_Visual2D(car.getElement(i),v2d1);
		car.setPosition(Point3D(0,0,200));
	}

	// adaugare inamic1
	for (int j = 0; j < 4; j++) {
		enemies.push_back(new Enemy1());
	}
	for (int j = 0; j < enemies.size(); j++) {
		for (unsigned int i = 0; i < enemies[j]->getNoOfElements(); i++) {
			addObject3D_to_Visual2D(enemies[j]->getElement(i),v2d1);
		}
		// plasez inamicii in afara campului vizual
		enemies[j]->setPosition(Point3D(0,0,800));
		enemies[j]->dontShow();
	}

	// adaugare inamic2
	for (int j = 0; j < 4; j++) {
		enemies.push_back(new Enemy2());
	}
	for (int j = 0; j < enemies.size(); j++) {
		for (unsigned int i = 0; i < enemies[j]->getNoOfElements(); i++) {
			addObject3D_to_Visual2D(enemies[j]->getElement(i),v2d1);
		}
		// plasez inamicii in afara campului vizual
		enemies[j]->setPosition(Point3D(0,0,800));
		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix(0,0,800);
		Transform3D::applyTransform(enemies[j]->getElement(0));
		enemies[j]->dontShow();
	}

	// adaugare inamic3
	for (int j = 0; j < 1; j++) {
		enemies.push_back(new Enemy3());
	}
	for (int j = 0; j < enemies.size(); j++) {
		for (unsigned int i = 0; i < enemies[j]->getNoOfElements(); i++) {
			addObject3D_to_Visual2D(enemies[j]->getElement(i),v2d1);
		}
		// plasez inamicii in afara campului vizual
		enemies[j]->setPosition(Point3D(0,0,800));
		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix(0,0,800);
		Transform3D::applyTransform(enemies[j]->getElement(0));
		enemies[j]->dontShow();
	}

	// adaugare inamic4
	for (int j = 0; j < 3; j++) {
		enemies.push_back(new Enemy4());
	}
	for (int j = 0; j < enemies.size(); j++) {
		for (unsigned int i = 0; i < enemies[j]->getNoOfElements(); i++) {
			addObject3D_to_Visual2D(enemies[j]->getElement(i),v2d1);
		}
		// plasez inamicii in afara campului vizual
		enemies[j]->setPosition(Point3D(0,0,800));
		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix(0,0,800);
		Transform3D::applyTransform(enemies[j]->getElement(0));
		enemies[j]->dontShow();
	}

	// adaugare shield
	for (int j = 0; j < 1; j++) {
		enemies.push_back(new Shield());
	}
	for (int j = 0; j < enemies.size(); j++) {
		for (unsigned int i = 0; i < enemies[j]->getNoOfElements(); i++) {
			addObject3D_to_Visual2D(enemies[j]->getElement(i),v2d1);
		}
		// plasez inamicii in afara campului vizual
		enemies[j]->setPosition(Point3D(0,0,800));
		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix(0,0,800);
		Transform3D::applyTransform(enemies[j]->getElement(0));
		enemies[j]->dontShow();
	}

	
	//initializare keyStates
	for (int i = 0; i < 256; i++) {
		keyStates[i] = false;
		specialKeyStates[i] = false;
	}

	// desenare benzi intermitente stanga	
	for (int i = 0; i < 13; i++) {
		strips.push_back(Strip());
		addObject3D_to_Visual2D(strips[i].getObject3D(), v2d1);

		// pozitionare initiala
		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix(-200, 0, -970 + i * 100);
		Transform3D::loadIdentityProjectionMatrix();
		Transform3D::perspectiveProjectionMatrix(xc, yc, 400);
		Transform3D::applyTransform(strips[i].getObject3D());

		strips[i].setPosition(Point3D(-200, 0, -970 + i * 100));
	}

	// desenare benzi intermitente dreapta
	for (int i = 13; i < 26; i++) {
		strips.push_back(Strip());
		addObject3D_to_Visual2D(strips[i].getObject3D(), v2d1);

		// pozitionare initiala
		Transform3D::loadIdentityModelMatrix();
		Transform3D::translateMatrix(200, 0, -970 + (i % 13) * 100);
		Transform3D::loadIdentityProjectionMatrix();
		Transform3D::perspectiveProjectionMatrix(xc, yc, 400);
		Transform3D::applyTransform(strips[i].getObject3D());

		strips[i].setPosition(Point3D(200, 0, -970 + (i % 13) * 100));
	}
	
	// adaugare drum la contextul vizual
	for (unsigned int i = 0; i < drum.getNoOfElements(); i++) {
		addObject3D_to_Visual2D(drum.getElement(i),v2d1);
	}

	// initializez timpul de inceput
	startTime = clock();

}


//functia care permite animatia
void DrawingWindow::onIdle()
{
	if (gameOver == false) {

		float oldSpeed = car.getSpeed(), newSpeed;
		newSpeed = oldSpeed - 0.025;
		if (newSpeed > 0) {
			oldSpeed = newSpeed;
		}
		car.setSpeed (oldSpeed);

		// Apasare taste:
		if (specialKeyStates[KEY_UP]) {
			float oldSpeed = car.getSpeed(), newSpeed;
			newSpeed = oldSpeed + 0.15;
			cout << car.getTopSpeed() << endl;
			if (newSpeed <= car.getTopSpeed()) {
				oldSpeed = newSpeed;
			}
			car.setSpeed (oldSpeed);
		}
		if (specialKeyStates[KEY_DOWN]) {
			float oldSpeed = car.getSpeed(), newSpeed;
			newSpeed = oldSpeed - 0.2;
			if (newSpeed >= 0) {
				oldSpeed = newSpeed;
			} else {
				oldSpeed = 0;
			}
			car.setSpeed (oldSpeed);
		}
		if (specialKeyStates[KEY_LEFT]) {
			float newPosX = car.getPosX() - car.getSpeed();
			// verific sa nu iasa de pe drum!
			if (newPosX - car.getWidth() > drum.getMinX()) {
				car.setPosX(newPosX);
			}
		}
		if (specialKeyStates[KEY_RIGHT]) {
			float newPosX = car.getPosX() + car.getSpeed();
			// verific sa nu iasa de pe drum!
			if (newPosX + car.getWidth() < drum.getMaxX()) {
				car.setPosX(newPosX);
			}
		}
		// pentru schimbare perspectiva
		if (keyStates['a']) {
			xc += pasTaste;
		}
		if (keyStates['s']) {
			yc += pasTaste;
		}
		if (keyStates['d']) {
			zc += pasTaste;
		}
		if (keyStates['z']) {
			xc -= pasTaste;
		}
		if (keyStates['x']) {
			yc -= pasTaste;
		}
		if (keyStates['c']) {
			zc -= pasTaste;
		}
		// pentru rotatie masina
		if (keyStates['q']) {
			float oldAngle = car.getAngle();
			car.setAngle(oldAngle - 0.05);
		}
		if (keyStates['e']) {
			float oldAngle = car.getAngle();
			car.setAngle(oldAngle + 0.05);
		}

		// Afisare drum
		Transform3D::loadIdentityModelMatrix();
		Transform3D::loadIdentityProjectionMatrix();
		Transform3D::perspectiveProjectionMatrix(xc, yc, 400);
		for (unsigned int i = 0; i < drum.getNoOfElements(); i++) {
			Transform3D::applyTransform(drum.getElement(i));
		}

		// Animatie benzi intermitente
		for (unsigned int j = 0; j < strips.size(); j++) {
			// calculez noua pozitie
			float px, py, pz;
			px = strips[j].getPosition().x;
			py = strips[j].getPosition().y;
			pz = strips[j].getPosition().z;
			if (pz > 330) {
				pz = -970;
			} else {
				pz += car.getSpeed();
			}
			Point3D newPos(px, py, pz);
			strips[j].setPosition(newPos);

			Transform3D::loadIdentityModelMatrix();
			Transform3D::translateMatrix(px, py, pz);
			Transform3D::loadIdentityProjectionMatrix();
			Transform3D::perspectiveProjectionMatrix(xc,yc,400);
			Transform3D::applyTransform(strips[j].getObject3D());
		}

		// Animatie inamic1
		for (unsigned int j = 0; j < enemies.size(); j++) {
			if (enemies[j]->isShowable()) {
				// calculez noua pozitie
				float px, py, pz;
				px = enemies[j]->getPosition().x;
				py = enemies[j]->getPosition().y;
				pz = enemies[j]->getPosition().z;
				// daca iese de pe drum, il mut mai departe
				// de campul vizual pentru a-l folosi mai tarziu
				if (pz > 400) {
					pz = 800;
					px = py = 0;
					enemies[j]->setPosition(Point3D(px,py,pz));
					enemies[j]->dontShow();
					Transform3D::loadIdentityModelMatrix();
					Transform3D::translateMatrix(px, py, pz);
					Transform3D::loadIdentityProjectionMatrix();
					Transform3D::perspectiveProjectionMatrix(xc,yc,zc);
					for (unsigned int i = 0; i < enemies[j]->getNoOfElements(); i++) {
						Transform3D::applyTransform(enemies[j]->getElement(i));
					}
				} else {
					
					pz += car.getSpeed();
					if (enemies[j]->getType() == 5) {
						pz -= enemies[j]->getSpeed();
					}
		
					Point3D newPos(px, py, pz);
					enemies[j]->setPosition(newPos);
					Transform3D::loadIdentityModelMatrix();
					// daca obiectul e de tipul 3, atunci il si rotesc:
					if (enemies[j]->getType() == 3) {
						rotAngle += 0.1;
						Transform3D::rotateMatrixOy(rotAngle);
					}
					Transform3D::translateMatrix(px, py, pz);
					Transform3D::loadIdentityProjectionMatrix();
					Transform3D::perspectiveProjectionMatrix(xc,yc,zc);
					for (unsigned int i = 0; i < enemies[j]->getNoOfElements(); i++) {
						Transform3D::applyTransform(enemies[j]->getElement(i));
					}
				}

				// animatie pentru inamcii de tipul 5, care pot iesi de pe drum si
				// spre z -> -inf
				if (enemies[j]->getType() == 5 && enemies[j]->isShowable()) {
					if (enemies[j]->getPosition().z < -1550) {
						pz = 800;
						px = py = 0;
						enemies[j]->setPosition(Point3D(px,py,pz));
						enemies[j]->dontShow();
						Transform3D::loadIdentityModelMatrix();
						Transform3D::translateMatrix(px, py, pz);
						Transform3D::loadIdentityProjectionMatrix();
						Transform3D::perspectiveProjectionMatrix(xc,yc,zc);
						for (unsigned int i = 0; i < enemies[j]->getNoOfElements(); i++) {
							Transform3D::applyTransform(enemies[j]->getElement(i));
						}
					}
				}
			}
		}

		// Adaugare inamic la un anumit interval de timp;
		elipsedTime++;
		// afisez un nou obiect, random pe una din benzi, la un interval de timp
		// invers proportional cu viteza de deplasare a masinii
		// in cazul in care viteza e 0, nu mai afisez niciun inamic
		if ((car.getSpeed() != 0) && (elipsedTime >= 600/car.getSpeed())) {
			unsigned int ii;
			
			while(1) {
				ii = rand() % enemies.size();
				if (enemies[ii]->isShowable() == false) {
					if (enemies[ii]->getType() == 4) { 
						if (speedBonus == false) {
							if (rand() % 3 == 0) {
								enemies[ii]->doShow();
								break;
							}
						}
					} else {
						enemies[ii]->doShow();
						break;
					}
				}
			}
			if (ii < enemies.size()) {
				int rnd = rand() % 3;
				enemies[ii]->setPosition(drum.getSideCenterPosition(rnd));
			}
			elipsedTime = 0;
		}


		// Animatie masina
		Point3D crtPos = car.getPosition();
		Transform3D::loadIdentityModelMatrix();
		Transform3D::rotateMatrixOy(car.getAngle());
		Transform3D::translateMatrix(crtPos.x, crtPos.y, crtPos.z);
		Transform3D::loadIdentityProjectionMatrix();
		Transform3D::perspectiveProjectionMatrix(xc,yc,zc);
		for (unsigned int i = 0; i < car.getNoOfElements(); i++) {
			Transform3D::applyTransform(car.getElement(i));
		}

		// roatire roti 
		crtPos = car.getPosition();
		for (unsigned int i = 0; i < 4; i++) {
			Transform3D::loadIdentityModelMatrix();
			Transform3D::translateMatrix(-car.getOffset(i).x, 0, -car.getOffset(i).y);
			if ( i < 2) {
				Transform3D::rotateMatrixOz(-PI/2); //(cu pi/2 fata de oz ca sa nu mai fie culcate)
			} else {
				Transform3D::rotateMatrixOz(+PI/2); // celelalte 2 roti trebuiesc rotice cu +Pi/2
			}

			car.setWheelAngle(car.getWheelAngle() - car.getSpeed() / 100 * 0.2); // rotire roti in sensul de mers
			Transform3D::rotateMatrixOx(car.getWheelAngle());
			Transform3D::translateMatrix(car.getOffset(i).x, 0, car.getOffset(i).y);
			Transform3D::rotateMatrixOy(car.getAngle());
			Transform3D::translateMatrix(crtPos.x, crtPos.y, crtPos.z); // aduc rotile in aceeasi pozitie cu masina
			Transform3D::loadIdentityProjectionMatrix();
			Transform3D::perspectiveProjectionMatrix(xc, yc, zc);
	
			Transform3D::applyTransform(car.getWheel(i)->getWheel());
		}
	
		

		// coliziune inamic vs masina
		for (unsigned int i = 0; i < 4; i++) {
			// cp = car points, ep = enemy points
			Point2D cp1, cp2, ep1, ep2;
			int j = (i + 1) % 4;
			cp1.x = (car.getBorder().at(i).x + car.getPosition().x);
			cp1.y = (car.getBorder().at(i).y + car.getPosition().z);
			cp2.x = (car.getBorder().at(j).x + car.getPosition().x);
			cp2.y = (car.getBorder().at(j).y + car.getPosition().z);

			for (int j = 0; j < enemies.size(); j++) {
				for (unsigned int k = 0; k < 4; k++) {
					int kj = (k + 1) % 4;
					ep1.x = enemies[j]->getBorder().at(k).x + enemies[j]->getPosition().x;
					ep1.y = enemies[j]->getBorder().at(k).y + enemies[j]->getPosition().z;
					ep2.x = enemies[j]->getBorder().at(kj).x + enemies[j]->getPosition().x;
					ep2.y = enemies[j]->getBorder().at(kj).y + enemies[j]->getPosition().z;

					if (collision.segmentIntersection(cp1, cp2, ep1, ep2)) {

						// fac elementul sa dispara din teren
						enemies[j]->setPosition(Point3D(0,0,800));
						if (enemies[j]->getType() == 4) {
							if (speedBonus == false) {
								speedBonus = true;
								startSpeedBonus = clock();
							}
						} else {
							
							if (speedBonus == false) {
								// opresc masina
								car.setSpeed(0); 

								// scad vietile
								car.setLives(car.getLives() - 1);
								sLives = "Lives: ";
								sLives.append(to_string(car.getLives()));
								tLives->setText(sLives);

								// scad puncte
								car.setScore(car.getScore() - 20);
								cout << "COLISION!!" << endl;
							} else {
								//daca am bonusul activat, cresc punctele
								car.setScore(car.getScore() + 20);
							}
						}

						// daca am ramas fara vieti, jocul s-a terminat
						if (car.getLives() <= 0) {
							gameOver = true;
							tGameOver->setText("GAME OVER!");
							tLives->setText("");
							tDistance->setText("");
							tScore->setText("");
							tTime->setText("");

						}
						break;
					}
				}
			}
		}

		// actualizare informatii joc: scor, distanta etc.
		if (!gameOver) {
			// afisare distanta ramasa
			crtDistance += (car.getSpeed() / 10);
			sDistance = "Distance: ";
			sDistance.append(to_string(car.getTotalDistance() - crtDistance));
			sDistance.append(" m");
			tDistance->setText(sDistance);

			if (crtDistance == car.getTotalDistance()) {
				tGameOver->setText("WINNER!!!");
				gameOver = true;
			}

			// afisare scor
			sScore = "Score: ";
			long int score = car.getScore();
			score += car.getSpeed() / 10;
			car.setScore(score);
			sScore.append(to_string(score));
			tScore->setText(sScore);

			// afisare timp
			crtTime = clock();
			crtTime = (crtTime - startTime) / CLOCKS_PER_SEC;
			int min, sec;
			sec = crtTime % 60;
			min = crtTime / 60;
			sTime = "Time:  ";
			if (min != 0) {
				sTime.append(to_string(min));
				sTime.append(" min ");
			}
			sTime.append(to_string(sec));
			sTime.append(" sec");
			tTime->setText(sTime);
		}
	}

	if (speedBonus) {
		crtTime = clock();
		crtTime = (crtTime - startSpeedBonus) / CLOCKS_PER_SEC;
		string b = "Shield Bonus: ";
		tSpeedBonus->setText(b.append(to_string(5 - crtTime)));
		if (crtTime == 5) {
			speedBonus = false;
			cout << "END SPEED BONUS";
			tSpeedBonus->setText("");
		}
	}
}

//functia care se apeleaza la redimensionarea ferestrei
void DrawingWindow::onReshape(int width,int height)
{
	
	v2d1->poarta(0,0,width,height);

}

//functia care defineste ce se intampla cand se apasa pe tastatura
void DrawingWindow::onKey(unsigned char key)
{
	keyStates[key] = true;
	switch(key)
	{
		case 27 : exit(0);

		
	}
}

void DrawingWindow::onSpecialKey(int key) {
	specialKeyStates[key] = true;
	if (key == KEY_LEFT) {
		car.setAngle(-PI/8);
	}
	if (key == KEY_RIGHT) {
		car.setAngle(PI/8);
	}
	
}

void DrawingWindow::onKeyUp(unsigned char key) {
	keyStates[key] = false;
}

void DrawingWindow::onSpecialKeyUp(int key) {
	specialKeyStates[key] = false;
	if (key == KEY_LEFT) {
		car.setAngle(0);
	}
	if (key == KEY_RIGHT) {
		car.setAngle(0);
	}
}

//functia care defineste ce se intampla cand se da click pe mouse
void DrawingWindow::onMouse(int button,int state,int x, int y)
{


}


int main(int argc, char** argv)
{
	//creare fereastra
	DrawingWindow dw(argc, argv, 1366, 768, 200, 50, "Laborator EGC");
	//se apeleaza functia init() - in care s-au adaugat obiecte
	dw.init();
	//se intra in bucla principala de desenare - care face posibila desenarea, animatia si procesarea evenimentelor
	dw.run();
	return 0;

}