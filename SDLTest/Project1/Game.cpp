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
		m_screenSize = Size(1000, 1000);

		//creates our renderer, which looks after drawing and the window
		m_REND = Renderer();
		m_REND.init(m_screenSize, "AStarThreading");
		m_REND.setViewRect(Rect(0, 0, m_screenSize.w, m_screenSize.h));

		//set up the viewport
		//we want the vp centred on origin and 20 units wide
		float aspectRatio = m_screenSize.w / m_screenSize.h;
		Size vpSize(m_screenSize.w, m_screenSize.h);
		Vector2 vpBottomLeft(0, 0);

		Rect vpRect(vpBottomLeft, vpSize);
		m_REND.setViewPort(vpRect);
		gridSize = 100;
		//start = Vector2D(1, 4);
		//end = Vector2D(8, 4);
		randomStart();
		myStar.initiialise(wallOne, gridSize);
		
		m_running = true;

	return true;
}



void Game::LoadContent()
{

}

void Game::Render()
{
	m_REND.clear(Colour(128, 128, 128, 32));
	//m_REND.drawRect(Rect( 80, 60, 80, 60), Colour(255, 0, 255, 128));
	//12, 4, 6, 51

	for (int y = 0; y < gridSize; y++) {
		for (int x = 0; x < gridSize; x++) {
			m_REND.drawFillRect(Rect(x * (m_screenSize.w / gridSize), y * (m_screenSize.h / gridSize), (m_screenSize.w / gridSize), (m_screenSize.w / gridSize)), Colour(60, 60, 255, 128));
		}
	}
	for each (Vector2D var in wallOne)
	{
		m_REND.drawFillRect(Rect(var.GetX() * (m_screenSize.w / gridSize), var.GetY() * (m_screenSize.w / gridSize), (m_screenSize.w / gridSize), (m_screenSize.w / gridSize)), Colour(0, 0, 600, 255));
	}


	if (route.size() != 0) {
		
		for each (Vector2D var2D in route)
		{
			m_REND.drawFillRect(Rect(var2D.GetX() * (m_screenSize.w / gridSize), var2D.GetY() * (m_screenSize.w / gridSize), (m_screenSize.w / gridSize), (m_screenSize.w / gridSize)), Colour(64, 128, 32, 255));
		}
	}
	m_REND.drawFillRect(Rect(start.GetX() * (m_screenSize.w / gridSize), start.GetY() * (m_screenSize.w / gridSize), (m_screenSize.w / gridSize), (m_screenSize.w / gridSize)), Colour(12, 80, 100, 255));
	m_REND.drawFillRect(Rect(end.GetX() * (m_screenSize.w / gridSize), end.GetY() * (m_screenSize.w / gridSize), (m_screenSize.w / gridSize), (m_screenSize.w / gridSize)), Colour(255, 255, 255, 255));

	m_REND.present();
}

void Game::Update()
{
	//DEBUG_MSG("Updating....");
	
	//if (route.size() == 0) {
	//	//route = myStar.getValue(0, 6, 9, 6);
	//	route = myStar.getValue(start.GetX(), start.GetY(), end.GetX(), end.GetY());
	//	
	//}
	
	if (waiting) {
		if (routeA.size() == 0) {
			routeA = myStar.getValue(start.GetX(), start.GetY(), end.GetX() / 2, end.GetY() / 2);
		}
		if (routeA.size() != 0 && routeB.size() != 0)
		{
			waiting = false;
			redraw = true;
		}
	}

	if (redraw) {
		for each (Vector2D v2A in routeA)
		{
			route.push_back(v2A);
		}
		for each (Vector2D v2B in routeB)
		{
			route.push_back(v2B);
		}
		redraw = false;
	}
	//m_Player->Update();
}

void Game::HandleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type) {

		case SDL_MOUSEBUTTONDOWN:
			//do whatever you want to do after a mouse button was pressed,
			// e.g.:
			mousePress(event.button);
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
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
}


void Game::mousePress(SDL_MouseButtonEvent& b) {
	if (b.button == SDL_BUTTON_LEFT) {
		Vector2D actual = Vector2D(b.x, b.y);
		myStar.initiialise(wallOne, gridSize);
		end = Vector2D(b.x / (m_screenSize.w / gridSize) , b.y / (m_screenSize.h / gridSize));
		waiting = true;
		dataToSend = true;
		//route = myStar.getValue(start.GetX(), start.GetY(), end.GetX(), end.GetY());
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


void Game::clean() {
	route.clear();
	m_REND.clear(Colour(128, 128, 128, 32));
}

void Game::randomStart()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> distributionOneX(0, gridSize);
	//std::uniform_int_distribution<int> distributionOneY(0, 10);
	int x1 = distributionOneX(mt);
	int y1 = distributionOneX(mt);
	//std::uniform_int_distribution<int> distributionTwoX(x1 + 1, 10);
	//std::uniform_int_distribution<int> distributionTwoY(y1 + 1, 10);
	int x2 = distributionOneX(mt);
	int y2 = distributionOneX(mt);
	std::uniform_int_distribution<int> distributionTwo(-10, 10);
	int dif = distributionTwo(mt);

	for (int i = 0; i < 80; i++) {
		wallOne.push_back(Vector2D(20 + (dif), i));

		wallOne.push_back(Vector2D(40 + (dif), ((50 + dif) - i)));

		wallOne.push_back(Vector2D(60 + (dif), ((50 - dif) - i)));
	}


	start = Vector2D(10, 6);
	end = Vector2D(x2, y2);
}

Vector2D Game::getStart()
{
	return start;
}

Vector2D Game::getEnd()
{
	return end;
}

void Game::setB(vector<Vector2D> v)
{
	routeB = v;
	clean();
}

AStar * Game::getAstar()
{
	AStar* retStar = &myStar;
	return retStar;
}

bool Game::getDataToSend()
{
	return dataToSend;
}

void Game::setDataToSend(bool b)
{
	dataToSend = b;
}
