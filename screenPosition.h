#pragma once
class screenPosition
{

private:
	float x;
	float y;
	float z;
	bool isActive;
	bool filled;

	int boardRow;
	int  boardCol;

public:
	void setBoardRow(int);
	void setBoardCol(int);
	int getBoardRow(); 
	int getBoardCol();



	void init(float, float, float);

	void setFilled(bool);

	float getX();
	float getY();
	float getZ();
	void setActive(bool);

	bool getActive();
	bool isCorrect();

};

