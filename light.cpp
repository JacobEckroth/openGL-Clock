#include "light.h"
GLuint light::sphereList = 0;
float light::sphereRadius = 0;

void light::initLightInfo() {
	sphereRadius = .5;
	sphereList = glGenLists(1);
	glNewList(sphereList, GL_COMPILE);
		glutSolidSphere(sphereRadius, 20, 20);	
	glEndList();
}
void light::drawLight() {

	glColor3f(r,g,b);
	glPushMatrix();
	glTranslatef(x,y,z);
	glCallList(sphereList);
	glPopMatrix();

}

float light::getR() {
	return r;
}
float light::getB() {
	return b;
}

float light::getG() {
	return g;
}

float light::getX() {
	return x;
}

float light::getY() {
	return y;
}

float light::getZ() {
	return z;
}

void light::init(float newX, float newY, float newZ, float newR, float newG, float newB) {
	x = newX;
	y = newY;
	z = newZ;
	r = newR;
	g = newG;
	b = newB;
}