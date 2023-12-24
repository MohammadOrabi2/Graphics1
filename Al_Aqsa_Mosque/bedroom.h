#pragma once
class bedroom
{
public:
	static double bedroom::curtainsRate;
	static bool bedroom::doorIsOpen1;
	static bool bedroom::doorIsOpen2;
	// int diffX,diffY,diffZ;

	static void bedroom::bed(double x,double y,double z,int woodPhoto,int fabricPhoto);
	static void bedroom::bedRoom(double x, double y, double z,bool openDoor, bool openDoor2,bool curtainIsOpen,int trainFront,int trainEdge1,int trainTop1,int trainbottom2,int door,int wallpaper,int wood, int fabric, int curtainsPhoto,int ground,int differentX,int differentY,int differentZ);
	static void bedroom::table(double x,int wood);
	static void bedroom::curtains(double x, double y, double z, int curtainsPhoto, bool curtainIsOpen);
	static void bedroom::bedroomBoarders(bool keys[]);

	static bool bedroom::forwardZ();
	static bool bedroom::backwardZ();
	static bool bedroom::forwardX();
	static bool bedroom::backwardX();
};

