#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
//#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <texture.h>
#include  "camera.h"
#include "tools.h"
#include "rkapr.h"
#include "lighting.h"
#include "boarders.h"



int lighting::light1=0;
int lighting::light2=0;
int lighting::light3=0;
int lighting::light4=0;

float Lightpos1[] = { 0, 0,0, 1.0 };
float Lightpos2[] = { 0, 0,0, 1.0};
float Lightpos3[] = { 0, 0,0, 1.0 };
float Lightpos4[] = { 0, 0,0, 1.0};

bool lighting::enableLight1=0;
bool lighting::enableLight2=0;
bool lighting::enableLight3=0;
bool lighting::enableLight4=0;

int dduration=0;

void lighting::enableLighting(bool keys[]){
	dduration++;

	float Lightdiff[] = { 1, 1, 1, 0 };
    float Lightspec[] = { 0, 0, 0, 1 };
    float Lightamb[] = { 0, 0, 0, 1 };
    float Matamb[] = { 1, 1, 1, 1 };  //
    float Matspec[] = { 1, 1, 1, 1 };  //

	if(keys['U']) lighting::light4+=10;
	if(keys['J']) lighting::light4-=10;
	
	/*if(keys['1']) lighting::light1=1900; //bathroom
	if(keys['2']) lighting::light1=1500; //kitchen
	if(keys['3']) lighting::light1=1340; //rkap
	if(keys['4']) lighting::light1=1080; //rkap
	if(keys['5']) lighting::light1=780;  //rkap
	if(keys['6']) lighting::light1=650;  //bedroom
	if(keys['7']) lighting::light1=300;  //cinema
	if(keys['8']) lighting::light1=40;   //kitchen
	if(keys['9']) lighting::light1=-220; //rkap
	if(keys['0']) lighting::light1=-400; //control*/

	//lighting::light1=650;

	if(keys['1'] && dduration>25){
		lighting::enableLight1 ^=1; lighting::light1=2000; dduration=0;
	}
	if(keys['2'] && dduration>25){
		lighting::enableLight2 ^=1; lighting::light2=1900; dduration=0;
	}
	if(keys['3'] && dduration>25){
		lighting::enableLight3 ^=1; lighting::light3=1530; dduration=0;
	}
	if(keys['4'] && dduration>25){
		lighting::enableLight4 ^=1; lighting::light4=1280; dduration=0;
	}
	if(keys['5'] && dduration>25){
		lighting::enableLight1 ^=1; lighting::light1=1000; dduration=0;
	}
	if(keys['6'] && dduration>25){
		lighting::enableLight2 ^=1; lighting::light2=700; dduration=0;
	}
	if(keys['7'] && dduration>25){
		lighting::enableLight3 ^=1; lighting::light3=340; dduration=0;
	}
	if(keys['8'] && dduration>25){
		lighting::enableLight4 ^=1; lighting::light4=240; dduration=0;
	}
	if(keys['9'] && dduration>25){
		lighting::enableLight1 ^=1; lighting::light1=-100; dduration=0;
	}
	if(keys['0'] && dduration>25){
		lighting::enableLight2 ^=1; lighting::light2=-400; dduration=0;
	}





	Lightpos1[0]=0;
	Lightpos1[1]=0;
	Lightpos1[2]=lighting::light1;

	Lightpos2[0]=0;
	Lightpos2[1]=0;
	Lightpos2[2]=lighting::light2;

	Lightpos3[0]=0;
	Lightpos3[1]=0;
	Lightpos3[2]=lighting::light3;

	Lightpos4[0]=0;
	Lightpos4[1]=0;
	Lightpos4[2]=lighting::light4;

	if(lighting::enableLight1) glEnable(GL_LIGHT1);
	else glDisable(GL_LIGHT1);
	if(lighting::enableLight2) glEnable(GL_LIGHT2);
	else glDisable(GL_LIGHT2);
	if(lighting::enableLight3) glEnable(GL_LIGHT3);
	else glDisable(GL_LIGHT3);
	if(lighting::enableLight4) glEnable(GL_LIGHT4);
	else glDisable(GL_LIGHT4);

	glLightfv(GL_LIGHT1, GL_POSITION, Lightpos1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, Lightamb);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Lightdiff);
	glLightfv(GL_LIGHT1, GL_SPECULAR, Lightspec);

	glLightfv(GL_LIGHT2, GL_POSITION, Lightpos2);
	glLightfv(GL_LIGHT2, GL_AMBIENT, Lightamb);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, Lightdiff);
	glLightfv(GL_LIGHT2, GL_SPECULAR, Lightspec);

	glLightfv(GL_LIGHT3, GL_POSITION, Lightpos3);
	glLightfv(GL_LIGHT3, GL_AMBIENT, Lightamb);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, Lightdiff);
	glLightfv(GL_LIGHT3, GL_SPECULAR, Lightspec);

	glLightfv(GL_LIGHT4, GL_POSITION, Lightpos4);
	glLightfv(GL_LIGHT4, GL_AMBIENT, Lightamb);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, Lightdiff);
	glLightfv(GL_LIGHT4, GL_SPECULAR, Lightspec);

	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, Matamb);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Matspec);
	glMateriali(GL_FRONT, GL_SHININESS, 128);

	//glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
}