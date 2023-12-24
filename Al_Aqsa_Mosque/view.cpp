#include "View.h"
#include "Point.h"
#include <windows.h>
#include <gl\gl.h>
#include <cmath>

void View::DrawSky(Point pUpperRight, Point pUpperLeft,
	Point pLowerLeft, Point pLowerRight)
{

	glBegin(GL_QUADS);
	glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z);
	glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
	glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
	glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
	glEnd();
}
void View::DrawGrass(Point center, float radius)
{
	glColor3f(0, 1, 0);
	int steps = 360;
	float theta = 0;
	float depth = center.z;
	glBegin(GL_TRIANGLES);
	for (int step = 0; step <= steps; step++)
	{
		float x = center.x + radius * cos(theta);
		float y = center.y + radius * sin(theta);
		glVertex3f(x, y, depth);
		theta = theta + .5;
		x = center.x + radius * cos(theta);
		y = center.y + radius * sin(theta);
		glVertex3f(x, y, depth);
		glVertex3f(center.x, center.y, depth);
		theta = theta + .5;
	}
	glEnd();
}

void View::DrawSolidCircle(Point center, float radius)
{

	int steps = 360;
	float theta = 0;
	float depth = center.z;
	glBegin(GL_TRIANGLES);
	for (int step = 0; step <= steps; step++)
	{
		float x = center.x + radius * cos(theta);
		float y = center.y + radius * sin(theta);
		glVertex3f(x, y, depth);
		theta = theta + .5;
		x = center.x + radius * cos(theta);
		y = center.y + radius * sin(theta);
		glVertex3f(x, y, depth);
		glVertex3f(center.x, center.y, depth);
		theta = theta + .5;
	}
	glEnd();
}

void View::DrawRectangle(Point pUpperRight, Point pUpperLeft, Point pLowerLeft, Point pLowerRight)
{
	glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(pUpperRight.x, pUpperRight.y, pUpperRight.z);
	glVertex3f(pUpperLeft.x, pUpperLeft.y, pUpperLeft.z);
	glVertex3f(pLowerLeft.x, pLowerLeft.y, pLowerLeft.z);
	glVertex3f(pLowerRight.x, pLowerRight.y, pLowerRight.z);
	glEnd();
}

void View::DrawLine(Point startPoint, Point endPoint)
{
	glLineWidth(8);
	glBegin(GL_LINES);
	glVertex3f(startPoint.x, startPoint.y, endPoint.z);
	glVertex3f(endPoint.x, endPoint.y, endPoint.z);
	glEnd();
}
void View::DrawHammer(Point pUpperRight, Point pUpperLeft, Point pLowerLeft, Point pLowerRight, Point startPoint, Point endPoint)
{
	glColor3f(1, 0, 0);
	DrawLine(startPoint, endPoint);
	DrawSky(pUpperRight, pUpperLeft, pLowerLeft, pLowerRight);
}