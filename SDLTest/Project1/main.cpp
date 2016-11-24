#include <iostream>
#include <thread>
#include <string>

#include "TinyXML2.h"

#include <SDL.h>
#include <SDL_image.h>

#include "Game.h"
#include "AStar.h"
#include "Tile.h"
#include "Player.h"

using namespace std;
using namespace tinyxml2;

int main(int argc, char** argv){

	DEBUG_MSG("Game Object Created");

	//Player* player = new Player();
	Tile theTiles[10][10];
	AStar theAlgo = AStar();
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			theTiles[j][i] = Tile(j, i);
		}
		
	}

	Game* game = new Game();

	XMLDocument doc;
	doc.LoadFile("Levels.xml");

	const char* temp = doc.FirstChildElement("root")->FirstChildElement("level1")->FirstChildElement("player")->FirstChildElement("health")->GetText();

	DEBUG_MSG(temp);

	//Adjust screen positions as needed
	DEBUG_MSG("Game Initialising");
	game->Initialize("DGPP Skelatol",300,100,800,600, SDL_WINDOW_INPUT_FOCUS);
	
	DEBUG_MSG("Loading Content");
	game->LoadContent();


	DEBUG_MSG("Game Loop Starting......");
	while(game->IsRunning())
	{
		theAlgo.Update(theTiles, theTiles[2][4], theTiles[3][6]);
		game->HandleEvents();
		game->Update();
		game->Render();
	}

	DEBUG_MSG("Calling Cleanup");
	game->CleanUp();
	game->UnloadContent();
	
	return 0;
}


