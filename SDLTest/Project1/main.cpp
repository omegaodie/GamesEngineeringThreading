#include <iostream>
#include <thread>
#include <string>

#include "TinyXML2.h"

#include <SDL.h>
#include <SDL_image.h>

#include "Game.h"

using namespace std;
using namespace tinyxml2;

// Very simple thread - counts 0 to 9 delaying 50ms between increments
static int TestThread(void *ptr)
{
	int cnt = 1; 

	ThreadData *tdata = (ThreadData*)ptr;
	int param1 = tdata->param1;
	char param2 = tdata->param2;
	free(ptr);


	return cnt;
}

typedef struct {
	int param1;
	char param2;
} ThreadData;


int main(int argc, char** argv){

	DEBUG_MSG("Game Object Created");

	Game* game = new Game();
	SDL_Thread *thread;
	int         threadReturnValue;

	ThreadData *data = malloc(sizeof(ThreadData));
	data->param1 = 1;
	data->param2 = 'red';
	thread = SDL_CreateThread(TestThread, "TestThread", (void *)data);


	printf("\nSimple SDL_CreateThread test:");

	// Simply create a thread
	thread = SDL_CreateThread(TestThread, "TestThread", (void *)NULL);

	if (NULL == thread) {
		DEBUG_MSG("\nSDL_CreateThread failed: %s\n", SDL_GetError());
	}
	else {
		SDL_WaitThread(thread, &threadReturnValue);
		DEBUG_MSG("\nThread returned value: %d", threadReturnValue);
	}



	game->Initialize("DGPP Skelatol",300,100,800,600, SDL_WINDOW_INPUT_FOCUS);
	

	while(game->IsRunning())
	{
		//
		game->HandleEvents();
		game->Update();
		game->Render();
	}

	DEBUG_MSG("Calling Cleanup");
	game->CleanUp();
	game->UnloadContent();
	
	return 0;
}


