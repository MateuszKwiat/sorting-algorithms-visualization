#include "App.h"

int main()
{
	srand(time(0));


	int x;
	int y;
	int z;

	std::cout << "how many shapes: ";
	std::cin >> x;
	std::cout << "animation speed: ";
	std::cin >> y;
	std::cout << "which sort: ";
	std::cin >> z;

	App app(y, x, z);

	while (app.running())
	{
		app.render();
	}
}
