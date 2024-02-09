#pragma once

class Settings
{
protected:
	bool dataWithSpaces;
	int windowWidth;
	int animationSpeed;
	int amountOfData;
public:
	Settings();
	void setSettings(int animationSpeed, int amountOfData, int windowWidth);
	int* getAmountOfDataPointer() { return &amountOfData; }
	int* getAnimationSpeedPointer() { return &animationSpeed; }
	void checkIfDataWithSpaces();
};

