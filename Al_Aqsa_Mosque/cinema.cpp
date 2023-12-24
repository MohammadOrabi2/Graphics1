#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
//#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <texture.h>
#include  "camera.h"
#include "cinema.h"
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>

#include <fstream>

#include <mmsystem.h>
#include "point.h"
#include "view.h"



	void cinema::WallRightLeftWithWindowHole(double index, double y, double z, int imeg) {
		glColor3ub(120, 207, 218);
		glBindTexture(GL_TEXTURE_2D, imeg);
		glPushMatrix();
		glBegin(GL_QUADS);//left wall
		glTexCoord2d(0, 0);
		glVertex3d(index, -y, z);
		glTexCoord2d(0.25, 0);
		glVertex3d(index, -y, z / 2);
		glTexCoord2d(0.25, 1);
		glVertex3d(index, y, z / 2);
		glTexCoord2d(0, 1);
		glVertex3d(index, y, z);
		glEnd();
		glPopMatrix();

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
	}

	void cinema::WallWithDoorHole(double x, double y, double index, int imeg) {
		glBindTexture(GL_TEXTURE_2D, imeg);
		glColor3ub(120, 207, 218);

		glPushMatrix();
		glBegin(GL_QUADS);
		//left wall
		glTexCoord2d(0, 0);
		glVertex3d(-x, -y, index);
		glTexCoord2d(0.37, 0);
		glVertex3d(-x / 2.73, -y, index);
		glTexCoord2d(0.37, 1);
		glVertex3d(-x / 2.73, y, index);
		glTexCoord2d(0, 1);
		glVertex3d(-x, y, index);

		//up to door
		glTexCoord2d(0.37, 0.75);
		glVertex3d(-x / 2.7, y / 2, index);
		glTexCoord2d(0.63, 0.75);
		glVertex3d(x / 2.7, y / 2, index);
		glTexCoord2d(0.63, 1);
		glVertex3d(x / 2.7, y, index);
		glTexCoord2d(0.37, 1);
		glVertex3d(-x / 2.7, y, index);

		//down to door
		glTexCoord2d(0.37, 0.0);
		glVertex3d(-x / 2.7, -y, index);
		glTexCoord2d(0.63, 0.0);
		glVertex3d(x / 2.7, -y, index);
		glTexCoord2d(0.63, 0.21);
		glVertex3d(x / 2.7, -y / 1.5, index);
		glTexCoord2d(0.37, 0.21);
		glVertex3d(-x / 2.7, -y / 1.5, index);

		//right wal
		glTexCoord2d(0.63, 0);
		glVertex3d(x / 2.7, -y, index);
		glTexCoord2d(1, 0);
		glVertex3d(x, -y, index);
		glTexCoord2d(1, 1);
		glVertex3d(x, y, index);
		glTexCoord2d(0.63, 1);
		glVertex3d(x / 2.7, y, index);
		glEnd();
		glPopMatrix();
	}

	void cinema::WallRightLeftWithoutWindowInside(double index, double y, double z, int imeg) {
		glColor3ub(120, 207, 218);
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, imeg);
		glBegin(GL_QUADS);//Wall
		glTexCoord2d(0, 0);
		glVertex3d(index, -y, z);
		glTexCoord2d(1, 0);
		glVertex3d(index, -y, -z);
		glTexCoord2d(1, 1);
		glVertex3d(index, y, -z);
		glTexCoord2d(0, 1);
		glVertex3d(index, y, z);
		glEnd();
		glPopMatrix();
	}

	void cinema::screen(double x, double y, double z, bool turnOn) {
		screenShow(x + 0.1, y, z);

		if (turnOn == 1) {

			//if (sound % 6000 == 0) {
			//	PlaySound(TEXT("game2.wav"), NULL, SND_FILENAME | SND_SYNC);
			//}
			glPushMatrix();
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glBegin(GL_QUADS);//screen
			glColor4f(1, 1, 1, 0.3);
			glVertex3d(-x + 0.3, -y / 5, z / 2);
			glVertex3d(-x + 0.3, -y / 5, -z / 2);
			glVertex3d(-x + 0.3, y / 2, -z / 2);
			glVertex3d(-x + 0.3, y / 2, z / 2);

			glEnd();
			glDisable(GL_BLEND);
			glPopMatrix();
		}
		else {
			glPushMatrix();
			glBegin(GL_QUADS);//screen
			glColor3ub(10, 10, 10);
			glVertex3d(-x + 0.3, -y / 5, z / 2);
			glVertex3d(-x + 0.3, -y / 5, -z / 2);
			glVertex3d(-x + 0.3, y / 2, -z / 2);
			glVertex3d(-x + 0.3, y / 2, z / 2);

			glEnd();
			glPopMatrix();
		}
		glPushMatrix();//horizantal down
		glBegin(GL_QUADS);
		glColor3ub(10, 10, 10);
		glVertex3d(-x + 0.3, -y / 5, z / 2);
		glVertex3d(-x + 0.3, -y / 5, -z / 2);
		glVertex3d(-x + 0.3, -y / 4, -z / 2);
		glVertex3d(-x + 0.3, -y / 4, z / 2);

		glEnd();
		glPopMatrix();
		glPushMatrix();
		glBegin(GL_QUADS);//horizantal up
		glColor3ub(10, 10, 10);
		glVertex3d(-x + 0.3, y / 2, z / 2);
		glVertex3d(-x + 0.3, y / 2, -z / 2);
		glVertex3d(-x + 0.3, y / 1.85, -z / 2);
		glVertex3d(-x + 0.3, y / 1.85, z / 2);

		glEnd();
		glPopMatrix();

		glPushMatrix();
		glBegin(GL_QUADS);//vertical right
		glColor3ub(10, 10, 10);
		glVertex3d(-x + 0.3, -y / 4, z / 2);
		glVertex3d(-x + 0.3, -y / 4, z / 1.9);
		glVertex3d(-x + 0.3, y / 1.85, z / 1.9);
		glVertex3d(-x + 0.3, y / 1.85, z / 2);

		glEnd();
		glPopMatrix();

		glPushMatrix();
		glBegin(GL_QUADS);//vertical left
		glColor3ub(10, 10, 10);
		glVertex3d(-x + 0.3, -y / 4, -z / 2);
		glVertex3d(-x + 0.3, -y / 4, -z / 1.9);
		glVertex3d(-x + 0.3, y / 1.85, -z / 1.9);
		glVertex3d(-x + 0.3, y / 1.85, -z / 2);

		glEnd();
		glPopMatrix();
		glPopMatrix();
	}

	void cinema::screenShow(double x, double y, double z) {
		glPushMatrix();
		glTranslated(-x + 0.01, 13, 0);

		glRotated(90, 0, 1, 0);

		glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
		srand(time(0));

		int xx = (rand() % 9 + 1);

		View::DrawSky(Point(-115 + x, -75 + y, 0), Point(x + 10, -75 + y, 0), Point(x + 10, y - 25, 0), Point(-115 + x, y - 25, 0));
		View::DrawGrass(Point(x - 50, -y + 25, 0), 40);
		glColor3f(0, 0, 0);///holes
		View::DrawSolidCircle(Point(-11, 8, 0), 3);//1
		View::DrawSolidCircle(Point(0, 7, 0), 3);//2
		View::DrawSolidCircle(Point(11, 8, 0), 3);//3
		View::DrawSolidCircle(Point(-7, 0, 0), 3);//4
		View::DrawSolidCircle(Point(0, 0, 0), 3);//5
		View::DrawSolidCircle(Point(7, 0, 0), 3);//6
		View::DrawSolidCircle(Point(-11, -8, 0), 3);//7
		View::DrawSolidCircle(Point(0, -7, 0), 3);//8
		View::DrawSolidCircle(Point(11, -8, 0), 3);//9
		glColor3f(1, 1, 1);///heads
		if (xx == 1)
		{
			View::DrawSolidCircle(Point(-11, 8, 0), 2.4);
		}
		else if (xx == 2)
		{
			View::DrawSolidCircle(Point(0, 7, 0), 2.4);
		}
		else if (xx == 3)
		{
			View::DrawSolidCircle(Point(11, 8, 0), 2.4);
		}
		else if (xx == 4)
		{
			View::DrawSolidCircle(Point(-7, 0, 0), 2.4);
		}
		else if (xx == 5)
		{
			View::DrawSolidCircle(Point(0, 0, 0), 2.4);
		}
		else if (xx == 6)
		{
			View::DrawSolidCircle(Point(7, 0, 0), 2.4);
		}
		else if (xx == 7)
		{

			View::DrawSolidCircle(Point(-11, -8, 0), 2.4);
		}
		else if (xx == 8)
		{
			View::DrawSolidCircle(Point(0, -7, 0), 2.4);
		}
		else if (xx == 9)
		{
			View::DrawSolidCircle(Point(11, -8, 0), 2.4);
		}
		glColor3f(0, 0, 0);///nose
		View::DrawSolidCircle(Point(-11, 7, 0), 0.8);//1
		View::DrawSolidCircle(Point(0, 6, 0), 0.8);//2
		View::DrawSolidCircle(Point(11, 7, 0), 0.8);//3
		View::DrawSolidCircle(Point(-7, -1, 0), 0.8);//4
		View::DrawSolidCircle(Point(0, -1, 0), 0.8);//5
		View::DrawSolidCircle(Point(7, -1, 0), 0.8);//6
		View::DrawSolidCircle(Point(-11, -9, 0), 0.8);//7
		View::DrawSolidCircle(Point(0, -8, 0), 0.8);//8
		View::DrawSolidCircle(Point(11, -9, 0), 0.8);//9
													 ///lefteye
		View::DrawSolidCircle(Point(-12, 9, 0), 0.5);//1
		View::DrawSolidCircle(Point(-1, 8, 0), 0.5);//2
		View::DrawSolidCircle(Point(10, 9, 0), 0.5);//3
		View::DrawSolidCircle(Point(-8, 1, 0), 0.5);//4
		View::DrawSolidCircle(Point(-1, 1, 0), 0.5);//5
		View::DrawSolidCircle(Point(6, 1, 0), 0.5);//6
		View::DrawSolidCircle(Point(-12, -7, 0), 0.5);//7
		View::DrawSolidCircle(Point(-1, -6, 0), 0.5);//8
		View::DrawSolidCircle(Point(10, -7, 0), 0.5);//9
													 ////righteye
		View::DrawSolidCircle(Point(-10, 9, 0), 0.5);//1
		View::DrawSolidCircle(Point(1, 8, 0), 0.5);//2
		View::DrawSolidCircle(Point(12, 9, 0), 0.5);//3
		View::DrawSolidCircle(Point(-6, 1, 0), 0.5);//4
		View::DrawSolidCircle(Point(1, 1, 0), 0.5);//5
		View::DrawSolidCircle(Point(8, 1, 0), 0.5);//6
		View::DrawSolidCircle(Point(-10, -7, 0), 0.5);//7
		View::DrawSolidCircle(Point(1, -6, 0), 0.5);//8
		View::DrawSolidCircle(Point(12, -7, 0), 0.5);//9

		glPopMatrix();
	}

	void cinema::sofa(double x, double y, double z, int img) {
		glBindTexture(GL_TEXTURE_2D, img);
		glPushMatrix();
		glScaled(1, 0.8, 1);
		glBegin(GL_QUADS);
		glColor3ub(184, 52, 42);
		glVertex3d(x - 22, y - 80, z + 95);//sit
		glVertex3d(x - 22, y - 80, z + 115);
		glVertex3d(x - 1, y - 80, z + 115);
		glVertex3d(x - 1, y - 80, z + 95);

		glColor3ub(184, 52, 42);
		glVertex3d(x - 22, y - 85, z + 95);//connect to sit
		glVertex3d(x - 22, y - 85, z + 115);
		glVertex3d(x - 22, y - 80, z + 115);
		glVertex3d(x - 22, y - 80, z + 95);

		glColor3ub(184, 52, 42);
		glVertex3d(x - 22, y - 85, z + 95);//sit
		glVertex3d(x - 22, y - 85, z + 115);
		glVertex3d(x - 1, y - 85, z + 115);
		glVertex3d(x - 1, y - 85, z + 95);
		glColor3ub(64, 53, 53);
		glVertex3d(x - 22, y - 100, z + 115);//right hand
		glVertex3d(x - 1, y - 100, z + 115);
		glVertex3d(x - 1, y - 70, z + 115);
		glVertex3d(x - 22, y - 70, z + 115);
		glColor3ub(64, 53, 53);
		glVertex3d(x - 22, y - 100, z + 117);//right hand
		glVertex3d(x - 1, y - 100, z + 117);
		glVertex3d(x - 1, y - 70, z + 117);
		glVertex3d(x - 22, y - 70, z + 117);
		glColor3ub(64, 53, 53);
		glVertex3d(x - 22, y - 70, z + 115);//right hand
		glVertex3d(x - 22, y - 70, z + 117);
		glVertex3d(x - 1, y - 70, z + 117);
		glVertex3d(x - 1, y - 70, z + 115);
		glColor3ub(64, 53, 53);
		glVertex3d(x - 22, y - 100, z + 115);//right hand
		glVertex3d(x - 22, y - 100, z + 117);
		glVertex3d(x - 22, y - 70, z + 117);
		glVertex3d(x - 22, y - 70, z + 115);


		glColor3ub(64, 53, 53);
		glVertex3d(x - 22, y - 100, z + 95);//left hand
		glVertex3d(x - 1, y - 100, z + 95);
		glVertex3d(x - 1, y - 70, z + 95);
		glVertex3d(x - 22, y - 70, z + 95);
		glColor3ub(64, 53, 53);
		glVertex3d(x - 22, y - 100, z + 93);//left hand
		glVertex3d(x - 1, y - 100, z + 93);
		glVertex3d(x - 1, y - 70, z + 93);
		glVertex3d(x - 22, y - 70, z + 93);
		glColor3ub(64, 53, 53);
		glVertex3d(x - 22, y - 70, z + 93);//left hand
		glVertex3d(x - 22, y - 70, z + 95);
		glVertex3d(x - 1, y - 70, z + 95);
		glVertex3d(x - 1, y - 70, z + 93);
		glColor3ub(64, 53, 53);
		glVertex3d(x - 22, y - 100, z + 93);//left hand
		glVertex3d(x - 22, y - 100, z + 95);
		glVertex3d(x - 22, y - 70, z + 95);
		glVertex3d(x - 22, y - 70, z + 93);


		glColor3ub(174, 84, 84);
		glVertex3d(x - 1, y - 80, z + 95);//back
		glVertex3d(x - 1, y - 80, z + 115);
		glVertex3d(x - 1, y - 50, z + 115);
		glVertex3d(x - 1, y - 50, z + 95);

		glColor4f(1, 1, 1,1);
		glTexCoord2d(0, 0);
		glVertex3d(x - 10, y - 80, z + 95);//back
		glTexCoord2d(1, 0);
		glVertex3d(x - 10, y - 80, z + 115);
		glTexCoord2d(1, 1);
		glVertex3d(x - 1, y - 50, z + 115);
		glTexCoord2d(0, 1);
		glVertex3d(x - 1, y - 50, z + 95);
		glEnd();

		glBegin(GL_TRIANGLES);//back

		glColor3ub(3, 3, 3);
		glVertex3d(x - 1, y - 50, z + 115);
		glVertex3d(x - 1, y - 80, z + 115);
		glVertex3d(x - 10, y - 80, z + 95);

		glColor3ub(3, 3, 3);
		glVertex3d(x - 1, y - 50, z + 95);
		glVertex3d(x - 1, y - 80, z + 95);
		glVertex3d(x - 10, y - 80, z + 115);

		glEnd();

		glPushMatrix();
		dra(x, y, z);
		glTranslated(0, 0, -22);
		dra(x, y, z);
		glPopMatrix();

		glPopMatrix();

	}

	void cinema::table(double x, double y, double z, int img) {
		glBindTexture(GL_TEXTURE_2D, img);

		glPushMatrix();
		glScaled(1, 0.8, 1);
		glColor3ub(255, 255, 255);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(x - 17, y - 70, z + 5);//face
		glTexCoord2d(0, 1);

		glTexCoord2d(0, 1);
		glVertex3d(x - 17, y - 70, z + 20);
		glTexCoord2d(1, 1);
		glVertex3d(x - 2, y - 70, z + 20);
		glTexCoord2d(1, 0);
		glVertex3d(x - 2, y - 70, z + 5);

		glColor3ub(255, 255, 255);
		glTexCoord2d(0, 0);
		glVertex3d(x - 17, y - 75, z + 5);//face
		glTexCoord2d(0, 1);

		glVertex3d(x - 17, y - 75, z + 20);
		glTexCoord2d(1, 1);

		glVertex3d(x - 2, y - 75, z + 20);
		glTexCoord2d(1, 0);

		glVertex3d(x - 2, y - 75, z + 5);

		glTexCoord2d(0, 0);
		glVertex3d(x - 17, y - 75, z + 5);//face
		glTexCoord2d(0, 1);

		glVertex3d(x - 17, y - 75, z + 20);
		glTexCoord2d(1, 1);

		glVertex3d(x - 17, y - 70, z + 20);
		glTexCoord2d(1, 0);

		glVertex3d(x - 17, y - 70, z + 5);
		glTexCoord2d(0, 0);
		glVertex3d(x - 17, y - 75, z + 20);//face
		glTexCoord2d(0, 1);

		glVertex3d(x - 2, y - 75, z + 20);
		glTexCoord2d(1, 1);

		glVertex3d(x - 2, y - 70, z + 20);
		glTexCoord2d(1, 0);

		glVertex3d(x - 17, y - 70, z + 20);

		glTexCoord2d(0, 0);
		glVertex3d(x - 2, y - 75, z + 5);//face
		glTexCoord2d(0, 1);

		glVertex3d(x - 2, y - 75, z + 20);
		glTexCoord2d(1, 1);

		glVertex3d(x - 2, y - 70, z + 20);
		glTexCoord2d(1, 0);

		glVertex3d(x - 2, y - 70, z + 5);

		glTexCoord2d(0, 0);
		glVertex3d(x - 17, y - 75, z + 5);//face
		glTexCoord2d(0, 1);

		glVertex3d(x - 2, y - 75, z + 5);
		glTexCoord2d(1, 1);

		glVertex3d(x - 2, y - 70, z + 5);
		glTexCoord2d(1, 0);

		glVertex3d(x - 17, y - 70, z + 5);
		/////////////////////////////////////////////////////////////////////
		glTexCoord2d(0, 0);
		glVertex3d(x - 17, y - 100, z + 7);//leg1
		glTexCoord2d(0, 1);

		glVertex3d(x - 17, y - 100, z + 5);
		glTexCoord2d(1, 1);

		glVertex3d(x - 15, y - 100, z + 5);
		glTexCoord2d(1, 0);

		glVertex3d(x - 15, y - 100, z + 7);
		glTexCoord2d(0, 0);
		glVertex3d(x - 17, y - 75, z + 7);//leg1
		glTexCoord2d(0, 1);

		glVertex3d(x - 17, y - 75, z + 5);
		glTexCoord2d(1, 1);

		glVertex3d(x - 15, y - 75, z + 5);
		glTexCoord2d(1, 0);

		glVertex3d(x - 15, y - 75, z + 7);
		/////////////////////////////////////
		glTexCoord2d(0, 0);
		glVertex3d(x - 17, y - 100, z + 5);//leg1
		glTexCoord2d(0, 1);

		glVertex3d(x - 17, y - 100, z + 7);
		glTexCoord2d(1, 1);

		glVertex3d(x - 17, y - 75, z + 7);
		glTexCoord2d(1, 0);

		glVertex3d(x - 17, y - 75, z + 5);
		glTexCoord2d(0, 0);
		glVertex3d(x - 15, y - 100, z + 5);//leg1
		glTexCoord2d(0, 1);

		glVertex3d(x - 15, y - 100, z + 7);
		glTexCoord2d(1, 1);

		glVertex3d(x - 15, y - 75, z + 7);
		glTexCoord2d(1, 0);

		glVertex3d(x - 15, y - 75, z + 5);
		glTexCoord2d(0, 0);
		glVertex3d(x - 17, y - 100, z + 7);//leg1
		glTexCoord2d(0, 1);

		glVertex3d(x - 15, y - 100, z + 7);
		glTexCoord2d(1, 1);

		glVertex3d(x - 15, y - 75, z + 7);
		glTexCoord2d(1, 0);

		glVertex3d(x - 17, y - 75, z + 7);
		glTexCoord2d(0, 0);
		glVertex3d(x - 17, y - 100, z + 5);//leg1
		glTexCoord2d(0, 1);

		glVertex3d(x - 15, y - 100, z + 5);
		glTexCoord2d(1, 1);

		glVertex3d(x - 15, y - 75, z + 5);
		glTexCoord2d(1, 0);

		glVertex3d(x - 17, y - 75, z + 5);
		////////////////////////////////////////////////////////////////
		glTexCoord2d(0, 0);
		glVertex3d(x - 17, y - 100, z + 20);//leg2
		glTexCoord2d(0, 1);

		glVertex3d(x - 17, y - 100, z + 18);
		glTexCoord2d(1, 1);

		glVertex3d(x - 15, y - 100, z + 18);
		glTexCoord2d(1, 0);

		glVertex3d(x - 15, y - 100, z + 20);
		glTexCoord2d(0, 0);
		glVertex3d(x - 17, y - 75, z + 20);//leg2
		glTexCoord2d(0, 1);

		glVertex3d(x - 17, y - 75, z + 18);
		glTexCoord2d(1, 1);

		glVertex3d(x - 15, y - 75, z + 18);
		glTexCoord2d(1, 0);

		glVertex3d(x - 15, y - 75, z + 20);
		/////////////////////////////////////
		glTexCoord2d(0, 0);
		glVertex3d(x - 17, y - 100, z + 18);//leg2
		glTexCoord2d(0, 1);

		glVertex3d(x - 17, y - 100, z + 20);
		glTexCoord2d(1, 1);

		glVertex3d(x - 17, y - 75, z + 20);
		glTexCoord2d(1, 0);

		glVertex3d(x - 17, y - 75, z + 18);
		glTexCoord2d(0, 0);
		glVertex3d(x - 15, y - 100, z + 18);//leg2
		glTexCoord2d(0, 1);

		glVertex3d(x - 15, y - 100, z + 20);
		glTexCoord2d(1, 1);

		glVertex3d(x - 15, y - 75, z + 20);
		glTexCoord2d(1, 0);

		glVertex3d(x - 15, y - 75, z + 18);
		glTexCoord2d(0, 0);
		glVertex3d(x - 17, y - 100, z + 20);//leg2
		glTexCoord2d(0, 1);

		glVertex3d(x - 15, y - 100, z + 20);
		glTexCoord2d(1, 1);

		glVertex3d(x - 15, y - 75, z + 20);
		glTexCoord2d(1, 0);

		glVertex3d(x - 17, y - 75, z + 20);
		glTexCoord2d(0, 0);
		glVertex3d(x - 17, y - 100, z + 18);//leg2
		glTexCoord2d(0, 1);

		glVertex3d(x - 15, y - 100, z + 18);
		glTexCoord2d(1, 1);

		glVertex3d(x - 15, y - 75, z + 18);
		glTexCoord2d(1, 0);

		glVertex3d(x - 17, y - 75, z + 18);

		//////////////////////////////////////////////////////////////////////////////
		glTexCoord2d(0, 0);
		glVertex3d(x - 4, y - 100, z + 20);//leg3
		glTexCoord2d(0, 1);

		glVertex3d(x - 4, y - 100, z + 18);
		glTexCoord2d(1, 1);

		glVertex3d(x - 2, y - 100, z + 18);
		glTexCoord2d(1, 0);

		glVertex3d(x - 2, y - 100, z + 20);
		glTexCoord2d(0, 0);
		glVertex3d(x - 4, y - 75, z + 20);//leg3
		glTexCoord2d(0, 1);

		glVertex3d(x - 4, y - 75, z + 18);
		glTexCoord2d(1, 1);

		glVertex3d(x - 2, y - 75, z + 18);
		glTexCoord2d(1, 0);

		glVertex3d(x - 2, y - 75, z + 20);
		/////////////////////////////////////
		glTexCoord2d(0, 0);
		glVertex3d(x - 4, y - 100, z + 18);//leg3
		glTexCoord2d(0, 1);

		glVertex3d(x - 4, y - 100, z + 20);
		glTexCoord2d(1, 1);

		glVertex3d(x - 4, y - 75, z + 20);
		glTexCoord2d(1, 0);

		glVertex3d(x - 4, y - 75, z + 18);
		glTexCoord2d(0, 0);
		glVertex3d(x - 2, y - 100, z + 18);//leg3
		glTexCoord2d(0, 1);

		glVertex3d(x - 2, y - 100, z + 20);
		glTexCoord2d(1, 1);

		glVertex3d(x - 2, y - 75, z + 20);
		glTexCoord2d(1, 0);

		glVertex3d(x - 2, y - 75, z + 18);
		glTexCoord2d(0, 0);
		glVertex3d(x - 4, y - 100, z + 20);//leg3
		glTexCoord2d(0, 1);

		glVertex3d(x - 2, y - 100, z + 20);
		glTexCoord2d(1, 1);

		glVertex3d(x - 2, y - 75, z + 20);
		glTexCoord2d(1, 0);

		glVertex3d(x - 4, y - 75, z + 20);
		glTexCoord2d(0, 0);
		glVertex3d(x - 4, y - 100, z + 18);//leg3
		glTexCoord2d(0, 1);

		glVertex3d(x - 2, y - 100, z + 18);
		glTexCoord2d(1, 1);

		glVertex3d(x - 2, y - 75, z + 18);
		glTexCoord2d(1, 0);

		glVertex3d(x - 2, y - 75, z + 18);

		//////////////////////////////////////////////////////////////////////////////
		glTexCoord2d(0, 0);
		glVertex3d(x - 4, y - 100, z + 7);//leg4
		glTexCoord2d(0, 1);

		glVertex3d(x - 4, y - 100, z + 5);
		glTexCoord2d(1, 1);

		glVertex3d(x - 2, y - 100, z + 5);
		glTexCoord2d(1, 0);

		glVertex3d(x - 2, y - 100, z + 7);
		glTexCoord2d(0, 0);
		glVertex3d(x - 4, y - 75, z + 7);//leg4
		glTexCoord2d(0, 1);

		glVertex3d(x - 4, y - 75, z + 5);
		glTexCoord2d(1, 1);

		glVertex3d(x - 2, y - 75, z + 5);
		glTexCoord2d(1, 0);

		glVertex3d(x - 2, y - 75, z + 7);
		/////////////////////////////////////
		glTexCoord2d(0, 0);
		glVertex3d(x - 4, y - 100, z + 5);//leg4
		glTexCoord2d(0, 1);

		glVertex3d(x - 4, y - 100, z + 7);
		glTexCoord2d(1, 1);

		glVertex3d(x - 4, y - 75, z + 7);
		glTexCoord2d(1, 0);

		glVertex3d(x - 4, y - 75, z + 5);
		glTexCoord2d(0, 0);
		glVertex3d(x - 2, y - 100, z + 5);//leg4
		glTexCoord2d(0, 1);

		glVertex3d(x - 2, y - 100, z + 7);
		glTexCoord2d(1, 1);

		glVertex3d(x - 2, y - 75, z + 7);
		glTexCoord2d(1, 0);

		glVertex3d(x - 2, y - 75, z + 5);
		glTexCoord2d(0, 0);
		glVertex3d(x - 4, y - 100, z + 7);//leg4
		glTexCoord2d(0, 1);

		glVertex3d(x - 2, y - 100, z + 7);
		glTexCoord2d(1, 1);

		glVertex3d(x - 2, y - 75, z + 7);
		glTexCoord2d(1, 0);

		glVertex3d(x - 4, y - 75, z + 7);
		glTexCoord2d(0, 0);
		glVertex3d(x - 4, y - 100, z + 5);//leg4
		glTexCoord2d(0, 1);

		glVertex3d(x - 2, y - 100, z + 5);
		glTexCoord2d(1, 1);

		glVertex3d(x - 2, y - 75, z + 5);
		glTexCoord2d(1, 0);

		glVertex3d(x - 2, y - 75, z + 5);

		glEnd();
		glPopMatrix();
	}

	void cinema::vasefun(double x, double y, double z) {
		glPushMatrix();
		glScaled(1, 0.8, 1);
		glBegin(GL_TRIANGLE_FAN);

		glVertex3d(x - 7, y - 70, z + 13);

		glVertex3d(x - 17, y - 62, z + 17);
		glVertex3d(x - 2, y - 62, z + 17);

		glVertex3d(x - 17, y - 62, z + 17);
		glVertex3d(x - 10, y - 62, z + 5);

		glVertex3d(x - 10, y - 62, z + 5);
		glVertex3d(x - 2, y - 62, z + 17);


		glEnd();
		glPopMatrix();
	}

	GLUquadric* quadric = gluNewQuadric();

	void cinema::dra(double x, double y, double z)
	{
		glColor3ub(244, 109, 99);
		glPushMatrix();
		glScaled(1, 1, 1);
		glPushMatrix();
		glTranslated(77 - x, -70 + y, z + 116);
		glRotated(90, 0, 1, 0);
		glColor3ub(243, 67, 54);
		gluCylinder(quadric, 2.0, 2.0, x - 28, 32, 70);
		gluSphere(quadric, 3.0, 16, 16);
		glPopMatrix();
		glPopMatrix();
	}



