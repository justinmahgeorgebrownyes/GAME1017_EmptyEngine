#include "States.h"
#include "StateManager.h"
#include "Engine.h"
#include <iostream>
using namespace std;

void State::Render()
{
	SDL_RenderPresent(Engine::Instance().GetRenderer());


}

void State::Resume()
{
}

TitleState::TitleState()
{
	m_button1 = { 255, 128, 512, 512 };


}

void TitleState::Enter()
{
	cout << "Enter titleState..." << endl;
}

void TitleState::Update()
{
	if (Engine::Instance().KeyDown(SDL_SCANCODE_N)) {
		cout << "changing to gamstate" << endl;
		STMA::ChangeState( new GameState() );
	} 
	
	if (Engine::Instance().MouseClick(m_button1)) {
		cout << "changing to gamstate" << endl;
		STMA::ChangeState(new GameState());
	}

}

void TitleState::Render()
{
	SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(), 0, 0, 255, 255);
	SDL_RenderClear(Engine::Instance().GetRenderer());


	SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(), 255, 0, 0, 128);



	SDL_RenderFillRect(Engine::Instance().GetRenderer(), &m_button1);


	State::Render();
}

void TitleState::Exit()
{
	cout << "exiting titleState..." << endl;

}

PauseState::PauseState()
{

}

void PauseState::Enter()
{

}

void PauseState::Update()
{
}

void PauseState::Render()
{
	STMA::GetStates().front()->Render();

	SDL_SetRenderDrawBlendMode(Engine::Instance().GetRenderer(), SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(), 255, 0, 0, 128);
	SDL_Rect rect = { 255, 128, 512, 512 };
	SDL_RenderFillRect(Engine::Instance().GetRenderer(), &rect);
	State::Render();

}

void PauseState::Exit()
{
}

GameState::GameState()
{
}

void GameState::Enter()
{
	cout << "entering gamestate..." << endl;
	//load music sfx, add them to map, and play it
	// load music track, add it to map, and play it

}

void GameState::Update()
{
	if (Engine::Instance().KeyDown(SDL_SCANCODE_N)) {
		cout << "changing to pausestate" << endl;
		//pause the music track
		STMA::PushState(new PauseState());
	}
	// parse 1 key and play first sfx
	//parse 2 key and play second sfx
}

void GameState::Render()
{
	SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(), 0, 255, 0, 255);
	SDL_RenderClear(Engine::Instance().GetRenderer());
	State::Render();
}

void GameState::Exit()
{
	cout << "exiting gameState..." << endl;

}

void GameState::Resume()
{
}

EndState::EndState()
{
}

void EndState::Enter()
{
}

void EndState::Update()
{
}

void EndState::Render()
{
}

void EndState::Exit()
{
}
