#include "Player.h"

Player::Player()
{
	DEBUG_MSG("Constructing Player");
}

Player::~Player()
{
	DEBUG_MSG("Destructing Player");
	//32*48
}

void Player::Initialize(const GameObjectParameters* params) {

}

void Player::Initialize(const GameObjectParameters* params, SDL_Renderer* m_p)
{
	DEBUG_MSG("Player Initializing");

	m_p_Surface = SDL_LoadBMP("assets/leppy.bmp");
	m_p_Texture = SDL_CreateTextureFromSurface(m_p, m_p_Surface);
	SDL_FreeSurface(m_p_Surface);
	f_x = 32;
	f_y = 48;

	this->SetX(params->GetX());
	this->SetY(params->GetY());
}

void Player::Initialize(SDL_Renderer* m_p)
{
	DEBUG_MSG("Player Initializing");

	m_p_Surface = SDL_LoadBMP("assets/leppy.bmp");
	m_p_Texture = SDL_CreateTextureFromSurface(m_p, m_p_Surface);
	SDL_FreeSurface(m_p_Surface);
	f_x = 32;
	f_y = 48;

	this->SetX(10);
	this->SetY(10);
}

void Player::Render() {
	//wow such empty
}

void Player::Render(SDL_Renderer* m_p)
{//32, 48, , m_y

	SDL_Rect* frame = new SDL_Rect();
	frame->x = f_x;
	frame->y = f_y;
	frame->w = 32;
	frame->h = 48;

	SDL_RenderCopy(m_p, m_p_Texture, frame, NULL);
	DEBUG_MSG("Player Drawing");
}

void Player::Update()
{
	DEBUG_MSG("Player Updating");
	if (f_x <= 96) {
		f_x += 32;
	}
	else {
		f_x = 0;
		if (f_y <= 144) {
			f_y += 48;
		}
		else {
			f_y = 0;
		}
	}
	
}

void Player::CleanUp()
{
	DEBUG_MSG("Cleaning Up Player");
}
