#include "App.h"

int main()
{
	srand(time(0));


	int x = 1000;
	int y = 3;
	int z = 1;

	//std::cout << "how many shapes: ";
	//std::cin >> x;
	//std::cout << "animation speed: ";
	//std::cin >> y;
	//std::cout << "which sort: ";
	//std::cin >> z;

	App app(y, x, z);

	while (app.running())
	{
		app.render();
	}
}
