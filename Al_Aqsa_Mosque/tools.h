#pragma once
class tools
{
public:
	static void tools::WallWithoutDoor(double x, double y, double index, int imeg);
	static void tools::WallWithDoor(double x, double y, double index, int imeg, bool openDoor);
	static void tools::TopDown(double x, double index, double z, int imeg, int imeg2);
	static void tools::WallRightLeftWithoutWindowInside(double index, double y, double z, int imeg);
	static void tools::WallRightLeftWithWindow(double index, double y, double z, int imeg);
	static void tools::WallRightLeftWithWindowHole(double index, double y, double z, int imeg);
	static void tools::WallWithDoorHole(double index, double y, double z, int imeg);
	static void tools::WallRightLeftWithoutWindowOutside(double index, double y, double z, int imeg);


};

