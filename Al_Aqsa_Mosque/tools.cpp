#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
//#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <texture.h>
#include  "camera.h"
#include "tools.h"

void tools::WallWithoutDoor(double x, double y, double index, int imeg) {
	//glColor3ub(255, 255, 255);

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, imeg);
	glBegin(GL_QUADS); //Wall
	glNormal3f(0, 0, (index<0 ? 1 : -1));                               //normal
	glTexCoord2d(0, 0);
	glVertex3d(-x, -y, index);
	glTexCoord2d(1, 0);
	glVertex3d(x, -y, index);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, index);
	glTexCoord2d(0, 1);
	glVertex3d(-x, y, index);

	glEnd();
	glPopMatrix();

}

void tools::WallWithDoor(double x, double y, double index, int imeg, bool openDoor) {
	//glColor3ub(255, 255, 255);
	glBindTexture(GL_TEXTURE_2D, imeg);
	glPushMatrix();
	if (openDoor) {
		glTranslated(-35, 0, 0);

	}

	glBegin(GL_QUADS);
	// door
	glNormal3f(0, 0, (index<0 ? 1 : -1));                               //normal
	glTexCoord2d(0.37, 0.21);
	glVertex3d(-x / 2.7, -y / 1.5, index);
	glTexCoord2d(0.63, 0.21);
	glVertex3d(x / 2.7, -y / 1.5, index);
	glTexCoord2d(0.63, 0.75);
	glVertex3d(x / 2.7, y / 2, index);
	glTexCoord2d(0.37, 0.75);
	glVertex3d(-x / 2.7, y / 2, index);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);
	//left wall
	glNormal3f(0, 0, (index<0 ? 1 : -1));                               //normal
	glTexCoord2d(0, 0);
	glVertex3d(-x, -y, index);
	glTexCoord2d(0.37, 0);
	glVertex3d(-x / 2.73, -y, index);
	glTexCoord2d(0.37, 1);
	glVertex3d(-x / 2.73, y, index);
	glTexCoord2d(0, 1);
	glVertex3d(-x, y, index);

	//up to door
	//glNormal3f(0,0,-index/index);                               //normal
	glTexCoord2d(0.37, 0.75);
	glVertex3d(-x / 2.7, y / 2, index);
	glTexCoord2d(0.63, 0.75);
	glVertex3d(x / 2.7, y / 2, index);
	glTexCoord2d(0.63, 1);
	glVertex3d(x / 2.7, y, index);
	glTexCoord2d(0.37, 1);
	glVertex3d(-x / 2.7, y, index);

	//down to door
	//glNormal3f(0,0,-index/index);                               //normal
	glTexCoord2d(0.37, 0.0);
	glVertex3d(-x / 2.7, -y, index);
	glTexCoord2d(0.63, 0.0);
	glVertex3d(x / 2.7, -y, index);
	glTexCoord2d(0.63, 0.21);
	glVertex3d(x / 2.7, -y / 1.5, index);
	glTexCoord2d(0.37, 0.21);
	glVertex3d(-x / 2.7, -y / 1.5, index);

	//right wal
	//glNormal3f(0,0,-index/index);                               //normal
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

void tools::TopDown(double x, double index, double z, int imeg, int imeg2) {
	//glColor3ub(255, 255, 255);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glPushMatrix();//Top
	glBindTexture(GL_TEXTURE_2D, imeg);
	glBegin(GL_QUADS);
	glNormal3f(0, -1, 0);                               //the normal
	glTexCoord2d(0, 0);
	glVertex3d(-x, index, z);
	glTexCoord2d(1, 0);
	glVertex3d(x, index, z);
	glTexCoord2d(1, 3);
	glVertex3d(x, index, -z);
	glTexCoord2d(0, 3);
	glVertex3d(-x, index, -z);
	glEnd();

	//down
	//glColor3ub(255, 255, 255);

	glBindTexture(GL_TEXTURE_2D, imeg2);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);                                  //normal
	glTexCoord2d(0, 0);
	glVertex3d(-x, -index + 15, z);
	glTexCoord2d(1, 0);
	glVertex3d(x, -index + 15, z);
	glTexCoord2d(1, 3);
	glVertex3d(x, -index + 15, -z);
	glTexCoord2d(0, 3);
	glVertex3d(-x, -index + 15, -z);

	glEnd();
	glPopMatrix();

}

void tools::WallRightLeftWithoutWindowInside(double index, double y, double z, int imeg) {
	glPushMatrix();
	//glColor3ub(255, 255, 255);
	glBindTexture(GL_TEXTURE_2D, imeg);
	glBegin(GL_QUADS);//Wall
	glNormal3f((index<0 ? 1 : -1), 0, 0);                               //normal
	glTexCoord2d(0, 0);
	glVertex3d(index, -y, z);
	glTexCoord2d(1, 0);
	glVertex3d(index, -y, -z);
	glTexCoord2d(1, 1);
	glVertex3d(-index, y, -z);
	glTexCoord2d(0, 1);
	glVertex3d(index, y, z);

	glEnd();
	glPopMatrix();
}

void tools::WallRightLeftWithoutWindowOutside(double index, double y, double z, int imeg) {
	//glColor3ub(255, 255, 255);
	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, imeg);
	glBegin(GL_QUADS);//Wall
	glNormal3f((index<0 ? 1 : -1), 0, 0);                               //normal
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

void tools::WallRightLeftWithWindow(double index, double y, double z, int imeg) {

	glBindTexture(GL_TEXTURE_2D, imeg);

	glPushMatrix();
	glBegin(GL_QUADS);//left wall
	glNormal3f((index<0 ? 1 : -1), 0, 0);                               //normal
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
	glNormal3f((index<0 ? 1 : -1), 0, 0);                               //normal
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

	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);//window
	glNormal3f((index<0 ? 1 : -1), 0, 0);                               //normal
	glColor4f(1, 1, 1, 0.5);
	glVertex3d(index, -y / 5, z / 2);
	glVertex3d(index, -y / 5, -z / 2);
	glVertex3d(index, y / 2, -z / 2);
	glVertex3d(index, y / 2, z / 2);
	glEnd();
	glDisable(GL_BLEND);
	glPopMatrix();

	//up to window

	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f((index<0 ? 1 : -1), 0, 0);                               //normal
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
	glNormal3f((index<0 ? 1 : -1), 0, 0);                               //normal
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

void tools::WallRightLeftWithWindowHole(double index, double y, double z, int imeg) {
	//glColor3ub(255, 255, 255);
	glBindTexture(GL_TEXTURE_2D, imeg);
	glPushMatrix();
	glBegin(GL_QUADS);//left wall
	glNormal3f((index<0 ? 1 : -1), 0, 0);                               //normal
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
	glNormal3f((index<0 ? 1 : -1), 0, 0);                               //normal
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
	glNormal3f((index<0 ? 1 : -1), 0, 0);                               //normal
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
	glNormal3f((index<0 ? 1 : -1), 0, 0);                               //normal
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

void tools::WallWithDoorHole(double x, double y, double index, int imeg) {
	glBindTexture(GL_TEXTURE_2D, imeg);
	//glColor3ub(120, 207, 218);

	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f(0, 0, (index<0 ? 1 : -1));                               //normal
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
	glNormal3f(0, 0, (index<0 ? 1 : -1));                               //normal
	glTexCoord2d(0.37, 0.75);
	glVertex3d(-x / 2.7, y / 2, index);
	glTexCoord2d(0.63, 0.75);
	glVertex3d(x / 2.7, y / 2, index);
	glTexCoord2d(0.63, 1);
	glVertex3d(x / 2.7, y, index);
	glTexCoord2d(0.37, 1);
	glVertex3d(-x / 2.7, y, index);

	//down to door
	glNormal3f(0, 0, (index<0 ? 1 : -1));                               //normal
	glTexCoord2d(0.37, 0.0);
	glVertex3d(-x / 2.7, -y, index);
	glTexCoord2d(0.63, 0.0);
	glVertex3d(x / 2.7, -y, index);
	glTexCoord2d(0.63, 0.21);
	glVertex3d(x / 2.7, -y / 1.5, index);
	glTexCoord2d(0.37, 0.21);
	glVertex3d(-x / 2.7, -y / 1.5, index);

	//right wal
	glNormal3f(0, 0, (index<0 ? 1 : -1));                               //normal
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