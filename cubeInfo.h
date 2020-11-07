#pragma once
#include "glew.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "glut.h"
#include "glslprogram.h"
#include "light.h"
class cubeInfo
{


public:
	void drawCube(light);
	void init(float, float, float);
	cubeInfo();


	static void setUpBoxList(float boxSize, int mainWindow);
	static float cubeWidth;
	static GLuint BoxList;				// object display list
	static GLSLProgram* Pattern;
	static int cubeRows;
	static int cubeCols;


	static float furthestLeftX;
	static float furthestRightX;
	static float greenDistance;

	static float cubeSpeed;			//how many units it can move per second.
	static float margin;
	void move(float);
	void setMoving(float, float, float,bool);
	void reset();
	bool moving();

	bool inBoard();
	int getClockRow();
	int getClockCol();
	void setClockRow(int);
	void setClockCol(int);

	bool isInClock();

	void moveToLocation(float, float, float, float);
private:
	float r;
	float g;
	float b;
	float defaultX;
	float defaultY;
	float defaultZ;

	float intermediateClockX;
	float intermediateClockY;
	float intermediateClockZ;

	float intermediateBoardX;
	float intermediateBoardY;
	float intermediateBoardZ;

	int clockRow;
	int clockCol;


	float finalX;
	float finalY;
	float finalZ;

	bool doneX;
	bool doneY;
	bool doneZ;

	bool leftBoard;
	bool beforeClock;		//keeps track if it's entered the clock yet.

	
	float x;
	float y;
	float z;
	bool isMoving;
	bool inClock;

};

