
#pragma once
//#ifndef AAA_HEADER
//#define AAA_HEADER
#include "Point.h"
class View
{
public:
	static void DrawGrass(Point center, float radius); //circle
	static void DrawSky(Point pUpperRight, Point pUpperLeft, Point pLowerLeft, Point pLowerRight); //rectangle
	static void DrawSolidCircle(Point center, float radius);
	static void DrawRectangle(Point pUpperRight, Point pUpperLeft, Point pLowerLeft, Point pLowerRight);
	static void DrawHammer(Point pUpperRight, Point pUpperLeft, Point pLowerLeft, Point pLowerRight, Point startPoint, Point endPoint);
	static void DrawLine(Point startPoint, Point endPoint);
};
//#endif