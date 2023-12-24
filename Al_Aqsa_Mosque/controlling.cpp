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
#include "controlling.h"


int duration=0;
int speed=50;
bool controlling::lightSwitch = 0;

void controlling::control(bool keys[], bool openDoor[]){

	duration++;

	if (keys['O'] && boarders::zd >= 2010 && boarders::zd <= 2180 && boarders::xd >0 && duration>speed) {
		openDoor[12] ^= 1; duration=0;
	}
	if (keys['O'] && boarders::zd >= 2010 && boarders::zd <= 2180 && boarders::xd <0 && duration>speed) {
		openDoor[11] ^= 1; duration=0;
	}

	if (keys['O'] && boarders::zd >= 1820 && boarders::zd <= 2080 && duration>speed) {
		openDoor[0] ^= 1; duration=0;
		openDoor[20] ^=1;
	}
	if (keys['O'] && boarders::zd >= 1560 && boarders::zd <= 1820 && duration>speed) {
		openDoor[1] ^= 1; duration=0;
		openDoor[21] ^=1;
	}
	if (keys['O'] && boarders::zd >= 1300 && boarders::zd <= 1560 && duration>speed) {
		openDoor[2] ^= 1; duration=0;
		openDoor[22] ^=1;
	}
	if (keys['O'] && boarders::zd >= 1040 && boarders::zd <= 1300 && duration>speed) {
		openDoor[3] ^= 1; duration=0;
		openDoor[23] ^=1;
	}
	if (keys['O'] && boarders::zd >= 780 && boarders::zd <= 1040 && duration>speed) {
		openDoor[4] ^= 1; duration=0;
		openDoor[24] ^=1;
	}
	if (keys['O'] && boarders::zd >= 520 && boarders::zd <= 780 && duration>speed) {
		openDoor[5] ^= 1; duration=0;
		openDoor[25] ^=1;
	}
	if (keys['O'] && boarders::zd >= 260 && boarders::zd <= 520 && duration>speed) {
		openDoor[6] ^= 1; duration=0;
		openDoor[26] ^=1;
	}
	if (keys['O'] && boarders::zd >= 0 && boarders::zd <= 260 && duration>speed) {
		openDoor[7] ^= 1; duration=0;
		openDoor[27] ^=1;
	}
	if (keys['O'] && boarders::zd >= -230 && boarders::zd <= 0 && duration>speed) {
		openDoor[8] ^= 1; duration=0;
		openDoor[28] ^=1;
	}
	if (keys['O'] && boarders::zd >= -230 && boarders::zd <= 0 && duration>speed) {
		openDoor[9] ^= 1; duration=0;
		openDoor[29] ^=1;
	}


	if (keys['T']) {
		openDoor[10] = 1;
	}
	if (keys['Y']) {
		openDoor[10] = 0;
	}

	if(keys['I'] && duration>speed){
		for(int i=0; i<130; i++) if(i%10==0)openDoor[i/10]^=1; duration=0;
	}
	if(keys['L'] && duration>speed){
		controlling::lightSwitch ^=1; duration=0; 
	}
	if (keys['P'] && boarders::zd >= 520 && boarders::zd <= 1040 && duration>speed) {
		openDoor[0] ^= 1; duration=0;
	}
}
