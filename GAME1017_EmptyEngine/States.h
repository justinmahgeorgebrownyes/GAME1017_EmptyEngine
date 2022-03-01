#pragma once
#ifndef _STATES_H_
#define _STATES_H_
#include "SDL.h"
using namespace std;


class State {

protected:
	State() {};

public:
	virtual ~State() = default;
	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void Render();
		virtual void Exit() = 0;
	virtual void Resume();


//	vector<std::pair<std::string, GameObject*>> m_objects;



};

class TitleState : public State {
private:
	SDL_Rect m_button1;

public:
	TitleState();
	void Enter();
	void Update();
	void Render();
	void Exit();


};

class PauseState : public State {
private:

public:
	PauseState();
	void Enter();
	void Update();
	void Render();
	void Exit();


};

class GameState : public State {
private:

public:
	GameState();
	void Enter();
	void Update();
	void Render();
	void Exit();
	void Resume();

};

//end endstate here just like hte otherssd
class EndState : public State {
private:

public:
	EndState();
	void Enter();
	void Update();
	void Render();
	void Exit();


};

#endif