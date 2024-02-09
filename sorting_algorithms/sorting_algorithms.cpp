#include "App.h"

int main()
{
	srand(time(0));
	App app;

	while (app.running())
	{
		app.render();
	}
}
