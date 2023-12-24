#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
//#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <texture.h>
#include  "camera.h"
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>

#include <fstream>

#include <mmsystem.h>
#include "controll.h"


GLUquadric* quadricc = gluNewQuadric();

void controll::controllC(double x, double y, double z, int controlll, int frontControll, int rightControll, int leftControll, double red, double green,double gg) {


	glBindTexture(GL_TEXTURE_2D, controlll);
	glPushMatrix();
	glBegin(GL_QUADS);
	//front
	glTexCoord2d(0, 0);
	glVertex3d(-x + 20, -y + 12, z + 85);
	glTexCoord2d(0, 1);
	glVertex3d(x - 20, -y + 12, z + 85);
	glTexCoord2d(1, 1);
	glVertex3d(x - 20, -y + 30, z + 85);
	glTexCoord2d(1, 0);
	glVertex3d(-x + 20, -y + 30, z + 85);

	glTexCoord2d(0, 0);
	glVertex3d(-x + 20, -y + 30, z + 85);
	glTexCoord2d(1, 0);
	glVertex3d(x - 20, -y + 30, z + 85);
	glTexCoord2d(1, 1);
	glVertex3d(x - 20, -y + 30, z + 72);
	glTexCoord2d(0, 0.1);
	glVertex3d(-x + 20, -y + 30, z + 72);



	glEnd();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, frontControll);
	glPushMatrix();
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);
	glVertex3d(-x + 20, -y + 30, z + 72);
	glTexCoord2d(1, 0);
	glVertex3d(x - 20, -y + 30, z + 72);
	glTexCoord2d(1.2, 1);
	glVertex3d(x - 20, -y + 40, z + 55);
	glTexCoord2d(0.35, 1);
	glVertex3d(-x + 20, -y + 40, z + 55);
	glEnd();
	glPopMatrix();


	//right
	glBindTexture(GL_TEXTURE_2D, controlll);
	glPushMatrix();
	glBegin(GL_QUADS);

	//div
	glTexCoord2d(0, 0);
	glVertex3d(x - 20, -y + 12, z + 55);
	glTexCoord2d(1, 0);
	glVertex3d(x - 20, -y + 12, z + 85);
	glTexCoord2d(1, 1);
	glVertex3d(x - 20, -y + 30, z + 85);
	glTexCoord2d(0, 1);
	glVertex3d(x - 20, -y + 40, z + 55);

	glTexCoord2d(0, 0);
	glVertex3d(x - 20, -y + 12, z + 85);
	glTexCoord2d(1, 0);
	glVertex3d(x, -y + 12, z + 120);
	glTexCoord2d(1, 1);
	glVertex3d(x, -y + 30, z + 120);
	glTexCoord2d(0.2, 1);
	glVertex3d(x - 20, -y + 30, z + 85);

	glEnd();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, rightControll);
	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(x - 20, -y + 30, z + 85);
	glTexCoord2d(1, 0);
	glVertex3d(x, -y + 30, z + 120);
	glTexCoord2d(1.55, 1);
	glVertex3d(x, -y + 40, z + 80);
	glTexCoord2d(0.6, 0.96);
	glVertex3d(x - 20, -y + 40, z + 55);
	glEnd();
	glPopMatrix();

	//left
	glBindTexture(GL_TEXTURE_2D, controlll);
	glPushMatrix();
	glBegin(GL_QUADS);

	//div
	glTexCoord2d(0, 0);
	glVertex3d(-x + 20, -y + 12, z + 55);
	glTexCoord2d(1, 0);
	glVertex3d(-x + 20, -y + 12, z + 85);
	glTexCoord2d(1, 1);
	glVertex3d(-x + 20, -y + 30, z + 85);
	glTexCoord2d(0, 1);
	glVertex3d(-x + 20, -y + 40, z + 55);


	glTexCoord2d(0, 0);
	glVertex3d(-x + 20, -y + 12, z + 85);
	glTexCoord2d(1, 0);
	glVertex3d(-x, -y + 12, z + 120);
	glTexCoord2d(1, 1);
	glVertex3d(-x, -y + 30, z + 120);
	glTexCoord2d(0.2, 1);
	glVertex3d(-x + 20, -y + 30, z + 85);

	glEnd();
	glPopMatrix();

	//left
	glBindTexture(GL_TEXTURE_2D, leftControll);
	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2d(1.1, 0);
	glVertex3d(-x + 20, -y + 30, z + 85);
	glTexCoord2d(0.05, 0);
	glVertex3d(-x, -y + 30, z + 120);
	glTexCoord2d(0.45, 1);
	glVertex3d(-x, -y + 40, z + 80);
	glTexCoord2d(1.45, 0.9);
	glVertex3d(-x + 20, -y + 40, z + 55);

	glEnd();
	glPopMatrix();

	glBegin(GL_TRIANGLES);
	//right
	glVertex3d(x - 20, -y + 40, z + 55);
	glVertex3d(x, -y + 40, z + 80);
	glVertex3d(x, -y + 40, z + 55);

	//left
	glVertex3d(-x + 20, -y + 40, z + 55);
	glVertex3d(-x, -y + 40, z + 80);
	glVertex3d(-x, -y + 40, z + 55);


	glEnd();

	//controll
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, controlll);
	glTranslated(0, y - 70, z + 72);
	glTranslated(0, 0, z + 120);
	glRotated(gg, 1, 0, 0);
	glTranslated(0, 0, -z - 120);

	gluCylinder(quadricc, 1.18, 1.18, y - 40, 60, 30);
	glColor3ub(1, 1, 1);
	gluSphere(quadricc, 2.18, 16, 16);
	glPopMatrix();


	glPushMatrix();
	glTranslated(0, red, 0);

	glBegin(GL_QUADS);//red

	glColor3ub(243, 67, 54);
	glVertex3d(-x + 32, -y + 31, z + 83);
	glVertex3d(-x + 40, -y + 31, z + 83);
	glVertex3d(-x + 40, -y + 31, z + 78);
	glVertex3d(-x + 32, -y + 31, z + 78);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, green, 0);
	glBegin(GL_QUADS);//green
	glColor3ub(165, 214, 167);
	glVertex3d(x - 32, -y + 31, z + 83);
	glVertex3d(x - 40, -y + 31, z + 83);
	glVertex3d(x - 40, -y + 31, z + 78);
	glVertex3d(x - 32, -y + 31, z + 78);

	glEnd();
	glPopMatrix();

}

void controll::controllChair(double x, double y, double z) {
	glColor3ub(1, 1, 1);

	glBegin(GL_QUADS);

	glVertex3d(-x + 45, -y + 30, z + 140);
	glVertex3d(x - 45, -y + 30, z + 140);
	glVertex3d(x - 45, -y + 30, z + 120);
	glVertex3d(-x + 45, -y + 30, z + 120);

	glVertex3d(-x + 45, -y + 34, z + 140);
	glVertex3d(x - 45, -y + 34, z + 140);
	glVertex3d(x - 45, -y + 34, z + 120);
	glVertex3d(-x + 45, -y + 34, z + 120);

	glVertex3d(-x + 45, -y + 30, z + 140);
	glVertex3d(x - 45, -y + 30, z + 140);
	glVertex3d(x - 45, -y + 34, z + 140);
	glVertex3d(-x + 45, -y + 34, z + 140);

	glVertex3d(-x + 45, -y + 30, z + 120);
	glVertex3d(x - 45, -y + 30, z + 120);
	glVertex3d(x - 45, -y + 34, z + 120);
	glVertex3d(-x + 45, -y + 34, z + 120);

	glVertex3d(-x + 45, -y + 30, z + 120);
	glVertex3d(-x + 45, -y + 30, z + 140);
	glVertex3d(-x + 45, -y + 34, z + 140);
	glVertex3d(-x + 45, -y + 34, z + 120);

	glVertex3d(x - 45, -y + 30, z + 120);
	glVertex3d(x - 45, -y + 30, z + 140);
	glVertex3d(x - 45, -y + 34, z + 140);
	glVertex3d(x - 45, -y + 34, z + 120);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3d(-x + 45, -y + 34, z + 120);
	glVertex3d(-x + 35, -y + 38, z + 120);
	glVertex3d(-x + 35, -y + 38, z + 140);
	glVertex3d(-x + 45, -y + 34, z + 140);

	glVertex3d(-x + 45, -y + 30, z + 120);
	glVertex3d(-x + 35, -y + 34, z + 120);
	glVertex3d(-x + 35, -y + 34, z + 140);
	glVertex3d(-x + 45, -y + 30, z + 140);

	glVertex3d(-x + 45, -y + 30, z + 120);
	glVertex3d(-x + 35, -y + 34, z + 120);
	glVertex3d(-x + 35, -y + 38, z + 120);
	glVertex3d(-x + 45, -y + 34, z + 120);

	glVertex3d(-x + 45, -y + 30, z + 140);
	glVertex3d(-x + 35, -y + 34, z + 140);
	glVertex3d(-x + 35, -y + 38, z + 140);
	glVertex3d(-x + 45, -y + 34, z + 140);


	glVertex3d(-x + 35, -y + 34, z + 120);
	glVertex3d(-x + 35, -y + 34, z + 140);
	glVertex3d(-x + 35, -y + 38, z + 140);
	glVertex3d(-x + 35, -y + 38, z + 120);





	glVertex3d(x - 45, -y + 34, z + 120);
	glVertex3d(x - 35, -y + 38, z + 120);
	glVertex3d(x - 35, -y + 38, z + 140);
	glVertex3d(x - 45, -y + 34, z + 140);

	glVertex3d(x - 45, -y + 30, z + 120);
	glVertex3d(x - 35, -y + 34, z + 120);
	glVertex3d(x - 35, -y + 34, z + 140);
	glVertex3d(x - 45, -y + 30, z + 140);

	glVertex3d(x - 45, -y + 30, z + 120);
	glVertex3d(x - 35, -y + 34, z + 120);
	glVertex3d(x - 35, -y + 38, z + 120);
	glVertex3d(x - 45, -y + 34, z + 120);

	glVertex3d(x - 45, -y + 30, z + 140);
	glVertex3d(x - 35, -y + 34, z + 140);
	glVertex3d(x - 35, -y + 38, z + 140);
	glVertex3d(x - 45, -y + 34, z + 140);

	glVertex3d(x - 35, -y + 34, z + 120);
	glVertex3d(x - 35, -y + 34, z + 140);
	glVertex3d(x - 35, -y + 38, z + 140);
	glVertex3d(x - 35, -y + 38, z + 120);

	glEnd();

	glBegin(GL_QUADS);

	glVertex3d(-x + 50, -y + 12, z + 140);
	glVertex3d(x - 50, -y + 12, z + 140);
	glVertex3d(x - 50, -y + 30, z + 140);
	glVertex3d(-x + 50, -y + 30, z + 140);

	glVertex3d(-x + 50, -y + 12, z + 120);
	glVertex3d(x - 50, -y + 12, z + 120);
	glVertex3d(x - 50, -y + 30, z + 120);
	glVertex3d(-x + 50, -y + 30, z + 120);

	glVertex3d(-x + 50, -y + 12, z + 120);
	glVertex3d(-x + 50, -y + 12, z + 140);
	glVertex3d(-x + 50, -y + 30, z + 140);
	glVertex3d(-x + 50, -y + 30, z + 120);

	glVertex3d(x - 50, -y + 12, z + 120);
	glVertex3d(x - 50, -y + 12, z + 140);
	glVertex3d(x - 50, -y + 30, z + 140);
	glVertex3d(x - 50, -y + 30, z + 120);

	glEnd();

	glBegin(GL_QUADS);//hand

					  //left

	glVertex3d(-x + 35, -y + 34, z + 140);
	glVertex3d(-x + 39, -y + 34, z + 140);
	glVertex3d(-x + 39, -y + 42, z + 140);
	glVertex3d(-x + 35, -y + 42, z + 140);

	glVertex3d(-x + 35, -y + 34, z + 137);
	glVertex3d(-x + 39, -y + 34, z + 137);
	glVertex3d(-x + 39, -y + 42, z + 137);
	glVertex3d(-x + 35, -y + 42, z + 137);


	glVertex3d(-x + 35, -y + 34, z + 137);
	glVertex3d(-x + 35, -y + 34, z + 140);
	glVertex3d(-x + 35, -y + 42, z + 140);
	glVertex3d(-x + 35, -y + 42, z + 137);

	glVertex3d(-x + 39, -y + 34, z + 137);
	glVertex3d(-x + 39, -y + 34, z + 140);
	glVertex3d(-x + 39, -y + 42, z + 140);
	glVertex3d(-x + 39, -y + 42, z + 137);

	/////////////////////////////////////////

	glVertex3d(-x + 35, -y + 34, z + 123);
	glVertex3d(-x + 39, -y + 34, z + 123);
	glVertex3d(-x + 39, -y + 42, z + 123);
	glVertex3d(-x + 35, -y + 42, z + 123);

	glVertex3d(-x + 35, -y + 34, z + 120);
	glVertex3d(-x + 39, -y + 34, z + 120);
	glVertex3d(-x + 39, -y + 42, z + 120);
	glVertex3d(-x + 35, -y + 42, z + 120);

	glVertex3d(-x + 35, -y + 34, z + 120);
	glVertex3d(-x + 35, -y + 34, z + 123);
	glVertex3d(-x + 35, -y + 42, z + 123);
	glVertex3d(-x + 35, -y + 42, z + 120);

	glVertex3d(-x + 39, -y + 34, z + 120);
	glVertex3d(-x + 39, -y + 34, z + 123);
	glVertex3d(-x + 39, -y + 42, z + 123);
	glVertex3d(-x + 39, -y + 42, z + 120);

	//////////////////////////////////////////////

	glVertex3d(-x + 35, -y + 40, z + 120);
	glVertex3d(-x + 35, -y + 40, z + 140);
	glVertex3d(-x + 35, -y + 42, z + 140);
	glVertex3d(-x + 35, -y + 42, z + 120);

	glVertex3d(-x + 39, -y + 40, z + 120);
	glVertex3d(-x + 39, -y + 40, z + 140);
	glVertex3d(-x + 39, -y + 42, z + 140);
	glVertex3d(-x + 39, -y + 42, z + 120);

	glVertex3d(-x + 35, -y + 40, z + 120);
	glVertex3d(-x + 35, -y + 40, z + 140);
	glVertex3d(-x + 39, -y + 40, z + 140);
	glVertex3d(-x + 39, -y + 40, z + 120);

	glVertex3d(-x + 35, -y + 42, z + 120);
	glVertex3d(-x + 35, -y + 42, z + 140);
	glVertex3d(-x + 39, -y + 42, z + 140);
	glVertex3d(-x + 39, -y + 42, z + 120);


	//right

	glVertex3d(x - 35, -y + 34, z + 140);
	glVertex3d(x - 39, -y + 34, z + 140);
	glVertex3d(x - 39, -y + 42, z + 140);
	glVertex3d(x - 35, -y + 42, z + 140);

	glVertex3d(x - 35, -y + 34, z + 137);
	glVertex3d(x - 39, -y + 34, z + 137);
	glVertex3d(x - 39, -y + 42, z + 137);
	glVertex3d(x - 35, -y + 42, z + 137);


	glVertex3d(x - 35, -y + 34, z + 137);
	glVertex3d(x - 35, -y + 34, z + 140);
	glVertex3d(x - 35, -y + 42, z + 140);
	glVertex3d(x - 35, -y + 42, z + 137);

	glVertex3d(x - 39, -y + 34, z + 137);
	glVertex3d(x - 39, -y + 34, z + 140);
	glVertex3d(x - 39, -y + 42, z + 140);
	glVertex3d(x - 39, -y + 42, z + 137);

	/////////////////////////////////////////

	glVertex3d(x - 35, -y + 34, z + 123);
	glVertex3d(x - 39, -y + 34, z + 123);
	glVertex3d(x - 39, -y + 42, z + 123);
	glVertex3d(x - 35, -y + 42, z + 123);

	glVertex3d(x - 35, -y + 34, z + 120);
	glVertex3d(x - 39, -y + 34, z + 120);
	glVertex3d(x - 39, -y + 42, z + 120);
	glVertex3d(x - 35, -y + 42, z + 120);

	glVertex3d(x - 35, -y + 34, z + 120);
	glVertex3d(x - 35, -y + 34, z + 123);
	glVertex3d(x - 35, -y + 42, z + 123);
	glVertex3d(x - 35, -y + 42, z + 120);

	glVertex3d(x - 39, -y + 34, z + 120);
	glVertex3d(x - 39, -y + 34, z + 123);
	glVertex3d(x - 39, -y + 42, z + 123);
	glVertex3d(x - 39, -y + 42, z + 120);

	//////////////////////////////////////////////

	glVertex3d(x - 35, -y + 40, z + 120);
	glVertex3d(x - 35, -y + 40, z + 140);
	glVertex3d(x - 35, -y + 42, z + 140);
	glVertex3d(x - 35, -y + 42, z + 120);

	glVertex3d(x - 39, -y + 40, z + 120);
	glVertex3d(x - 39, -y + 40, z + 140);
	glVertex3d(x - 39, -y + 42, z + 140);
	glVertex3d(x - 39, -y + 42, z + 120);

	glVertex3d(x - 35, -y + 40, z + 120);
	glVertex3d(x - 35, -y + 40, z + 140);
	glVertex3d(x - 39, -y + 40, z + 140);
	glVertex3d(x - 39, -y + 40, z + 120);

	glVertex3d(x - 35, -y + 42, z + 120);
	glVertex3d(x - 35, -y + 42, z + 140);
	glVertex3d(x - 39, -y + 42, z + 140);
	glVertex3d(x - 39, -y + 42, z + 120);

	glEnd();


}

void controll::controllTopDown(double x, double index, double z, int imeg, int imeg2) {
	//glColor3ub(255, 255, 255);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glPushMatrix();//Top
	glBindTexture(GL_TEXTURE_2D, imeg);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-x, index, z + 55);
	glTexCoord2d(1, 0);
	glVertex3d(x, index, z + 55);
	glTexCoord2d(1, 3);
	glVertex3d(x, index, -z);
	glTexCoord2d(0, 3);
	glVertex3d(-x, index, -z);
	glEnd();

	//down
	glBindTexture(GL_TEXTURE_2D, imeg2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-x, -index + 15, z + 55);
	glTexCoord2d(1, 0);
	glVertex3d(x, -index + 15, z + 55);
	glTexCoord2d(1, 1);
	glVertex3d(x, -index + 15, -z);
	glTexCoord2d(0, 1);
	glVertex3d(-x, -index + 15, -z);

	glEnd();
	glPopMatrix();

}

void controll::frontWindowcontroll(double index, double y, double z, int imeg) {

	glBindTexture(GL_TEXTURE_2D, imeg);



	//up to window

	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2d(0.25, 0.75);
	glVertex3d(index, y / 2, z / 2);
	glTexCoord2d(0.75, 0.75);
	glVertex3d(index, y / 2, -z / 2);
	glTexCoord2d(0.75, 1);
	glVertex3d(index, y, -z / 2);
	glTexCoord2d(0.25, 1);
	glVertex3d(index, y, z / 2);

	glEnd();
	glPopMatrix();

	//down to window

	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2d(0.25, 0);
	glVertex3d(index, -y, z / 2);
	glTexCoord2d(0.75, 0);
	glVertex3d(index, -y, -z / 2);
	glTexCoord2d(0.75, 0.4);
	glVertex3d(index, -y / 5, -z / 2);
	glTexCoord2d(0.25, 0.4);
	glVertex3d(index, -y / 5, z / 2);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);//window
	glColor4f(1, 1, 1, 0.5);
	glVertex3d(index, -y / 5, z / 2);
	glVertex3d(index, -y / 5, -z / 2);
	glVertex3d(index, y / 2, -z / 2);
	glVertex3d(index, y / 2, z / 2);
	glEnd();
	glDisable(GL_BLEND);
	glPopMatrix();

}

void controll::rightLeftControllWall(double index, double y, double z, int imeg) {

	glBindTexture(GL_TEXTURE_2D, imeg);



	glPushMatrix();

	glBegin(GL_QUADS);//right wall
	glTexCoord2d(0.755, 0);
	glVertex3d(index, -y, -z / 2);
	glTexCoord2d(1, 0);
	glVertex3d(index, -y, -z);
	glTexCoord2d(1, 1);
	glVertex3d(index, y, -z);
	glTexCoord2d(0.755, 1);
	glVertex3d(index, y, -z / 2);

	glEnd();
	glPopMatrix();

	//up to window

	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2d(0.25, 0.75);
	glVertex3d(index, y / 2, z / 2);
	glTexCoord2d(0.75, 0.75);
	glVertex3d(index, y / 2, -z / 2);
	glTexCoord2d(0.75, 1);
	glVertex3d(index, y, -z / 2);
	glTexCoord2d(0.25, 1);
	glVertex3d(index, y, z / 2);

	glEnd();
	glPopMatrix();

	//down to window

	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2d(0.25, 0);
	glVertex3d(index, -y, z / 2);
	glTexCoord2d(0.75, 0);
	glVertex3d(index, -y, -z / 2);
	glTexCoord2d(0.75, 0.4);
	glVertex3d(index, -y / 5, -z / 2);
	glTexCoord2d(0.25, 0.4);
	glVertex3d(index, -y / 5, z / 2);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);//window
	glColor4f(1, 1, 1, 0.5);
	glVertex3d(index, -y / 5, z / 2);
	glVertex3d(index, -y / 5, -z / 2);
	glVertex3d(index, y / 2, -z / 2);
	glVertex3d(index, y / 2, z / 2);
	glEnd();
	glDisable(GL_BLEND);
	glPopMatrix();

}



