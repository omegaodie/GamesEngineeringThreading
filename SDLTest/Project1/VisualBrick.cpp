#include "VisualBrick.h"

VisualBrick::VisualBrick()
{
	//DEBUG_MSG("Constructing VisualBrick");
}

VisualBrick::~VisualBrick()
{
	DEBUG_MSG("Destructing VisualBrick");
	//32*48
}

void VisualBrick::Initialize(const GameObjectParameters* params) {

}



void VisualBrick::Initialize(Uint16 x, Uint16 y, SDL_Renderer* m_p, SDL_Window* m_p_W) {


	//Get window surface
	SDL_Surface *screenSurface = SDL_GetWindowSurface(m_p_W);

	//Fill the surface white
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));



	//create a square
	SDL_Rect* frame = new SDL_Rect();
	frame->x = f_x;
	frame->y = f_y;
	frame->w = 100;
	frame->h = 100;


	SDL_FillRect(screenSurface, frame, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));

	this->SetX(x);
	this->SetY(y);
}

void VisualBrick::Initialize(const GameObjectParameters* params, SDL_Renderer* m_p, SDL_Window* m_p_W)
{
	//DEBUG_MSG("VisualBrick Initializing");

	//m_p_Surface = SDL_LoadBMP("assets/leppy.bmp");
	//m_p_Texture = SDL_CreateTextureFromSurface(m_p, m_p_Surface);
	//SDL_FreeSurface(m_p_Surface);
	//f_x = 32;
	//f_y = 48;

	//Get window surface
	SDL_Surface *screenSurface = SDL_GetWindowSurface(m_p_W);

	//Fill the surface white
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

	//create a square
	SDL_Rect* frame = new SDL_Rect();
	frame->x = f_x;
	frame->y = f_y;
	frame->w = 100;
	frame->h = 100;


	SDL_FillRect(screenSurface, frame, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));

	this->SetX(params->GetX());
	this->SetY(params->GetY());
}

void VisualBrick::Initialize(SDL_Renderer* m_p)
{
	DEBUG_MSG("VisualBrick Initializing");

	//m_p_Surface = SDL_LoadBMP("assets/leppy.bmp");
	//m_p_Texture = SDL_CreateTextureFromSurface(m_p, m_p_Surface);
	//SDL_FreeSurface(m_p_Surface);
	//f_x = 32;
	//f_y = 48;




	this->SetX(10);
	this->SetY(10);
}

void VisualBrick::Render() {
	//wow such empty
}

void VisualBrick::Render(SDL_Renderer* m_p)
{//32, 48, , m_y

	//SDL_Rect* frame = new SDL_Rect();
	//frame->x = f_x;
	//frame->y = f_y;
	//frame->w = 32;
	//frame->h = 48;

	//SDL_RenderCopy(m_p, m_p_Texture, frame, NULL);

	//Get window surface




	DEBUG_MSG("VisualBrick Drawing");
}

void VisualBrick::Update()
{
	DEBUG_MSG("VisualBrick Updating");
	//if (f_x <= 96) {
	//	f_x += 32;
	//}
	//else {
	//	f_x = 0;
	//	if (f_y <= 144) {
	//		f_y += 48;
	//	}
	//	else {
	//		f_y = 0;
	//	}
	//}

}

void VisualBrick::CleanUp()
{
	DEBUG_MSG("Cleaning Up VisualBrick");
}
