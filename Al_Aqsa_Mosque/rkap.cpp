#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
//#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <texture.h>
#include  "camera.h"
#include "tools.h"
#include "rkapr.h"




void rkap::hold(int x, int y, int z, int width, int height, int depth,int metal) {
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, metal);
	glBegin(GL_QUADS);//the bottom face of down mental
	glTexCoord2d(0, 0);
	glVertex3d(x, y, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + width, y, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + width, y, z + height);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, z + height);
	glEnd();

	glBegin(GL_QUADS);//the top face of down mental
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + width, y + depth, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + width, y + depth, z + height);
	glTexCoord2d(1, 0);
	glVertex3d(x, y + depth, z + height);
	glEnd();

	glBegin(GL_QUADS);//the front face of down mental
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth, z + height);
	glTexCoord2d(0, 1);
	glVertex3d(x + width, y + depth, z + height);
	glTexCoord2d(1, 1);
	glVertex3d(x + width, y, z + height);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, z + height);
	glEnd();


	glBegin(GL_QUADS);//the  back of down mental
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + width, y + depth, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + width, y, z);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, z);
	glEnd();

	glBegin(GL_QUADS);//the  right of down mental
	glTexCoord2d(0, 0);
	glVertex3d(x + width, y + depth, z + height);
	glTexCoord2d(0, 1);
	glVertex3d(x + width, y + depth, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + width, y, z);
	glTexCoord2d(1, 0);
	glVertex3d(x + width, y, z + height);
	glEnd();

	glBegin(GL_QUADS);//the  left of down mental
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth, z + height);
	glTexCoord2d(0, 1);
	glVertex3d(x, y + depth, z);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, z);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, z + height);
	glEnd();
	glPopMatrix();



}



void rkap::chair(int x, int y, int z, int width, int height, int height1, int depth, int angel,int cloth1) {
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, cloth1);
	glBegin(GL_QUADS);//the bottom face of down pice of chaire
	glTexCoord2d(0, 0);
	glVertex3d(x, y, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + width, y, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + width, y, z + height);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, z + height);

	glEnd();


	//the top face of down pice of chaire
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + width, y + depth, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + width, y + depth, z + height);
	glTexCoord2d(1, 0);
	glVertex3d(x, y + depth, z + height);

	glEnd();

	//the front face from pice chaire 
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth, z + height);
	glTexCoord2d(0, 1);
	glVertex3d(x + width, y + depth, z + height);
	glTexCoord2d(1, 1);
	glVertex3d(x + width, y, z + height);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, z + height);

	glEnd();

	glBegin(GL_QUADS);///back
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + width, y + depth, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + width, y, z);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, z);

	glEnd();




	glBegin(GL_QUADS);///right
	glTexCoord2d(0, 0);
	glVertex3d(x + width, y + depth, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + width, y, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + width, y, z + height);
	glTexCoord2d(1, 0);
	glVertex3d(x + width, y + depth, z + height);

	glEnd();

	glBegin(GL_QUADS);///left
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth, z);
	glTexCoord2d(0, 1);
	glVertex3d(x, y, z);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, z + height);
	glTexCoord2d(1, 0);
	glVertex3d(x, y + depth, z + height);

	glEnd();
	glPopMatrix();
	//
	glPushMatrix();
	glTranslated(0,0,height-depth);//
	glPushMatrix();
	glBegin(GL_QUADS);//bottom
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + width, y + depth, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + width, y + depth, z + depth);
	glTexCoord2d(1, 0);
	glVertex3d(x, y + depth, z + depth);

	glEnd();

	glBegin(GL_QUADS);//top
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth + height1, z + -(angel));
	glTexCoord2d(0, 1);
	glVertex3d(x + width, y + depth + height1, z + -(angel));
	glTexCoord2d(1, 1);
	glVertex3d(x + width, y + depth + height1, z + depth + -(angel));
	glTexCoord2d(1, 0);
	glVertex3d(x, y + depth + height1, z + depth + -(angel));
	glEnd();

	glBegin(GL_QUADS);//front
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth + height1, z + depth +-(angel));
	glTexCoord2d(0, 1);
	glVertex3d(x + width, y + depth + height1, z + depth + -(angel));
	glTexCoord2d(1, 1);
	glVertex3d(x + width, y + depth, z + depth);
	glTexCoord2d(1, 0);
	glVertex3d(x, y + depth, z + depth);
	glEnd();

	glBegin(GL_QUADS);//back
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth + height1, z + -(angel));
	glTexCoord2d(0, 1);
	glVertex3d(x + width, y + depth + height1, z + -(angel));
	glTexCoord2d(1, 1);
	glVertex3d(x + width, y + depth, z);
	glTexCoord2d(1, 0);
	glVertex3d(x, y + depth, z);
	glEnd();

	glBegin(GL_QUADS);//right
	glTexCoord2d(0, 0);
	glVertex3d(x + width, y + depth + height1, z + depth + -(angel));//
	glTexCoord2d(0, 1);
	glVertex3d(x + width, y + depth + height1, z + -(angel));
	glTexCoord2d(1, 1);
	glVertex3d(x + width, y + depth, z);
	glTexCoord2d(1, 0);
	glVertex3d(x + width, y + depth, z + depth);
	glEnd();

	glBegin(GL_QUADS);//left
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth + height1, z + depth + -(angel));
	glTexCoord2d(0, 1);
	glVertex3d(x, y + depth + height1, z + -(angel));
	glTexCoord2d(1, 1);
	glVertex3d(x, y + depth, z);
	glTexCoord2d(1, 0);
	glVertex3d(x, y + depth, z + depth);
	glEnd();
	glPopMatrix();
	glPopMatrix();





	glPopMatrix();
	glPopMatrix();
}


void rkap::rotated1chair(int x, int y, int z, int width, int height, int depth,int cloth1) {
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, cloth1);
	glBegin(GL_QUADS);//the bottom face of down pice of chaire
	glTexCoord2d(0, 0);
	glVertex3d(x, y, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + height, y, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + height, y, z + width);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, z + width);

	glEnd();


	//the top face of down pice of chaire
	glBegin(GL_QUADS);//the top face of down pice of chaire
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + height, y + depth, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + height, y + depth, z + width);
	glTexCoord2d(1, 0);
	glVertex3d(x, y + depth, z + width);

	glEnd();

	//the front face from pice chaire 
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth, z + height);
	glTexCoord2d(0, 1);
	glVertex3d(x + height, y + depth, z + width);
	glTexCoord2d(1, 1);
	glVertex3d(x + height, y, z + width);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, z + width);

	glEnd();

	glBegin(GL_QUADS);///back
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + height, y + depth, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + height, y, z);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, z);

	glEnd();




	glBegin(GL_QUADS);///right
	glTexCoord2d(0, 0);
	glVertex3d(x + height, y + depth, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + height, y, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + height, y, z + width);
	glTexCoord2d(1, 0);
	glVertex3d(x + height, y + depth, z + width);

	glEnd();

	glBegin(GL_QUADS);///left
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth, z);
	glTexCoord2d(0, 1);
	glVertex3d(x, y, z);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, z + width);
	glTexCoord2d(1, 0);
	glVertex3d(x, y + depth, z + width);

	glEnd();
	glPopMatrix();
	//the second part of chair
	glBegin(GL_QUADS);//bottom
	glTexCoord2d(0, 0);
	glVertex3d(x + height - depth, y + depth, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + height, y + depth, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + height, y + depth, z + width);
	glTexCoord2d(1, 0);
	glVertex3d(x + height - depth, y + depth, z + width);

	glEnd();

	glBegin(GL_QUADS);//top
	glTexCoord2d(0, 0);
	glVertex3d(x + height - depth, y + depth + height, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + height, y + depth + height, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + height, y + depth + height, z + width);
	glTexCoord2d(1, 0);
	glVertex3d(x + height - depth, y + depth + height, z + width);

	glEnd();

	glBegin(GL_QUADS);//front
	glTexCoord2d(0, 0);
	glVertex3d(x + height - depth, y + depth + height, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + height - depth, y + depth + height, z + width);
	glTexCoord2d(1, 1);
	glVertex3d(x + height - depth, y + depth, z + width);
	glTexCoord2d(1, 0);
	glVertex3d(x + height - depth, y + depth, z);

	glEnd();

	glBegin(GL_QUADS);//back
	glTexCoord2d(0, 0);
	glVertex3d(x + height, y + depth + height, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + height, y + depth + height, z + width);
	glTexCoord2d(1, 1);
	glVertex3d(x + height, y + depth, z + width);
	glTexCoord2d(1, 0);
	glVertex3d(x + height, y + depth, z);

	glEnd();

	glBegin(GL_QUADS);//right
	glTexCoord2d(0, 0);
	glVertex3d(x + height, y + depth + height, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + height - depth, y + depth + height, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + height - depth, y + depth, z);
	glTexCoord2d(1, 0);
	glVertex3d(x + height, y + depth, z);

	glEnd();

	glBegin(GL_QUADS);//left
	glTexCoord2d(0, 0);
	glVertex3d(x + height, y + depth + height, z + width);
	glTexCoord2d(0, 1);
	glVertex3d(x + height - depth, y + depth + height, z + width);
	glTexCoord2d(1, 1);
	glVertex3d(x + height - depth, y + depth, z + width);
	glTexCoord2d(1, 0);
	glVertex3d(x + height, y + depth, z + width);

	glEnd();





	glPopMatrix();
	glPopMatrix();
}




void rkap::rotated2chair(int x, int y, int z, int width, int height, int depth,int cloth1) {
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, cloth1);
	glBegin(GL_QUADS);//the bottom face of down pice of chaire
	glTexCoord2d(0, 0);
	glVertex3d(x, y, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + height, y, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + height, y, z + width);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, z + width);

	glEnd();


	//the top face of down pice of chaire
	glBegin(GL_QUADS);//the top face of down pice of chaire
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + height, y + depth, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + height, y + depth, z + width);
	glTexCoord2d(1, 0);
	glVertex3d(x, y + depth, z + width);

	glEnd();

	//the front face from pice chaire 
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth, z + height);
	glTexCoord2d(0, 1);
	glVertex3d(x + height, y + depth, z + width);
	glTexCoord2d(1, 1);
	glVertex3d(x + height, y, z + width);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, z + width);

	glEnd();

	glBegin(GL_QUADS);///back
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + height, y + depth, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + height, y, z);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, z);

	glEnd();




	glBegin(GL_QUADS);///right
	glTexCoord2d(0, 0);
	glVertex3d(x + height, y + depth, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + height, y, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + height, y, z + width);
	glTexCoord2d(1, 0);
	glVertex3d(x + height, y + depth, z + width);

	glEnd();

	glBegin(GL_QUADS);///left
	glTexCoord2d(0, 0);
	glVertex3d(x, y + depth, z);
	glTexCoord2d(0, 1);
	glVertex3d(x, y, z);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, z + width);
	glTexCoord2d(1, 0);
	glVertex3d(x, y + depth, z + width);

	glEnd();
	glPopMatrix();
	//the second part of chair
	glPushMatrix();
	glTranslated(-height + depth, 0, 0);
	glPushMatrix();
	glBegin(GL_QUADS);//bottom
	glTexCoord2d(0, 0);
	glVertex3d(x + height - depth, y + depth, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + height, y + depth, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + height, y + depth, z + width);
	glTexCoord2d(1, 0);
	glVertex3d(x + height - depth, y + depth, z + width);

	glEnd();

	glBegin(GL_QUADS);//top
	glTexCoord2d(0, 0);
	glVertex3d(x + height - depth, y + depth + height, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + height, y + depth + height, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + height, y + depth + height, z + width);
	glTexCoord2d(1, 0);
	glVertex3d(x + height - depth, y + depth + height, z + width);

	glEnd();

	glBegin(GL_QUADS);//front
	glTexCoord2d(0, 0);
	glVertex3d(x + height - depth, y + depth + height, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + height - depth, y + depth + height, z + width);
	glTexCoord2d(1, 1);
	glVertex3d(x + height - depth, y + depth, z + width);
	glTexCoord2d(1, 0);
	glVertex3d(x + height - depth, y + depth, z);

	glEnd();

	glBegin(GL_QUADS);//back
	glTexCoord2d(0, 0);
	glVertex3d(x + height, y + depth + height, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + height, y + depth + height, z + width);
	glTexCoord2d(1, 1);
	glVertex3d(x + height, y + depth, z + width);
	glTexCoord2d(1, 0);
	glVertex3d(x + height, y + depth, z);

	glEnd();

	glBegin(GL_QUADS);//right
	glTexCoord2d(0, 0);
	glVertex3d(x + height, y + depth + height, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + height - depth, y + depth + height, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + height - depth, y + depth, z);
	glTexCoord2d(1, 0);
	glVertex3d(x + height, y + depth, z);

	glEnd();

	glBegin(GL_QUADS);//left
	glTexCoord2d(0, 0);
	glVertex3d(x + height, y + depth + height, z + width);
	glTexCoord2d(0, 1);
	glVertex3d(x + height - depth, y + depth + height, z + width);
	glTexCoord2d(1, 1);
	glVertex3d(x + height - depth, y + depth, z + width);
	glTexCoord2d(1, 0);
	glVertex3d(x + height, y + depth, z + width);

	glEnd();
	glPopMatrix();
	glPopMatrix();





	glPopMatrix();
	glPopMatrix();
}




void rkap::hold_horizontal(int x, int y, int z, int width, int height, int depth,int metal) {
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, metal);
	//glTranslated(x,y,z);
	glPushMatrix();
	glBegin(GL_QUADS);///small1
	glTexCoord2d(0, 0);
	glVertex3d(x, y, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + width, y, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + width, y - height, z);
	glTexCoord2d(1, 0);
	glVertex3d(x, y - height, z);
	glEnd();

	glBegin(GL_QUADS);///small2
	glTexCoord2d(0, 0);
	glVertex3d(x, y, z + depth);
	glTexCoord2d(0, 1);
	glVertex3d(x + width, y, z + depth);
	glTexCoord2d(1, 1);
	glVertex3d(x + width, y - height, z + depth);
	glTexCoord2d(1, 0);
	glVertex3d(x, y - height, z + depth);
	glEnd();

	glBegin(GL_QUADS);///top
	glTexCoord2d(0, 0);
	glVertex3d(x, y, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + width, y, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + width, y, z + depth);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, z + depth);
	glEnd();

	glBegin(GL_QUADS);///bottom
	glTexCoord2d(0, 0);
	glVertex3d(x, y - height, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + width, y - height, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + width, y - height, z + depth);
	glTexCoord2d(1, 0);
	glVertex3d(x, y - height, z + depth);
	glEnd();

	glBegin(GL_QUADS);///right
	glTexCoord2d(0, 0);
	glVertex3d(x + width, y, z);
	glTexCoord2d(0, 1);
	glVertex3d(x + width, y - height, z);
	glTexCoord2d(1, 1);
	glVertex3d(x + width, y - height, z + depth);
	glTexCoord2d(1, 0);
	glVertex3d(x + width, y, z + depth);
	glEnd();

	glBegin(GL_QUADS);///left
	glTexCoord2d(0, 0);
	glVertex3d(x, y, z);
	glTexCoord2d(0, 1);
	glVertex3d(x, y - height, z);
	glTexCoord2d(1, 1);
	glVertex3d(x, y - height, z + depth);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, z + depth);
	glEnd();
	glPopMatrix();
	glPopMatrix();
}
