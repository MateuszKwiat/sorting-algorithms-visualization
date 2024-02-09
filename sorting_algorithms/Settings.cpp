#include "Settings.h"

Settings::Settings() : animationSpeed(0), amountOfData(0), windowWidth(0), dataWithSpaces(true) {}

void Settings::setSettings(int animationSpeed, int amountOfData, int windowWidth)
{
	this->animationSpeed = animationSpeed;
	this->amountOfData = amountOfData;
	this->windowWidth = windowWidth;

	// All data blocks should be separated with 1px of free space.
	// If it's not possible there should be no space between each block.
	if (amountOfData * 2 >= windowWidth)
		this->dataWithSpaces = false;
	else
		this->dataWithSpaces = true;
}

void Settings::checkIfDataWithSpaces() {
	if (amountOfData * 2 >= windowWidth)
		this->dataWithSpaces = false;
	else
		this->dataWithSpaces = true;
}