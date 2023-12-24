#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
//#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <texture.h>
#include  "camera.h"
#include "road.h"

void road::road1(int imeg) {
	int sizeZ = 20000, size = 500;
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, imeg);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-size, 0, -sizeZ);
	glTexCoord2d(1, 0);
	glVertex3d(size, 0, -sizeZ);
	glTexCoord2d(1, 70);
	glVertex3d(size, 0, 0);
	glTexCoord2d(0, 70);
	glVertex3d(-size, 0, 0);
	glEnd();
	glPopMatrix();
}
void road::roadRight(int imeg, int repX, int repY) {
	int sizeZ = 20000, size = 30000;
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, imeg);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(500, 0, -sizeZ);
	glTexCoord2d(repX, 0);
	glVertex3d(size, 0, -sizeZ);
	glTexCoord2d(repX, repY);
	glVertex3d(size, 0, 0);
	glTexCoord2d(0, repY);
	glVertex3d(500, 0, 0);
	glEnd();
	glPopMatrix();
}
void road::roadLeft(int imeg) {
	int sizeZ = 20000, size = 30000;
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, imeg);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-500, 0, -sizeZ);
	glTexCoord2d(100, 0);
	glVertex3d(-size, 0, -sizeZ);
	glTexCoord2d(100, 80);
	glVertex3d(-size, 0, 0);
	glTexCoord2d(0, 80);
	glVertex3d(-500, 0, 0);
	glEnd();
	glPopMatrix();
}
void road::roadBetween(int imeg, int imeg2) {
	int sizeZ = -3000, size = 500;
	int size2 = 30000;
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, imeg);
	//left
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-size, 0, 0);
	glTexCoord2d(1, 0);
	glVertex3d(-size + 300, 0, 0);
	glTexCoord2d(1, 1);
	glVertex3d(-size + 300, size - 300, 0);
	glTexCoord2d(0, 1);
	glVertex3d(-size, size - 300, 0);
	glEnd();
	//right
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(+size, 0, 0);
	glTexCoord2d(1, 0);
	glVertex3d(+size - 300, 0, 0);
	glTexCoord2d(1, 1);
	glVertex3d(+size - 300, size - 300, 0);
	glTexCoord2d(0, 1);
	glVertex3d(+size, size - 300, 0);
	glEnd();
	//up
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-size, size - 300, 0);
	glTexCoord2d(2, 0);
	glVertex3d(+size, size - 300, 0);
	glTexCoord2d(2, 1);
	glVertex3d(+size, size, 0);
	glTexCoord2d(0, 1);
	glVertex3d(-size, size, 0);
	glEnd();
	//leftright
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-500, 0, 0);
	glTexCoord2d(40, 0);
	glVertex3d(-size2, 0, 0);
	glTexCoord2d(40, 3);
	glVertex3d(-size2, size, 0);
	glTexCoord2d(0, 3);
	glVertex3d(-500, size, 0);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(+500, 0, 0);
	glTexCoord2d(40, 0);
	glVertex3d(+size2, 0, 0);
	glTexCoord2d(40, 3);
	glVertex3d(+size2, size, 0);
	glTexCoord2d(0, 3);
	glVertex3d(+500, size, 0);
	glEnd();
	//left
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-size, 0, sizeZ);
	glTexCoord2d(1, 0);
	glVertex3d(-size + 300, 0, sizeZ);
	glTexCoord2d(1, 1);
	glVertex3d(-size + 300, size - 300, sizeZ);
	glTexCoord2d(0, 1);
	glVertex3d(-size, size - 300, sizeZ);
	glEnd();
	//right
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(+size, 0, sizeZ);
	glTexCoord2d(1, 0);
	glVertex3d(+size - 300, 0, sizeZ);
	glTexCoord2d(1, 1);
	glVertex3d(+size - 300, size - 300, sizeZ);
	glTexCoord2d(0, 1);
	glVertex3d(+size, size - 300, sizeZ);
	glEnd();
	//up
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-size, size - 300, sizeZ);
	glTexCoord2d(2, 0);
	glVertex3d(+size, size - 300, sizeZ);
	glTexCoord2d(2, 1);
	glVertex3d(+size, size, sizeZ);
	glTexCoord2d(0, 1);
	glVertex3d(-size, size, sizeZ);
	glEnd();
	//leftright
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-500, 0, sizeZ);
	glTexCoord2d(40, 0);
	glVertex3d(-size2, 0, sizeZ);
	glTexCoord2d(40, 3);
	glVertex3d(-size2, size, sizeZ);
	glTexCoord2d(0, 3);
	glVertex3d(-500, size, sizeZ);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(+500, 0, sizeZ);
	glTexCoord2d(40, 0);
	glVertex3d(+size2, 0, sizeZ);
	glTexCoord2d(40, 3);
	glVertex3d(+size2, size, sizeZ);
	glTexCoord2d(0, 3);
	glVertex3d(+500, size, sizeZ);
	glEnd();
	//roadup
	glBindTexture(GL_TEXTURE_2D, imeg);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-size2, size, 0);
	glTexCoord2d(80, 0);
	glVertex3d(+size2, size, 0);
	glTexCoord2d(80, 3);
	glVertex3d(+size2, size, sizeZ);
	glTexCoord2d(0, 3);
	glVertex3d(-size2, size, sizeZ);
	glEnd();
	//leftinsid
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-size + 300, 0, 0);
	glTexCoord2d(2, 0);
	glVertex3d(-size + 300, 0, sizeZ);
	glTexCoord2d(2, 1);
	glVertex3d(-size + 300, size - 300, sizeZ);
	glTexCoord2d(0, 1);
	glVertex3d(-size + 300, size - 300, 0);
	glEnd();

	//rightinside
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(+size - 300, 0, sizeZ);
	glTexCoord2d(2, 0);
	glVertex3d(+size - 300, 0, 0);
	glTexCoord2d(2, 1);
	glVertex3d(+size - 300, size - 300, 0);
	glTexCoord2d(0, 1);
	glVertex3d(+size - 300, size - 300, sizeZ);
	glEnd();

	//up
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-size, size - 300, 0);
	glTexCoord2d(2, 0);
	glVertex3d(-size, size - 300, sizeZ);
	glTexCoord2d(2, 1);
	glVertex3d(+size, size - 300, sizeZ);
	glTexCoord2d(0, 1);
	glVertex3d(+size, size - 300, 0);
	glEnd();
	glPopMatrix();
	//down
	glBindTexture(GL_TEXTURE_2D, imeg2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-size, 0, 0);
	glTexCoord2d(1, 0);
	glVertex3d(size, 0, 0);
	glTexCoord2d(1, 1);
	glVertex3d(+size, 0, sizeZ);
	glTexCoord2d(0, 1);
	glVertex3d(-size, 0, sizeZ);
	glEnd();
	glPopMatrix();
}
 void road::snowTree(int imeg) {
	 int w = 200,h=600;
	 glPushMatrix();
	 glBindTexture(GL_TEXTURE_2D, imeg);
	 glBegin(GL_TRIANGLES);
	 glTexCoord2d(0, 0);
	 glVertex3d(-w, 0, w);
	 glTexCoord2d(0.5, 1);
	 glVertex3d(0, h, 0);
	 glTexCoord2d(1, 0);
	 glVertex3d(w, 0, w);
	 glEnd();
	 //2
	 glBegin(GL_TRIANGLES);
	 glTexCoord2d(0, 0);
	 glVertex3d(-w, 0, -w);
	 glTexCoord2d(0.5, 1);
	 glVertex3d(0, h, 0);
	 glTexCoord2d(1, 0);
	 glVertex3d(w, 0, -w);
	 glEnd();
	 //3
	 glBegin(GL_TRIANGLES);
	 glTexCoord2d(0, 0);
	 glVertex3d(-w, 0, -w);
	 glTexCoord2d(0.5, 1);
	 glVertex3d(0, h, 0);
	 glTexCoord2d(1, 0);
	 glVertex3d(-w, 0, w);
	 glEnd();
	 //4
	 glBegin(GL_TRIANGLES);
	 glTexCoord2d(0, 0);
	 glVertex3d(w, 0, -w);
	 glTexCoord2d(0.5, 1);
	 glVertex3d(0, h, 0);
	 glTexCoord2d(1, 0);
	 glVertex3d(w, 0, w);
	 glEnd();
	 glPopMatrix();
}
 void road::snowTreeRe(int imeg) {
	 int b = 1300;
	 //10
	 glPushMatrix();
	 road::snowTree(imeg);
	 glRotated(45, 0, 1, 0);
	 road::snowTree(imeg);
	 glPopMatrix();
	 glTranslated(0, 0, -b);
	 glPushMatrix();
	 road::snowTree(imeg);
	 glRotated(45, 0, 1, 0);
	 road::snowTree(imeg);
	 glPopMatrix();
	 glTranslated(0, 0, -b);
	 glPushMatrix();
	 road::snowTree(imeg);
	 glRotated(45, 0, 1, 0);
	 road::snowTree(imeg);
	 glPopMatrix();
	 glTranslated(0, 0, -b);
	 glPushMatrix();
	 road::snowTree(imeg);
	 glRotated(45, 0, 1, 0);
	 road::snowTree(imeg);
	 glPopMatrix();
	 glTranslated(0, 0, -b);
	 glPushMatrix();
	 road::snowTree(imeg);
	 glRotated(45, 0, 1, 0);
	 road::snowTree(imeg);
	 glPopMatrix();
	 glTranslated(0, 0, -b);
	 glPushMatrix();
	 road::snowTree(imeg);
	 glRotated(45, 0, 1, 0);
	 road::snowTree(imeg);
	 glPopMatrix();
	 glTranslated(0, 0, -b);
	 glPushMatrix();
	 road::snowTree(imeg);
	 glRotated(45, 0, 1, 0);
	 road::snowTree(imeg);
	 glPopMatrix();
	 glTranslated(0, 0, -b);
	 glPushMatrix();
	 road::snowTree(imeg);
	 glRotated(45, 0, 1, 0);
	 road::snowTree(imeg);
	 glPopMatrix();
	 glTranslated(0, 0, -b);
	 glPushMatrix();
	 road::snowTree(imeg);
	 glRotated(45, 0, 1, 0);
	 road::snowTree(imeg);
	 glPopMatrix();
	 glTranslated(0, 0, -b);
	 glPushMatrix();
	 road::snowTree(imeg);
	 glRotated(45, 0, 1, 0);
	 road::snowTree(imeg);
	 glPopMatrix();
	 glTranslated(0, 0, -b);
	 //10
	 glPushMatrix();
	 road::snowTree(imeg);
	 glRotated(45, 0, 1, 0);
	 road::snowTree(imeg);
	 glPopMatrix();
	 glTranslated(0, 0, -b);
	 glPushMatrix();
	 road::snowTree(imeg);
	 glRotated(45, 0, 1, 0);
	 road::snowTree(imeg);
	 glPopMatrix();
	 glTranslated(0, 0, -b);
	 glPushMatrix();
	 road::snowTree(imeg);
	 glRotated(45, 0, 1, 0);
	 road::snowTree(imeg);
	 glPopMatrix();
	 glTranslated(0, 0, -b);
	 glPushMatrix();
	 road::snowTree(imeg);
	 glRotated(45, 0, 1, 0);
	 road::snowTree(imeg);
	 glPopMatrix();
	 glTranslated(0, 0, -b);
	 glPushMatrix();
	 road::snowTree(imeg);
	 glRotated(45, 0, 1, 0);
	 road::snowTree(imeg);
	 glPopMatrix();

	
 }

 void road::snowHous(int imeg1, int imeg2, int imeg3) {
	 int w = 700, w2 = 400;
	 glBindTexture(GL_TEXTURE_2D, imeg1);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(+w2, 0, -w);
	 glTexCoord2d(1, 0);
	 glVertex3d(+w2, 0, w);
	 glTexCoord2d(1, 1);
	 glVertex3d(+w2, w2, w);
	 glTexCoord2d(0, 1);
	 glVertex3d(+w2, w2, -w);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-w2, 0, -w);
	 glTexCoord2d(1, 0);
	 glVertex3d(-w2, 0, w);
	 glTexCoord2d(1, 1);
	 glVertex3d(-w2, w2, w);
	 glTexCoord2d(0, 1);
	 glVertex3d(-w2, w2, -w);
	 glEnd();
	 glBindTexture(GL_TEXTURE_2D, imeg2);
	 glBegin(GL_TRIANGLES);
	 glTexCoord2d(0, 0);
	 glVertex3d(+w2, w2, w);
	 glTexCoord2d(0.5, 1);
	 glVertex3d(+w2, w2*1.5, 0);
	 glTexCoord2d(1, 0);
	 glVertex3d(+w2, w2, -w);
	 glEnd();
	 glBegin(GL_TRIANGLES);
	 glTexCoord2d(0, 0);
	 glVertex3d(-w2, w2, w);
	 glTexCoord2d(0.5, 1);
	 glVertex3d(-w2, w2*1.5, 0);
	 glTexCoord2d(1, 0);
	 glVertex3d(-w2, w2, -w);
	 glEnd();
	 glBindTexture(GL_TEXTURE_2D, imeg3);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-w2, w2*1.5, 0);
	 glTexCoord2d(1, 0);
	 glVertex3d(+w2, w2*1.5, 0);
	 glTexCoord2d(1, 1);
	 glVertex3d(+w2, w2, w);
	 glTexCoord2d(0, 1);
	 glVertex3d(-w2, w2, w);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-w2, w2*1.5, 0);
	 glTexCoord2d(1, 0);
	 glVertex3d(+w2, w2*1.5, 0);
	 glTexCoord2d(1, 1);
	 glVertex3d(+w2, w2, -w);
	 glTexCoord2d(0, 1);
	 glVertex3d(-w2, w2, -w);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-w2, 0, w);
	 glTexCoord2d(1, 0);
	 glVertex3d(+w2, 0, w);
	 glTexCoord2d(1, 1);
	 glVertex3d(+w2, w2, w);
	 glTexCoord2d(0, 1);
	 glVertex3d(-w2, w2, w);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-w2, 0, -w);
	 glTexCoord2d(1, 0);
	 glVertex3d(+w2, 0, -w);
	 glTexCoord2d(1, 1);
	 glVertex3d(+w2, w2, -w);
	 glTexCoord2d(0, 1);
	 glVertex3d(-w2, w2, -w);
	 glEnd();
 }

 void road::snowHousRe(int imeg1, int imeg2, int imeg3, int imeg4, int imeg5) {
	 road::snowHous( imeg1,  imeg2,  imeg5);
	 glTranslated(0, 0, -3600);
	 road::snowHous(imeg3, imeg4, imeg5);
	 glTranslated(0, 0, -3600);
	 road::snowHous(imeg1, imeg2, imeg5);
	 glTranslated(0, 0, -3600);
	 road::snowHous(imeg3, imeg4, imeg5);
	 glTranslated(0, 0, -3600);
	 road::snowHous(imeg1, imeg2, imeg5);



 }

 void road::snowRoad(int imeg) {
	 int sizeZ = 20000, size = 400;
	 glPushMatrix();
	 glBindTexture(GL_TEXTURE_2D, imeg);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-size, 0, -sizeZ);
	 glTexCoord2d(1, 0);
	 glVertex3d(size, 0, -sizeZ);
	 glTexCoord2d(1, 70);
	 glVertex3d(size, 0, 0);
	 glTexCoord2d(0, 70);
	 glVertex3d(-size, 0, 0);
	 glEnd();
	 glPopMatrix();
 }

 void road::ad(int imeg, int imeg2,int w,int h) {
	 glPushMatrix();
	 glBindTexture(GL_TEXTURE_2D, imeg);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-w, 200, -10);
	 glTexCoord2d(1, 0);
	 glVertex3d(w, 200, -10);
	 glTexCoord2d(1, 1);
	 glVertex3d(w, h+200, -10);
	 glTexCoord2d(0, 1);
	 glVertex3d(-w, h + 200, -10);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-w, 200, 10);
	 glTexCoord2d(1, 0);
	 glVertex3d(w, 200, 10);
	 glTexCoord2d(1, 1);
	 glVertex3d(w, h + 200, 10);
	 glTexCoord2d(0, 1);
	 glVertex3d(-w, h + 200, 10);
	 glEnd();
	 glPopMatrix();
	 glPushMatrix();
	 glBindTexture(GL_TEXTURE_2D, imeg2);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-w, 200, -10);
	 glTexCoord2d(1, 0);
	 glVertex3d(-w, 200, 10);
	 glTexCoord2d(1, 1);
	 glVertex3d(-w,h + 200, 10);
	 glTexCoord2d(0, 1);
	 glVertex3d(-w, h + 200, -10);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(w, 200, -10);
	 glTexCoord2d(1, 0);
	 glVertex3d(w, 200, 10);
	 glTexCoord2d(1, 1);
	 glVertex3d(w, h + 200, 10);
	 glTexCoord2d(0, 1);
	 glVertex3d(w, h + 200, -10);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-w, 200, -10);
	 glTexCoord2d(1, 0);
	 glVertex3d(w, 200, -10);
	 glTexCoord2d(1, 1);
	 glVertex3d(w, 200, 10);
	 glTexCoord2d(0, 1);
	 glVertex3d(-w, 200, 10);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-w, h + 200, -10);
	 glTexCoord2d(1, 0);
	 glVertex3d(w, h + 200, -10);
	 glTexCoord2d(1, 1);
	 glVertex3d(w, h + 200, 10);
	 glTexCoord2d(0, 1);
	 glVertex3d(-w, h + 200, 10);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-10, 0, -10);
	 glTexCoord2d(1, 0);
	 glVertex3d(10 ,0, -10);
	 glTexCoord2d(1, 1);
	 glVertex3d(10, 200, -10);
	 glTexCoord2d(0, 1);
	 glVertex3d(-10, 200, -10);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-10, 0, 10);
	 glTexCoord2d(1, 0);
	 glVertex3d(10, 0, 10);
	 glTexCoord2d(1, 1);
	 glVertex3d(10, 200, 10);
	 glTexCoord2d(0, 1);
	 glVertex3d(-10, 200, 10);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-10, 0, -10);
	 glTexCoord2d(1, 0);
	 glVertex3d(-10, 0, 10);
	 glTexCoord2d(1, 1);
	 glVertex3d(-10, 200, 10);
	 glTexCoord2d(0, 1);
	 glVertex3d(-10, 200, -10);
	 glEnd();glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-10, 0, -10);
	 glTexCoord2d(1, 0);
	 glVertex3d(-10, 0, 10);
	 glTexCoord2d(1, 1);
	 glVertex3d(-10, 200, 10);
	 glTexCoord2d(0, 1);
	 glVertex3d(-10, 200, -10);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(10, 0, -10);
	 glTexCoord2d(1, 0);
	 glVertex3d(10, 0, 10);
	 glTexCoord2d(1, 1);
	 glVertex3d(10, 200, 10);
	 glTexCoord2d(0, 1);
	 glVertex3d(10, 200, -10);
	 glEnd();

	 glPopMatrix();
 }
 void road::building(int x, int y, int z, int width, int height, int depth, int metal, int image) {
	 glPushMatrix();
	 glBindTexture(GL_TEXTURE_2D, image);
	 glBegin(GL_QUADS);//the bottom face of down mental
	 glTexCoord2d(0, 0);
	 glVertex3d(x, y, z);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width, y, z);
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width, y, z + height);
	 glTexCoord2d(0, 1);
	 glVertex3d(x, y, z + height);
	 glEnd();

	 glBegin(GL_QUADS);//the top face of down mental
	 glTexCoord2d(0, 0);
	 glVertex3d(x, y + depth, z);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width, y + depth, z);
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width, y + depth, z + height);
	 glTexCoord2d(0, 1);
	 glVertex3d(x, y + depth, z + height);
	 glEnd();

	 glBegin(GL_QUADS);//the front face of down mental
	 glTexCoord2d(0, 0);
	 glVertex3d(x, y + depth, z + height);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width, y + depth, z + height);
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width, y, z + height);
	 glTexCoord2d(0, 1);
	 glVertex3d(x, y, z + height);
	 glEnd();


	 glBegin(GL_QUADS);//the  back of down mental
	 glTexCoord2d(0, 0);
	 glVertex3d(x, y + depth, z);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width, y + depth, z);
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width, y, z);
	 glTexCoord2d(0, 1);
	 glVertex3d(x, y, z);
	 glEnd();

	 glBegin(GL_QUADS);//the  right of down mental
	 glTexCoord2d(0, 0);
	 glVertex3d(x + width, y + depth, z + height);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width, y + depth, z);
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width, y, z);
	 glTexCoord2d(0, 1);
	 glVertex3d(x + width, y, z + height);
	 glEnd();

	 glBegin(GL_QUADS);//the  left of down mental
	 glTexCoord2d(0, 0);
	 glVertex3d(x, y + depth, z + height);
	 glTexCoord2d(1, 0);
	 glVertex3d(x, y + depth, z);
	 glTexCoord2d(1, 1);
	 glVertex3d(x, y, z);
	 glTexCoord2d(0, 1);
	 glVertex3d(x, y, z + height);
	 glEnd();
	 glPopMatrix();



 }
  void road::buildingSakhra(int x, int y, int z, int width, int height, int depth,int depth2,int widthOfPice,int heightOfDoor, int carbit,int wall,int wallWithDoor) {
glPushMatrix();
glBindTexture(GL_TEXTURE_2D, carbit);
glBegin(GL_POLYGON); // bottom face

glTexCoord2d(0, 0);    //1
glVertex3d(x, y, z);

glTexCoord2d(10, 0);   //2 (Half the value to ensure twice along S direction)
glVertex3d(x + width / 2, y, z - depth2);

glTexCoord2d(20, 0);   //3 (Twice the value for four times along S direction)
glVertex3d(x + width, y, z);

glTexCoord2d(20, 10);   //4 (Twice the value along S, half along T)
glVertex3d(x + width + depth2, y, z + height / 2);

glTexCoord2d(20, 20);   //5 (Twice the value along S and T)
glVertex3d(x + width, y, z + height);

glTexCoord2d(10, 20);   //6 (Half along S, twice along T)
glVertex3d(x + width / 2, y, z + height + depth2);

glTexCoord2d(0, 20);   //7 (Along T)
glVertex3d(x, y, z + height);

glTexCoord2d(0, 10);   //8 (Half along T)
glVertex3d(x - depth2, y, z + height / 2);

glEnd();
glPopMatrix();






	glBindTexture(GL_TEXTURE_2D, wall);
    glBegin(GL_POLYGON); // top face

    glTexCoord2d(0, 0);//1
    glVertex3d(x,y+depth, z);

	glTexCoord2d(0.5, 0);//2
	glVertex3d(x + width / 2, y+depth, z - depth2);

	glTexCoord2d(1, 0);//3
	glVertex3d(x + width, y+depth, z);

	glTexCoord2d(1, 0.5);//4
	glVertex3d(x + width + depth2, y+depth, z + height / 2);

	glTexCoord2d(1, 1);//5
	glVertex3d(x + width, y+depth, z + height);

	glTexCoord2d(0.5, 1);//6
	glVertex3d(x + width / 2, y+depth, z + height + depth2);
	
	glTexCoord2d(0, 1);//7
	glVertex3d(x, y+depth, z + height);

	glTexCoord2d(0, 0.5);//8
	glVertex3d(x - depth2, y+depth, z + height / 2);

	glEnd();
	 
/*	glBindTexture(GL_TEXTURE_2D, wallWithDoor);
	 glBegin(GL_QUADS);//front 1
	 glTexCoord2d(0, 0);
	 glVertex3d(x + width / 2, y+depth, z + height + depth2);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width, y+depth, z + height);
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width, y, z + height);
	 glTexCoord2d(0, 1);
	 glVertex3d(x + width / 2, y, z + height + depth2);
	 glEnd();
	 */
	 glBindTexture(GL_TEXTURE_2D, wall);
	 glBegin(GL_QUADS);//front 1 up of door
	 glTexCoord2d(0, 0);
	 glVertex3d(x + width / 2, y+depth, z + height + depth2);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width, y+depth, z + height);
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width, y+depth-heightOfDoor, z + height);
	 glTexCoord2d(0, 1);
	 glVertex3d(x + width / 2, y+depth-heightOfDoor, z + height + depth2);
	 glEnd();

	 glBindTexture(GL_TEXTURE_2D, wall);
	 glBegin(GL_QUADS);//front 1 right of door
	 glTexCoord2d(0, 0);
	 glVertex3d(x + width-widthOfPice, y+depth-heightOfDoor, z + height+(depth2 / 6));
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width, y+depth-heightOfDoor, z + height);
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width, y, z + height);
	 glTexCoord2d(0, 1);
	 glVertex3d(x + width-widthOfPice, y, z + height+(depth2 / 6));
	 glEnd();

	 glBindTexture(GL_TEXTURE_2D, wall);
	 glBegin(GL_QUADS);//front 1 left of door
	 glTexCoord2d(0, 0);
	 glVertex3d(x + width / 2, y+depth-heightOfDoor, z + height + depth2);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width / 2+widthOfPice, y+depth-heightOfDoor, z + height+(depth2*(3/4)));
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width / 2+widthOfPice, y,z + height+(depth2*(3/4)));
	 glTexCoord2d(0, 1);
	 glVertex3d(x + width / 2, y, z + height + depth2);
	 glEnd();

	 /*the right code
	 	 glBindTexture(GL_TEXTURE_2D, wall);
	 glBegin(GL_QUADS);//front 1down of door
	 glTexCoord2d(0, 0);
	 glVertex3d(x + width / 2, y+depth-heightOfDoor, z + height + depth2);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width, y+depth-heightOfDoor, z + height);
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width, y, z + height);
	 glTexCoord2d(0, 1);
	 glVertex3d(x + width / 2, y, z + height + depth2);
	 glEnd();
	 */
 /*    glBindTexture(GL_TEXTURE_2D, wallWithDoor);
	 glBegin(GL_QUADS);//front 1 right of door
	 glTexCoord2d(0, 0);
	 glVertex3d(x + width-((x+width-widthOfDoor)/2), y+depth-heightOfDoor, z + height + depth2);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width, y+depth-heightOfDoor, z + height + depth2);
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width, y, z + height + depth2);
	 glTexCoord2d(0, 1);
	 glVertex3d(x + width-((x+width-widthOfDoor)/2), y, z + height + depth2);
	 glEnd();*/


	 glBindTexture(GL_TEXTURE_2D, wall);
	 glBegin(GL_QUADS);//front 2
	 glTexCoord2d(0, 0);
	 glVertex3d(x, y+depth, z + height);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width / 2, y+depth, z + height + depth2);
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width / 2, y, z + height + depth2);
	 glTexCoord2d(0, 1);
	 glVertex3d(x, y, z + height);
	 glEnd();

	 glBindTexture(GL_TEXTURE_2D, wall);
	 glBegin(GL_QUADS);//back1
	 glTexCoord2d(0, 0);
	 glVertex3d(x,y+depth, z);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width / 2, y+depth, z - depth2);
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width / 2, y, z - depth2);
	 glTexCoord2d(0, 1);
	 glVertex3d(x, y, z);
	 glEnd();


	 glBindTexture(GL_TEXTURE_2D, wall);	 
	 glBegin(GL_QUADS);//back2
	 glTexCoord2d(0, 0);
	 glVertex3d(x + width / 2, y+depth, z - depth2);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width, y+depth, z);
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width, y, z);
	 glTexCoord2d(0, 1);
	 glVertex3d(x + width / 2, y, z - depth2);
	 glEnd();


	 glBindTexture(GL_TEXTURE_2D, wall);
	 glBegin(GL_QUADS);//right1
	 glTexCoord2d(0, 0);
	 glVertex3d(x + width + depth2, y+depth, z + height / 2);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width, y+depth, z);
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width, y, z);
	 glTexCoord2d(0, 1);
	 glVertex3d(x + width + depth2, y, z + height / 2);
	 glEnd();


	 glBindTexture(GL_TEXTURE_2D, wall);	 
	 glBegin(GL_QUADS);//right2
	 glTexCoord2d(0, 0);
	 glVertex3d(x + width, y+depth, z + height);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width + depth2, y+depth, z + height / 2);
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width + depth2, y, z + height / 2);
	 glTexCoord2d(0, 1);
	 glVertex3d(x + width, y, z + height);
	 glEnd();
	  
	 glBindTexture(GL_TEXTURE_2D, wall);
	 glBegin(GL_QUADS);//left1
	 glTexCoord2d(0, 0);
	 glVertex3d(x - depth2, y+depth, z + height / 2);
	 glTexCoord2d(1, 0);
	 glVertex3d(x, y+depth, z + height);
	 glTexCoord2d(1, 1);
	 glVertex3d(x, y, z + height);
	 glTexCoord2d(0, 1);
	 glVertex3d(x - depth2, y, z + height / 2);
	 glEnd();


	 glBindTexture(GL_TEXTURE_2D, wall);	 
	 glBegin(GL_QUADS);//left2
	 glTexCoord2d(0, 0);
	 glVertex3d(x,y+depth, z);
	 glTexCoord2d(1, 0);
	 glVertex3d(x - depth2, y+depth, z + height / 2);
	 glTexCoord2d(1, 1);
	 glVertex3d(x - depth2, y, z + height / 2);
	 glTexCoord2d(0, 1);
	 glVertex3d(x, y, z);
	 glEnd();


	 /*
	 glBegin(GL_QUADS);//the  back of down mental
	 glTexCoord2d(0, 0);
	 glVertex3d(x, y + depth, z);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width, y + depth, z);
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width, y, z);
	 glTexCoord2d(0, 1);
	 glVertex3d(x, y, z);
	 glEnd();

	 glBegin(GL_QUADS);//the  right of down mental
	 glTexCoord2d(0, 0);
	 glVertex3d(x + width, y + depth, z + height);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width, y + depth, z);
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width, y, z);
	 glTexCoord2d(0, 1);
	 glVertex3d(x + width, y, z + height);
	 glEnd();

	 glBegin(GL_QUADS);//the  left of down mental
	 glTexCoord2d(0, 0);
	 glVertex3d(x, y + depth, z + height);
	 glTexCoord2d(1, 0);
	 glVertex3d(x, y + depth, z);
	 glTexCoord2d(1, 1);
	 glVertex3d(x, y, z);
	 glTexCoord2d(0, 1);
	 glVertex3d(x, y, z + height);
	 glEnd();*/
	 glPopMatrix();



 }
 void road::street(int x, int y, int z, int width, int height, int depth, int image) {
	 glPushMatrix();
	 glBindTexture(GL_TEXTURE_2D, image);
	 //glTranslated(x,y,z);

	 glBegin(GL_QUADS);///bottom
	 glTexCoord2d(0, 0);
	 glVertex3d(x, y, z);
	 glTexCoord2d(0, 70);
	 glVertex3d(x + width, y, z);
	 glTexCoord2d(1, 70);
	 glVertex3d(x + width, y, z + height);
	 glTexCoord2d(1, 0);
	 glVertex3d(x, y, z + height);
	 glEnd();
	 glPopMatrix();

 }

 void road::trees(int x, int y, int z, int width, int height, int width1, int height1, int depth, int image1, int image2, int n, int v) {
	 glPushMatrix();
	 glBindTexture(GL_TEXTURE_2D, image1);
	 //glTranslated(x,y,z);

	 glBegin(GL_TRIANGLES);///bottom
	 glTexCoord2d(0, 0);
	 glVertex3d(x, y, z);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width, y, z - height);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + 2 * (width), y, z);
	 glEnd();


	 glBegin(GL_TRIANGLES);///front
	 glTexCoord2d(0, 0);
	 glVertex3d(x, y, z);
	 glTexCoord2d(0, 10);
	 glVertex3d(x + width, y + height, z - 0.5*(height));
	 glTexCoord2d(1, 0);
	 glVertex3d(x + 2 * (width), y, z);
	 glEnd();

	 glBegin(GL_TRIANGLES);///right
	 glTexCoord2d(0, 0);
	 glVertex3d(x + 2 * (width), y, z);
	 glTexCoord2d(0, 10);
	 glVertex3d(x + width, y + height, z - 0.5*(height));
	 glTexCoord2d(1, 0);
	 glVertex3d(x + (width), y, z - height);
	 glEnd();

	 glBegin(GL_TRIANGLES);///left
	 glTexCoord2d(0, 0);
	 glVertex3d(x, y, z);
	 glTexCoord2d(0, 10);
	 glVertex3d(x + width, y + height, z - 0.5*(height));
	 glTexCoord2d(1, 0);
	 glVertex3d(x + (width), y, z - height);
	 glEnd();



	 glPushMatrix();
	 glTranslated(0, n, 0);
	 glPushMatrix();
	 glBindTexture(GL_TEXTURE_2D, image1);
	 //glTranslated(x,y,z);

	 glBegin(GL_TRIANGLES);///bottom
	 glTexCoord2d(0, 0);
	 glVertex3d(x, y, z);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width, y, z - height);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + 2 * (width), y, z);
	 glEnd();


	 glBegin(GL_TRIANGLES);///front
	 glTexCoord2d(0, 0);
	 glVertex3d(x, y, z);
	 glTexCoord2d(0, 10);
	 glVertex3d(x + width, y + height, z - 0.5*(height));
	 glTexCoord2d(1, 0);
	 glVertex3d(x + 2 * (width), y, z);
	 glEnd();

	 glBegin(GL_TRIANGLES);///right
	 glTexCoord2d(0, 0);
	 glVertex3d(x + 2 * (width), y, z);
	 glTexCoord2d(0, 10);
	 glVertex3d(x + width, y + height, z - 0.5*(height));
	 glTexCoord2d(1, 0);
	 glVertex3d(x + (width), y, z - height);
	 glEnd();

	 glBegin(GL_TRIANGLES);///left
	 glTexCoord2d(0, 0);
	 glVertex3d(x, y, z);
	 glTexCoord2d(0, 10);
	 glVertex3d(x + width, y + height, z - 0.5*(height));
	 glTexCoord2d(1, 0);
	 glVertex3d(x + (width), y, z - height);
	 glEnd();

	 glPushMatrix();

	 glPushMatrix();
	 glTranslated(0, n, 0);
	 glPushMatrix();
	 glBindTexture(GL_TEXTURE_2D, image1);
	 //glTranslated(x,y,z);

	 glBindTexture(GL_TEXTURE_2D, image1);
	 //glTranslated(x,y,z);

	 glBegin(GL_TRIANGLES);///bottom
	 glTexCoord2d(0, 0);
	 glVertex3d(x, y, z);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width, y, z - height);
	 glTexCoord2d(1, 0);
	 glVertex3d(x + 2 * (width), y, z);
	 glEnd();


	 glBegin(GL_TRIANGLES);///front
	 glTexCoord2d(0, 0);
	 glVertex3d(x, y, z);
	 glTexCoord2d(0, 10);
	 glVertex3d(x + width, y + height, z - 0.5*(height));
	 glTexCoord2d(1, 0);
	 glVertex3d(x + 2 * (width), y, z);
	 glEnd();

	 glBegin(GL_TRIANGLES);///right
	 glTexCoord2d(0, 0);
	 glVertex3d(x + 2 * (width), y, z);
	 glTexCoord2d(0, 10);
	 glVertex3d(x + width, y + height, z - 0.5*(height));
	 glTexCoord2d(1, 0);
	 glVertex3d(x + (width), y, z - height);
	 glEnd();

	 glBegin(GL_TRIANGLES);///left
	 glTexCoord2d(0, 0);
	 glVertex3d(x, y, z);
	 glTexCoord2d(0, 10);
	 glVertex3d(x + width, y + height, z - 0.5*(height));
	 glTexCoord2d(1, 0);
	 glVertex3d(x + (width), y, z - height);
	 glEnd();


	 glPopMatrix();
	 glPopMatrix();

	 glPopMatrix();

	 glPopMatrix();
	 //
	 glPushMatrix();
	 glTranslated(v, n, 0);//////////////////*******************************
	 glPushMatrix();
	 glBindTexture(GL_TEXTURE_2D, image2);////////////////////////////////
	 glBegin(GL_QUADS);//the new top face of down mental
	 glTexCoord2d(0, 0);
	 glVertex3d(x + width - 0.5*(width1), y, z - 0.5*(height)-0.5*(height1));
	 glTexCoord2d(0, 1);
	 glVertex3d(x + width + 0.5*(width1), y, z - 0.5*(height)-0.5*(height1));
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width + 0.5*(width1), y, z - 0.5*(height)+0.5*(height1));
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width - 0.5*(width1), y, z - 0.5*(height)+0.5*(height1));
	 glEnd();

	 glBegin(GL_QUADS);//the new bottom face of down mental
	 glTexCoord2d(0, 0);
	 glVertex3d(x + width - 0.5*(width1), y - depth, z - 0.5*(height)-0.5*(height1));
	 glTexCoord2d(0, 1);
	 glVertex3d(x + width + 0.5*(width1), y - depth, z - 0.5*(height)-0.5*(height1));
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width + 0.5*(width1), y - depth, z - 0.5*(height)+0.5*(height1));
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width - 0.5*(width1), y - depth, z - 0.5*(height)+0.5*(height1));
	 glEnd();

	 glBegin(GL_QUADS);//the new front face of down mental
	 glTexCoord2d(0, 0);
	 glVertex3d(x + width - 0.5*(width1), y, z - 0.5*(height)+0.5*(height1));
	 glTexCoord2d(0, 1);
	 glVertex3d(x + width + 0.5*(width1), y, z - 0.5*(height)+0.5*(height1));
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width + 0.5*(width1), y - depth, z - 0.5*(height)+0.5*(height1));
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width - 0.5*(width1), y - depth, z - 0.5*(height)+0.5*(height1));
	 glEnd();


	 glBegin(GL_QUADS);//the new back face of down mental
	 glTexCoord2d(0, 0);
	 glVertex3d(x + width - 0.5*(width1), y, z - 0.5*(height)-0.5*(height1));
	 glTexCoord2d(0, 1);
	 glVertex3d(x + width + 0.5*(width1), y, z - 0.5*(height)-0.5*(height1));
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width + 0.5*(width1), y - depth, z - 0.5*(height)-0.5*(height1));
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width - 0.5*(width1), y - depth, z - 0.5*(height)-0.5*(height1));
	 glEnd();

	 glBegin(GL_QUADS);//the new right face of down mental
	 glTexCoord2d(0, 0);
	 glVertex3d(x + width + 0.5*(width1), y, z - 0.5*(height)-0.5*(height1));
	 glTexCoord2d(0, 1);
	 glVertex3d(x + width + 0.5*(width1), y, z - 0.5*(height)+0.5*(height1));
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width + 0.5*(width1), y - depth, z - 0.5*(height)+0.5*(height1));
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width + 0.5*(width1), y - depth, z - 0.5*(height)-0.5*(height1));
	 glEnd();

	 glBegin(GL_QUADS);//the  new left of down mental
	 glTexCoord2d(0, 0);
	 glVertex3d(x + width - 0.5*(width1), y, z - 0.5*(height)+0.5*(height1));
	 glTexCoord2d(0, 1);
	 glVertex3d(x + width - 0.5*(width1), y, z - 0.5*(height)-0.5*(height1));
	 glTexCoord2d(1, 1);
	 glVertex3d(x + width - 0.5*(width1), y - depth, z - 0.5*(height)-0.5*(height1));
	 glTexCoord2d(1, 0);
	 glVertex3d(x + width - 0.5*(width1), y - depth, z - 0.5*(height)+0.5*(height1));
	 glEnd();
	 glPopMatrix();
	 glPopMatrix();
	 glPopMatrix();





	 glPopMatrix();

 }

 void road::road1Gro(int structure1, int structure2, int structure3, int structure4, int structure5, int structure6, int structure7, int trees1, int trees2,int structure,int street) {
	 glPushMatrix();
	 road::building(4000, 0, -2000, 600, 600, 1200, 0, structure1);//
	 road::building(-4000, 0, -2000, 600, 600, 1200, 0, structure1);//

	 road::building(1500, 0, -2000, 600, 600, 1200, 0, structure3);//1
	 road::building(-2000, 0, -2000, 600, 600, 1200, 0, structure3);

	 road::building(4000, 0, -4000, 600, 600, 1200, 0, structure2);//
	 road::building(-4000, 0, -4000, 600, 600, 1200, 0, structure2);//

	 road::building(1500, 0, -4500, 1200, 1200, 600, 0, structure7);//2
	 road::building(-2500, 0, -4500, 1200, 1200, 600, 0, structure7);

	 road::building(4000, 0, -6000, 600, 600, 1200, 0, structure1);//
	 road::building(-4000, 0, -6000, 600, 600, 1200, 0, structure1);//

	 road::building(4000, 0, -8500, 1200, 1200, 600, 0, structure);//
	 road::building(-4000, 0, -8500, 1200, 1200, 600, 0, structure);//


	 road::building(1500, 0, -6000, 600, 600, 1200, 0, structure4);//3
	 road::building(-2000, 0, -6000, 600, 600, 1200, 0, structure4);
	 road::building(1500, 0, -8000, 600, 600, 1200, 0, structure3);//4
	 road::building(-2000, 0, -8000, 600, 600, 1200, 0, structure3);

	 road::building(4000, 0, -12000, 600, 600, 1200, 0, structure1);//
	 road::building(-4000, 0, -12000, 600, 600, 1200, 0, structure1);//

	 road::building(1500, 0, -12000, 600, 600, 1200, 0, structure2);//6
	 road::building(-2000, 0, -12000, 600, 600, 1200, 0, structure2);

	 road::building(4000, 0, -14500, 1200, 1200, 600, 0, structure3);//
	 road::building(-4000, 0, -14500, 1200, 1200, 600, 0, structure3);//
																	  //road::building(4000,0,-16500,600,600,1200,0,structure1);//
																	  //road::building(-4000,0,-16500,600,600,1200,0,structure1);//

	 road::building(1500, 0, -14000, 600, 600, 1200, 0, structure3);//7
	 road::building(-2000, 0, -14000, 600, 600, 1200, 0, structure3);

	 road::building(4000, 0, -10300, 600, 600, 1200, 0, structure2);//
	 road::building(-4000, 0, -10300, 600, 600, 1200, 0, structure2);//


	 road::building(1500, 0, -10500, 1200, 1200, 600, 0, structure5);//5
	 road::building(-2500, 0, -10500, 1200, 1200, 600, 0, structure5);


	 road::building(1500, 0, -16500, 1200, 1200, 600, 0, structure6);//8
	 road::building(-2500, 0, -16500, 1200, 1200, 600, 0, structure6);


	 road::building(4000, 0, -16500, 1200, 1200, 600, 0, structure4);//
	 road::building(-4000, 0, -16500, 1200, 1200, 600, 0, structure4);//




	road::building(1500, 0, -18000, 600, 600, 1200, 0, structure3);//9
	road::building(-2000, 0, -18000, 600, 600, 1200, 0, structure3);



	/* road::street(330, 3, -5000, 20000, 250, 0, street);
	 road::street(330, 3, -3000, 20000, 250, 0, street);//2500
	 road::street(330, 3, -1000, 20000, 250, 0, street);
	 road::street(330, 3, -7000, 20000, 250, 0, street);
	 road::street(330, 3, -9000, 20000, 250, 0, street);
	 road::street(330, 3, -11000, 20000, 250, 0, street);
	 road::street(330, 3, -13000, 20000, 250, 0, street);
	 road::street(330, 3, -15000, 20000, 250, 0, street);
	 road::street(330, 3, -17000, 20000, 250, 0, street);
	 road::street(330, 3, -19000, 20000, 250, 0, street);


	 road::street(-20000, 3, -5000, 19665, 250, 0, street);
	 road::street(-20000, 3, -3000, 19665, 250, 0, street);//2500
	 road::street(-20000, 3, -1000, 19665, 250, 0, street);
	 road::street(-20000, 3, -7000, 19665, 250, 0, street);
	 road::street(-20000, 3, -9000, 19665, 250, 0, street);
	 road::street(-20000, 3, -11000, 19665, 250, 0, street);
	 road::street(-20000, 3, -13000, 19665, 250, 0, street);
	 road::street(-20000, 3, -15000, 19665, 250, 0, street);
	 road::street(-20000, 3, -17000, 19665, 250, 0, street);
	 road::street(-20000, 3, -19000, 19665, 250, 0, street);*/




	 road::trees(1500, 90, -1100, 60, 120, 30, 30, 150, trees1, trees2, 25, 20);//1
	 road::trees(1500, 90, -2200, 60, 120, 30, 30, 150, trees1, trees2, 25, 20);
	 road::trees(-1500, 90, -1100, 60, 120, 30, 30, 150, trees1, trees2, 25, -20);
	 road::trees(-1500, 90, -2200, 60, 120, 30, 30, 150, trees1, trees2, 25, -20);

	 road::trees(1500, 90, -3100, 60, 120, 30, 30, 150, trees1, trees2, 25, 20);//2
	 road::trees(-1500, 90, -3100, 60, 120, 30, 30, 150, trees1, trees2, 25, -20);

	 road::trees(1500, 90, -5100, 60, 120, 30, 30, 150, trees1, trees2, 25, 20);//3
	 road::trees(1500, 90, -6200, 60, 120, 30, 30, 150, trees1, trees2, 25, 20);
	 road::trees(-1500, 90, -5100, 60, 120, 30, 30, 150, trees1, trees2, 25, -20);
	 road::trees(-1500, 90, -6200, 60, 120, 30, 30, 150, trees1, trees2, 25, -20);

	 road::trees(1500, 90, -7100, 60, 120, 30, 30, 150, trees1, trees2, 25, 20);//4
	 road::trees(1500, 90, -8200, 60, 120, 30, 30, 150, trees1, trees2, 25, 20);
	 road::trees(-1500, 90, -7100, 60, 120, 30, 30, 150, trees1, trees2, 25, -20);
	 road::trees(-1500, 90, -8200, 60, 120, 30, 30, 150, trees1, trees2, 25, -20);

	 road::trees(1500, 90, -9100, 60, 120, 30, 30, 150, trees1, trees2, 25, 20);//5
	 road::trees(-1500, 90, -9100, 60, 120, 30, 30, 150, trees1, trees2, 25, -20);

	 road::trees(1500, 90, -11100, 60, 120, 30, 30, 150, trees1, trees2, 25, 20);//6
	 road::trees(1500, 90, -12200, 60, 120, 30, 30, 150, trees1, trees2, 25, 20);
	 road::trees(-1500, 90, -11100, 60, 120, 30, 30, 150, trees1, trees2, 25, -20);
	 road::trees(-1500, 90, -12200, 60, 120, 30, 30, 150, trees1, trees2, 25, -20);

	 road::trees(1500, 90, -13100, 60, 120, 30, 30, 150, trees1, trees2, 25, 20);//7
	 road::trees(1500, 90, -14200, 60, 120, 30, 30, 150, trees1, trees2, 25, 20);
	 road::trees(-1500, 90, -13100, 60, 120, 30, 30, 150, trees1, trees2, 25, -20);
	 road::trees(-1500, 90, -14200, 60, 120, 30, 30, 150, trees1, trees2, 25, -20);

	 road::trees(1500, 90, -15100, 60, 120, 30, 30, 150, trees1, trees2, 25, 20);//8
	 road::trees(-1500, 90, -15100, 60, 120, 30, 30, 150, trees1, trees2, 25, -20);

	 road::trees(1500, 90, -17100, 60, 120, 30, 30, 150, trees1, trees2, 25, 20);//9
	 road::trees(1500, 90, -18200, 60, 120, 30, 30, 150, trees1, trees2, 25, 20);
	 road::trees(-1500, 90, -17100, 60, 120, 30, 30, 150, trees1, trees2, 25, -20);
	 road::trees(-1500, 90, -18200, 60, 120, 30, 30, 150, trees1, trees2, 25, -20);




	 glPopMatrix();
 }

 void road::ishara(int imeg1, int imeg2) {

	 glBindTexture(GL_TEXTURE_2D, imeg1);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-230, 185, 5);
	 glTexCoord2d(1, 0);
	 glVertex3d(-170, 185, 5);
	 glTexCoord2d(1, 1);
	 glVertex3d(-170,  215, 5);
	 glTexCoord2d(0, 1);
	 glVertex3d(-230,  215, 5);
	 glEnd();

	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(230, 185, 5);
	 glTexCoord2d(1, 0);
	 glVertex3d(170, 185, 5);
	 glTexCoord2d(1, 1);
	 glVertex3d(170, 215, 5);
	 glTexCoord2d(0, 1);
	 glVertex3d(230, 215, 5);
	 glEnd();

	 glColor3b(0, 0, 0);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-230, 185, -5);
	 glTexCoord2d(1, 0);
	 glVertex3d(-170, 185, -5);
	 glTexCoord2d(1, 1);
	 glVertex3d(-170, 215, -5);
	 glTexCoord2d(0, 1);
	 glVertex3d(-230, 215, -5);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-230, 185, -5);
	 glTexCoord2d(1, 0);
	 glVertex3d(-230, 185, 5);
	 glTexCoord2d(1, 1);
	 glVertex3d(-230, 215, 5);
	 glTexCoord2d(0, 1);
	 glVertex3d(-230, 215, -5);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-170, 185, -5);
	 glTexCoord2d(1, 0);
	 glVertex3d(-170, 185, 5);
	 glTexCoord2d(1, 1);
	 glVertex3d(-170, 215, 5);
	 glTexCoord2d(0, 1);
	 glVertex3d(-170, 215, -5);
	 glEnd();

	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(230, 185, -5);
	 glTexCoord2d(1, 0);
	 glVertex3d(170, 185, -5);
	 glTexCoord2d(1, 1);
	 glVertex3d(170, 215, -5);
	 glTexCoord2d(0, 1);
	 glVertex3d(230, 215, -5);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(230, 185, -5);
	 glTexCoord2d(1, 0);
	 glVertex3d(230, 185, 5);
	 glTexCoord2d(1, 1);
	 glVertex3d(230, 215, 5);
	 glTexCoord2d(0, 1);
	 glVertex3d(230, 215, -5);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(170, 185, -5);
	 glTexCoord2d(1, 0);
	 glVertex3d(170, 185, 5);
	 glTexCoord2d(1, 1);
	 glVertex3d(170, 215, 5);
	 glTexCoord2d(0, 1);
	 glVertex3d(170, 215, -5);
	 glEnd();


	 glColor4f(1, 1, 1, 0);

	 glBindTexture(GL_TEXTURE_2D, imeg2);

	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-404, 0, -2);
	 glTexCoord2d(1, 0);
	 glVertex3d(-400, 0, -2);
	 glTexCoord2d(1, 1);
	 glVertex3d(-400, 200, -2);
	 glTexCoord2d(0, 1);
	 glVertex3d(-404, 200, -2);
	 glEnd();

	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-404, 0, 2);
	 glTexCoord2d(1, 0);
	 glVertex3d(-400, 0, 2);
	 glTexCoord2d(1, 1);
	 glVertex3d(-400, 200,2);
	 glTexCoord2d(0, 1);
	 glVertex3d(-404, 200,2);
	 glEnd();

	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-404, 0, -2);
	 glTexCoord2d(1, 0);
	 glVertex3d(-404, 0, 2);
	 glTexCoord2d(1, 1);
	 glVertex3d(-404, 200, 2);
	 glTexCoord2d(0, 1);
	 glVertex3d(-404, 200, -2);
	 glEnd();

	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-400, 0, -2);
	 glTexCoord2d(1, 0);
	 glVertex3d(-400, 0, 2);
	 glTexCoord2d(1, 1);
	 glVertex3d(-400, 200, 2);
	 glTexCoord2d(0, 1);
	 glVertex3d(-400, 200, -2);
	 glEnd();

	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-404, 0, -2);
	 glTexCoord2d(1, 0);
	 glVertex3d(-400, 0, -2);
	 glTexCoord2d(1, 1);
	 glVertex3d(-400, 200, -2);
	 glTexCoord2d(0, 1);
	 glVertex3d(-404, 200, -2);
	 glEnd();

	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-404, 0, 2);
	 glTexCoord2d(1, 0);
	 glVertex3d(-400, 0, 2);
	 glTexCoord2d(1, 1);
	 glVertex3d(-400, 200,2);
	 glTexCoord2d(0, 1);
	 glVertex3d(-404, 200,2);
	 glEnd();

	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-404, 0, -2);
	 glTexCoord2d(1, 0);
	 glVertex3d(-404, 0, 2);
	 glTexCoord2d(1, 1);
	 glVertex3d(-404, 200, 2);
	 glTexCoord2d(0, 1);
	 glVertex3d(-404, 200, -2);
	 glEnd();

	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-400, 0, -2);
	 glTexCoord2d(1, 0);
	 glVertex3d(-400, 0, 2);
	 glTexCoord2d(1, 1);
	 glVertex3d(-400, 200, 2);
	 glTexCoord2d(0, 1);
	 glVertex3d(-400, 200, -2);
	 glEnd();


	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(404, 0, -2);
	 glTexCoord2d(1, 0);
	 glVertex3d(400, 0, -2);
	 glTexCoord2d(1, 1);
	 glVertex3d(400, 200, -2);
	 glTexCoord2d(0, 1);
	 glVertex3d(404, 200, -2);
	 glEnd();

	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(404, 0, 2);
	 glTexCoord2d(1, 0);
	 glVertex3d(400, 0, 2);
	 glTexCoord2d(1, 1);
	 glVertex3d(400, 200, 2);
	 glTexCoord2d(0, 1);
	 glVertex3d(404, 200, 2);
	 glEnd();

	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(404, 0, -2);
	 glTexCoord2d(1, 0);
	 glVertex3d(404, 0, 2);
	 glTexCoord2d(1, 1);
	 glVertex3d(404, 200, 2);
	 glTexCoord2d(0, 1);
	 glVertex3d(404, 200, -2);
	 glEnd();

	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(400, 0, -2);
	 glTexCoord2d(1, 0);
	 glVertex3d(400, 0, 2);
	 glTexCoord2d(1, 1);
	 glVertex3d(400, 200, 2);
	 glTexCoord2d(0, 1);
	 glVertex3d(400, 200, -2);
	 glEnd();

	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-400, 198, -2);
	 glTexCoord2d(1, 0);
	 glVertex3d(-230, 198, -2);
	 glTexCoord2d(1, 1);
	 glVertex3d(-230, 202, -2);
	 glTexCoord2d(0, 1);
	 glVertex3d(-400, 202, -2);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-400, 198, 2);
	 glTexCoord2d(1, 0);
	 glVertex3d(-230, 198, 2);
	 glTexCoord2d(1, 1);
	 glVertex3d(-230, 202, 2);
	 glTexCoord2d(0, 1);
	 glVertex3d(-400, 202, 2);
	 glEnd();

	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(400, 198, -2);
	 glTexCoord2d(1, 0);
	 glVertex3d(230, 198, -2);
	 glTexCoord2d(1, 1);
	 glVertex3d(230, 202, -2);
	 glTexCoord2d(0, 1);
	 glVertex3d(400, 202, -2);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(400, 198, 2);
	 glTexCoord2d(1, 0);
	 glVertex3d(230, 198, 2);
	 glTexCoord2d(1, 1);
	 glVertex3d(230, 202, 2);
	 glTexCoord2d(0, 1);
	 glVertex3d(400, 202, 2);
	 glEnd();

	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-170, 198, 2);
	 glTexCoord2d(1, 0);
	 glVertex3d(230, 198, 2);
	 glTexCoord2d(1, 1);
	 glVertex3d(230, 202, 2);
	 glTexCoord2d(0, 1);
	 glVertex3d(-170, 202, 2);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3d(-170, 198, -2);
	 glTexCoord2d(1, 0);
	 glVertex3d(230, 198, -2);
	 glTexCoord2d(1, 1);
	 glVertex3d(230, 202, -2);
	 glTexCoord2d(0, 1);
	 glVertex3d(-170, 202, -2);
	 glEnd();
 }

 void road::tent1(int img1, int img2 ,int ll,int wood) {
	 glBindTexture(GL_TEXTURE_2D, ll);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 1);
	 glVertex3f(1000, 1, 19500);
	 glTexCoord2d(1, 1);
	 glVertex3f(1500, 1, 19500);
	 glTexCoord2d(1, 0);
	 glVertex3f(1500, 1, 19000);
	 glTexCoord2d(0, 0);
	 glVertex3f(1000, 1, 19000);
	 glEnd();
	 glBindTexture(GL_TEXTURE_2D, img1);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 1);
	 glVertex3f(1000, 1, 19500);
	 glTexCoord2d(1, 1);
	 glVertex3f(1500, 1, 19500);
	 glTexCoord2d(1, 0);
	 glVertex3f(1500, 250, 19500);
	 glTexCoord2d(0, 0);
	 glVertex3f(1000, 250, 19500);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 1);
	 glVertex3f(1000, 1, 19000);
	 glTexCoord2d(1, 1);
	 glVertex3f(1500, 1, 19000);
	 glTexCoord2d(1, 0);
	 glVertex3f(1500, 250, 19000);
	 glTexCoord2d(0, 0);
	 glVertex3f(1000, 250, 19000);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(1500, 1, 19000);
	 glTexCoord2d(1, 0);
	 glVertex3f(1500, 1, 19500);
	 glTexCoord2d(1, 1);
	 glVertex3f(1500, 250, 19500);
	 glTexCoord2d(0, 1);
	 glVertex3f(1500, 250, 19000);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 1);
	 glVertex3f(1000, 250, 19500);
	 glTexCoord2d(1, 1);
	 glVertex3f(1500, 250, 19500);
	 glTexCoord2d(1, 0);
	 glVertex3f(1500, 250, 19000);
	 glTexCoord2d(0, 0);
	 glVertex3f(1000, 250, 19000);
	 glEnd();
	 glBindTexture(GL_TEXTURE_2D, img2);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(1000, 250, 19000);
	 glTexCoord2d(1, 0);
	 glVertex3f(1000, 250, 19250);
	 glTexCoord2d(1, 1);
	 glVertex3f(1000, 2, 19220);
	 glTexCoord2d(0, 1);
	 glVertex3f(1000, 2, 19000);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(1000, 250, 19500);
	 glTexCoord2d(1, 0);
	 glVertex3f(1000, 250, 19250);
	 glTexCoord2d(1, 1);
	 glVertex3f(1000, 2, 19280);
	 glTexCoord2d(0, 1);
	 glVertex3f(1000, 2, 19500);
	 glEnd();
	 glBegin(GL_LINES);
	 glPointSize(1);
	 glVertex3f(810, 280, 18960);
	 glVertex3f(1000, 250, 19000);
	 glEnd();
	 glBegin(GL_LINES);
	 glPointSize(1);
	 glVertex3f(810, 280, 19550);
	 glVertex3f(1000, 250, 19500);
	 glEnd();
	 glBindTexture(GL_TEXTURE_2D, wood);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(800, 2, 19550);
	 glTexCoord2d(1, 0);
	 glVertex3f(810, 2, 19550);
	 glTexCoord2d(1, 1);
	 glVertex3f(810, 280, 19550);
	 glTexCoord2d(0, 1);
	 glVertex3f(800, 280, 19550);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(800, 2, 19540);
	 glTexCoord2d(1, 0);
	 glVertex3f(810, 2, 19540);
	 glTexCoord2d(1, 1);
	 glVertex3f(810, 280, 19540);
	 glTexCoord2d(0, 1);
	 glVertex3f(800, 280, 19540);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(800, 2, 19540);
	 glTexCoord2d(1, 0);
	 glVertex3f(800, 2, 19550);
	 glTexCoord2d(1, 1);
	 glVertex3f(800, 280, 19550);
	 glTexCoord2d(0, 1);
	 glVertex3f(800, 280, 19540);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(810, 2, 19540);
	 glTexCoord2d(1, 0);
	 glVertex3f(810, 2, 19550);
	 glTexCoord2d(1, 1);
	 glVertex3f(810, 280, 19550);
	 glTexCoord2d(0, 1);
	 glVertex3f(810, 280, 19540);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(800, 2, 18950);
	 glTexCoord2d(1, 0);
	 glVertex3f(810, 2, 18950);
	 glTexCoord2d(1, 1);
	 glVertex3f(810, 280, 18950);
	 glTexCoord2d(0, 1);
	 glVertex3f(800, 280, 18950);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(800, 2, 18960);
	 glTexCoord2d(1, 0);
	 glVertex3f(810, 2, 18960);
	 glTexCoord2d(1, 1);
	 glVertex3f(810, 280, 18960);
	 glTexCoord2d(0, 1);
	 glVertex3f(800, 280, 18960);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(800, 2, 18960);
	 glTexCoord2d(1, 0);
	 glVertex3f(800, 2, 18950);
	 glTexCoord2d(1, 1);
	 glVertex3f(800, 280, 18950);
	 glTexCoord2d(0, 1);
	 glVertex3f(800, 280, 18960);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(810, 2, 18950);
	 glTexCoord2d(1, 0);
	 glVertex3f(810, 2, 18960);
	 glTexCoord2d(1, 1);
	 glVertex3f(810, 280, 18960);
	 glTexCoord2d(0, 1);
	 glVertex3f(810, 280, 18950);
	 glEnd();
 }

 void road::tent(int ll,int ll2,int pp , int ll1,int lll1 ,int wood) {
	 glBindTexture(GL_TEXTURE_2D, ll);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-1000, 1, 19500);
	 glTexCoord2d(1, 0);
	 glVertex3f(-5000, 1, 19500);
	 glTexCoord2d(1, 1);
	 glVertex3f(-5000, 1, 25000);
	 glTexCoord2d(0, 1);
	 glVertex3f(-1000, 1, 25000);
	 glEnd();
	 glBindTexture(GL_TEXTURE_2D, ll2);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-200, 1, 19500);
	 glTexCoord2d(5, 0);
	 glVertex3f(-1000, 1, 19500);
	 glTexCoord2d(5, 5);
	 glVertex3f(-1000, 1, 25000);
	 glTexCoord2d(0, 5);
	 glVertex3f(-200, 1, 25000);
	 glEnd();
	 glBindTexture(GL_TEXTURE_2D, pp);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 1);
	 glVertex3f(-5000, 1, 19500);
	 glTexCoord2d(4, 1);
	 glVertex3f(-5000, 1, 25000);
	 glTexCoord2d(4, 0);
	 glVertex3f(-5000, 300, 25000);
	 glTexCoord2d(0, 0);
	 glVertex3f(-5000, 300, 19500);
	 glEnd();
	 glBegin(GL_TRIANGLES);
	 glTexCoord2d(0, 0);
	 glVertex3f(-5000, 300, 19500);
	 glTexCoord2d(4, 0);
	 glVertex3f(-5000, 300, 25000);
	 glTexCoord2d(4, 1);
	 glVertex3f(-5000, 500, 22250);
	 glEnd();
	 glBegin(GL_TRIANGLES);
	 glTexCoord2d(0, 0);
	 glVertex3f(-1000, 300, 19500);
	 glTexCoord2d(4, 0);
	 glVertex3f(-1000, 300, 25000);
	 glTexCoord2d(4, 1);
	 glVertex3f(-1000, 500, 22250);
	 glEnd();
	 glBindTexture(GL_TEXTURE_2D, ll1);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-1000, 1, 19500);
	 glTexCoord2d(1, 0);
	 glVertex3f(-5000, 1, 19500);
	 glTexCoord2d(1, 1);
	 glVertex3f(-5000, 300, 19500);
	 glTexCoord2d(0, 1);
	 glVertex3f(-1000, 300, 19500);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-1000, 1, 25000);
	 glTexCoord2d(1, 0);
	 glVertex3f(-5000, 1, 25000);
	 glTexCoord2d(1, 1);
	 glVertex3f(-5000, 300, 25000);
	 glTexCoord2d(0, 1);
	 glVertex3f(-1000, 300, 25000);
	 glEnd();
	 glBindTexture(GL_TEXTURE_2D, lll1);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-1000, 300, 25000);
	 glTexCoord2d(1, 0);
	 glVertex3f(-5000, 300, 25000);
	 glTexCoord2d(1, 1);
	 glVertex3f(-5000, 500, 22250);
	 glTexCoord2d(0, 1);
	 glVertex3f(-1000, 500, 22250);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-1000, 300, 19500);
	 glTexCoord2d(1, 0);
	 glVertex3f(-5000, 300, 19500);
	 glTexCoord2d(1, 1);
	 glVertex3f(-5000, 500, 22250);
	 glTexCoord2d(0, 1);
	 glVertex3f(-1000, 500, 22250);
	 glEnd();
	 glBindTexture(GL_TEXTURE_2D, wood);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-150, 2, 19320);
	 glTexCoord2d(1, 0);
	 glVertex3f(-160, 2, 19320);
	 glTexCoord2d(1, 1);
	 glVertex3f(-160, 370, 19320);
	 glTexCoord2d(0, 1);
	 glVertex3f(-150, 370, 19320);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-150, 2, 19330);
	 glTexCoord2d(1, 0);
	 glVertex3f(-160, 2, 19330);
	 glTexCoord2d(1, 1);
	 glVertex3f(-160, 370, 19330);
	 glTexCoord2d(0, 1);
	 glVertex3f(-150, 370, 19330);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-150, 2, 19320);
	 glTexCoord2d(1, 0);
	 glVertex3f(-150, 2, 19330);
	 glTexCoord2d(1, 1);
	 glVertex3f(-150, 370, 19330);
	 glTexCoord2d(0, 1);
	 glVertex3f(-150, 370, 19320);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-160, 2, 19320);
	 glTexCoord2d(1, 0);
	 glVertex3f(-160, 2, 19330);
	 glTexCoord2d(1, 1);
	 glVertex3f(-160, 370, 19330);
	 glTexCoord2d(0, 1);
	 glVertex3f(-160, 370, 19320);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-150, 2, 25180);
	 glTexCoord2d(1, 0);
	 glVertex3f(-160, 2, 25180);
	 glTexCoord2d(1, 1);
	 glVertex3f(-160, 370, 25180);
	 glTexCoord2d(0, 1);
	 glVertex3f(-150, 370, 25180);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-150, 2, 25170);
	 glTexCoord2d(1, 0);
	 glVertex3f(-160, 2, 25170);
	 glTexCoord2d(1, 1);
	 glVertex3f(-160, 370, 25170);
	 glTexCoord2d(0, 1);
	 glVertex3f(-150, 370, 25170);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-150, 2, 25180);
	 glTexCoord2d(1, 0);
	 glVertex3f(-150, 2, 25170);
	 glTexCoord2d(1, 1);
	 glVertex3f(-150, 370, 25170);
	 glTexCoord2d(0, 1);
	 glVertex3f(-150, 370, 25180);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-160, 2, 25180);
	 glTexCoord2d(1, 0);
	 glVertex3f(-160, 2, 25170);
	 glTexCoord2d(1, 1);
	 glVertex3f(-160, 370, 25170);
	 glTexCoord2d(0, 1);
	 glVertex3f(-160, 370, 25180);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-150, 2, 22255);
	 glTexCoord2d(1, 0);
	 glVertex3f(-160, 2, 22255);
	 glTexCoord2d(1, 1);
	 glVertex3f(-160, 570, 22255);
	 glTexCoord2d(0, 1);
	 glVertex3f(-150, 570, 22255);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-150, 2, 22245);
	 glTexCoord2d(1, 0);
	 glVertex3f(-160, 2, 22245);
	 glTexCoord2d(1, 1);
	 glVertex3f(-160, 570, 22245);
	 glTexCoord2d(0, 1);
	 glVertex3f(-150, 570, 22245);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-150, 2, 22255);
	 glTexCoord2d(1, 0);
	 glVertex3f(-150, 2, 22245);
	 glTexCoord2d(1, 1);
	 glVertex3f(-150, 570, 22245);
	 glTexCoord2d(0, 1);
	 glVertex3f(-150, 570, 22255);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-160, 2, 22255);
	 glTexCoord2d(1, 0);
	 glVertex3f(-160, 2, 22245);
	 glTexCoord2d(1, 1);
	 glVertex3f(-160, 570, 22245);
	 glTexCoord2d(0, 1);
	 glVertex3f(-160, 570, 22255);
	 glEnd();
	 glBegin(GL_LINES);
	 glPointSize(1);
	 glVertex3f(-160, 570, 22255);
	 glVertex3f(-1000, 500, 22250);
	 glEnd();
	 glBegin(GL_LINES);
	 glPointSize(1);
	 glVertex3f(-150, 370, 19320);
	 glVertex3f(-1000, 300, 19500);
	 glEnd();
	 glBegin(GL_LINES);
	 glPointSize(1);
	 glVertex3f(-160, 370, 25180);
	 glVertex3f(-1000, 300, 25000);
	 glEnd();
 }

 void road::shal(int img1, int img2,int lll3,int bl) {
	 glBindTexture(GL_TEXTURE_2D, img1);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 1);
	 glVertex3f(-1000, 1, -2000);
	 glTexCoord2d(1, 1);
	 glVertex3f(-1500, 1, -2000);
	 glTexCoord2d(1, 0);
	 glVertex3f(-1500, 250, -2000);
	 glTexCoord2d(0, 0);
	 glVertex3f(-1000, 250, -2000);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 1);
	 glVertex3f(-1000, 1, -1500);
	 glTexCoord2d(1, 1);
	 glVertex3f(-1500, 1, -1500);
	 glTexCoord2d(1, 0);
	 glVertex3f(-1500, 250, -1500);
	 glTexCoord2d(0, 0);
	 glVertex3f(-1000, 250, -1500);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-1500, 1, -2000);
	 glTexCoord2d(1, 0);
	 glVertex3f(-1500, 1, -1500);
	 glTexCoord2d(1, 1);
	 glVertex3f(-1500, 250, -1500);
	 glTexCoord2d(0, 1);
	 glVertex3f(-1500, 250, -2000);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-1000, 1, -2000);
	 glTexCoord2d(1, 0);
	 glVertex3f(-1000, 1, -1500);
	 glTexCoord2d(1, 1);
	 glVertex3f(-1000, 250, -1500);
	 glTexCoord2d(0, 1);
	 glVertex3f(-1000, 250, -2000);
	 glEnd();
	 glBindTexture(GL_TEXTURE_2D, bl);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-999, 90, -1780);
	 glTexCoord2d(1, 0);
	 glVertex3f(-999, 90, -1870);
	 glTexCoord2d(1, 1);
	 glVertex3f(-999, 190, -1870);
	 glTexCoord2d(0, 1);
	 glVertex3f(-999, 190, -1780);
	 glEnd();
	 glBindTexture(GL_TEXTURE_2D, lll3);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(-999, 5, -1600);
	 glTexCoord2d(1, 0);
	 glVertex3f(-999, 5, -1700);
	 glTexCoord2d(1, 1);
	 glVertex3f(-999, 190, -1700);
	 glTexCoord2d(0, 1);
	 glVertex3f(-999, 190, -1600);
	 glEnd();
	 glBindTexture(GL_TEXTURE_2D, img2);
	 glBegin(GL_TRIANGLES);
	 glTexCoord2d(0, 0);
	 glVertex3f(-1500, 250, -2000);
	 glTexCoord2d(1, 0);
	 glVertex3f(-1000, 250, -2000);
	 glTexCoord2d(1, 1);
	 glVertex3f(-1250, 400, -1750);
	 glEnd();
	 glBegin(GL_TRIANGLES);
	 glTexCoord2d(0, 0);
	 glVertex3f(-1500, 250, -1500);
	 glTexCoord2d(1, 0);
	 glVertex3f(-1000, 250, -1500);
	 glTexCoord2d(1, 1);
	 glVertex3f(-1250, 400, -1750);
	 glEnd();
	 glBegin(GL_TRIANGLES);
	 glTexCoord2d(0, 0);
	 glVertex3f(-1500, 250, -2000);
	 glTexCoord2d(1, 0);
	 glVertex3f(-1500, 250, -1500);
	 glTexCoord2d(1, 1);
	 glVertex3f(-1250, 400, -1750);
	 glEnd();
	 glBegin(GL_TRIANGLES);
	 glTexCoord2d(0, 0);
	 glVertex3f(-1000, 250, -2000);
	 glTexCoord2d(1, 0);
	 glVertex3f(-1000, 250, -1500);
	 glTexCoord2d(1, 1);
	 glVertex3f(-1250, 400, -1750);
	 glEnd();
 }

 void  road::ship(int sh,int wood) {
	 glBindTexture(GL_TEXTURE_2D, wood);
	 glBegin(GL_TRIANGLES);
	 glTexCoord2d(0, 0);
	 glVertex3f(7000, 2, 0);
	 glTexCoord2d(0, 1);
	 glVertex3f(10000, 2, 0);
	 glTexCoord2d(1, 1);
	 glVertex3f(8500, 2, 3000);
	 glEnd();
	 glBegin(GL_TRIANGLES);
	 glTexCoord2d(0, 0);
	 glVertex3f(7000, 2, 0);
	 glTexCoord2d(0, 1);
	 glVertex3f(10000, 2, 0);
	 glTexCoord2d(1, 1);
	 glVertex3f(8500, 2, -3000);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(8500, 2, -3000);
	 glTexCoord2d(0, 1);
	 glVertex3f(8500, 250, -3000);
	 glTexCoord2d(1, 1);
	 glVertex3f(7000, 250, 0);
	 glTexCoord2d(1, 0);
	 glVertex3f(7000, 2, 0);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(8500, 2, -3000);
	 glTexCoord2d(0, 1);
	 glVertex3f(8500, 250, -3000);
	 glTexCoord2d(1, 1);
	 glVertex3f(10000, 250, 0);
	 glTexCoord2d(1, 0);
	 glVertex3f(10000, 2, 0);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(8500, 2, 3000);
	 glTexCoord2d(0, 1);
	 glVertex3f(8500, 250, 3000);
	 glTexCoord2d(1, 1);
	 glVertex3f(10000, 250, 0);
	 glTexCoord2d(1, 0);
	 glVertex3f(10000, 2, 0);
	 glEnd();
	 glBegin(GL_QUADS);
	 glTexCoord2d(0, 0);
	 glVertex3f(8500, 2, 3000);
	 glTexCoord2d(0, 1);
	 glVertex3f(8500, 250, 3000);
	 glTexCoord2d(1, 1);
	 glVertex3f(7000, 250, 0);
	 glTexCoord2d(1, 0);
	 glVertex3f(7000, 2, 0);
	 glEnd();
	 glBindTexture(GL_TEXTURE_2D, sh);
	 glBegin(GL_TRIANGLES);
	 glTexCoord2d(0, 0);
	 glVertex3f(8500, 3, -2990);
	 glTexCoord2d(3, 0);
	 glVertex3f(8500, 3, 2990);
	 glTexCoord2d(3, 3);
	 glVertex3f(8500, 1500, 0);
	 glEnd();
 }////roadgroub

 void road::shipGr(int lll3, int bl, int sh, int wood,int mm,int ww,int ww1,int ww2) {
	 road::shal( mm, ww,lll3,bl);
	 glTranslated(0, 0, -1000);
	 road::shal(ww1, mm, lll3, bl);
	 glTranslated(0, 0, -1000);
	 road::shal(mm, ww2, lll3, bl);
	 glTranslated(0, 0, -1000);
	 road::shal(ww2, ww1, lll3, bl);
	 glTranslated(0, 0, -1000);
	 road::shal(mm, ww, lll3, bl);
	 glTranslated(0, 0, -1000);
	 road::shal(ww1, mm, lll3, bl);
	 glTranslated(0, 0, -1000);
	 road::shal(mm, ww2, lll3, bl);
	 glTranslated(0, 0, -1000);
	 road::shal(ww2, ww1, lll3, bl);
	 glTranslated(0, 0, -1000);
	 road::shal(mm, ww, lll3, bl);
	 glTranslated(0, 0, -1000);
	 road::shal(ww1, mm, lll3, bl);
	 glTranslated(0, 0, -1000);
	 road::shal(mm, ww2, lll3, bl);
	 glTranslated(0, 0, -1000);
	 road::shal(ww2, ww1, lll3, bl);
	 glTranslated(0, 0, 11000);
	 ///
	 glTranslated(-1000, 0, -500);
	 road::shal(mm, ww, lll3, bl);
	 glTranslated(0, 0, -1000);
	 road::shal(ww1, mm, lll3, bl);
	 glTranslated(0, 0, -1000);
	 road::shal(mm, ww2, lll3, bl);;
	 glTranslated(0, 0, -1000);
	 road::shal(ww2, ww1, lll3, bl);
	 glTranslated(0, 0, -1000);
	 road::shal(mm, ww, lll3, bl);
	 glTranslated(0, 0, -1000);
	 road::shal(ww1, mm, lll3, bl);
	 glTranslated(0, 0, -1000);
	 road::shal(mm, ww2, lll3, bl);
	 glTranslated(0, 0, -1000);
	 road::shal(ww2, ww1, lll3, bl);
	 glTranslated(0, 0, -1000);
	 road::shal(mm, ww, lll3, bl);
	 glTranslated(0, 0, -1000);
	 road::shal(ww1, mm, lll3, bl);
	 glTranslated(0, 0, -1000);
	 road::shal(mm, ww2, lll3, bl);
	 glTranslated(0, 0, -1000);
	 road::shal(ww2, ww1, lll3, bl);
	 //////////////////////////ship
	 int mile = -3500;
	 bool mi = false;

	 if (mile<6000 && mi == false) {
		 glTranslatef(-2000, 0, mile);
		 ship(sh,wood);
		 mile += 1;
		 if (mile == 4000) {
			 mi = true;
		 }
	 }
	 if (mi == true) {
		 glTranslatef(-2000, 0, mile);
		 ship(sh,wood);
		 mile -= 1;
		 if (mile == -2500) {
			 mi = false;
		 }
	 }
 }

 void road::ahramat(int img) {
	 glPushMatrix();
	 glBindTexture(GL_TEXTURE_2D, img);
	 glTranslated(0, 0, 4000);
	 glBegin(GL_TRIANGLE_STRIP);
	 glTexCoord2d(0, 0);
	 glVertex3f(3000, 0, 1000);
	 glTexCoord2d(100, 0);
	 glVertex3f(3000, 0, 10000);
	 glTexCoord2d(100, 10);
	 glVertex3f(5000, 3000, 7000);
	 glTexCoord2d(100, 10);
	 glVertex3f(12000, 0, 10000);
	 glTexCoord2d(0, 0);
	 glVertex3f(3000, 0, 1000);
	 glEnd();
	 glPopMatrix();
 }

 void road::tentGr(int img,int jj,int kk,int jj1,int kk1,int wood,int ll, int ll2, int pp, int ll1, int lll1) {
	 road::ahramat( img);

	 road::tent1(jj, kk,ll,wood);
	 glTranslated(0, 0, -1500);
	 road::tent1(jj1, kk1, ll, wood);
	 glTranslated(0, 0, -1500);
	 road::tent1(jj, kk, ll, wood);
	 glTranslated(0, 0, -1500);
	 road::tent1(jj1, kk1, ll, wood); glTranslated(0, 0, -1500);
	 road::tent1(jj, kk, ll, wood); glTranslated(0, 0, -1500);
	 road::tent1(jj1, kk1, ll, wood); glTranslated(0, 0, -1500);
	 road::tent1(jj, kk, ll, wood); glTranslated(0, 0, -1500);
	 road::tent1(jj1, kk1, ll, wood); glTranslated(0, 0, -1500);
	 road::tent1(jj, kk, ll, wood); glTranslated(0, 0, -1500);
	 road::tent1(jj1, kk1, ll, wood); glTranslated(0, 0, -1500);
	 road::tent1(jj, kk, ll, wood);
	 road::tent( ll,  ll2,  pp,  ll1,  lll1,wood);
	 glTranslated(0, 0, 9000);
	 road::tent( ll,  ll2,  pp,  ll1,  lll1, wood);
 }
 void road::allTrees(int x,int trees1,int trees2){
	 	//front
	 road::trees(150, 0, -3100, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(150+2*x, 0, -3100, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(150+3*x, 0, -3100, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(150+4*x, 0, -3100, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(150+5*x, 0, -3100, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(150+6*x, 0, -3100, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(150+7*x, 0, -3100, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(150+8*x, 0, -3100, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(150+9*x, 0, -3100, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(150+9*x, 0, -3100, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1

	 road::trees(-400, 0, -3100, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(-400-2*x, 0, -3100, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(-400-3*x, 0, -3100, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(-400-4*x, 0, -3100, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(-400-5*x, 0, -3100, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(-400-6*x, 0, -3100, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(-400-7*x, 0, -3100, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(-400-8*x, 0, -3100, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(-400-9*x, 0, -3100, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(-400-9*x, 0, -3100, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	//road::buildingSakhra(-600, 0, -4500, 1200, 1200, 600,200, structure7,structure7,structure7);//2
	// road::building(-2500, 0, -4500, 1200, 1200, 600, 0, structure7);t

	 //back 
	 road::trees(150, 0, -13750, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(150+2*x, 0, -13750, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(150+3*x, 0, -13750, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(150+4*x, 0, -13750, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(150+5*x, 0, -13750, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(150+6*x, 0, -13750, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(150+7*x, 0, -13750, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(150+8*x, 0, -13750, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(150+9*x, 0, -13750, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(150+9*x, 0, -13750, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1

	 road::trees(-400, 0, -13750, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(-400-2*x, 0, -13750, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(-400-3*x, 0, -13750, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(-400-4*x, 0, -13750, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(-400-5*x, 0, -13750, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(-400-6*x, 0, -13750, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(-400-7*x, 0, -13750, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(-400-8*x, 0, -13750, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(-400-9*x, 0, -13750, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	 road::trees(-400-9*x, 0, -13750, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1


	 //right
	  road::trees(150+9*x, 0, -3100-x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(150+9*x, 0, -3100-2*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(150+9*x, 0, -3100-3*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(150+9*x, 0, -3100-4*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(150+9*x, 0, -3100-5*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(150+9*x, 0, -3100-6*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(150+9*x, 0, -3100-7*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(150+9*x, 0, -3100-8*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(150+9*x, 0, -3100-9*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(150+9*x, 0, -3100-10*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(150+9*x, 0, -3100-11*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(150+9*x, 0, -3100-12*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1





	  road::trees(-400-9*x, 0, -3100-x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(-400-9*x, 0, -3100-2*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(-400-9*x, 0, -3100-3*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(-400-9*x, 0, -3100-4*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(-400-9*x, 0, -3100-5*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(-400-9*x, 0, -3100-6*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(-400-9*x, 0, -3100-7*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(-400-9*x, 0, -3100-8*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(-400-9*x, 0, -3100-9*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(-400-9*x, 0, -3100-10*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(-400-9*x, 0, -3100-11*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	  road::trees(-400-9*x, 0, -3100-12*x, 120, 240, 60, 60, 300, trees1, trees2, 50, 0);//1
	

	glPopMatrix();
 }