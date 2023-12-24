#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <GLAUX.H>
#include <texture.h>
#include  "camera.h"
#include "bedroom.h"
#include "tools.h"
#include "boarders.h"



void bedroom::bed(double x,double y,double z,int woodPhoto,int fabricPhoto)
{

	
	glBindTexture(GL_TEXTURE_2D, fabricPhoto); //drawing the fabric:
	glColor3ub(125,0,0);
	glBegin(GL_QUADS);
	//right
	glTexCoord2d(0,0); glVertex3f(x,(2*y)/3,0); glTexCoord2d(5,0); glVertex3f(x,(2*y)/3,z); glTexCoord2d(5,1); glVertex3f(x,y,z); glTexCoord2d(0,1); glVertex3f(x,y,0);
	//left 
	glTexCoord2d(0,0); glVertex3f(0,(2*y)/3,z); glTexCoord2d(5,0); glVertex3f(0,(2*y)/3,0); glTexCoord2d(5,1); glVertex3f(0,y,0); glTexCoord2d(0,1); glVertex3f(0,y,z);
	//up
	glTexCoord2d(0,0); glVertex3f(0,y,0); glTexCoord2d(4,0); glVertex3f(x,y,0); glTexCoord2d(4,1); glVertex3f(x,y,z); glTexCoord2d(0,1); glVertex3f(0,y,z);

	glTexCoord2d(0,0); glVertex3f(x/8,y,(3*z)/4); glTexCoord2d(4,0); glVertex3f((7*x)/8,y,(3*z)/4); glTexCoord2d(4,1); glVertex3f((7*x)/8,y+(y/4),(3*z)/4); glTexCoord2d(0,1); glVertex3f(x/8,y+(y/4),(3*z)/4);

	glTexCoord2d(0,0); glVertex3f(x/8,y+(y/4),(3*z)/4); glTexCoord2d(4,0); glVertex3f((7*x)/8,y+(y/4),(3*z)/4); glTexCoord2d(4,1); glVertex3f((7*x)/8,y+(y/4),z); glTexCoord2d(0,1); glVertex3f(x/8,y+(y/4),z);

	glTexCoord2d(0,0); glVertex3f(x/8,y,z-0.1); glTexCoord2d(4,0); glVertex3f((7*x)/8,y,z-0.1); glTexCoord2d(4,1); glVertex3f((7*x)/8,y+(y/4),z-0.1); glTexCoord2d(0,1); glVertex3f(x/8,y+(y/4),z-0.1);
	glEnd();

	

	glBindTexture(GL_TEXTURE_2D, woodPhoto); //drawing the wood
	glColor3ub(255,255,255);
	
	glBegin(GL_QUADS);
	//front
	glTexCoord2d(0,0); glVertex3f(0,0,0);	glTexCoord2d(3,0); glVertex3f(x,0,0); glTexCoord2d(3,1); glVertex3f(x,y,0); glTexCoord2d(0,1); glVertex3f(0,y,0);
	//back
	glTexCoord2d(0,0); glVertex3f(x,0,z); glTexCoord2d(3,0); glVertex3f(0,0,z); glTexCoord2d(3,3); glVertex3f(0,2*y,z); glTexCoord2d(0,3); glVertex3f(x,2*y,z);
	//right
	glTexCoord2d(0,0); glVertex3f(x,0,0); glTexCoord2d(4,0); glVertex3f(x,0,z); glTexCoord2d(4,1); glVertex3f(x,(2*y)/3,z); glTexCoord2d(0,1); glVertex3f(x,(2*y)/3,0);
	//left
	glTexCoord2d(0,0); glVertex3f(0,0,z); glTexCoord2d(4,0); glVertex3f(0,0,0); glTexCoord2d(4,1); glVertex3f(0,(2*y)/3,0); glTexCoord2d(0,1); glVertex3f(0,(2*y)/3,z);
	glEnd();

	glPushMatrix();
	glScaled(0.5,0.8,0.5);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3f(-x/10,-y/4,x/10);	glTexCoord2d(1,0); glVertex3f(0,-y/4,x/10); glTexCoord2d(1,6); glVertex3f(0,(3*y)/2,x/10); glTexCoord2d(0,6); glVertex3f(-x/10,(3*y)/2,x/10);
	glTexCoord2d(0,0); glVertex3f(0,-y/4,x/10); glTexCoord2d(1,0); glVertex3f(0,-y/4,0); glTexCoord2d(1,6); glVertex3f(0,(3*y)/2,0); glTexCoord2d(0,6); glVertex3f(0,(3*y)/2,x/10);
	glTexCoord2d(0,0); glVertex3f(0,-y/4,0); glTexCoord2d(1,0); glVertex3f(-x/10,-y/4,0); glTexCoord2d(1,6); glVertex3f(-x/10,(3*y)/2,0); glTexCoord2d(0,6); glVertex3f(0,(3*y)/2,0);
	glTexCoord2d(0,0); glVertex3f(-x/10,-y/4,0); glTexCoord2d(1,0); glVertex3f(-x/10,-y/4,x/10); glTexCoord2d(1,6); glVertex3f(-x/10,(3*y)/2,x/10); glTexCoord2d(0,6); glVertex3f(-x/10,(3*y)/2,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(x+(x/20),0,0);
	glScaled(0.5,0.8,0.5);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3f(-x/10,-y/4,x/10);	glTexCoord2d(1,0); glVertex3f(0,-y/4,x/10); glTexCoord2d(1,6); glVertex3f(0,(3*y)/2,x/10); glTexCoord2d(0,6); glVertex3f(-x/10,(3*y)/2,x/10);
	glTexCoord2d(0,0); glVertex3f(0,-y/4,x/10); glTexCoord2d(1,0); glVertex3f(0,-y/4,0); glTexCoord2d(1,6); glVertex3f(0,(3*y)/2,0); glTexCoord2d(0,6); glVertex3f(0,(3*y)/2,x/10);
	glTexCoord2d(0,0); glVertex3f(0,-y/4,0); glTexCoord2d(1,0); glVertex3f(-x/10,-y/4,0); glTexCoord2d(1,6); glVertex3f(-x/10,(3*y)/2,0); glTexCoord2d(0,6); glVertex3f(0,(3*y)/2,0);
	glTexCoord2d(0,0); glVertex3f(-x/10,-y/4,0); glTexCoord2d(1,0); glVertex3f(-x/10,-y/4,x/10); glTexCoord2d(1,6); glVertex3f(-x/10,(3*y)/2,x/10); glTexCoord2d(0,6); glVertex3f(-x/10,(3*y)/2,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,+z);
	glScaled(0.5,1.5,0.5);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3f(-x/10,-y/4,x/10);	glTexCoord2d(1,0); glVertex3f(0,-y/4,x/10); glTexCoord2d(1,6); glVertex3f(0,(3*y)/2,x/10); glTexCoord2d(0,6); glVertex3f(-x/10,(3*y)/2,x/10);
	glTexCoord2d(0,0); glVertex3f(0,-y/4,x/10); glTexCoord2d(1,0); glVertex3f(0,-y/4,0); glTexCoord2d(1,6); glVertex3f(0,(3*y)/2,0); glTexCoord2d(0,6); glVertex3f(0,(3*y)/2,x/10);
	glTexCoord2d(0,0); glVertex3f(0,-y/4,0); glTexCoord2d(1,0); glVertex3f(-x/10,-y/4,0); glTexCoord2d(1,6); glVertex3f(-x/10,(3*y)/2,0); glTexCoord2d(0,6); glVertex3f(0,(3*y)/2,0);
	glTexCoord2d(0,0); glVertex3f(-x/10,-y/4,0); glTexCoord2d(1,0); glVertex3f(-x/10,-y/4,x/10); glTexCoord2d(1,6); glVertex3f(-x/10,(3*y)/2,x/10); glTexCoord2d(0,6); glVertex3f(-x/10,(3*y)/2,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(x+(x/20),0,z);
	glScaled(0.5,1.5,0.5);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3f(-x/10,-y/4,x/10);	glTexCoord2d(1,0); glVertex3f(0,-y/4,x/10); glTexCoord2d(1,6); glVertex3f(0,(3*y)/2,x/10); glTexCoord2d(0,6); glVertex3f(-x/10,(3*y)/2,x/10);
	glTexCoord2d(0,0); glVertex3f(0,-y/4,x/10); glTexCoord2d(1,0); glVertex3f(0,-y/4,0); glTexCoord2d(1,6); glVertex3f(0,(3*y)/2,0); glTexCoord2d(0,6); glVertex3f(0,(3*y)/2,x/10);
	glTexCoord2d(0,0); glVertex3f(0,-y/4,0); glTexCoord2d(1,0); glVertex3f(-x/10,-y/4,0); glTexCoord2d(1,6); glVertex3f(-x/10,(3*y)/2,0); glTexCoord2d(0,6); glVertex3f(0,(3*y)/2,0);
	glTexCoord2d(0,0); glVertex3f(-x/10,-y/4,0); glTexCoord2d(1,0); glVertex3f(-x/10,-y/4,x/10); glTexCoord2d(1,6); glVertex3f(-x/10,(3*y)/2,x/10); glTexCoord2d(0,6); glVertex3f(-x/10,(3*y)/2,0);
	glEnd();
	glPopMatrix();

}

void bedroom::table(double x , int wood){
	glColor3ub(210,105,30);
	auxSolidCube(x);

	glBegin(GL_QUADS);              //the table
	glBindTexture(GL_TEXTURE_2D, wood); 
	glColor3ub(255,255,255); 
	glTexCoord2d(0,0); glVertex3f(-(x+1)/2,(3*x+3)/5,-(x+1)/2); glTexCoord2d(1,0); glVertex3f((x+1)/2,(3*x+3)/5,-(x+1)/2); glTexCoord2d(1,1); glVertex3f((x+1)/2,(3*x+3)/5,(x+1)/2); glTexCoord2d(0,1); glVertex3f(-(x+1)/2,(3*x+3)/5,(x+1)/2);
	glPushMatrix();
	glColor3ub(255,255,255);
	glTranslated(0,1,0);
	glTexCoord2d(0,0); glVertex3f(x/2,1,-(x/2-1)); glTexCoord2d(1,0); glVertex3f(x/2,1,(x/2-1)); glTexCoord2d(1,2); glVertex3f(x/2,(x/2-1),(x/2-1)); glTexCoord2d(0,2); glVertex3f(x/2,(x/2-1),-(x/2-1));
	glTexCoord2d(0,0); glVertex3f(x/2,-(x/2-1),-(x/2-1)); glTexCoord2d(1,0); glVertex3f(x/2,-(x/2-1),(x/2-1)); glTexCoord2d(1,2); glVertex3f(x/2,-1,(x/2-1)); glTexCoord2d(0,2); glVertex3f(x/2,-1,-(x/2-1));
	glPopMatrix();
	glEnd();

	glPushMatrix();           //the wooden board on the table
	glColor3ub(190,105,30);
	glTranslated(0,x/(1.7),0);
	glScaled(11,1,11);
	auxSolidCube(x/10);
	glPopMatrix();

	glPushMatrix();             //the handles
	glColor3ub(255,255,255);
	glTranslated(x/2,3,0);
	auxSolidSphere(0.5);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255,255,255);
	glTranslated(x/2,-3,0);
	auxSolidSphere(0.5);
	glPopMatrix();

	glBegin(GL_QUADS);              //the lights
	//glBindTexture(GL_TEXTURE_2D, wood); 
	glColor3ub(128,0,128); 
		//glBindTexture(GL_TEXTURE_2D, wood); 
	glTexCoord2d(0,0); glVertex3f(x/4,x,x/4); glTexCoord2d(1,0); glVertex3f(x/4,x,-x/4); glTexCoord2d(1,6); glVertex3f(x/8,(4*x)/3,-x/8); glTexCoord2d(0,6); glVertex3f(x/8,(4*x)/3,x/8);
	glTexCoord2d(0,0); glVertex3f(-x/4,x,x/4); glTexCoord2d(1,0); glVertex3f(x/4,x,x/4); glTexCoord2d(1,6); glVertex3f(x/8,(4*x)/3,x/8); glTexCoord2d(0,6); glVertex3f(-x/8,(4*x)/3,x/8);
	glTexCoord2d(0,0); glVertex3f(-x/4,x,-x/4); glTexCoord2d(1,0); glVertex3f(-x/4,x,x/4); glTexCoord2d(1,6); glVertex3f(-x/8,(4*x)/3,x/8); glTexCoord2d(0,6); glVertex3f(-x/8,(4*x)/3,-x/8);
	glTexCoord2d(0,0); glVertex3f(x/4,x,-x/4); glTexCoord2d(1,0); glVertex3f(-x/4,x,-x/4); glTexCoord2d(1,6); glVertex3f(-x/8,(4*x)/3,-x/8); glTexCoord2d(0,6); glVertex3f(x/8,(4*x)/3,-x/8);
	glEnd();

	glPushMatrix();
	glColor3ub(210,105,30);
	glScaled(1,(20*x)/8,1);
	auxSolidCube(x/15);
	glPopMatrix();

	glPushMatrix();           //the wooden board under the light
	glColor3ub(190,105,30);
	glTranslated(0,x/(1.5),0);
	glScaled(3,0.3,3);
	auxSolidCube(x/10);
	glPopMatrix();

}

double bedroom::curtainsRate=0;

void bedroom::curtains(double x, double y, double z, int curtainsPhoto, bool curtainIsOpen){

	if(curtainIsOpen&&curtainsRate<40) curtainsRate+=0.1;
	if(!curtainIsOpen&&curtainsRate>0) curtainsRate-=0.1;
	

	glBindTexture(GL_TEXTURE_2D,curtainsPhoto);
	glBegin(GL_QUADS);              //curtains
	glColor3ub(255,255,255);

	glPushMatrix();
	glTexCoord2d(0,0); glVertex3f(x,-y,-z); glTexCoord2d(z/50,0); glVertex3f(x,-y,-curtainsRate); glTexCoord2d(z/50,y/25); glVertex3f(x,y,-curtainsRate); glTexCoord2d(0,y/25); glVertex3f(x,y,-z);
	glPopMatrix();

	glPushMatrix();
	glTexCoord2d(0,0); glVertex3f(x,-y,curtainsRate); glTexCoord2d(z/50,0); glVertex3f(x,-y,z); glTexCoord2d(z/50,y/25); glVertex3f(x,y,z); glTexCoord2d(0,y/25); glVertex3f(x,y,curtainsRate);
	glPopMatrix();

	glEnd();

}

bool bedroom::doorIsOpen1;
bool bedroom::doorIsOpen2;
int diffX,diffY,diffZ;

void bedroom::bedRoom(double x, double y, double z,bool openDoor, bool openDoor2,bool curtainIsOpen,int trainFront,int trainEdge1,int trainTop1,int trainbottom2,int door,int wallpaper,int wood, int fabric, int curtainsPhoto,int ground,int differentX,int differentY,int differentZ) {
		//doorIsOpen1 = openDoor; 
		//doorIsOpen2 = openDoor2;
		doorIsOpen1 = ( openDoor2==1 ? true : false);
		doorIsOpen2 = ( openDoor==1 ? true : false);
		diffX=differentX;
		diffY=differentY;
		diffZ=differentZ;

		tools::WallWithDoor(x, y, z, trainFront, openDoor);
		tools::WallWithDoor(x, y, -z, trainFront, openDoor2);
		
		tools::TopDown(x, y, z,trainTop1,trainbottom2);

		int t=6;  //the thickness between the inside wall and the outside wall.

		tools::WallWithDoor(x-t,y-t,z+t,door,openDoor);
		tools::WallWithDoor(x-t,y-t,-z-t,door,openDoor2);
		tools::WallRightLeftWithWindowHole(x-t,y-t,z+t,ground);
		tools::WallRightLeftWithWindowHole(-x+t,y-t,z+t,ground);
		//tools::TopDown(x-t,-y+t,z+t,ground,ground);

		glPushMatrix();
		//glTranslated(0,-35,0);
		tools::TopDown(x-t,y-t,z+t,ground,ground);
		glPopMatrix();

		glPushMatrix(); //right bed
		glTranslated(13,-30,-70);
		glRotated(90,0,1,0);
		bedroom::bed(20,10,31,wood,fabric);
		glPopMatrix();

		glPushMatrix(); //right bed
		glTranslated(13,-30,-20);
		glRotated(90,0,1,0);
		bedroom::bed(20,10,31,wood,fabric);
		glPopMatrix();

		glPushMatrix(); //right bed
		glTranslated(13,-30,30);
		glRotated(90,0,1,0);
		bedroom::bed(20,10,31,wood,fabric);
		glPopMatrix();

		glPushMatrix(); //right bed
		glTranslated(13,-30,80);
		glRotated(90,0,1,0);
		bedroom::bed(20,10,31,wood,fabric);
		glPopMatrix();

		glPushMatrix(); //left bed
		glTranslated(-12,-30,-90);
		glRotated(-90,0,1,0);
		bedroom::bed(20,10,31,wood,fabric);
		glPopMatrix();

		glPushMatrix(); //left bed
		glTranslated(-12,-30,-40);
		glRotated(-90,0,1,0);
		bedroom::bed(20,10,31,wood,fabric);
		glPopMatrix();

		glPushMatrix(); //left bed
		glTranslated(-12,-30,10);
		glRotated(-90,0,1,0);
		bedroom::bed(20,10,31,wood,fabric);
		glPopMatrix();

		glPushMatrix(); //left bed
		glTranslated(-12,-30,60);
		glRotated(-90,0,1,0);
		bedroom::bed(20,10,31,wood,fabric);
		glPopMatrix();
		
		glPushMatrix(); //left table1
		glTranslated(-40,-24,45);
		bedroom::table(12,wood);
		glPopMatrix();

		glPushMatrix(); //left table2
		glTranslated(-40,-24,-5);
		bedroom::table(12,wood);
		glPopMatrix();

		glPushMatrix(); //left table3
		glTranslated(-40,-24,-55);
		bedroom::table(12,wood);
		glPopMatrix();

		glPushMatrix(); //right table1
		glTranslated(40,-24,45);
		glRotated(180,0,1,0);
		bedroom::table(12,wood);
		glPopMatrix();

		glPushMatrix(); //right table2
		glTranslated(40,-24,-5);
		glRotated(180,0,1,0);
		bedroom::table(12,wood);
		glPopMatrix();

		glPushMatrix(); //right table3
		glTranslated(40,-24,-55);
		glRotated(180,0,1,0);
		bedroom::table(12,wood);
		glPopMatrix();

		curtains(x-t-1,40,50,curtainsPhoto,curtainIsOpen);         //curtains
		curtains(-x+t+1,40,50,curtainsPhoto,curtainIsOpen);

		glPushMatrix();                                            //the sticks on the top of the curtains
	    glTranslated(x-t-1,40,0);
	    glScaled(1,1,70);
	    auxSolidSphere(1);
	    glPopMatrix();

		glPushMatrix();
	    glTranslated(-x+t+1,40,0);
	    glScaled(1,1,70);
	    auxSolidSphere(1);
	    glPopMatrix();

		tools::WallRightLeftWithWindow(-x, y, z, trainEdge1);
		tools::WallRightLeftWithWindow(x, y, z, trainEdge1);
	}

	void bedroom::bedroomBoarders(bool keys[]){
		boarders::xd;
		
	}

	bool diff(double x,double y){     //use this function for the boarder operations instead of using the (==) operation, because (==) will not work with (float) numbers.
		return (abs(x-y)<3);
	}

	
	bool bedroom::forwardZ(){              //if(diff(x,y)) means: if(x==y)

		if((boarders::xd>15+diffX && boarders::xd<50+diffX) || (boarders::xd>-50+diffX && boarders::xd<-15+diffX)){
			if(diff(boarders::zd,-95+diffZ) || diff(boarders::zd,-45+diffZ) || diff(boarders::zd,5+diffZ) || diff(boarders::zd,55+diffZ) || diff(boarders::zd,90+diffZ)) return false;
		}
		else if(boarders::xd>-15+diffX && boarders::xd<15+diffX){
			if(diff(boarders::zd,90+diffZ) && !doorIsOpen1) return false;
		}
		return true;
	}

	bool bedroom::backwardZ(){
		if((boarders::xd>15+diffX && boarders::xd<50+diffX) || (boarders::xd>-50+diffX && boarders::xd<-15+diffX)){
			if(diff(boarders::zd,80+diffZ) || diff(boarders::zd,30+diffZ) || diff(boarders::zd,-20+diffZ) || diff(boarders::zd,-70+diffZ) || diff(boarders::zd,-90+diffZ)) return false;
		}
		else if(boarders::xd>-15+diffX && boarders::xd<15+diffX){
			if(diff(boarders::zd,-90+diffZ) && !doorIsOpen2) return false;
		}
		return true;
	}

	bool bedroom::forwardX(){
		if((boarders::zd>-95+diffZ && boarders::zd<-70+diffZ)||(boarders::zd>-45+diffZ && boarders::zd<-20+diffZ)||(boarders::zd>5+diffZ && boarders::zd<30+diffZ)||(boarders::zd>55+diffZ && boarders::zd<80+diffZ)){
			if(diff(boarders::xd,15+diffX)) return false;
		}
		else if((boarders::zd>-100+diffZ && boarders::zd<-95+diffZ)||(boarders::zd>-70+diffZ && boarders::zd<-45+diffZ)||(boarders::zd>-20+diffZ && boarders::zd<5+diffZ)||(boarders::zd>30+diffZ && boarders::zd<55+diffZ)||(boarders::zd>80+diffZ && boarders::zd<100+diffZ)){
			if(diff(boarders::xd,40+diffX)) return false;
		}
		return true;
	}

	bool bedroom::backwardX(){
		if((boarders::zd>-95+diffZ && boarders::zd<-70+diffZ)||(boarders::zd>-45+diffZ && boarders::zd<-20+diffZ)||(boarders::zd>5+diffZ && boarders::zd<30+diffZ)||(boarders::zd>55+diffZ && boarders::zd<80+diffZ)){
			if(diff(boarders::xd,-15+diffX)) return false;
		}
		else if((boarders::zd>-100+diffZ && boarders::zd<-95+diffZ)||(boarders::zd>-70+diffZ && boarders::zd<-45+diffZ)||(boarders::zd>-20+diffZ && boarders::zd<5+diffZ)||(boarders::zd>30+diffZ && boarders::zd<55+diffZ)||(boarders::zd>80+diffZ && boarders::zd<100+diffZ)){
			if(diff(boarders::xd,-40+diffX)) return false;
		}
		return true;
	}