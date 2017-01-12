#include <iostream>
#include <thread>
#include <string>

#include "TinyXML2.h"

#include <SDL.h>
#include <SDL_image.h>

#include "Game.h"

using namespace std;
using namespace tinyxml2;



typedef struct {
	Vector2D start;
	Vector2D end;
	AStar* starRef;
	Game* gme;
	vector<Vector2D> routeB;
	bool AorB; // true for A false for B
} ThreadData;

static int TestThread(void *ptr)
{
	ThreadData *tdata = (ThreadData*)ptr;

	tdata->routeB = tdata->starRef->getValue((tdata->start.GetX() + tdata->end.GetX()) / 2, (tdata->start.GetY() + tdata->end.GetY()) / 2, tdata->end.GetX(), tdata->end.GetY());
	int cnt = 1;
	return cnt;
}




int main(int argc, char** argv){

	DEBUG_MSG("Game Object Created");

	SDL_mutex *mutex;
	mutex = SDL_CreateMutex();


	Game* game = new Game();
	ThreadData *data = new ThreadData;
	SDL_Thread *thread = NULL;
	int threadReturnValue = 0;
	vector<Vector2D> routeB;
	game->Initialize("DGPP Skelatol",300,100,800,600, SDL_WINDOW_INPUT_FOCUS);
	

	while(game->IsRunning())
	{
		//
		game->HandleEvents();
		game->Update();
		game->Render();
		if (game->getDataToSend()) {
				data->start = game->getStart();
				data->end = game->getEnd();
				data->AorB = false;
				data->routeB;
				data->gme = game;
				data->starRef = game->getAstar();
				game->setDataToSend(false);
				if (SDL_LockMutex(mutex) == 0) {
					thread = SDL_CreateThread(TestThread, "TestThread", data);
					SDL_UnlockMutex(mutex);
					//
				}
				else {
					fprintf(stderr, "Couldn't lock mutex\n");
				}
				
		}
		if ((NULL != thread)&&(data->routeB.size() != 0)) {
			//while (data->routeB.size() == 0) {
			//	//SDL_WaitThread(thread, &threadReturnValue);
			//}
			game->setB(data->routeB);
			thread = NULL;
			DEBUG_MSG("\nThread returned value: %d", threadReturnValue);
		}
	}

	DEBUG_MSG("Calling Cleanup");
	game->CleanUp();
	game->UnloadContent();
	
	return 0;
}


//SDL_mutex *mutex;
//
//mutex = SDL_CreateMutex();
//if (!mutex) {
//	fprintf(stderr, "Couldn't create mutex\n");
//	return;
//}
//
//if (SDL_LockMutex(mutex) == 0) {
//	/* Do stuff while mutex is locked */
//	SDL_UnlockMutex(mutex);
//}
//else {
//	fprintf(stderr, "Couldn't lock mutex\n");
//}
//
//SDL_DestroyMutex(mutex);
