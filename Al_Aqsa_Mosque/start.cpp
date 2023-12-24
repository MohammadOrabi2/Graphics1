#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
//#include <glaux.h>// Header File For The Glaux Library
#include <cmath>
#include <texture.h>
#include  "camera.h"
#include "tools.h"
#include "bathroom.h"
#include "rkapr.h"
#include "road.h"
#include "bedroom.h"
#include "boarders.h"
#include <GLAUX.H>
#include <stdlib.h>
#include <iostream>
#include<fstream>
#include"view.h"
#include "controll.h"
#include "controlling.h"
#include "lighting.h"
#include"Model_3DS.h"

//#pragma comment(lib, "legacy_stdio_definitions.lib")

double x = 55, y = 50, z = -110;
Camera MyCamera;
int mouseX = 0, mouseY = 0;
bool isClicked = 0, isRClicked = 0;
int back, Front, Left, Right, Top, bottom,
trainEdge1,trainTop1, trainbottom1,trainFront, trainEdge2, trainTop2, trainEdge3,
road1, road2, road3, road4, roadRight1, roadRight2, roadRight3,
roadLeft1, roadLeft2, roadLeft3, roomKitchen1, roomKitchen3, roomKitchen4, roomKitchen2, roomKitchen5
, roomKitchen6, roomKitchen7, roomKitchen8, roomKitchen9
,roadBetween1, roadBetween2, cloth, metal, cloth1, wallpaper, bedRoomDoor, wood, fabric,
curtains, ground, door, road5,road6, road7, road8, road9, roadRight4, snowTree,snowHous1, snowHous2,snowRoad;
int sofa1, sofa2,cinemaWall, wall, sofaBack , ad1, ad2,  ad3, ad4, ad5, ad6, ad7, snowHous3, snowHous4;
int img1, img2, e, f, h, i, j, k, m, i1, m1, m2, m3;
int structure, structure1, structure2, structure3, structure4, structure5, structure6, structure7, street, trees1, trees2;
int frontControll, rightControll, leftControll, controlll;

int kk, jj, ll, jj1, kk1, ll1, lll1, ll2, lll3, bl, mm, sh, ww, ww1, ww2, pp;
int mile = -5500;
bool mi = false;



///////////////new photo
int carbet,newWall,wallWithDoor;


HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Cntext
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

							//bool	keys[256];			// Array Used For The Keyboard Routine
bool keys[256];
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = FALSE;	// Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

														// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 5.1f, 200000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}
void mouse(int mouseX, int mouseY, bool isClicked, bool isRClicked)
{
	if (isClicked)
		MyCamera.RotateY(-0.1);
	if (isRClicked)
		MyCamera.RotateY(0.1);
}
void keybord(float speedcam)
{
	if (keys['Q'])    		MyCamera.MoveUpward(0.3+ speedcam/10);
	if (keys['E'])			MyCamera.MoveUpward(-0.3- speedcam/10);
	if (keys['A'])			MyCamera.RotateY(0.2+ speedcam/10);
	if (keys['D'])		    MyCamera.RotateY(-0.2- speedcam/10);
	if (keys['S'])		    MyCamera.RotateX(-0.1- speedcam/10);
	if (keys['W'])		    MyCamera.RotateX(0.1+ speedcam/10);
	if (keys[VK_DOWN])        MyCamera.MoveForward(-2-speedcam);
	if (keys[VK_UP])      MyCamera.MoveForward(2+speedcam);
	if (keys[VK_LEFT])	    MyCamera.MoveRight(-2-speedcam);
	if (keys[VK_RIGHT])		MyCamera.MoveRight(+2+speedcam);
}


void skybox(int size, int sizeZ)
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, Front);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0.5);
	glVertex3d(-sizeZ, -size , -sizeZ);
	glTexCoord2d(1, 0.5);
	glVertex3d(sizeZ, -size, -sizeZ);
	glTexCoord2d(1, 1);
	glVertex3d(sizeZ, size , -sizeZ);
	glTexCoord2d(0, 1);
	glVertex3d(-sizeZ, size , -sizeZ);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, back);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0.5);
	glVertex3d(sizeZ, -size, sizeZ);
	glTexCoord2d(1, 0.5);
	glVertex3d(-sizeZ, -size , sizeZ);
	glTexCoord2d(1, 1);
	glVertex3d(-sizeZ, size , sizeZ);
	glTexCoord2d(0, 1);
	glVertex3d(sizeZ, size , sizeZ);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, Left);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0.5);
	glVertex3d(-sizeZ, -size , sizeZ);
	glTexCoord2d(1, 0.5);
	glVertex3d(-sizeZ, -size , -sizeZ);
	glTexCoord2d(1, 1);
	glVertex3d(-sizeZ, size , -sizeZ);
	glTexCoord2d(0, 1);
	glVertex3d(-sizeZ, size , sizeZ);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, Right);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0.5);
	glVertex3d(sizeZ, -size , -sizeZ);
	glTexCoord2d(1, 0.5);
	glVertex3d(sizeZ, -size , sizeZ);
	glTexCoord2d(1, 1);
	glVertex3d(sizeZ, size , sizeZ);
	glTexCoord2d(0, 1);
	glVertex3d(sizeZ, size, -sizeZ);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, Top);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-sizeZ, size , -sizeZ);
	glTexCoord2d(1, 0);
	glVertex3d(sizeZ, size , -sizeZ);
	glTexCoord2d(1, 1);
	glVertex3d(sizeZ, size , sizeZ);
	glTexCoord2d(0, 1);
	glVertex3d(-sizeZ, size , sizeZ);
	glEnd();
	glPopMatrix();

	/*glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, bottom);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-sizeZ, -size , -sizeZ);
	glTexCoord2d(10, 0);
	glVertex3d(sizeZ, -size , -sizeZ);
	glTexCoord2d(10, 10);
	glVertex3d(sizeZ, -size , sizeZ);
	glTexCoord2d(0, 10);
	glVertex3d(-sizeZ, -size , sizeZ);
	glEnd();
	glPopMatrix();*/
}


void Kitchen(double x, double y, double z,bool openDoor, bool openDoor2) {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		//down to window
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, roomKitchen1);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(-25, -38, 100 );
		glTexCoord2d(1, 0);
		glVertex3d(-25, -38, -100 );
		glTexCoord2d(1, 1);
		glVertex3d(-25, -12, -100 );
		glTexCoord2d(0, 1);
		glVertex3d(-25, -12, 100 );
		glEnd();
		glBindTexture(GL_TEXTURE_2D, roomKitchen2);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(-25, -12, 100);
		glTexCoord2d(1, 0);
		glVertex3d(-25, -12, -100);
		glTexCoord2d(1, 1);
		glVertex3d(-50, -12, -100);
		glTexCoord2d(0, 1);
		glVertex3d(-50, -12, 100);
		glEnd();
		glPopMatrix();
		//up to window
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, roomKitchen3);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(-25, 27, 100);
		glTexCoord2d(1.5, 0);
		glVertex3d(-25, 27, -100);
		glTexCoord2d(1.5, 1);
		glVertex3d(-25, 50, -100);
		glTexCoord2d(0, 1);
		glVertex3d(-25, 50, 100);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, roomKitchen4);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(-25, 27, 100);
		glTexCoord2d(1, 0);
		glVertex3d(-25, 27, -100);
		glTexCoord2d(1, 1);
		glVertex3d(-50, 27, -100);
		glTexCoord2d(0, 1);
		glVertex3d(-50, 27, 100);
		glEnd();
		glPopMatrix();
		//barad
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, roomKitchen5);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(+25, -38, -95);
		glTexCoord2d(1, 0);
		glVertex3d(+25, -38, -55);
		glTexCoord2d(1, 1);
		glVertex3d(+25, 27, -55);
		glTexCoord2d(0, 1);
		glVertex3d(+25, 27, -95);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, roomKitchen6);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(+25, -38, -55);
		glTexCoord2d(1, 0);
		glVertex3d(+50, -38, -55);
		glTexCoord2d(1, 1);
		glVertex3d(+50, 27, -55);
		glTexCoord2d(0, 1);
		glVertex3d(+25, 27, -55);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(+25, -38, -95);
		glTexCoord2d(1, 0);
		glVertex3d(+50, -38, -95);
		glTexCoord2d(1, 1);
		glVertex3d(+50, 27, -95);
		glTexCoord2d(0, 1);
		glVertex3d(+25, 27, -95);
		glEnd();
		glPopMatrix();
		//gazz
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, roomKitchen7);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(+25, -38, -35);
		glTexCoord2d(1, 0);
		glVertex3d(+25, -38, 0);
		glTexCoord2d(1, 1);
		glVertex3d(+25, -10, 0);
		glTexCoord2d(0, 1);
		glVertex3d(+25, -10, -35);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, roomKitchen8);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(+25, -38, -35);
		glTexCoord2d(1, 0);
		glVertex3d(+50, -38, -35);
		glTexCoord2d(1, 1);
		glVertex3d(+50, -10, -35);
		glTexCoord2d(0, 1);
		glVertex3d(+25, -10, -35);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(+25, -38, 0);
		glTexCoord2d(1, 0);
		glVertex3d(+50, -38, 0);
		glTexCoord2d(1, 1);
		glVertex3d(+50, -10, 0);
		glTexCoord2d(0, 1);
		glVertex3d(+25, -10, 0);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, roomKitchen9);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(+25, -10, -35);
		glTexCoord2d(1, 0);
		glVertex3d(+25, -10, 0);
		glTexCoord2d(1, 1);
		glVertex3d(+50, -10, 0);
		glTexCoord2d(0, 1);
		glVertex3d(+50, -10, -35);
		glEnd();
		//·ÊÕ Œ‘»
		int yy = -10;
		glBindTexture(GL_TEXTURE_2D, wood);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(+25, yy, 10);
		glTexCoord2d(1, 0);
		glVertex3d(+25, yy, 90);
		glTexCoord2d(1, 1);
		glVertex3d(+50, yy, 90);
		glTexCoord2d(0, 1);
		glVertex3d(+50, yy, 10);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(+25, yy-2, 10);
		glTexCoord2d(1, 0);
		glVertex3d(+25, yy-2, 90);
		glTexCoord2d(1, 1);
		glVertex3d(+50, yy-2, 90);
		glTexCoord2d(0, 1);
		glVertex3d(+50, yy-2, 10);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(+25, yy-2, 10);
		glTexCoord2d(1, 0);
		glVertex3d(+25, yy-2, 90);
		glTexCoord2d(1, 1);
		glVertex3d(+25, yy, 90);
		glTexCoord2d(0, 1);
		glVertex3d(+25, yy, 10);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(+50, yy-2, 10);
		glTexCoord2d(1, 0);
		glVertex3d(+25, yy-2, 10);
		glTexCoord2d(1, 1);
		glVertex3d(+25, yy, 10);
		glTexCoord2d(0, 1);
		glVertex3d(+50, yy, 10);
		glEnd();
		 yy = -20;
		glBindTexture(GL_TEXTURE_2D, wood);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(+25, yy, 10);
		glTexCoord2d(1, 0);
		glVertex3d(+25, yy, 90);
		glTexCoord2d(1, 1);
		glVertex3d(+50, yy, 90);
		glTexCoord2d(0, 1);
		glVertex3d(+50, yy, 10);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(+25, yy - 2, 10);
		glTexCoord2d(1, 0);
		glVertex3d(+25, yy - 2, 90);
		glTexCoord2d(1, 1);
		glVertex3d(+50, yy - 2, 90);
		glTexCoord2d(0, 1);
		glVertex3d(+50, yy - 2, 10);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(+25, yy - 2, 10);
		glTexCoord2d(1, 0);
		glVertex3d(+25, yy - 2, 90);
		glTexCoord2d(1, 1);
		glVertex3d(+25, yy, 90);
		glTexCoord2d(0, 1);
		glVertex3d(+25, yy, 10);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(+50, yy - 2, 10);
		glTexCoord2d(1, 0);
		glVertex3d(+25, yy - 2, 10);
		glTexCoord2d(1, 1);
		glVertex3d(+25, yy, 10);
		glTexCoord2d(0, 1);
		glVertex3d(+50, yy, 10);
		glEnd();
		 yy = -30;
		glBindTexture(GL_TEXTURE_2D, wood);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(+25, yy, 10);
		glTexCoord2d(1, 0);
		glVertex3d(+25, yy, 90);
		glTexCoord2d(1, 1);
		glVertex3d(+50, yy, 90);
		glTexCoord2d(0, 1);
		glVertex3d(+50, yy, 10);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(+25, yy - 2, 10);
		glTexCoord2d(1, 0);
		glVertex3d(+25, yy - 2, 90);
		glTexCoord2d(1, 1);
		glVertex3d(+50, yy - 2, 90);
		glTexCoord2d(0, 1);
		glVertex3d(+50, yy - 2, 10);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(+25, yy - 2, 10);
		glTexCoord2d(1, 0);
		glVertex3d(+25, yy - 2, 90);
		glTexCoord2d(1, 1);
		glVertex3d(+25, yy, 90);
		glTexCoord2d(0, 1);
		glVertex3d(+25, yy, 10);
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(+50, yy - 2, 10);
		glTexCoord2d(1, 0);
		glVertex3d(+25, yy - 2, 10);
		glTexCoord2d(1, 1);
		glVertex3d(+25, yy, 10);
		glTexCoord2d(0, 1);
		glVertex3d(+50, yy, 10);
		glEnd();
		glPopMatrix();

		tools::WallWithDoor(x, y, z, trainFront, openDoor);
		tools::WallWithDoor(x, y, -z, trainFront, openDoor2);
		tools::TopDown(x, y, z, trainTop1, trainbottom1);
		tools::WallRightLeftWithWindowHole(x - 5, y, z, roomKitchen2);
		tools::WallRightLeftWithWindowHole(-x + 5, y, z, roomKitchen2);
		tools::WallWithDoorHole(x, y, z + 5, roomKitchen2);
		tools::WallWithDoorHole(x, y, -z - 5, roomKitchen2);
		tools::WallRightLeftWithWindow(-x, y, z, trainEdge1);
		tools::WallRightLeftWithWindow(x, y, z, trainEdge1);
	}

void roadGroub(double roadSpeed) {
	glPushMatrix();
	glTranslated(0, -55, 0);
	road::roadBetween(roadBetween1, road8);
	glPopMatrix();

	//⁄‘»
	glPushMatrix();
	glTranslated(0, -55, 0);
	road::road1(road1);
	road::roadRight(roadRight1, 100, 80);
	road::roadLeft(roadRight1);

	/*glPushMatrix();
	glTranslated(500, 0, -5000);
	road::ad(ad1, roomKitchen6, 150, 150);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-500, 0, -5000);
	road::ad(ad3, roomKitchen6, 150, 150);
	glPopMatrix();

	glPushMatrix();
	glTranslated(500, 0, -10000);
	road::ad(ad4, roomKitchen6, 150, 150);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-500, 0, -10000);
	road::ad(ad5, roomKitchen6, 150, 150);
	glPopMatrix();

	glPushMatrix();
	glTranslated(500, 0, -17000);
	road::ad(ad6, roomKitchen6, 150, 150);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-500, 0, -17000);
	road::ad(ad7, roomKitchen6, 150, 150);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, -2000);
	//road::ishara(ad2, roomKitchen6);
	glTranslated(0, 0, -11000);
	//road::ishara(ad2, roomKitchen6);
	glPopMatrix();*/

	glPopMatrix();
	glPushMatrix();
	glTranslated(0, -55, -14000);
	road::roadBetween(roadBetween1, road8);
	glPopMatrix();

	
	glPushMatrix();
	glRotated(90, 0, 1,0);
	glTranslated(0, -55, -8000);
	road::roadBetween(roadBetween1, road8);
	glPopMatrix();

	glPushMatrix();
	glRotated(-90, 0, 1,0);
	glTranslated(0, -55, -8000);
	road::roadBetween(roadBetween1, road8);
	glPopMatrix();
	//glPushMatrix();
	/*glTranslated(0, -55, -23000);
	//road::roadBetween(roadBetween1, road4);
	glPopMatrix();*/

	//»Õ—
	/*glPushMatrix();

	glTranslated(0, -55, -26000);
	road::road1(road3);
	road::roadRight(roadRight3, 20, 30);
	road::roadLeft(roadLeft3);

	glPushMatrix();
	road::shipGr(lll3, bl, sh, wood, mm, ww, ww1, ww2);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, -2000);
	//road::ishara(ad2, roomKitchen6);
	glTranslated(0, 0, -11000);
	//road::ishara(ad2, roomKitchen6);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -55, -46000);
	road::roadBetween(roadBetween1, road5);
	glPopMatrix();

	//—„·
	glPushMatrix();
	glTranslated(0, -55, -49000);
	road::road1(road2);
	road::roadRight(roadRight2, 80, 60);
	road::roadLeft(roadRight2);

	glPushMatrix();
	glTranslated(0, 0, -22000);
	road::tentGr(jj,jj, kk, jj1, kk1, wood, ll, ll2, pp, ll1, lll1);
	glPopMatrix();

	

	glPushMatrix();
	glTranslated(0, 0, -2000);
	//road::ishara(ad2, roomKitchen6);
	glTranslated(0, 0, -11000);
	//road::ishara(ad2, roomKitchen6);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -55, -69000);
	road::roadBetween(roadBetween1, road9);
	glPopMatrix();

	//À·Ã
	glPushMatrix();
	glTranslated(0, -55, - 72000);
	road::road1(road7);
	road::roadRight(roadRight4, 40, 60);
	road::roadLeft(roadRight4);
	glPushMatrix();
	glTranslated(500, -40, -700);
	road::snowTreeRe(snowTree);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-500, -40, -700);
	road::snowTreeRe(snowTree);
	glPopMatrix();*/

	/*glPushMatrix();
	glTranslated(-3000, 0, -2000);
	road::snowHousRe(snowHous1, snowHous2, snowHous3, snowHous4, roadRight4);
	glPopMatrix();
	glPushMatrix();
	glTranslated(3000, 0, -2000);
	road::snowHousRe(snowHous1, snowHous2, snowHous3, snowHous4, roadRight4);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-6000, 0, -3500);
	road::snowHousRe(snowHous1, snowHous2, snowHous3, snowHous4, roadRight4);
	glPopMatrix();
	glPushMatrix();
	glTranslated(6000, 0, -3500);
	road::snowHousRe(snowHous1, snowHous2, snowHous3, snowHous4, roadRight4);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2000, 5, 0);
	road::snowRoad(snowRoad);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-2000, 5, 0);
	road::snowRoad(snowRoad);
	glPopMatrix();
	glPushMatrix();
	glTranslated(5000, 5, 0);
	road::snowRoad(snowRoad);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-5000, 5, 0);
	road::snowRoad(snowRoad);
	glPopMatrix();*/

	/*glPushMatrix();
	glTranslated(0, 0, -2000);
	//road::ishara(ad2, roomKitchen6);
	glTranslated(0, 0, -11000);
	//road::ishara(ad2, roomKitchen6);
	glPopMatrix();

	glPopMatrix();



	


	glPushMatrix();
	glTranslated(0, -55, -92000);
	road::roadBetween(roadBetween1, road8);
	glPopMatrix();

	//⁄‘»
	glPushMatrix();
	glTranslated(0, -55,-95000);
	road::road1(road1);
	road::roadRight(roadRight1, 100, 80);
	road::roadLeft(roadRight1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -55, -115000);
	road::roadBetween(roadBetween1, road8);
	glPopMatrix();



	//À·Ã
	glPushMatrix();
	glTranslated(0, -55,+20000);
	road::road1(road7);
	road::roadRight(roadRight4, 40, 60);
	road::roadLeft(roadRight4);
	glPushMatrix();
	glTranslated(500, -40, -700);
	road::snowTreeRe(snowTree);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-500, -40, -700);
	road::snowTreeRe(snowTree);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 0, -2000);
	//road::ishara(ad2, roomKitchen6);
	glTranslated(0, 0, -11000);
	//road::ishara(ad2, roomKitchen6);
	glPopMatrix();

	glPopMatrix();*/


	glPushMatrix();
	//glTranslated(900, 0, 900);
	glTranslated(0, -54, -3000);
	glRotated(-25, 0, 1,0);
   // road::road1Gro( structure1,  structure2,  structure3,  structure4,  structure5,  structure6,  structure7,  trees1,  trees2, structure, street);
    road::buildingSakhra(-3700, 0, -7000, 1800, 1800, 900,300,300,450, carbet,newWall,wallWithDoor);//2

	int x=800;
	road::allTrees(x,trees1,trees2);
    
	 //road::trees(1500, 90, -2200, 60, 120, 30, 30, 150, trees1, trees2, 25, 20);
}
void bath(double x, double y, double z,bool openDoor) {
	tools::WallWithDoor(x, y, -z, trainFront, openDoor);
	tools::WallWithoutDoor(x, y, z, trainFront);
	glPushMatrix();
	glRotated(180, 0, 1,0);
	tools::TopDown(x, y, z, trainTop1, trainbottom1);
	glPopMatrix();
	tools::WallRightLeftWithoutWindowOutside(-x, y, z, trainEdge2);
	tools::WallRightLeftWithoutWindowOutside(x, y, z, trainEdge2);
}
void room3(double x1, double x2, double y1, double y2, double z1, double z2, int door, bool n)
{
	bathroom::room(x1, x2, y1, y2, z1, z2, img1);
	bathroom::wc(x1, x2, y1, y2, z1, z2, f, e);
	bathroom::hand(x1, x2, y1, y2, z1, z2, h);
	bathroom::washingmachine(x1, x2, y1, y2, z1, z2, j, k);
	bathroom::mirror(x1, y1, y2, z2, m);
	bathroom::door(x1, x2, y1, y2, z1, z2, door, n);
}
void mirror()
{
	glBindTexture(GL_TEXTURE_2D, m1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-14.50, -35, 9);
	glTexCoord2d(1, 0);
	glVertex3f(14.50, -35, 9);
	glTexCoord2d(1, 1);
	glVertex3f(14.50, 20, 9);
	glTexCoord2d(0, 1);
	glVertex3f(-14.50, 20, 9);
	glEnd();
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, m2);
	glBlendFunc(GL_SRC_ALPHA, GL_DST_ALPHA);
	glEnable(GL_BLEND);
	glColor4f(1.0f, 1.0f, 1.0f, 0.6f);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-12, -25, 10);
	glTexCoord2d(1, 0);
	glVertex3f(12, -25, 10);
	glTexCoord2d(1, 1);
	glVertex3f(12, 17, 10);
	glTexCoord2d(0, 1);
	glVertex3f(-12, 17, 10);
	glEnd();
	glDisable(GL_BLEND);
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, m3);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-14.5, 17, 10);
	glTexCoord2d(1, 0);
	glVertex3f(15, 17, 10);
	glTexCoord2d(1, 1);
	glVertex3f(15, 20.2, 10);
	glTexCoord2d(0, 1);
	glVertex3f(-14.5, 20.2, 10);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-14.5, -27, 10);
	glTexCoord2d(1, 0);
	glVertex3f(-12, -27, 10);
	glTexCoord2d(1, 1);
	glVertex3f(-12, 17.2, 10);
	glTexCoord2d(0, 1);
	glVertex3f(-14.5, 17.2, 10);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(12, -27, 10);
	glTexCoord2d(1, 0);
	glVertex3f(15, -27, 10);
	glTexCoord2d(1, 1);
	glVertex3f(15, 17.2, 10);
	glTexCoord2d(0, 1);
	glVertex3f(12, 17.2, 10);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-14.5, -28, 10);
	glTexCoord2d(1, 0);
	glVertex3f(15, -28, 10);
	glTexCoord2d(1, 1);
	glVertex3f(15, -25, 10);
	glTexCoord2d(0, 1);
	glVertex3f(-14.5, -25, 10);
	glEnd();
}
void outbath()
{
	glBindTexture(GL_TEXTURE_2D, img2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-49.98, -35, -99.98);
	glTexCoord2d(1, 0);
	glVertex3f(49.98, -35, -99.98);
	glTexCoord2d(1, 1);
	glVertex3f(49.98, -35, 99.98);
	glTexCoord2d(0, 1);
	glVertex3f(-49.98, -35, 99.98);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, img1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-15, 20, 10);
	glTexCoord2d(1, 0);
	glVertex3f(15, 20, 10);
	glTexCoord2d(1, 1);
	glVertex3f(15, 49.98, 10);
	glTexCoord2d(0, 1);
	glVertex3f(-15, 49.98, 10);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-15, -35, 10);
	glTexCoord2d(1, 0);
	glVertex3f(15, -35, 10);
	glTexCoord2d(1, 1);
	glVertex3f(15, -28, 10);
	glTexCoord2d(0, 1);
	glVertex3f(-15, -28, 10);
	glEnd();
}
void bathroom(bool openDoor,bool n,bool n11) {
	glPushMatrix();
	room3(15, 49.97, -35, 49.98, -99.98, 10, i, n);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-64.5, 0, 0);
	room3(15, 49.97, -35, 49.98, -99.98, 10, i1, n11);
	glTranslated(64.5, 0, 0);
	glPopMatrix();

	bath(x, y, z, openDoor);
	mirror();
	outbath();
}

void rkap1(double x, double y, double z, bool openDoor, bool openDoor2) {

	tools::WallWithDoor(x, y, z, trainFront, openDoor);
	tools::WallWithDoor(x, y, -z, trainFront, openDoor2);

	tools::TopDown(x, y, z, trainTop1, trainbottom1);
	rkap::chair(-49, -25, 60, 30, 22, 20, 5, -5,cloth1);//chair(int x, int y, int z,int width,int height,int height1,int depth,int angel)
	rkap::hold(-22, -35, 90, 2, 2, 85,metal);
	rkap::hold(-22, -35, -30, 2, 2, 85, metal);
	rkap::chair(-49, -25, -60, 30, 22, 20, 5, -5,cloth1);
	rkap::chair(-49, -25, 20, 30, 22, 20, 5, -5, cloth1);
	rkap::hold(-22, -35, 50, 2, 2, 85, metal);
	rkap::chair(-49, -25, -20, 30, 22, 20, 5, -5, cloth1);
	rkap::hold(-22, -35, 10, 2, 2, 85, metal);
	rkap::hold_horizontal(-22, 45, -100, 2, 2, 200, metal);
	rkap::hold(-22, -35, -90, 2, 2, 85, metal);
	rkap::hold(-22, -35, -30, 2, 2, 85, metal);
	rkap::chair(19, -25, 60, 30, 22, 20, 5, -5, cloth1);
	rkap::hold(22, -35, 90, 2, 2, 85, metal);
	rkap::hold(22, -35, -30, 2, 2, 85, metal);
	rkap::chair(19, -25, 20, 30, 22, 20, 5, -5, cloth1);
	rkap::chair(19, -25, -20, 30, 22, 20, 5, -5, cloth1);
	rkap::hold(22, -35, 50, 2, 2, 85, metal);
	rkap::chair(19, -25, -60, 30, 22, 20, 5, -5, cloth1);
	rkap::hold(22, -35, 10, 2, 2, 85, metal);
	rkap::hold_horizontal(22, 45, -100, 2, 2, 200, metal);
	rkap::hold(22, -35, -90, 2, 2, 85, metal);
	rkap::hold(22, -35, -30, 2, 2, 85, metal);
	tools::WallRightLeftWithWindow(-x, y, z, trainEdge1);
	tools::WallRightLeftWithWindow(x, y, z, trainEdge1);
}
void rkap3(double x, double y, double z, bool openDoor, bool openDoor2) {

	tools::WallWithDoor(x, y, z, trainFront, openDoor);
	tools::WallWithDoor(x, y, -z, trainFront, openDoor2);

	tools::TopDown(x, y, z, trainTop1, trainbottom1);
	rkap::chair(-49, -25, 60, 30, 22, 20, 5, -5, cloth);//chair(int x, int y, int z,int width,int height,int height1,int depth,int angel)
	rkap::hold(-22, -35, 90, 2, 2, 85, metal);
	rkap::hold(-22, -35, -30, 2, 2, 85, metal);
	rkap::chair(-49, -25, -60, 30, 22, 20, 5, -5, cloth);
	rkap::chair(-49, -25, 20, 30, 22, 20, 5, -5, cloth);
	rkap::hold(-22, -35, 50, 2, 2, 85, metal);
	rkap::chair(-49, -25, -20, 30, 22, 20, 5, -5, cloth);
	rkap::hold(-22, -35, 10, 2, 2, 85, metal);
	rkap::hold_horizontal(-22, 45, -100, 2, 2, 200, metal);
	rkap::hold(-22, -35, -90, 2, 2, 85, metal);
	rkap::hold(-22, -35, -30, 2, 2, 85, metal);
	rkap::chair(19, -25, 60, 30, 22, 20, 5, -5, cloth);
	rkap::hold(22, -35, 90, 2, 2, 85, metal);
	rkap::hold(22, -35, -30, 2, 2, 85, metal);
	rkap::chair(19, -25, 20, 30, 22, 20, 5, -5, cloth);
	rkap::chair(19, -25, -20, 30, 22, 20, 5, -5, cloth);
	rkap::hold(22, -35, 50, 2, 2, 85, metal);
	rkap::chair(19, -25, -60, 30, 22, 20, 5, -5, cloth);
	rkap::hold(22, -35, 10, 2, 2, 85, metal);
	rkap::hold_horizontal(22, 45, -100, 2, 2, 200, metal);
	rkap::hold(22, -35, -90, 2, 2, 85, metal);
	rkap::hold(22, -35, -30, 2, 2, 85, metal);
	tools::WallRightLeftWithWindow(-x, y, z, trainEdge1);
	tools::WallRightLeftWithWindow(x, y, z, trainEdge1);
}
void rkap2(double x, double y, double z, bool openDoor, bool openDoor2) {

	tools::WallWithDoor(x, y, z, trainFront, openDoor);
	tools::WallWithDoor(x, y, -z, trainFront, openDoor2);

	tools::TopDown(x, y, z, trainTop1, trainbottom1);

	//the first side
	rkap::rotated1chair(27, -25, 60, 30, 22, 5, cloth1);
	rkap::hold(29, -35, 90, 2, 2, 85, metal);
	rkap::hold(29, -35, -30, 2, 2, 85, metal);
	rkap::rotated1chair(27, -25, -60, 30, 22, 5, cloth1);
	rkap::rotated1chair(27, -25, 20, 30, 22, 5, cloth1);
	rkap::hold(29, -35, 50, 2, 2, 85, metal);
	rkap::rotated1chair(27, -25, -20, 30, 22, 5, cloth1);
	rkap::hold(29, -35, 10, 2, 2, 85, metal);
	rkap::hold_horizontal(29, 45, -100, 2, 2, 200, metal);
	rkap::hold(29, -35, -90, 2, 2, 85, metal);
	rkap::hold(29, -35, -30, 2, 2, 85, metal);




	//the second side
	rkap::rotated2chair(-49, -25, 60, 30, 22, 5, cloth1);
	rkap::hold(-29, -35, 90, 2, 2, 85, metal);
	rkap::hold(-29, -35, -30, 2, 2, 85, metal);
	rkap::rotated2chair(-49, -25, -60, 30, 22, 5, cloth1);
	rkap::rotated2chair(-49, -25, 20, 30, 22, 5, cloth1);
	rkap::hold(-29, -35, 50, 2, 2, 85, metal);
	rkap::rotated2chair(-49, -25, -20, 30, 22, 5, cloth1);
	rkap::hold(-29, -35, 10, 2, 2, 85, metal);
	rkap::hold_horizontal(-29, 45, -100, 2, 2, 200, metal);
	rkap::hold(-29, -35, -90, 2, 2, 85, metal);
	rkap::hold(-29, -35, -30, 2, 2, 85, metal);
	tools::WallRightLeftWithWindow(-x, y, z, trainEdge1);
	tools::WallRightLeftWithWindow(x, y, z, trainEdge1);
}

void DrawCircle(float cx, float cy, float r, int num_segments) {
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++) {
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 
		glColor3ub(255, 0, 0);
		glVertex2f(x + cx, y + cy);//output vertex 
	}
	glEnd();
}

Model_3DS* vase1;
Model_3DS* vase2;
Model_3DS* vase3;
Model_3DS* vase4;


void cinemaRoom(double x, double y, double z, bool openDoor, bool openDoor2, bool turnOn, int imgSofa, int imgWood) {

	tools::WallWithDoor(x, y, z, trainFront, openDoor);
	tools::WallWithDoor(x, y, -z, trainFront, openDoor2);
	tools::TopDown(x, y, z, trainTop1, wall);
	tools::WallRightLeftWithoutWindowOutside(-x, y, z, trainEdge2);
	tools::WallRightLeftWithoutWindowOutside(x, y, z, trainEdge2);

}



GLuint _displayListId;


int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	MyCamera = Camera();
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	glEnable(GL_TEXTURE_2D);
	back = LoadTexture("images/Box_Back.bmp");
	Right = LoadTexture("images/Box_Right.bmp");
	Front = LoadTexture("images/Box_Front.bmp");
	Left = LoadTexture("images/Box_Left.bmp");
	Top = LoadTexture("images/Box_Top.bmp");
	bottom = LoadTexture("images/Box_bottom.bmp");
	road1 = LoadTexture("images/roadBetween1.bmp");
	road2 = LoadTexture("images/roadBetween1.bmp");
	road3 = LoadTexture("images/roadBetween1.bmp");
	road4 = LoadTexture("images/roadBetween1.bmp");
	road5 = LoadTexture("images/roadBetween1.bmp");
	road6 = LoadTexture("images/roadBetween1.bmp");
	road7 = LoadTexture("images/roadBetween1.bmp");
	road8 = LoadTexture("images/roadBetween1.bmp");
	road9 = LoadTexture("images/roadBetween1.bmp");
	roadRight1 = LoadTexture("images/roadBetween1.bmp");
	roadRight2 = LoadTexture("images/roadRight2.bmp");
	roadRight3 = LoadTexture("images/roadRight3.bmp");
	roadRight4 = LoadTexture("images/roadRight4.bmp");
	roadLeft1 = LoadTexture("images/roadLeft1.bmp");
	roadLeft2 = LoadTexture("images/roadLeft2.bmp");
	roadLeft3 = LoadTexture("images/roadLeft3.bmp");
	roadBetween1 = LoadTexture("images/roadBetween1.bmp");
	roadBetween2 = LoadTexture("images/roadBetween2.bmp");

	roomKitchen1 = LoadTexture("images/roomKitchen1.bmp");
	roomKitchen2 = LoadTexture("images/roomKitchen2.bmp");
	roomKitchen3 = LoadTexture("images/roomKitchen3.bmp");
	roomKitchen4 = LoadTexture("images/roomKitchen4.bmp");
	roomKitchen5 = LoadTexture("images/roomKitchen5.bmp");
	roomKitchen6 = LoadTexture("images/roomKitchen6.bmp");
	roomKitchen7 = LoadTexture("images/roomKitchen7.bmp");
	roomKitchen8 = LoadTexture("images/roomKitchen8.bmp");
	roomKitchen9 = LoadTexture("images/roomKitchen9.bmp");

	//trainEdge1 = LoadTexture("images/trainleft1.bmp");
	//trainEdge2 = LoadTexture("images/trainleft2.bmp");
	//trainEdge3 = LoadTexture("images/trainleft3.bmp");
	//trainFront = LoadTexture("images/trainfront1.bmp");
	//trainTop1 = LoadTexture("images/trainTop1.bmp");
	//trainTop2 = LoadTexture("images/trainTop2.bmp");
	//trainbottom1 = LoadTexture("images/trainbottom1.bmp");

	//ahmad
	img1 = LoadTexture("images/B-2.bmp");
	img2 = LoadTexture("images/C-2.bmp");
	e = LoadTexture("images/E-2.bmp");
	f = LoadTexture("images/F-2.bmp");
	h = LoadTexture("images/H-2.bmp");
	i = LoadTexture("images/I-2.bmp");
	j = LoadTexture("images/J-2.bmp");
	k = LoadTexture("images/K-2.bmp");
	m = LoadTexture("images/M-2.bmp");
	i1 = LoadTexture("images/I1-2.bmp");
	m1 = LoadTexture("images/M1-2.bmp");
	m2 = LoadTexture("images/M2-2.bmp");
	m3 = LoadTexture("images/M3-2.bmp");
	kk = LoadTexture("images/kk.bmp");
	jj = LoadTexture("images/jj.bmp");
	ll = LoadTexture("images/ll.bmp");
	pp = LoadTexture("images/pp.bmp");
	jj1 = LoadTexture("images/jj1.bmp");
	kk1 = LoadTexture("images/kk1.bmp");
	ll1 = LoadTexture("images/ll1.bmp");
	lll1 = LoadTexture("images/lll1.bmp");
	ll2 = LoadTexture("images/ll2.bmp");
	mm = LoadTexture("images/m.bmp");
	ww = LoadTexture("images/ww.bmp");
	ww1 = LoadTexture("images/ww1.bmp");
	ww2 = LoadTexture("images/ww2.bmp");
	lll3 = LoadTexture("images/l.bmp");
	bl = LoadTexture("images/bl.bmp");
	sh = LoadTexture("images/sh.bmp");

	//trablse
	cloth = LoadTexture("images/cloth.bmp");
	cloth1 = LoadTexture("images/cloth1.bmp");
	metal = LoadTexture("images/metal.bmp");
	structure = LoadTexture("images/structure.bmp");
	structure1 = LoadTexture("images/structure1.bmp");
	structure2 = LoadTexture("images/structure2.bmp");
	structure3 = LoadTexture("images/structure3.bmp");
	structure4 = LoadTexture("images/structure4.bmp");
	structure5 = LoadTexture("images/structure5.bmp");
	structure6 = LoadTexture("images/structure6.bmp");
	structure7 = LoadTexture("images/structure7.bmp");
	street = LoadTexture("images/ww1.bmp");
	trees1 = LoadTexture("images/trees1.bmp");
	trees2 = LoadTexture("images/trees2.bmp");

	//qattan
	wallpaper = LoadTexture("images/wallpaper2.bmp");
	bedRoomDoor = LoadTexture("images/bedRoomDoor2.bmp");
	wood = LoadTexture("images/wood.bmp");
	fabric = LoadTexture("images/fabric.bmp");
	curtains = LoadTexture("images/curtain.bmp");
	ground = LoadTexture("images/ground.bmp");
	door = LoadTexture("images/door4.bmp");
	//bassam
	cinemaWall = LoadTexture("images/cinemaWall.bmp");
	wall = LoadTexture("images/wall.bmp", 255);
	sofaBack = LoadTexture("images/sofaBack.bmp");
	sofa1 = LoadTexture("images/sofaBack.bmp", 255);
	sofa2 = LoadTexture("images/sofaBack.bmp", 255);
	//snow
	snowTree = LoadTexture("images/snowTree.bmp", 255);
	snowHous1 = LoadTexture("images/snowHous1.bmp", 255);
	snowHous2 = LoadTexture("images/snowHous2.bmp", 255);
	snowHous3 = LoadTexture("images/snowHous3.bmp", 255);
	snowHous4 = LoadTexture("images/snowHous4.bmp", 255);
	snowRoad = LoadTexture("images/snowRoad.bmp", 255);
	//ad
	ad1 = LoadTexture("images/AlQassam.bmp", 255);
	//ad2= LoadTexture("images/ad2.bmp", 255);
	ad3 = LoadTexture("images/ad3.bmp", 255);
	ad4 = LoadTexture("images/ad4.bmp", 255);
	ad5 = LoadTexture("images/ad5.bmp", 255);
	ad6 = LoadTexture("images/ad6.bmp", 255);
	ad7 = LoadTexture("images/ad7.bmp", 255);
	//controll
	frontControll = LoadTexture("images/frontControll.bmp", 255);
	leftControll = LoadTexture("images/leftControll.bmp", 255);
	rightControll = LoadTexture("images/rightControll.bmp", 255);
	controlll = LoadTexture("images/controll.bmp", 255);



	//new photo
	carbet = LoadTexture("images/carbet.bmp", 255);
	newWall = LoadTexture("images/wall.bmp", 255);
	wallWithDoor = LoadTexture("images/wallWithDoor.bmp", 255);


	glEnable(GL_COLOR_MATERIAL);


	//vase1 = new Model_3DS();
	//vase1->Load("Vase.3DS");
	//vase2 = new Model_3DS();
	//vase2->Load("Vase.3DS");
	//vase3 = new Model_3DS();
	//vase3->Load("Vase.3DS");
	//vase4 = new Model_3DS();
	//vase4->Load("Vase.3DS");
	
	_displayListId = glGenLists(1);
	glNewList(_displayListId, GL_COMPILE);
	//cinemaRoom(x, y, z, true, true, true, sofa1, wood);
	glEndList();

	return TRUE;										// Initialization Went OK
}



double roadSpeed = 0, angle = 0;
bool viewLook = 0;
float speedcam = 0.1,speedview=0.1;


void controllroom(double x, double y, double z, bool openDoor, bool openDoor2, double red, double green, double gg) {


	controll::controllC(x, y, z, controlll, frontControll, rightControll, leftControll, red, green, gg);

	controll::controllChair(x, y, z);

	glColor3ub(255, 255, 255);
	tools::WallWithDoor(x, y, -z, trainFront, openDoor);
	glColor3ub(255, 255, 255);
	controll::controllTopDown(x, y, z, trainTop1, trainbottom1);

	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glColor3ub(255, 255, 255);
	controll::frontWindowcontroll(x, y, z, trainEdge1);
	glPopMatrix();


	controll::rightLeftControllWall(x, y, z, trainEdge1);
	controll::rightLeftControllWall(-x, y, z, trainEdge1);


}
bool handControllFast = false;
bool handControllSlow = false;
//controll
double gg = 165;
double red = 0, green = 0;
bool openDoor[40] = { 0 };
void doorkey() {

	if (keys['O'] && boarders::zd >= 1750 && boarders::zd <= 1920 && boarders::xd >0) {
		openDoor[12] = 1;
	}
	if (keys['P'] && boarders::zd >= 1750 && boarders::zd <= 1920 && boarders::xd >0) {
		openDoor[12] = 0;
	}
	if (keys['O'] && boarders::zd >= 1750 && boarders::zd <= 1920 && boarders::xd <0) {
		openDoor[11] = 1;
	}
	if (keys['P'] && boarders::zd >= 1750 && boarders::zd <= 1920 && boarders::xd <0) {
		openDoor[11] = 0;
	}


	if (keys['O'] && boarders::zd >= 1560 && boarders::zd <= 1800) {
		openDoor[1] = 1;
		openDoor[21] = 0;
	}
	if (keys['P'] && boarders::zd >= 1560 && boarders::zd <= 1800) {
		openDoor[1] = 0;
		openDoor[21] = 1;
	}
	if (keys['O'] && boarders::zd >= 1300 && boarders::zd <= 1560) {
		openDoor[2] = 1;
		openDoor[22] = 0;
	}
	if (keys['P'] && boarders::zd >= 1300 && boarders::zd <= 1560) {
		openDoor[2] = 0;
		openDoor[22] = 1;
	}
	if (keys['O'] && boarders::zd >= 1040 && boarders::zd <= 1300) {
		openDoor[3] = 1;
		openDoor[23] = 0;
	}
	if (keys['P'] && boarders::zd >= 1040 && boarders::zd <= 1300) {
		openDoor[3] = 0;
		openDoor[23] =1;
	}
	if (keys['O'] && boarders::zd >= 780 && boarders::zd <= 1040) {
		openDoor[4] = 1;
		openDoor[24] = 0;
	}
	if (keys['P'] && boarders::zd >= 780 && boarders::zd <= 1040) {
		openDoor[4] = 0;
		openDoor[24] = 1;
	}
	if (keys['O'] && boarders::zd >= 520 && boarders::zd <= 780) {
		openDoor[5] = 1;
		openDoor[25] = 0;
	}
	if (keys['P'] && boarders::zd >= 520 && boarders::zd <= 780) {
		openDoor[5] = 0;
		openDoor[25] = 1;
	}
	if (keys['O'] && boarders::zd >= 260 && boarders::zd <= 520) {
		openDoor[6] = 1;
		openDoor[26] = 0;
	}
	if (keys['P'] && boarders::zd >= 260 && boarders::zd <= 520) {
		openDoor[6] = 0;
		openDoor[26] = 1;
	}
	if (keys['O'] && boarders::zd >= 0 && boarders::zd <= 260) {
		openDoor[7] = 1;
		openDoor[27] = 0;
	}
	if (keys['P'] && boarders::zd >= 0 && boarders::zd <= 260) {
		openDoor[7] = 0;
		openDoor[27] = 1;
	}
	if (keys['O'] && boarders::zd >= -130 && boarders::zd <= 0) {
		openDoor[8] = 1;
		openDoor[28] = 0;
	}
	if (keys['P'] && boarders::zd >= -130 && boarders::zd <= 0) {
		openDoor[8] = 0;
		openDoor[28] = 1;
	}
	if (keys['O'] && boarders::zd >= -130 && boarders::zd <= 0) {
		openDoor[9] = 1;
		openDoor[29] = 0;
	}
	if (keys['P'] && boarders::zd >= -130 && boarders::zd <= 0) {
		openDoor[9] = 0;
		openDoor[29] = 1;
	}

	if (keys['L'] ) {
		openDoor[10] = 1;
	}
	if (keys['K']) {
		openDoor[10] = 0;
	}

}
void fullTrain() {

	//9
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT3);
	glDisable(GL_LIGHT4);
	glPushMatrix();
	glTranslated(0, 0, -130);
	//trainBet();
	glTranslated(0, 0, -130);
	controllroom(x, y, z, openDoor[8], openDoor[10], red, green, gg);
	if (lighting::enableLight1) glEnable(GL_LIGHT1);
	if (lighting::enableLight3) glEnable(GL_LIGHT3);
	if (lighting::enableLight4) glEnable(GL_LIGHT4);

	glPopMatrix();
	//8
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT3);
	glDisable(GL_LIGHT4);
	rkap1(x, y, z, openDoor[8], openDoor[7]);  //0,0,0
	glTranslated(0, 0, 130);
	//trainBet();
	glTranslated(0, 0, 130);
	if (lighting::enableLight2) glEnable(GL_LIGHT2);
	if (lighting::enableLight3) glEnable(GL_LIGHT3);
	if (lighting::enableLight4) glEnable(GL_LIGHT4);
	//7
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT3);
	Kitchen(x, y, z, openDoor[7], openDoor[6]);  //0,0,260
	glTranslated(0, 0, 130);
	//trainBet();
	glTranslated(0, 0, 130);
	if (lighting::enableLight1) glEnable(GL_LIGHT1);
	if (lighting::enableLight2) glEnable(GL_LIGHT2);
	if (lighting::enableLight3) glEnable(GL_LIGHT3);
	//6
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT4);
	cinemaRoom(x, y, z, openDoor[6], openDoor[5], openDoor[10], sofa1, wood);  //0,0,520
	glTranslated(0, 0, 130);
	//trainBet();
	glTranslated(0, 0, 130);
	glPushMatrix();
	glTranslated(0, 0, 0);
	if (lighting::enableLight1) glEnable(GL_LIGHT1);
	if (lighting::enableLight2) glEnable(GL_LIGHT2);
	if (lighting::enableLight4) glEnable(GL_LIGHT4);
	//5                     //0,0,780
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT3);
	glDisable(GL_LIGHT4);
	bedroom::bedRoom(x, y, z, openDoor[5], openDoor[4], openDoor[0], trainFront, trainEdge1, trainTop1, trainbottom1, door, wallpaper, wood, fabric, curtains, ground, 0, 0, 780);
	glPopMatrix();
	glTranslated(0, 0, 130);
	//trainBet();
	glTranslated(0, 0, 130);
	if (lighting::enableLight1) glEnable(GL_LIGHT1);
	if (lighting::enableLight2) glEnable(GL_LIGHT3);
	if (lighting::enableLight4) glEnable(GL_LIGHT4);
	//4
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT3);
	glDisable(GL_LIGHT4);
	rkap3(x, y, z, openDoor[4], openDoor[3]);       //0,0,1040                  
	glTranslated(0, 0, 130);
	//trainBet();
	glTranslated(0, 0, 130);
	if (lighting::enableLight2) glEnable(GL_LIGHT2);
	if (lighting::enableLight3) glEnable(GL_LIGHT3);
	if (lighting::enableLight4) glEnable(GL_LIGHT4);
	//3
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT3);
	rkap2(x, y, z, openDoor[3], openDoor[2]);      //0,0,1300                      
	glTranslated(0, 0, 130);
	//trainBet();
	glTranslated(0, 0, 130);
	if (lighting::enableLight1) glEnable(GL_LIGHT1);
	if (lighting::enableLight2) glEnable(GL_LIGHT2);
	if (lighting::enableLight3) glEnable(GL_LIGHT3);
	//4
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT4);
	rkap1(x, y, z, openDoor[2], openDoor[1]);       //0,0,1560               
	glTranslated(0, 0, 130);
	//trainBet();
	glTranslated(0, 0, 130);
	if (lighting::enableLight1) glEnable(GL_LIGHT1);
	if (lighting::enableLight2) glEnable(GL_LIGHT2);
	if (lighting::enableLight4) glEnable(GL_LIGHT4);
	//2
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT3);
	glDisable(GL_LIGHT4);
	Kitchen(x, y, z, openDoor[1], openDoor[0]);    //0,0,1820
	glTranslated(0, 0, 130);
	//trainBet();
	glTranslated(0, 0, 130);
	glPushMatrix();
	glRotated(180, 0, 1, 0);
	if (lighting::enableLight1) glEnable(GL_LIGHT1);
	if (lighting::enableLight3) glEnable(GL_LIGHT3);
	if (lighting::enableLight4) glEnable(GL_LIGHT4);
	//1
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT3);
	glDisable(GL_LIGHT4);
	bathroom(openDoor[0], openDoor[11], openDoor[12]);                         //0,0,2080
	glPopMatrix();
	if (lighting::enableLight2) glEnable(GL_LIGHT2);
	if (lighting::enableLight3) glEnable(GL_LIGHT3);
	if (lighting::enableLight4) glEnable(GL_LIGHT4);
}

float color[4] = {1.0f,1.0f,1.0f,0.5f};


////////////////////////////////////////////////////////////////Audio

bool trainSound = true;
int soundCount1 = 0;
int soundCount2 = 0;
int soundCount3 = 0;
int soundCount4 = 0;

int gameSoundCount = 0;
int doorSoundCount = 0;


//////////////////////////////Winter, Desert ,City , Beach
bool trainSeasonsSound1;
bool trainSeasonsSound2;
bool trainSeasonsSound3;
bool trainSeasonsSound4;



bool doorSound = false;

bool TVSound = false;

/////////////////////////////////////////////////////////////////

int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//MyCamera.Render();
	if (keys[VK_CONTROL] ) {
		//speedcam = 2.1;
		speedcam = 0.05;
	}
	if (!keys[VK_CONTROL] ) {
		//speedcam = 0.1;
		speedcam = 0.05;
	}
	/*if (keys['V'] ) {
		viewLook = 1;
		MyCamera.Position = { 1, 999, 3000 };
		MyCamera.View = { 0,-0.8f,-1 };
	}
	if (keys['C'] ) {
		viewLook = 0;
		MyCamera.Position = { 0, 0, 0 };
		MyCamera.View = { 0,0,-1 };
	}*/
	if(viewLook)
		keybord(speedcam);
	else
	    boarders::MovingThroughTheScene(keys, openDoor);
	controlling::control(keys, openDoor);

	if(controlling::lightSwitch)
	lighting::enableLighting(keys);
	else
	glDisable(GL_LIGHTING);
	controlling::control(keys, openDoor);


	glPushMatrix();
	/*if (roadSpeed >= 69000 && roadSpeed <= 99000) {
		glEnable(GL_FOG);
		glFogi(GL_FOG_MODE, GL_LINEAR);
		glFogf(GL_FOG_DENSITY, 0.5);
		glFogfv(GL_FOG_COLOR, color);
		glFogf(GL_FOG_START, -100000);
		glFogf(GL_FOG_END, 100000);
	}
	else
		glDisable(GL_FOG);*/
	glRotated(angle, 0, 1, 0);
	glTranslated(0, 1940, 0);
	skybox(3000, 15000);
	angle += 0.002;////the speed for rotate sky box
	glPopMatrix();


	if (keys[VK_CONTROL] && keys['M'] && speedview <40) {
		speedview += 0.1;
	}
	if (keys[VK_CONTROL] && keys['N'] && speedview >-10) {
		speedview -= 0.1;
	}
	if (keys[VK_CONTROL] && keys['M'] && gg >0) {
		handControllFast = true;
	}
	if (handControllFast) {
		handControllFast = false;
		gg -= 0.5;
	}
	if (keys[VK_CONTROL] && keys['N'] && gg < 180) {
		handControllSlow = true;
	}
	if (handControllSlow) {
		handControllSlow = false;
		gg += 0.5;
	}
	if (speedview <= 0) {
		green = -10;
		red = 0;
	}
	else {

		green = 0;
		red = -10;
	}
	roadGroub(roadSpeed += speedview);
	if (roadSpeed >= 92000) {
		roadSpeed = 0;
	}
	glDisable(GL_FOG);

	if (controlling::lightSwitch) lighting::enableLighting(keys);
	//fullTrain();
	glDisable(GL_LIGHTING);
	

	/////////////////////// Audio /////////////////////////////

	if (speedview ==0) {
		trainSound = false;
	}

	if (speedview > 0 || speedview < 0) {
		trainSound = true;
	}

	
	if (roadSpeed<25000 && roadSpeed>0 && !TVSound && !doorSound) {
		trainSeasonsSound1 = true;
		trainSeasonsSound2 = false;
		trainSeasonsSound3 = false;
		trainSeasonsSound4 = false;

		soundCount2 = 0;
		soundCount3 = 0;
		soundCount4 = 0;
		gameSoundCount = 0;
		doorSoundCount = 0;

	}

	if (roadSpeed<48000 && roadSpeed>25000 && !TVSound && !doorSound) {
		trainSeasonsSound1 = false;
		trainSeasonsSound2 = true;
		trainSeasonsSound3 = false;
		trainSeasonsSound4 = false;

		soundCount1 = 0;
		soundCount3 = 0;
		soundCount4 = 0;
		gameSoundCount = 0;
		doorSoundCount = 0;
	}

	if (roadSpeed<71000 && roadSpeed>48000 && !TVSound && !doorSound) {
		trainSeasonsSound1 = false;
		trainSeasonsSound2 = false;
		trainSeasonsSound3 = true;
		trainSeasonsSound4 = false;

		soundCount1 = 0;
		soundCount2 = 0;
		soundCount4 = 0;
		gameSoundCount = 0;
		doorSoundCount = 0;

	}
	 if (roadSpeed<92000 && roadSpeed > 71000 && !TVSound && !doorSound) {
	 trainSeasonsSound1 = false;
	 trainSeasonsSound2 = false;
	 trainSeasonsSound3 = false;
	 trainSeasonsSound4 = true;

	 soundCount1 = 0;
	 soundCount2 = 0;
	 soundCount3 = 0;
	 gameSoundCount = 0;
	 doorSoundCount = 0;
	 }


	if (keys['T']) {
		trainSeasonsSound1 = false;
		trainSeasonsSound2 = false;
		trainSeasonsSound3 = false;
		trainSeasonsSound4 = false;
		soundCount1 = 0;
		soundCount2 = 0;
		soundCount3 = 0;
		soundCount4 = 0;

		TVSound = true;
	}

	if (keys['Y']) {
		TVSound = false;
	}
	
	if (keys['O']) {
		trainSeasonsSound1 = false;
		trainSeasonsSound2 = false;
		trainSeasonsSound3 = false;
		trainSeasonsSound4 = false;
		soundCount1 = 0;
		soundCount2 = 0;
		soundCount3 = 0;
		soundCount4 = 0;
		doorSound = true;
		TVSound = false;
	}

	//Logic door doesn't work
	
	if (doorSound) {
		if (doorSoundCount % 300 == 0) {
		PlaySound("audios/door_sound_effect.wav", NULL, SND_ASYNC);
		}
		if (doorSoundCount == 300) {
			doorSound = false;
		}
		doorSoundCount++;
	}
	
	//Logic door sound forever and by clicking (P) it will make it false;
	/*
	if (keys['P']) {
		doorSound = false;
	}
	
	if (doorSound) {
		if (doorSoundCount % 200 == 0) {
			PlaySound("audios/door_sound_effect.wav", NULL, SND_ASYNC);
		}
		doorSoundCount++;

	}
	*/

	if (trainSeasonsSound1 && trainSound) {
		if (soundCount1 % 1050 == 0) {
			PlaySound("audios/trainCity_sound_effect.wav", NULL, SND_ASYNC);
		}
		if (soundCount1 == 1050) {
			soundCount1 = 0;
		}
		soundCount1++;
	}
	if (trainSeasonsSound1 && !trainSound) {
		if (soundCount1 % 1050 == 0) {
			PlaySound("audios/city_sound_effect.wav", NULL, SND_ASYNC);
		}
		if (soundCount1 == 1050) {
			soundCount1 = 0;
		}
		soundCount1++;
	}



	if (trainSeasonsSound2 && trainSound) {
		if (soundCount2 % 1050 == 0) {
			PlaySound("audios/trainBeach_sound_effect.wav", NULL, SND_ASYNC);
		}
		if (soundCount2 == 1050) {
			soundCount2 = 0;
		}
		soundCount2++;
	}
	if (trainSeasonsSound2 && !trainSound) {
		if (soundCount2 % 1050 == 0) {
			PlaySound("audios/beach_sound_effect.wav", NULL, SND_ASYNC);
		}
		if (soundCount2 == 1050) {
			soundCount2 = 0;
		}
		soundCount2++;
	}





	if (trainSeasonsSound3 && trainSound) {
		if (soundCount3 % 1040 == 0) {
			PlaySound("audios/trainDesert_sound_effect.wav", NULL, SND_ASYNC);
		}
		if (soundCount3 == 1040) {
			soundCount3 = 0;
		}
		soundCount3++;
	}
	if (trainSeasonsSound3 && !trainSound) {
		if (soundCount3 % 1040 == 0) {
			PlaySound("audios/desert_sound_effect.wav", NULL, SND_ASYNC);
		}
		if (soundCount3 == 1040) {
			soundCount3 = 0;
		}
		soundCount3++;
	}


	if (trainSeasonsSound4 && trainSound) {
		if (soundCount4 % 1050 == 0) {
			PlaySound("audios/trainWinter_sound_effect.wav", NULL, SND_ASYNC);
		}
		if (soundCount4 == 1050) {
			soundCount4 = 0;
		}
		soundCount4++;
	}
	if (trainSeasonsSound4 && !trainSound) {
		if (soundCount4 % 1050 == 0) {
			PlaySound("audios/winter_sound_effect.wav", NULL, SND_ASYNC);
		}
		if (soundCount4 == 1050) {
			soundCount4 = 0;
		}
		soundCount4++;
	}


	//game

	if (TVSound && !trainSound) {
		if (gameSoundCount % 1400 == 0) {
			PlaySound("audios/game_sound_effect.wav", NULL, SND_ASYNC);
		}
		if (gameSoundCount == 1400) {
			gameSoundCount = 0;

		}
		gameSoundCount++;
	}

	if (TVSound && trainSound) {
		if (gameSoundCount % 1400 == 0) {
			PlaySound("audios/trainGame_sound_effect.wav", NULL, SND_ASYNC);
		}
		if (gameSoundCount == 1400) {

			gameSoundCount = 0;
		}
		gameSoundCount++;
	}




	////////////////////////////
	glCallList(_displayListId);
	///////////////////////////


	glFlush();
	return TRUE;
}
LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
	UINT	uMsg,			// Message For This Window
	WPARAM	wParam,			// Additional Message Information
	LPARAM	lParam)			// Additional Message Information
{
	static PAINTSTRUCT ps;

	switch (uMsg)									// Check For Windows Messages
	{
	case WM_PAINT:
		DrawGLScene();
		BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_TIMER:
		DrawGLScene();
		return 0;

	case WM_ACTIVATE:							// Watch For Window Activate Message
	{
		if (!HIWORD(wParam))					// Check Minimization State
		{
			active = TRUE;						// Program Is Active
		}
		else
		{
			active = FALSE;						// Program Is No Longer Active
		}

		return 0;								// Return To The Message Loop
	}

	case WM_SYSCOMMAND:							// Intercept System Commands
	{
		switch (wParam)							// Check System Calls
		{
		case SC_SCREENSAVE:					// Screensaver Trying To Start?
		case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
			return 0;							// Prevent From Happening
		}
		break;									// Exit
	}

	case WM_CLOSE:								// Did We Receive A Close Message?
	{
		PostQuitMessage(0);						// Send A Quit Message
		return 0;								// Jump Back
	}

	case WM_KEYDOWN:							// Is A Key Being Held Down?
	{
		keys[wParam] = TRUE;					// If So, Mark It As TRUE
		return 0;								// Jump Back
	}

	case WM_KEYUP:								// Has A Key Been Released?
	{
		keys[wParam] = FALSE;					// If So, Mark It As FALSE
		return 0;								// Jump Back
	}

	case WM_SIZE:								// Resize The OpenGL Window
	{
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
		return 0;								// Jump Back
	}
	case WM_MOUSEMOVE:
	{
		mouseX = (int)LOWORD(lParam);
		mouseY = (int)HIWORD(lParam);
		isClicked = (LOWORD(wParam) & MK_LBUTTON) ? true : false;
		isRClicked = (LOWORD(wParam) & MK_RBUTTON) ? true : false;
		break;
	}
	case WM_LBUTTONUP:
		isClicked = false; 	 break;
	case WM_RBUTTONUP:
		isRClicked = false;   break;
	case WM_LBUTTONDOWN:
		isClicked = true; 	break;
	case WM_RBUTTONDOWN:
		isRClicked = true;	break;

	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
*	title			- Title To Appear At The Top Of The Window				*
*	width			- Width Of The GL Window Or Fullscreen Mode				*
*	height			- Height Of The GL Window Or Fullscreen Mode			*
*	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
*	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "GL template", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

																	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}


int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

														// Ask The User Which Screen Mode They Prefer
														//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("OpenGL template", 640, 480, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}

	while (!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT)				// Have We Received A Quit Message?
			{
				done = TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active)								// Program Active?
			{
				if (keys[VK_ESCAPE])				// Was ESC Pressed?
				{
					done = TRUE;						// ESC Signalled A Quit
				}
				else								// Not Time To Quit, Update Screen
				{
					DrawGLScene();					// Draw The Scene
					SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
				}
			}

			if (keys[VK_F1])						// Is F1 Being Pressed?
			{
				keys[VK_F1] = FALSE;					// If So Make Key FALSE
				KillGLWindow();						// Kill Our Current Window
				fullscreen = !fullscreen;				// Toggle Fullscreen / Windowed Mode
														// Recreate Our OpenGL Window
				if (!CreateGLWindow("OpenGL template", 640, 480, 16, fullscreen))
				{
					return 0;						// Quit If Window Was Not Created
				}
			}
		}
	}

	// Shutdown
	KillGLWindow();									// Kill The Window
	return (msg.wParam);							// Exit The Program
}
