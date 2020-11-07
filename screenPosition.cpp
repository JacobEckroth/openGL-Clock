#include "screenPosition.h"

void screenPosition::init(float x, float y, float z) {
	isActive = false;
	filled = false;
	this->x = x;
	this->y = y;
	this->z = z;
}


float screenPosition::getX() {
	return x;
}

float screenPosition::getY() { 
	return y;
}
float screenPosition::getZ() {
	return z;
}


void screenPosition::setFilled(bool newFilled) {
	filled= newFilled;
}

void screenPosition::setActive(bool newActive) {
	isActive = newActive;
}

bool screenPosition::getActive() {
	return isActive;
}

bool screenPosition::isCorrect() {
	return filled == isActive;	//if it's filled and it's supposed to be filled.
}

void screenPosition::setBoardRow(int newRow) {
	boardRow = newRow;
}

void screenPosition::setBoardCol(int newCol) {
	boardCol = newCol;
}

int screenPosition::getBoardRow() {
	return boardRow;
}

int screenPosition::getBoardCol() {
	return boardCol;
}