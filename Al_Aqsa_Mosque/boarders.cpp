#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Libraryux Library
#include <cmath>
#include <glaux.h>		// Header File For The Gla
#include <GLAUX.H>
#include <texture.h>
#include  "camera.h"
#include "bedroom.h"
#include "tools.h"
#include "boarders.h"

double boarders::angle1=-1.57;
double boarders::angle2=0;
double boarders::angle3=0;
double boarders::xd=0;
double boarders::yd=8;
double boarders::zd=-2600;
double boarders::looking=0.025;
double boarders::velocity=400;
double boarders::cosMovingLength=4;
double boarders::cosMovingVelocity = 0.025;
double boarders::slowv = 0.5;
double boarders:: fastv = 10;
 
//bool	boarders::keys[256];			// Array Used For The Keyboard Routine

bool doors[15];

float gravity = 0;


bool difff(double x,double y){     //use this function for the boarder operations instead of using the (==) operation, because (==) will not work with (float) numbers.
		return (abs(x-y)<3);
}




int kitchenDiffX=0,kitchenDiffY=0,kitchenDiffZ=260;                // #################   kitchen number 1 boarders:    ####################

bool kitchen_backwardZ(){
	if((boarders::xd>-20+kitchenDiffX && boarders::xd<-15+kitchenDiffX)||(boarders::xd>15+kitchenDiffX && boarders::xd<20+kitchenDiffX))
		if(difff(boarders::zd,-90+kitchenDiffZ)) return false;
	if((boarders::xd>-15+kitchenDiffX && boarders::xd<15+kitchenDiffX) && !doors[7])
		if(difff(boarders::zd,-90+kitchenDiffZ)) return false;
	return true;
}
bool kitchen_forwardZ(){
	if((boarders::xd>-20+kitchenDiffX && boarders::xd<-15+kitchenDiffX)||(boarders::xd>15+kitchenDiffX && boarders::xd<20+kitchenDiffX))
		if(difff(boarders::zd,90+kitchenDiffZ)) return false;
	if((boarders::xd>-15+kitchenDiffX && boarders::xd<15+kitchenDiffX) && !doors[6])
		if(difff(boarders::zd,90+kitchenDiffZ)) return false;
	return true;
}
bool kitchen_forwardX(){
	if(boarders::zd>-90+kitchenDiffZ && boarders::zd<90+kitchenDiffZ)
		if(difff(boarders::xd,20+kitchenDiffX)) return false;
	return true;
}
bool kitchen_backwardX(){
	if(boarders::zd>-90+kitchenDiffZ && boarders::zd<90+kitchenDiffZ)
		if(difff(boarders::xd,-20+kitchenDiffX)) return false;
	return true;
}



int kitchenDiffX2=0,kitchenDiffY2=0,kitchenDiffZ2=1820;                // #################   kitchen number 2 boarders:    ####################

bool kitchen_backwardZ2(){
	if((boarders::xd>-20+kitchenDiffX2 && boarders::xd<-15+kitchenDiffX2)||(boarders::xd>15+kitchenDiffX2 && boarders::xd<20+kitchenDiffX2))
		if(difff(boarders::zd,-90+kitchenDiffZ2)) return false;
	if((boarders::xd>-15+kitchenDiffX2 && boarders::xd<15+kitchenDiffX2) && !doors[1])
		if(difff(boarders::zd,-90+kitchenDiffZ2)) return false;
	return true;
}
bool kitchen_forwardZ2(){
	if((boarders::xd>-20+kitchenDiffX2 && boarders::xd<-15+kitchenDiffX2)||(boarders::xd>15+kitchenDiffX2 && boarders::xd<20+kitchenDiffX2))
		if(difff(boarders::zd,90+kitchenDiffZ2)) return false;
	if((boarders::xd>-15+kitchenDiffX2 && boarders::xd<15+kitchenDiffX2) && !doors[0])
		if(difff(boarders::zd,90+kitchenDiffZ2)) return false;
	return true;
}
bool kitchen_forwardX2(){
	if(boarders::zd>-90+kitchenDiffZ2 && boarders::zd<90+kitchenDiffZ2)
		if(difff(boarders::xd,20+kitchenDiffX2)) return false;
	return true;
}
bool kitchen_backwardX2(){
	if(boarders::zd>-90+kitchenDiffZ2 && boarders::zd<90+kitchenDiffZ2)
		if(difff(boarders::xd,-20+kitchenDiffX2)) return false;
	return true;
}


int rkapDiffX3=0,rkapDiffY3=0,rdapDiffZ3=1300;                // #################   rkap number 3 boarders:    ####################

bool rkap_backwardZ3(){
	if((boarders::xd>-40+rkapDiffX3 && boarders::xd<-15+rkapDiffX3)||(boarders::xd>15+rkapDiffX3 && boarders::xd<40+rkapDiffX3))
		if(difff(boarders::zd,-90+rdapDiffZ3)) return false;
	if((boarders::xd>-15+rkapDiffX3 && boarders::xd<15+rkapDiffX3) && !doors[3])
		if(difff(boarders::zd,-90+rdapDiffZ3)) return false;
	return true;
}
bool rkap_forwardZ3(){
	if((boarders::xd>-40+rkapDiffX3 && boarders::xd<-15+rkapDiffX3)||(boarders::xd>15+rkapDiffX3 && boarders::xd<40+rkapDiffX3))
		if(difff(boarders::zd,90+rdapDiffZ3)) return false;
	if((boarders::xd>-15+rkapDiffX3 && boarders::xd<15+rkapDiffX3) && !doors[2])
		if(difff(boarders::zd,90+rdapDiffZ3)) return false;
	return true;
}
bool rkap_forwardX3(){
	if(boarders::zd>-90+rdapDiffZ3 && boarders::zd<90+rdapDiffZ3)
		if(difff(boarders::xd,40+rkapDiffX3)) return false;
	return true;
}
bool rkap_backwardX3(){
	if(boarders::zd>-90+rdapDiffZ3 && boarders::zd<90+rdapDiffZ3)
		if(difff(boarders::xd,-40+rkapDiffX3)) return false;
	return true;
}


int cinemaDiffX=0,cinemaDiffY=0,cinemaDiffZ=520;                // #################   cinema boarders:    ####################

bool cinema_backwardZ(){
	if((boarders::xd>-40+cinemaDiffX && boarders::xd<-15+cinemaDiffX)||(boarders::xd>15+cinemaDiffX && boarders::xd<40+cinemaDiffX))
		if(difff(boarders::zd,-90+cinemaDiffZ)) return false;
	if((boarders::xd>-15+cinemaDiffX && boarders::xd<15+cinemaDiffX) && !doors[6])
		if(difff(boarders::zd,-90+cinemaDiffZ)) return false;
	return true;
}
bool cinema_forwardZ(){
	if((boarders::xd>-40+cinemaDiffX && boarders::xd<-15+cinemaDiffX)||(boarders::xd>15+cinemaDiffX && boarders::xd<40+cinemaDiffX))
		if(difff(boarders::zd,90+cinemaDiffZ)) return false;
	if((boarders::xd>-15+cinemaDiffX && boarders::xd<15+cinemaDiffX) && !doors[5])
		if(difff(boarders::zd,90+cinemaDiffZ)) return false;
	return true;
}
bool cinema_forwardX(){
	if(boarders::zd>-90+cinemaDiffZ && boarders::zd<90+cinemaDiffZ)
		if(difff(boarders::xd,40+cinemaDiffX)) return false;
	return true;
}
bool cinema_backwardX(){
	if(boarders::zd>-90+cinemaDiffZ && boarders::zd<90+cinemaDiffZ)
		if(difff(boarders::xd,-40+cinemaDiffX)) return false;
	return true;
}


int rkapDiffX1=0,rkapDiffY1=0,rkapDiffZ1=0;                // #################   rkap number 1 boarders:    ####################

bool rkap_backwardZ1(){
	if((boarders::xd>-40+rkapDiffX1 && boarders::xd<-15+rkapDiffX1)||(boarders::xd>15+rkapDiffX1 && boarders::xd<40+rkapDiffX1))
		if(difff(boarders::zd,-90+rkapDiffZ1)||difff(boarders::zd,-60+rkapDiffZ1)||difff(boarders::zd,-20+rkapDiffZ1)||difff(boarders::zd,20+rkapDiffZ1)||difff(boarders::zd,60+rkapDiffZ1)||difff(boarders::zd,90+rkapDiffZ1)) return false;
	if((boarders::xd>-15+rkapDiffX1 && boarders::xd<15+rkapDiffX1) && !doors[8])
		if(difff(boarders::zd,-90+rkapDiffZ1)) return false;
	return true;
}
bool rkap_forwardZ1(){
	if((boarders::xd>-40+rkapDiffX1 && boarders::xd<-15+rkapDiffX1)||(boarders::xd>15+rkapDiffX1 && boarders::xd<40+rkapDiffX1))
		if(difff(boarders::zd,-90+rkapDiffZ1)||difff(boarders::zd,-60+rkapDiffZ1)||difff(boarders::zd,-20+rkapDiffZ1)||difff(boarders::zd,20+rkapDiffZ1)||difff(boarders::zd,60+rkapDiffZ1)||difff(boarders::zd,90+rkapDiffZ1)) return false;
	if((boarders::xd>-15+rkapDiffX1 && boarders::xd<15+rkapDiffX1) && !doors[7])
		if(difff(boarders::zd,90+rkapDiffZ1)) return false;
	return true;
}
bool rkap_forwardX1(){
	if(boarders::zd>-90+rkapDiffZ1 && boarders::zd<90+rkapDiffZ1)
		if(difff(boarders::xd,40+rkapDiffX1)) return false;
	return true;
}
bool rkap_backwardX1(){
	if(boarders::zd>-90+rkapDiffZ1 && boarders::zd<90+rkapDiffZ1)
		if(difff(boarders::xd,-40+rkapDiffX1)) return false;
	return true;
}


int rkapDiffX2=0,rkapDiffY2=0,rkapDiffZ2=1040;                // #################   rkap number 2 boarders:    ####################

bool rkap_backwardZ2(){
	if((boarders::xd>-40+rkapDiffX2 && boarders::xd<-15+rkapDiffX2)||(boarders::xd>15+rkapDiffX2 && boarders::xd<40+rkapDiffX2))
		if(difff(boarders::zd,-90+rkapDiffZ2)||difff(boarders::zd,-60+rkapDiffZ2)||difff(boarders::zd,-20+rkapDiffZ2)||difff(boarders::zd,20+rkapDiffZ2)||difff(boarders::zd,60+rkapDiffZ2)||difff(boarders::zd,90+rkapDiffZ2)) return false;
	if((boarders::xd>-15+rkapDiffX2 && boarders::xd<15+rkapDiffX2) && !doors[4])
		if(difff(boarders::zd,-90+rkapDiffZ2)) return false;
	return true;
}
bool rkap_forwardZ2(){
	if((boarders::xd>-40+rkapDiffX2 && boarders::xd<-15+rkapDiffX2)||(boarders::xd>15+rkapDiffX2 && boarders::xd<40+rkapDiffX2))
		if(difff(boarders::zd,-90+rkapDiffZ2)||difff(boarders::zd,-60+rkapDiffZ2)||difff(boarders::zd,-20+rkapDiffZ2)||difff(boarders::zd,20+rkapDiffZ2)||difff(boarders::zd,60+rkapDiffZ2)||difff(boarders::zd,90+rkapDiffZ2)) return false;
	if((boarders::xd>-15+rkapDiffX2 && boarders::xd<15+rkapDiffX2) && !doors[3])
		if(difff(boarders::zd,90+rkapDiffZ2)) return false;
	return true;
}
bool rkap_forwardX2(){
	if(boarders::zd>-90+rkapDiffZ2 && boarders::zd<90+rkapDiffZ2)
		if(difff(boarders::xd,40+rkapDiffX2)) return false;
	return true;
}
bool rkap_backwardX2(){
	if(boarders::zd>-90+rkapDiffZ2 && boarders::zd<90+rkapDiffZ2)
		if(difff(boarders::xd,-40+rkapDiffX2)) return false;
	return true;
}

int controlX=0,controlY=0,controlZ=-260;                // #################   control boarders:    ####################

bool control_forwardZ(){
	if((boarders::xd>-40+controlX && boarders::xd<-15+controlX)||(boarders::xd>15+controlX && boarders::xd<40+controlX))
		if(difff(boarders::zd,90+controlZ)) return false;
	if((boarders::xd>-15+controlX && boarders::xd<15+controlX) && !doors[8])
		if(difff(boarders::zd,90+controlZ)) return false;
	return true;
}
bool control_backwardZ(){
	if(boarders::xd>-40+controlX && boarders::xd<40+controlX)
		if(difff(boarders::zd,-8+controlZ)) return false;
	return true;
}
bool control_forwardX(){
	if(boarders::zd>-10+controlZ && boarders::zd<90+controlZ)
		if(difff(boarders::xd,40+controlX)) return false;
	return true;
}
bool control_backwardX(){
	if(boarders::zd>-10+controlZ && boarders::zd<90+controlZ)
		if(difff(boarders::xd,-40+controlX)) return false;
	return true;
}


int bathroomX=0,bathroomY=0,bathroomZ=2080;                // #################   bathroom boarders:    ####################

bool bathroom_backwardZ(){
	if(boarders::xd>-40+bathroomX && boarders::xd<-15+bathroomX)     //man door
		if((difff(boarders::zd,0+bathroomZ)&&!doors[11]) || difff(boarders::zd,-90+bathroomZ)) return false;
	if(boarders::xd>15+bathroomX && boarders::xd<40+bathroomX)     //woman door
		if((difff(boarders::zd,0+bathroomZ)&&!doors[12]) || difff(boarders::zd,-90+bathroomZ)) return false;
	if((boarders::xd>-15+bathroomX && boarders::xd<15+bathroomX) && !doors[0])       //main door
		if(difff(boarders::zd,-90+bathroomZ)) return false;
	return true;
}
bool bathroom_forwardZ(){
	if(boarders::xd>-40+bathroomX && boarders::xd<-15+bathroomX)     //man door
		if((difff(boarders::zd,-15+bathroomZ)&&!doors[11]) || difff(boarders::zd,90+bathroomZ)) return false;
	if(boarders::xd>15+bathroomX && boarders::xd<40+bathroomX)     //woman door
		if((difff(boarders::zd,-15+bathroomZ)&&!doors[12]) || difff(boarders::zd,90+bathroomZ)) return false;
	if((boarders::xd>-15+bathroomX && boarders::xd<15+bathroomX))       //main door
		if(difff(boarders::zd,-15+bathroomZ)) return false;
	return true;
}
bool bathroom_forwardX(){
	if(boarders::zd<0+bathroomZ && boarders::zd>-90+bathroomZ)
		if(difff(boarders::xd,40+bathroomX)) return false;
	if(boarders::zd<90+bathroomZ && boarders::zd>=0+bathroomZ)
		if(difff(boarders::xd,40+bathroomX) || difff(boarders::xd,-20+bathroomX)) return false;
	return true;
}
bool bathroom_backwardX(){
	if(boarders::zd<0+bathroomZ && boarders::zd>-90+bathroomZ)
		if(difff(boarders::xd,-40+bathroomX)) return false;
	if(boarders::zd<90+bathroomZ && boarders::zd>=0+bathroomZ)
		if(difff(boarders::xd,-40+bathroomX) || difff(boarders::xd,20+bathroomX)) return false;
	return true;
}



int diffb=260;
bool trainbet_backwardZ(){                           // #################   trainbet boarders:    ####################
	if((difff(boarders::zd,(-145+8*diffb)) && !doors[0]) || (difff(boarders::zd,(-145+7*diffb)) && !doors[1]) || (difff(boarders::zd,(-145+6*diffb)) && !doors[2]) || (difff(boarders::zd,(-145+5*diffb)) && !doors[3]) || (difff(boarders::zd,(-145+4*diffb)) && !doors[4]) || (difff(boarders::zd,(-145+3*diffb)) && !doors[5]) || (difff(boarders::zd,(-145+2*diffb)) && !doors[6]) || (difff(boarders::zd,(-145+1*diffb)) && !doors[7]) || (difff(boarders::zd,(-145+0*diffb)) && !doors[8]))
		return false;
	return true;
}
bool trainbet_forwardZ(){
	if((difff(boarders::zd,(-115+8*diffb)) && !doors[0]) || (difff(boarders::zd,(-115+7*diffb)) && !doors[1]) || (difff(boarders::zd,(-115+6*diffb)) && !doors[2]) || (difff(boarders::zd,(-115+5*diffb)) && !doors[3]) || (difff(boarders::zd,(-115+4*diffb)) && !doors[4]) || (difff(boarders::zd,(-115+3*diffb)) && !doors[5]) || (difff(boarders::zd,(-115+2*diffb)) && !doors[6]) || (difff(boarders::zd,(-115+1*diffb)) && !doors[7]) || (difff(boarders::zd,(-115+0*diffb)) && !doors[8]))
		return false;
	return true;
}
bool trainbet_forwardX(){
	if((boarders::zd<-90+8*diffb && boarders::zd>-170+8*diffb) || (boarders::zd<-90+7*diffb && boarders::zd>-170+7*diffb) || (boarders::zd<-90+6*diffb && boarders::zd>-170+6*diffb) || (boarders::zd<-90+5*diffb && boarders::zd>-170+5*diffb) || (boarders::zd<-90+4*diffb && boarders::zd>-170+4*diffb) || (boarders::zd<-90+3*diffb && boarders::zd>-170+3*diffb) || (boarders::zd<-90+2*diffb && boarders::zd>-170+2*diffb) || (boarders::zd<-90+1*diffb && boarders::zd>-170+1*diffb) || (boarders::zd<-90+0*diffb && boarders::zd>-170+0*diffb))
		if(difff(boarders::xd,15)) return false;
	return true;
}
bool trainbet_backawrdX(){
	if((boarders::zd<-90+8*diffb && boarders::zd>-170+8*diffb) || (boarders::zd<-90+7*diffb && boarders::zd>-170+7*diffb) || (boarders::zd<-90+6*diffb && boarders::zd>-170+6*diffb) || (boarders::zd<-90+5*diffb && boarders::zd>-170+5*diffb) || (boarders::zd<-90+4*diffb && boarders::zd>-170+4*diffb) || (boarders::zd<-90+3*diffb && boarders::zd>-170+3*diffb) || (boarders::zd<-90+2*diffb && boarders::zd>-170+2*diffb) || (boarders::zd<-90+1*diffb && boarders::zd>-170+1*diffb) || (boarders::zd<-90+0*diffb && boarders::zd>-170+0*diffb))
		if(difff(boarders::xd,-15)) return false;
	return true;
}

int rkapDiffX4=0,rkapDiffY4=0,rkapDiffZ4=1560;                // #################   rkap number 4 boarders:    ####################

bool rkap_backwardZ4(){
	if((boarders::xd>-40+rkapDiffX4 && boarders::xd<-15+rkapDiffX4)||(boarders::xd>15+rkapDiffX4 && boarders::xd<40+rkapDiffX4))
		if(difff(boarders::zd,-90+rkapDiffZ4)||difff(boarders::zd,-60+rkapDiffZ4)||difff(boarders::zd,-20+rkapDiffZ4)||difff(boarders::zd,20+rkapDiffZ4)||difff(boarders::zd,60+rkapDiffZ4)||difff(boarders::zd,90+rkapDiffZ4)) return false;
	if((boarders::xd>-15+rkapDiffX4 && boarders::xd<15+rkapDiffX4) && !doors[2])
		if(difff(boarders::zd,-90+rkapDiffZ4)) return false;
	return true;
}
bool rkap_forwardZ4(){
	if((boarders::xd>-40+rkapDiffX4 && boarders::xd<-15+rkapDiffX4)||(boarders::xd>15+rkapDiffX4 && boarders::xd<40+rkapDiffX4))
		if(difff(boarders::zd,-90+rkapDiffZ4)||difff(boarders::zd,-60+rkapDiffZ4)||difff(boarders::zd,-20+rkapDiffZ4)||difff(boarders::zd,20+rkapDiffZ4)||difff(boarders::zd,60+rkapDiffZ4)||difff(boarders::zd,90+rkapDiffZ4)) return false;
	if((boarders::xd>-15+rkapDiffX4 && boarders::xd<15+rkapDiffX4) && !doors[1])
		if(difff(boarders::zd,90+rkapDiffZ4)) return false; 
	return true;
}
bool rkap_forwardX4(){
	if(boarders::zd>-90+rkapDiffZ4 && boarders::zd<90+rkapDiffZ4)
		if(difff(boarders::xd,40+rkapDiffX4)) return false;
	return true;
}
bool rkap_backwardX4(){
	if(boarders::zd>-90+rkapDiffZ4 && boarders::zd<90+rkapDiffZ4)
		if(difff(boarders::xd,-40+rkapDiffX4)) return false;
	return true;
}



void boarders::MovingThroughTheScene(bool keys[],bool door[])
{
	for(int i=0 ; i<13 ; i++)
		doors[i]=door[i];

	if (keys[VK_CONTROL] ) {
		velocity = fastv;
	}
	if (!keys[VK_CONTROL] ) {
		velocity = slowv;
	}
	if(keys['G']) yd=2000;
	if(yd>8){
		gravity+=0.0005;
		yd-=gravity;}
	if(keys[VK_LEFT]) angle1-=looking;  // look at the Left,  angle1 is on the axis: x and z
	if(keys[VK_RIGHT]) angle1+=looking;  // look at the Right.
	if(keys['W']) if(angle2<1.45) angle2+=looking;  //look up,  angle2 is on the axis: x_z and y
	if(keys['S']) if(angle2>-1.45) angle2-=looking;  //look down.

	if(keys[VK_UP]) {              // moving Forward.   (changing yd axis to demonstrat the steps effect!)
		if(((bedroom::forwardZ() && kitchen_forwardZ() && kitchen_forwardZ2() && rkap_forwardZ3() && cinema_forwardZ() && rkap_forwardZ1() && rkap_forwardZ2() && bathroom_forwardZ() && trainbet_forwardZ() && control_forwardZ() && rkap_forwardZ4()) && sin(angle1)>0)||((bedroom::backwardZ() && kitchen_backwardZ() && kitchen_backwardZ2() && rkap_backwardZ3() && cinema_backwardZ() && rkap_backwardZ1() && rkap_backwardZ2() && bathroom_backwardZ() && trainbet_backwardZ() && control_backwardZ() && rkap_backwardZ4()) && sin(angle1)<0)) 
			zd+=velocity*sin(angle1); 
		if(((bedroom::forwardX() && kitchen_forwardX() && kitchen_forwardX2() && rkap_forwardX3() && cinema_forwardX() && rkap_forwardX1() && rkap_forwardX2() && bathroom_forwardX() && trainbet_forwardX() && control_forwardX() && rkap_forwardX4()) && cos(angle1)>0)||((bedroom::backwardX() && kitchen_backwardX() && kitchen_backwardX2() && rkap_backwardX3() && cinema_backwardX() && rkap_backwardX1() && rkap_backwardX2() && bathroom_backwardX() && trainbet_backawrdX() && control_backwardX() && rkap_backwardX4()) && cos(angle1)<0)) 
			xd+=velocity*cos(angle1);
		yd=cosMovingLength*abs(cos(angle3)) + 8;
		angle3+=cosMovingVelocity; 
	}  
	if(keys[VK_DOWN]) {            // moving Backward.
		if(((bedroom::backwardZ() && kitchen_backwardZ() && kitchen_backwardZ2() && rkap_backwardZ3() && cinema_backwardZ() && rkap_backwardZ1() && rkap_backwardZ2() && bathroom_backwardZ() && trainbet_backwardZ() && control_backwardZ() && rkap_backwardZ4()) && sin(angle1)>0)||((bedroom::forwardZ() && kitchen_forwardZ() && kitchen_forwardZ2() && rkap_forwardZ3() && cinema_forwardZ() && rkap_forwardZ1() && rkap_forwardZ2() && bathroom_forwardZ() && trainbet_forwardZ() && control_forwardZ() && rkap_forwardZ4()) && sin(angle1)<0)) 
			zd-=velocity*sin(angle1); 
		if(((bedroom::backwardX() && kitchen_backwardX()&& kitchen_backwardX2() && rkap_backwardX3() && cinema_backwardX() && rkap_backwardX1() && rkap_backwardX2() && bathroom_backwardX() && trainbet_backawrdX() && control_backwardX() && rkap_backwardX4()) && cos(angle1)>0)||((bedroom::forwardX() && kitchen_forwardX() && kitchen_forwardX2() && cinema_forwardX() && rkap_forwardX1() && rkap_forwardX2() && rkap_forwardX3() && bathroom_forwardX() && trainbet_forwardX() && control_forwardX() && rkap_forwardX4()) && cos(angle1)<0))
			xd-=velocity*cos(angle1); 
		yd=cosMovingLength*abs(cos(angle3)) + 8;
		angle3+=cosMovingVelocity;
	}  
	if(keys['A']) {              //moving to the Left. (moving to Right/Left is the same as moving Forward/Backward but with a different angle.
		if(((bedroom::forwardZ() && kitchen_forwardZ() && kitchen_forwardZ2() && rkap_forwardZ3() && cinema_forwardZ() && rkap_forwardZ1() && rkap_forwardZ2() && bathroom_forwardZ() && trainbet_forwardZ() && control_forwardZ() && rkap_forwardZ4()) && sin(angle1-1.57)>0)||((bedroom::backwardZ() && kitchen_backwardZ() && kitchen_backwardZ2() && cinema_backwardZ() && rkap_backwardZ1() && rkap_backwardZ2() && rkap_backwardZ3() && bathroom_backwardZ() && trainbet_backwardZ() && control_backwardZ() && rkap_backwardZ4()) && sin(angle1-1.57)<0)) 
			zd+=velocity*sin(angle1-1.57); 
		if(((bedroom::forwardX() && kitchen_forwardX() && kitchen_forwardX2() && rkap_forwardX3() && cinema_forwardX() && rkap_forwardX1() && rkap_forwardX2() && bathroom_forwardX() && trainbet_forwardX() && control_forwardX() && rkap_forwardX4()) && cos(angle1-1.57)>0)||((bedroom::backwardX() && kitchen_backwardX() && kitchen_backwardX2() && rkap_backwardX3() && cinema_backwardX() && rkap_backwardX1() && rkap_backwardX2() && bathroom_backwardX() && trainbet_backawrdX() && control_backwardX() && rkap_backwardX4()) && cos(angle1-1.57)<0)) 
			xd+= velocity*cos(angle1-1.57);  
		yd=cosMovingLength*abs(cos(angle3)) + 8;
		angle3+=cosMovingVelocity;
	}
	if(keys['D']) {               //moving to the Right
		if(((bedroom::backwardZ() && kitchen_backwardZ() && kitchen_backwardZ2() && rkap_backwardZ3() && cinema_backwardZ() && rkap_backwardZ1() && rkap_backwardZ2() && bathroom_backwardZ() && trainbet_backwardZ() && control_backwardZ() && rkap_backwardZ4()) && sin(angle1-1.57)>0)||((bedroom::forwardZ() && kitchen_forwardZ() && kitchen_forwardZ2() && rkap_forwardZ3() && cinema_forwardZ() && rkap_forwardZ1() && rkap_forwardZ2() && bathroom_forwardZ() && trainbet_forwardZ() && control_forwardZ() && rkap_forwardZ4()) && sin(angle1-1.57)<0)) 
			zd-=velocity*sin(angle1-1.57);
		if(((bedroom::backwardX() && kitchen_backwardX() && kitchen_backwardX2() && rkap_backwardX3() && cinema_backwardX() && rkap_backwardX1() && rkap_backwardX2() && bathroom_backwardX() && trainbet_backawrdX() && control_backwardX() && rkap_backwardX4()) && cos(angle1-1.57)>0)||((bedroom::forwardX() && kitchen_forwardX() && kitchen_forwardX2() && rkap_forwardX3() && cinema_forwardX() && rkap_forwardX1() && rkap_forwardX2() && bathroom_forwardX() && trainbet_forwardX() && control_forwardX() && rkap_forwardX4()) && cos(angle1-1.57)<0)) 
			xd-=velocity*cos(angle1-1.57);  
		yd=cosMovingLength*abs(cos(angle3)) + 8; 
		angle3+=cosMovingVelocity;
	}

	//if(yd>-10) {angle3+=cosMovingVelocity;}

	gluLookAt(xd,yd,zd,(cos(angle2)*cos(angle1))+xd,sin(angle2)+yd,(cos(angle2)*sin(angle1))+zd,0,1,0);
	// you can make it: gluLookAt(xd,yd,zd,cos()+xd,sin(angle2)+yd,sin(angle1)+zd,0,1,0);
}