#include "App.h"

//										Private methods
void App::initializeVariables()
{
	this->vectorCoordinatesX = 0.f;

	// calculate the width of blocks and if they should be separated.
	if (Settings::dataWithSpaces)
		this->dataSizeX = (this->window->getSize().x - Settings::amountOfData) /
			static_cast<float>(Settings::amountOfData);
	else
		this->dataSizeX = (this->window->getSize().x / static_cast<float>(Settings::amountOfData));

	this->sorted = true;
	this->isRunning = true;
}

void App::initializeVector()
{
	this->dataVector.resize(Settings::amountOfData);


	for (auto& x : this->dataVector)
	{
		x.shape.setFillColor(sf::Color::White);
		x.shape.setSize(sf::Vector2f(this->dataSizeX,
			rand() % 1050 + 20));
		x.value = x.shape.getSize().y;
		x.shape.setOrigin(sf::Vector2f(0.f, 
			x.shape.getGlobalBounds().height));
		x.shape.setPosition(sf::Vector2f(vectorCoordinatesX,
			this->window->getSize().y - 10.f));
		if (Settings::dataWithSpaces)
			vectorCoordinatesX += this->dataSizeX + 1.f;
		else
			vectorCoordinatesX += this->dataSizeX;
	//	vectorCoordinatesX += Settings::dataWithSpaces ? this->dataSizeX + 1.f : this->dataSizeX; // this->dataSizeX + 1.f;
	}

	// Check if all shapes get printed
	this->dataVector[Settings::amountOfData - 1].
		shape.setFillColor(sf::Color::Magenta);

}

void App::initializeMap()
{
	sortingFunctionsMap[0] = [=](int low, int high) { bubbleSort(low, high); };
	sortingFunctionsMap[1] = [=](int low, int high) { selectionSort(low, high); };
	sortingFunctionsMap[2] = [=](int low, int high) { quickSort(low, high); };
}

void App::initializeWindow()
{
	this->videoMode = sf::VideoMode::getDesktopMode();
	this->window = new sf::RenderWindow(this->videoMode,
		"sorting algorithms", sf::Style::Default);
	this->window->setFramerateLimit(60);
}

void App::windowUpdateAndDisplay()
{
//	this->pollEvents();

	this->window->clear();

	for (auto& x : this->dataVector)
		this->window->draw(x.shape);
	
	ImGuiController::update(*this->window);
	ImGuiController::render(*this->window, this->sorted, &sortChoice,
		Settings::getAmountOfDataPointer(), Settings::getAnimationSpeedPointer());
	this->window->display();
}

//										Constructor and destructor
App::App(int animationSpeed, int amountOfData, int sortChoice) 
	: Settings(), ImGuiController()
{
	this->sortChoice = sortChoice;

	this->initializeWindow();
	ImGuiController::initialize(*this->window);
	Settings::setSettings(animationSpeed, amountOfData, this->window->getSize().x);
	this->initializeVariables();
	this->initializeVector();
	this->initializeMap();
}

App::~App()
{
	ImGuiController::~ImGuiController();
	delete this->window;
}


//										Accessors
const bool App::running() const
{
	return isRunning;
}


//										Methods
void App::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		ImGuiController::eventProcessing(this->event);
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			this->isRunning = false;
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
				this->isRunning = false;
			}
			break;
		}
	}
}

void App::render()
{

	this->pollEvents();
	if (!this->sorted)
	{
		auto pickedSortingFunction = sortingFunctionsMap[sortChoice];
		pickedSortingFunction(0, dataVector.size() - 1);
		this->checkIfSorted();

		this->vectorCoordinatesX = 0.f;
		this->dataVector.clear();
		this->initializeVector();
		this->sorted = true;
	}
	else {
		this->windowUpdateAndDisplay();
	}
}

//										Debug methods
void App::show() const
{
	for (auto x : dataVector)
		std::cout << x.value << std::endl;
}
