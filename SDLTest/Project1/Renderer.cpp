#include "Renderer.h"
#include <iostream>

//THIS CODE IS THE WORK OF GITHUB USER OloinMilsom ///
// ITS SIMPLE EFFECTIVE CODE SO I SAW NO REASON TO CHANGE IT///
//USED without licence ///

Renderer::Renderer()
	:sdl_renderer(NULL),
	windowSize(Size()) {
}

bool Renderer::init(const Size& winSize, const char* title) {

	int e = SDL_Init(SDL_INIT_EVERYTHING);              // Initialize SDL2
	windowSize = winSize;
	if (e != 0)
	{
		// problem with SDL?...
		std::cout << "Could not init SDL: " << SDL_GetError() << std::endl;
		return false;
	}

	// Create an application window with the following settings:
	window = SDL_CreateWindow(
		title,                  // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		(int)winSize.w,                              // width, in pixels
		(int)winSize.h,                               // height, in pixels
		SDL_WINDOW_OPENGL                  // flags - see below
	);

	// Check that the window was successfully created
	if (window == NULL)
	{
		// In the case that the window could not be made...
		std::cout << "Could not create window: " << SDL_GetError() << std::endl;
		return false;
	}

	sdl_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (sdl_renderer == NULL)
	{
		// In the case that the renderer could not be made...
		std::cout << "Could not create renderer: " << SDL_GetError() << std::endl;
		return false;
	}

	//SDL_SetRenderDrawBlendMode(sdl_renderer, SDL_BLENDMODE_BLEND);

	return true;
}

//draw a filled rect in pixel coordinates
void Renderer::drawFillRect(const Rect& r, const Colour& c) const {
	if (r.pos.x < m_viewRect.pos.x + m_viewRect.size.w && r.pos.x + r.size.w > m_viewRect.pos.x &&
		r.pos.y < m_viewRect.pos.y + m_viewRect.size.h && r.pos.y + r.size.h > m_viewRect.pos.y) {
		SDL_SetRenderDrawColor(sdl_renderer, c.r, c.g, c.b, c.a);
		SDL_Rect sr;
		float wScale = (windowSize.w / m_viewRect.size.w);
		float hScale = (windowSize.h / m_viewRect.size.h);
		sr.h = static_cast<int>(r.size.h * hScale);
		sr.w = static_cast<int>(r.size.w * wScale);
		sr.x = static_cast<int>((r.pos.x - m_viewRect.pos.x) * wScale);
		sr.y = static_cast<int>((r.pos.y - m_viewRect.pos.y) * hScale);
		SDL_RenderFillRect(sdl_renderer, &sr); //Portal uses SDL_RenderDrawRect /***
	}
}

//draw a rect in pixel coordinates
void Renderer::drawRect(const Rect& r, const Colour& c) const {
	if (r.pos.x < m_viewRect.pos.x + m_viewRect.size.w && r.pos.x + r.size.w > m_viewRect.pos.x &&
		r.pos.y < m_viewRect.pos.y + m_viewRect.size.h && r.pos.y + r.size.h > m_viewRect.pos.y) {
		SDL_SetRenderDrawColor(sdl_renderer, c.r, c.g, c.b, c.a);
		SDL_Rect sr;
		float wScale = (windowSize.w / m_viewRect.size.w);
		float hScale = (windowSize.h / m_viewRect.size.h);
		sr.h = static_cast<int>(r.size.h * hScale);
		sr.w = static_cast<int>(r.size.w * wScale);
		sr.x = static_cast<int>((r.pos.x - m_viewRect.pos.x) * wScale);
		sr.y = static_cast<int>((r.pos.y - m_viewRect.pos.y) * hScale);
		SDL_RenderDrawRect(sdl_renderer, &sr); //Portal uses SDL_RenderDrawRect /***
	}
}

//draw a rect in world coordinates
void Renderer::drawWorldFillRect(const Rect &r, const Colour &c) const {
	drawFillRect(worldToScreen(r), c);
}

// Draw a rectin world coordinates
void Renderer::drawWorldRect(const Rect &r, const Colour &c) const {
	drawRect(worldToScreen(r), c);
}

void Renderer::present() {
	// Swap buffers
	SDL_RenderPresent(sdl_renderer);
}

void Renderer::clear(const Colour& col) const {
	SDL_SetRenderDrawColor(sdl_renderer, col.r, col.g, col.b, col.a);
	SDL_RenderClear(sdl_renderer);
}

Vector2 Renderer::worldToScreen(const Vector2 &p) const {
	float x = p.x * windowSize.w / viewportSize.w;
	float y = p.y * windowSize.h / viewportSize.h;

	return Vector2(x, y);
}

Rect Renderer::worldToScreen(const Rect &r) const {
	Vector2 p = worldToScreen(r.pos);
	float sw = ceil(r.size.w * (windowSize.w / viewportSize.w));
	float sh = ceil(r.size.h * (windowSize.h / viewportSize.h));
	Rect result = Rect(p, Size(sw, sh));
	return result;
}

void Renderer::setViewPort(const Rect &r) {
	viewportBottomLeft = r.pos;
	viewportSize = r.size;
}

void Renderer::setViewRect(const Rect &rect) {
	m_viewRect = rect;
}

Size Renderer::getWindowSize() const {
	return windowSize;
}

// Destroys SDL_Window and SDL_Renderer
void Renderer::destroy() {
	SDL_DestroyRenderer(sdl_renderer);
	SDL_DestroyWindow(window);
}

Renderer::~Renderer() {
	// Deconstructor
}