#pragma once
class clockInfo
{

public:
	void getZeroLayout(bool**&);
	void getOneLayout(bool**&);
	void getTwoLayout(bool**&);
	void getThreeLayout(bool**&);
	void  getFourLayout(bool**&);
	void getFiveLayout(bool**&);
	void getSixLayout(bool**&);
	void getSevenLayout(bool**&);
	void getEightLayout(bool**&);
	void getNineLayout(bool**&);
	void getColonLayout(bool**&);
	
	void clearLayout(bool**&);
	bool updateTime(bool&);
	void printTime();

	void forceUpdate();

	int getHour();
	int getMinute();
	int getSecond();

private:
	int hour;
	int minute;
	int second;
};

