#include "App.h"

//										Auxiliary methods
void App::checkIfSorted() {
	int notInOrder = 0;
	int frame = 0;

	for (auto& x : this->dataVector)
		x.shape.setFillColor(sf::Color::White);

	// Check if values are in order, if so set their color to green
	for (auto i = this->dataVector.begin(); i != this->dataVector.end() - 1; i++) {
		if (i->value <= (i + 1)->value)
			i->shape.setFillColor(sf::Color::Green);
		else
			notInOrder++;
		if (frame % Settings::animationSpeed == 0) {
			this->pollEvents();
			if (this->appIsRunning == false)
				break;
			this->windowUpdateAndDisplay();
		}

	frame++;
	}

	(this->dataVector.end() - 1)->shape.setFillColor(sf::Color::Green);

	if (notInOrder == 0)
		this->sorted = true;
}

void App::swap(int first, int second) {
	dataSprite temp;

	// Swap sizes and values
	temp.value = dataVector[second].value;
	temp.shape.setSize(sf::Vector2f(dataVector[second].shape.getSize().x,
		dataVector[second].shape.getSize().y));
	dataVector[second].value = dataVector[first].value;
	dataVector[second].shape.setSize(sf::Vector2f(dataVector[first].shape.getSize().x, 
		dataVector[first].shape.getSize().y));
	dataVector[first].value = temp.value;
	dataVector[first].shape.setSize(sf::Vector2f(temp.shape.getSize().x, temp.shape.getSize().y));

	// Set shapes color
	dataVector[first].shape.setFillColor(sf::Color::Red);
	dataVector[second].shape.setFillColor(sf::Color::Red);

	// Emplace the shapes in the correct position on the screen
	dataVector[second].shape.setOrigin(sf::Vector2f(0.f, dataVector[second].shape.getGlobalBounds().height));
	dataVector[first].shape.setOrigin(sf::Vector2f(0.f, dataVector[first].shape.getGlobalBounds().height));
}

int App::partition(int low, int high) {
	int frame = 0;
	int pivot = dataVector[high].value;
	int i = (low - 1);

	for (int j = low; j < high; j++) {		
		if (dataVector[j].value <= pivot) {
			i++;
			swap(i, j);

		if (frame % Settings::animationSpeed == 0) {
			this->pollEvents();
			if (this->appIsRunning == false)
				break;
			this->UpdateWindowAndColor();
		}
		}

		frame++;
	}
	swap(i + 1, high);

	return (i + 1);
}

//dataSprite dataSprite::operator=(dataSprite& other)
//{
//	// Swap sizes and values
//	this->value = other.value;
//	this->shape.setSize(sf::Vector2f(other.shape.getSize().x, other.shape.getSize().y));
//
//	
//
//	// Swap sizes and values
//
//	// Set shapes color
//	dataVector[first].shape.setFillColor(sf::Color::Red);
//	dataVector[second].shape.setFillColor(sf::Color::Red);
//
//	// Emplace the shapes in the correct position on the screen
//	dataVector[second].shape.setOrigin(sf::Vector2f(0.f, dataVector[second].shape.getGlobalBounds().height));
//	dataVector[first].shape.setOrigin(sf::Vector2f(0.f, dataVector[first].shape.getGlobalBounds().height));
//	
//}

void App::UpdateWindowAndColor() {
	this->windowUpdateAndDisplay();

	for (auto& x : this->dataVector)
		x.shape.setFillColor(sf::Color::White);
}

//										Sorting algorithms
void App::bubbleSort(int low, int high) {
	int frame = 0;
	dataSprite temp;

	for (int i = dataVector.size() - 1; i != 0; i--) {
		for (int j = 0; j != i; j++)
			if (dataVector[j].value > dataVector[i].value)
				swap(i, j);
		
		if (frame % Settings::animationSpeed == 0) {
			this->pollEvents();
			if (this->appIsRunning == false)
				break;
			this->UpdateWindowAndColor();
		}

		frame++;
	}
}

void App::selectionSort(int low, int high) {
	int frame = 0;

	for (int step = 0; step < dataVector.size() - 1; step++) {
		int minimumValueIndex = step;
		for (int i = step + 1; i < dataVector.size(); i++)
			if (dataVector[i].value < dataVector[minimumValueIndex].value)
				minimumValueIndex = i;

		if (frame % Settings::animationSpeed == 0) {
			this->pollEvents();
			if (this->appIsRunning == false)
				break;
			this->UpdateWindowAndColor();
		}

		frame++;

		swap(minimumValueIndex, step);
	}
}

//void App::insertionSort(int low, int high)
//{
//	int frame = 0;
//
//	for (int step = 1; step < dataVector.size(); step++)
//	{
//		dataSprite key = dataVector[step];
//		int i = step - 1;
//
//		// Needs a = method defined for data sprites
//	}
//
//	if (frame % Settings::animationSpeed == 0)
//	{
//		this->pollEvents();
//		if (this->isRunning == false)
//			break;
//		this->UpdateWindowAndColor();
//	}
//
//	frame++;
//}

void App::quickSort(int low, int high) {
	if (low < high) {
		int pivot = partition(low, high);
		quickSort(low, pivot - 1);
		quickSort(pivot + 1, high);
	}
}
