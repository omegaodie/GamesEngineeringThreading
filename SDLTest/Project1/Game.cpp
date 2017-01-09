#include "Game.h"
#include <iostream>
#include <thread>


using namespace std;

Game::Game() : m_running(false)
{
	//m_REND = Renderer();
}

Game::~Game()
{
}

bool Game::Initialize(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	//if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	//{
	//	DEBUG_MSG("SDL Init success");
	//	m_p_Window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		myStar = AStar();
		m_screenSize = Size(2000, 2000);

		//creates our renderer, which looks after drawing and the window
		m_REND = Renderer();
		m_REND.init(m_screenSize, "AStarThreading");
		m_REND.setViewRect(Rect(0, 0, 2000, 2000));

		//set up the viewport
		//we want the vp centred on origin and 20 units wide
		float aspectRatio = m_screenSize.w / m_screenSize.h;
		Size vpSize(2000, 2000);
		Vector2 vpBottomLeft(0, 0);

		Rect vpRect(vpBottomLeft, vpSize);
		m_REND.setViewPort(vpRect);

		start = Vector2D(1, 4);
		end = Vector2D(8, 4);
		randomStart();
		myStar.getWalls(wallOne);
		
	//	theTiles = new VisualBrick*[10];
	//	for (int i = 0; i < 10; i++) {
	//			theTiles[i] = new VisualBrick[10];
	//			for (int j = 0; j < 10; j++) {

	//				theTiles[i][j] = VisualBrick();
	//				theTiles[i][j].Initialize(i, j, m_p_Renderer, m_p_Window);

	//			}
	//	}
	//	if(m_p_Window != 0)
	//	{
	//		DEBUG_MSG("Window creation success");
	//		m_p_Renderer = SDL_CreateRenderer(m_p_Window, -1, 0);
	//		if(m_p_Renderer != 0)
	//		{
	//			DEBUG_MSG("Renderer creation success");
	//			SDL_SetRenderDrawColor(m_p_Renderer, 255, 0, 255, 255);
	//		}
	//		else
	//		{
	//			DEBUG_MSG("Renderer init fail");
	//			return false;
	//		}
	//	}
	//	else
	//	{
	//		DEBUG_MSG("Window init fail");
	//		return false;
	//	}
	//}
	//else
	//{
	//	DEBUG_MSG("SDL init fail");
	//	return false;
	//}
	m_running = true;

	return true;
}



void Game::LoadContent()
{
	//DEBUG_MSG("Loading Content");
	//m_p_Surface = SDL_LoadBMP("assets/sprite.bmp");
	//m_p_Texture = SDL_CreateTextureFromSurface(m_p_Renderer, m_p_Surface);
	//SDL_FreeSurface(m_p_Surface);

	////m_Player->Initialize(m_p_Renderer);
	//if(SDL_QueryTexture(m_p_Texture, NULL, NULL, &m_Source.w, &m_Destination.h)==0)
	//{
	//	m_Destination.x = m_Source.x = 0;
	//	m_Destination.y = m_Source.y = 0;
	//	m_Destination.w = m_Source.w;
	//	m_Destination.h = m_Source.h;

	//	//DEBUG_MSG("Destination X:" + m_Destination.x);
	//	/*DEBUG_MSG("Destination Y:" + m_Destination.y);
	//	DEBUG_MSG("Destination W:" + m_Destination.w);
	//	DEBUG_MSG("Destination H:" + m_Destination.h);*/
	//}
	//else
	//{
	//	DEBUG_MSG("Texture Query Failed");
	//	m_running = false;
	//}
}

void Game::Render()
{
	m_REND.clear(Colour(128, 128, 128, 32));
	//m_REND.drawRect(Rect( 80, 60, 80, 60), Colour(255, 0, 255, 128));
	//12, 4, 6, 51

	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			m_REND.drawRect(Rect(x * 50, y * 50, 50, 50), Colour(60, 60, 60, 255));
		}
	}
	for each (Vector2D var in wallOne)
	{
		m_REND.drawFillRect(Rect(var.GetX() * 50, var.GetY() * 50, 50, 50), Colour(0, 0, 600, 255));
	}


	if (route.size() != 0) {
		
		for each (Vector2D var2D in route)
		{
			m_REND.drawFillRect(Rect(var2D.GetX() * 50, var2D.GetY() * 50, 50, 50), Colour(64, 128, 32, 255));
		}
	}
	m_REND.drawFillRect(Rect(start.GetX() * 50, start.GetY() * 50, 50, 50), Colour(12, 80, 100, 255));
	m_REND.drawFillRect(Rect(end.GetX() * 50, end.GetY() * 50, 50, 50), Colour(255, 255, 255, 255));

	//m_REND.drawFillRect(Rect(1 * 50, 6 * 50, 50, 50), Colour(128, 64, 90, 255));
	//m_REND.drawFillRect(Rect(9 * 50, 6 * 50, 50, 50), Colour(255, 255, 255, 255));
	m_REND.present();
}

void Game::Update()
{
	//DEBUG_MSG("Updating....");
	
	if (route.size() == 0) {
		//route = myStar.getValue(0, 6, 9, 6);
		route = myStar.getValue(start.GetX(), start.GetY(), end.GetX(), end.GetY());
	}
	//m_Player->Update();
}

void Game::HandleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch(event.type)
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					m_running = false;
					break;
				case SDLK_UP:
					DEBUG_MSG("Up Key Pressed");
					//SDL_SetRenderDrawColor(m_p_Renderer, 255, 0, 0, 255);
					break;
				case SDLK_DOWN:
					DEBUG_MSG("Down Key Pressed");
					//SDL_SetRenderDrawColor(m_p_Renderer, 0, 255, 0, 255);
					break;
				case SDLK_LEFT:
					DEBUG_MSG("Left Key Pressed");
					//SDL_SetRenderDrawColor(m_p_Renderer, 0, 0, 255, 255);
					break;
				case SDLK_RIGHT:
					DEBUG_MSG("Right Key Pressed");
					//SDL_SetRenderDrawColor(m_p_Renderer, 255, 255, 255, 255);
					break;
				default:
					//SDL_SetRenderDrawColor(m_p_Renderer, 0, 0, 0, 255);
					break;
				}
	}
}

bool Game::IsRunning()
{
	return m_running;
}

void Game::UnloadContent()
{
	DEBUG_MSG("Unloading Content");
	//delete(m_p_Texture);
	//m_p_Texture = NULL;
}

void Game::CleanUp()
{
	DEBUG_MSG("Cleaning Up");
	//SDL_DestroyWindow(m_p_Window);
	//SDL_DestroyRenderer(m_p_Renderer);
	SDL_Quit();
}

void Game::randomStart()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> distributionOneX(0, 9);
	//std::uniform_int_distribution<int> distributionOneY(0, 10);
	int x1 = distributionOneX(mt);
	int y1 = distributionOneX(mt);
	//std::uniform_int_distribution<int> distributionTwoX(x1 + 1, 10);
	//std::uniform_int_distribution<int> distributionTwoY(y1 + 1, 10);
	int x2 = distributionOneX(mt);
	int y2 = distributionOneX(mt);


	wallOne.push_back(Vector2D(4, 3));
	wallOne.push_back(Vector2D(4, 4));
	wallOne.push_back(Vector2D(4, 5));
	wallOne.push_back(Vector2D(4, 6));
	wallOne.push_back(Vector2D(3, 6));
	wallOne.push_back(Vector2D(5, 6));


	start = Vector2D(x1, y1);
	end = Vector2D(x2, y2);
}
