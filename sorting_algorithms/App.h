#pragma once

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <cstdlib>

#include "Settings.h"

struct dataSprite
{
	sf::RectangleShape shape;
	int value;
//	dataSprite operator=(dataSprite &other);
};

class App : protected Settings
{
private:
	// Window
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event event;

	// Variables
	float vectorCoordinatesX;
	float dataSizeX;
	bool sorted;
	bool isRunning;
	int sortChoice;

	// App objects
	std::vector<dataSprite> dataVector;
	std::unordered_map<int, std::function<void(int, int)>> sortingFunctionsMap;

	// Private methods
	void initializeVector();
	void initializeVariables();
	void initializeMap();
	void initializeWindow();

	void windowUpdateAndDisplay();

	// Auxiliary methods
	void checkIfSorted();
	void swap(int a, int b);
	int partition(int low, int high);
	void UpdateWindowAndColor();


	// Sorting algorithms
	void bubbleSort(int low, int high);
	void selectionSort(int low, int high);
//	void insertionSort(int low, int high);
	void quickSort(int low, int high);

public:
	// Constructor and destructor
	App(int animationSpeed, int amountOfData, int sortChoice);
	~App();

	// Accessors
	const bool running() const;

	// Methods
	void pollEvents();

	void render();

	// Debug methods
	void show() const;
};

