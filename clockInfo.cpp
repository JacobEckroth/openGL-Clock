#include "clockInfo.h"
#include <ctime>
#include <iostream>
#include <sys/utime.h>
//All layouts passed into here will be pointers to 5 * 3 arrays.

void clockInfo::getZeroLayout(bool**& layout) {
	clearLayout(layout);
	for (int i = 0; i < 5; i++) {
		layout[i][0] = true;
		layout[i][2] = true;
	}
	layout[0][1] = true;
	layout[4][1] = true;
}
void clockInfo::getOneLayout(bool**& layout) {
	clearLayout(layout);
	for (int i = 0; i < 5; i++) {
		layout[i][1] = true;
	}

}

void clockInfo::getTwoLayout(bool**& layout) {
	clearLayout(layout);
	for (int i = 0; i < 3; i++) {
		layout[0][i] = true;
		layout[2][i] = true;
		layout[4][i] = true;
	}
	layout[1][2] = true;
	layout[3][0] = true;
}

void clockInfo::getThreeLayout(bool**& layout) {
	clearLayout(layout);
	for (int i = 0; i < 3; i++) {
		layout[0][i] = true;
		layout[4][i] = true;
	}
	for (int i = 0; i < 5; i++) {
		layout[i][2] = true;
	}
	layout[2][1] = true;
}
void clockInfo::getFourLayout(bool**& layout) {
	clearLayout(layout);
	for (int i = 0; i < 5; i++) {
		layout[i][2] = true;
	}
	for (int i = 0; i < 3; i++) {
		layout[i][0] = true;
	}
	layout[2][1] = true;
}
void clockInfo::getFiveLayout(bool**& layout) {
	clearLayout(layout);
	for (int i = 0; i < 3; i++) {
		layout[0][i] = true;
		layout[2][i] = true;
		layout[4][i] = true;
	}
	layout[1][0] = true;
	layout[3][2] = true;
}
void clockInfo::getSixLayout(bool**& layout) {
	clearLayout(layout);
	for (int i = 0; i < 5; i++) {
		layout[i][0] = true;
	}
	for (int i = 0; i < 3; i++) {
		layout[0][i] = true;
		layout[2][i] = true;
		layout[4][i] = true;

	}
	layout[3][2] = true;


}
void clockInfo::getSevenLayout(bool**& layout) {
	clearLayout(layout);
	for (int i = 0; i < 5; i++) {
		layout[i][2] = true;
	}
	for (int i = 0; i < 3; i++) {
		layout[0][i] = true;
	}
	
}
void clockInfo::getEightLayout(bool**& layout) {
	clearLayout(layout);
	for (int i = 0; i < 5; i++) {
		layout[i][0] = true;
		layout[i][2] = true;
	}
	layout[0][1] = true;
	layout[4][1] = true;
	layout[2][1] = true;
}
void clockInfo::getNineLayout(bool**& layout) {
	clearLayout(layout);
	for (int i = 0; i < 5; i++) {
		layout[i][2] = true;
	}
	for (int i = 0; i < 3; i++) {
		layout[i][0] = true;
	}
	layout[0][1] = true;
	layout[2][1] = true;
	
}
void clockInfo::getColonLayout(bool**& layout) {
	clearLayout(layout);
	layout[0][1] = true;
	layout[1][1] = true;

	layout[3][1] = true;
	layout[4][1] = true;
}

void clockInfo::clearLayout(bool**& layout) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			layout[i][j] = false;
		}
	}
}

bool clockInfo::updateTime(bool & secondsUpdated) {

	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);
	hour = now->tm_hour;
	bool updatedTime = false;
	if (now->tm_min != minute) {
		updatedTime = true;
	}
	if (now->tm_sec != second) {
		secondsUpdated = true;
	}
	minute = now->tm_min;
	second = now->tm_sec;
	return updatedTime;

}

void clockInfo::printTime() {
	std::cout << hour << ":" << minute << ":" << second << std::endl;
}

int clockInfo::getHour() {
	return hour;
}

int clockInfo::getMinute() {
	return minute;
}

int clockInfo::getSecond() {
	return second;
}

void clockInfo::forceUpdate() {
	minute++;
}