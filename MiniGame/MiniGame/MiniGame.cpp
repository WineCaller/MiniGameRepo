
#include <iostream>
#include <ctime>
#include "Game.h"
//#include "SmpleWindow.h"

int main()
{
	srand(time(NULL));

	Game MiniGame;
	
	// Game Loop
	while (MiniGame.Running())
	{
		MiniGame.EventHandler();
		
		MiniGame.Update();
		
		MiniGame.Render();
	}
}

