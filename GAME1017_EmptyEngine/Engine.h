#pragma once
#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <iostream>
#include <map>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#define FPS 60
#define WIDTH 1024
#define HEIGHT 768
using namespace std;

class Engine
{
private: // private properties.
	Engine() {}
	bool m_running = false;
	Uint32 m_start, m_end, m_delta, m_fps;
	const Uint8* m_keystates;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_x, m_y;
	Uint32 m_buttons;

	Mix_Music *m_backmusic;

	SDL_Texture* m_pTexture;
	SDL_Texture* m_pTexture1;
	SDL_Texture* m_pTexture2;

private: // private method prototypes.
	int Init(const char* title, int xPos, int yPos, int width, int height, int flags);
	void Clean();
	void Wake();
	void HandleEvents();
	// Moved KeyDown from here.
	void Update();
	void Render();
	void Sleep();

public: // public method prototypes.
	
	int Run();
	// Add static method for singleton here
	static Engine& Instance();
	SDL_Renderer* GetRenderer() { return m_pRenderer; }
	bool KeyDown(SDL_Scancode c);
	bool MouseClick(SDL_Rect button);
	void BackgroundMusic();
	void BackgroundImage();
	void TitleButton(SDL_Rect* size);
	void ResumeButton(SDL_Rect* size);
};

#endif

// Reminder: you can ONLY have declarations in headers, not logical code
