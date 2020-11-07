#include "cubeInfo.h"
#include <iostream>
float cubeInfo::cubeWidth = 1.;
GLuint cubeInfo::BoxList = 0;
int cubeInfo::cubeRows = 0;
int cubeInfo::cubeCols = 0;
GLSLProgram* cubeInfo::Pattern = NULL;
float cubeInfo::cubeSpeed;
float cubeInfo::margin;
float cubeInfo::furthestLeftX;
float cubeInfo::furthestRightX;
float cubeInfo::greenDistance;

cubeInfo::cubeInfo() {
	x = 0;
	y = 0;
	z = 0;
}

 

void cubeInfo::drawCube(light testlight) {

	Pattern->Use();
	if (inClock) {
		float ambient = .5;
		float diffuse = .4;
		float specular = .3;
		float shininess = 10.;
		float percentage;
		percentage = (greenDistance - x) / (cubeWidth);
		if (percentage <= 0) {
			percentage = 0; 
		}
		glm::vec3 objectColor(.5, .5, .5);
		glm::vec3 uSpecularColor(testlight.getR(), testlight.getB(), testlight.getG());
		glm::vec3 LIGHT1POSITION(testlight.getX(), testlight.getY(), testlight.getZ());
		
		Pattern->SetUniformVariable("leftX", x);
		Pattern->SetUniformVariable("rightX", x + cubeWidth);
		Pattern->SetUniformVariable("greenDistance", greenDistance);
		Pattern->SetUniformVariable("percentage", percentage);
		Pattern->SetUniformVariable("inClock",true);
		Pattern->SetUniformVariable("LIGHT1POSITION", LIGHT1POSITION);
		Pattern->SetUniformVariable("uKa", ambient);
		Pattern->SetUniformVariable("uKd", diffuse);
		Pattern->SetUniformVariable("uKs", specular);
		Pattern->SetUniformVariable("uShininess", shininess);
		Pattern->SetUniformVariable("uColor", objectColor);
		Pattern->SetUniformVariable("uSpecularColor", uSpecularColor);
		glPushMatrix();
		glTranslatef(x, y, z);
		glScalef(cubeWidth, cubeWidth, cubeWidth);
		glCallList(BoxList);
		glPopMatrix();
	}
	else {
		float ambient = .3;
		float diffuse = .4;
		float specular = .3;
		float shininess = 3.;
		glm::vec3 objectColor(r, g, b);
		glm::vec3 uSpecularColor(testlight.getR(), testlight.getB(), testlight.getG());
		glm::vec3 LIGHT1POSITION(testlight.getX(), testlight.getY(), testlight.getZ());
		Pattern->SetUniformVariable("inClock", false);
		Pattern->SetUniformVariable("greenDistance", greenDistance);
		Pattern->SetUniformVariable("LIGHT1POSITION", LIGHT1POSITION);
		Pattern->SetUniformVariable("uKa", ambient);
		Pattern->SetUniformVariable("uKd", diffuse);
		Pattern->SetUniformVariable("uKs", specular);
		Pattern->SetUniformVariable("uShininess", shininess);
		Pattern->SetUniformVariable("uColor", objectColor);
		Pattern->SetUniformVariable("uSpecularColor", uSpecularColor);
		glPushMatrix();
		glTranslatef(x, y, z);
		glScalef(cubeWidth, cubeWidth, cubeWidth);
		glCallList(BoxList);
		glPopMatrix();
	}
	
	Pattern->Use(0);

}

void cubeInfo::setUpBoxList(float boxSize, int MainWindow) {
	Pattern = new GLSLProgram();
	bool valid = Pattern->Create("lighting.vert", "lighting.frag");
	if (!valid) {
		fprintf(stderr, "Error with shader creation\n");
	}
	boxSize *= .9;		//makes there be spaces between the squares	
	//boxSize is 1, so the square is 1 by 1 which can be sacled up.
	float dx = boxSize / 2.f;
	float dy = boxSize / 2.f;
	float dz = boxSize / 2.f;
	glutSetWindow(MainWindow);

	// create the object:

	BoxList = glGenLists(1);
	glNewList(BoxList, GL_COMPILE);

	glBegin(GL_QUADS);

	glColor3f(1., 1., 1.);
	glNormal3f(0., 0., 1.);
	glVertex3f(-dx, -dy, dz);
	glVertex3f(dx, -dy, dz);
	glVertex3f(dx, dy, dz);
	glVertex3f(-dx, dy, dz);

	glNormal3f(0., 0., -1.);
	glTexCoord2f(0., 0.);
	glVertex3f(-dx, -dy, -dz);
	glTexCoord2f(0., 1.);
	glVertex3f(-dx, dy, -dz);
	glTexCoord2f(1., 1.);
	glVertex3f(dx, dy, -dz);
	glTexCoord2f(1., 0.);
	glVertex3f(dx, -dy, -dz);
	glNormal3f(1., 0., 0.);
	glVertex3f(dx, -dy, dz);
	glVertex3f(dx, -dy, -dz);
	glVertex3f(dx, dy, -dz);
	glVertex3f(dx, dy, dz);

	glNormal3f(-1., 0., 0.);
	glVertex3f(-dx, -dy, dz);
	glVertex3f(-dx, dy, dz);
	glVertex3f(-dx, dy, -dz);
	glVertex3f(-dx, -dy, -dz);


	glNormal3f(0., 1., 0.);
	glVertex3f(-dx, dy, dz);
	glVertex3f(dx, dy, dz);
	glVertex3f(dx, dy, -dz);
	glVertex3f(-dx, dy, -dz);

	glNormal3f(0., -1., 0.);
	glVertex3f(-dx, -dy, dz);
	glVertex3f(-dx, -dy, -dz);
	glVertex3f(dx, -dy, -dz);
	glVertex3f(dx, -dy, dz);

	glEnd();

	glEndList();
}



void cubeInfo::init(float x, float y, float z) {
	r = (x+cubeInfo::cubeRows/2) / cubeInfo::cubeRows;
	g = (z+cubeInfo::cubeCols/2) / cubeInfo::cubeCols;
	
	b = .5;


	this->x = x;
	this->y = y;
	this->z = z;
	defaultX = x;
	defaultY = y;
	defaultZ = z;
	intermediateBoardX = defaultX;
	intermediateBoardY = defaultY + 1;
	intermediateBoardZ = defaultZ;
	inClock = false;
}

void cubeInfo::setMoving(float newX, float newY, float newZ, bool goingToClock) {
	finalX = newX;
	finalY = newY;
	finalZ = newZ;
	doneX = false;
	doneY = false;
	doneZ = false;
	isMoving = true;

	intermediateClockX = newX;
	intermediateClockY = newY;
	intermediateClockZ = newZ - 1;
	leftBoard = !goingToClock;

	inClock = goingToClock;
	beforeClock = false;

}

void cubeInfo::move(float deltaTime) {
	if (isMoving) {
		if (inClock) {
			if (!leftBoard) {
				moveToLocation(intermediateBoardX, intermediateBoardY, intermediateBoardZ, deltaTime);
				if (doneX && doneY && doneZ) {
					leftBoard = true;
					doneX = doneY = doneZ = false;
				}
			}
			else if(!beforeClock){
				moveToLocation(intermediateClockX, intermediateClockY, intermediateClockZ, deltaTime);
				if (doneZ && doneX && doneY) {
					beforeClock = true;
					doneX = doneY = doneZ = false;
				}
			}
			else {
				moveToLocation(finalX, finalY, finalZ,deltaTime);
				if (doneZ && doneX && doneY) {
					isMoving = false;
					doneX = doneY = doneZ = false;
				}
			}
		}
		else {
			if (!beforeClock) {
				moveToLocation(intermediateClockX, intermediateClockY, intermediateClockZ, deltaTime);
				if (doneZ && doneX && doneY) {
					beforeClock = true;
					doneX = doneY = doneZ = false;
				}
			}
			else if (leftBoard) {
				moveToLocation(intermediateBoardX, intermediateBoardY, intermediateBoardZ, deltaTime);
				if (doneX && doneY && doneZ) {
					leftBoard = false;
					doneX = doneY = doneZ = false;
				}
			}
			else{
				moveToLocation(defaultX, defaultY, defaultZ, deltaTime);
				if (doneZ && doneX && doneY) {
					isMoving = false;
					doneX = doneY = doneZ = true;
				}
			}


		}
		
	}
}

void cubeInfo::reset() {
	if (inClock) {

		isMoving = true;
		inClock = false;
		doneX = false;
		doneY = false;
		doneZ = false;
		beforeClock = false;
		leftBoard = true;
	}
}

void cubeInfo::moveToLocation(float moveX, float moveY, float moveZ, float deltaTime) {
	if (!doneX) {
		if (abs(x - moveX) <= margin) {
			x = moveX;
			doneX = true;
		}
		else if (x > moveX) {
			x -= cubeSpeed * deltaTime;
		}
		else if (x < moveX) {
			x += cubeSpeed * deltaTime;
		}
	}
	if (!doneY) {
		if (abs(y - moveY) <= margin) {
			y = moveY;
			doneY = true;
		}
		else if (y > moveY) {
			y -= cubeSpeed * deltaTime;
		}
		else if (y < moveY) {
			y += cubeSpeed * deltaTime;
		}
	}
	if (!doneZ) {
		if (abs(z - moveZ) <= margin) {
			z = moveZ;
			doneZ = true;
		}
		else if (z > moveZ) {
			z -= cubeSpeed * deltaTime;
		}
		else if (z < moveZ) {
			z += cubeSpeed * deltaTime;
		}
	}
}

bool cubeInfo::moving() {
	return isMoving;
}
bool cubeInfo::inBoard() {
	return !inClock;
}

int cubeInfo::getClockRow() {
	return  clockRow;
}

int cubeInfo::getClockCol() {
	return clockCol;
}

void cubeInfo::setClockRow(int newRow) {
	clockRow = newRow;
}

void cubeInfo::setClockCol(int newCol) {
	clockCol = newCol;
}
bool cubeInfo::isInClock() {
	return inClock;
}