#pragma once
#include "glew.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "glut.h"

class light
{

public:
	void drawLight();

	void init(float, float, float, float, float, float);
	float getR();
	float getG();
	float getB();
	float getX();
	float getY();
	float getZ();
	static float sphereRadius;
	static GLuint sphereList;
	static void initLightInfo();

private:
	float r;
	float g;
	float b;
	float x;
	float y;
	float z;
	


};

