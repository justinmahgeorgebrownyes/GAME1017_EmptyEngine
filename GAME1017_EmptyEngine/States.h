#pragma once
#ifndef _STATES_H_
#define _STATES_H_
#include "SDL.h"
#include "GameObjects.h"
#include <vector>
using namespace std;


class State {

public:
	virtual ~State() = default;
	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void Render();
		virtual void Exit() = 0;
	virtual void Resume();
//	GameObject* GetGo(const std::string& s);
	auto GetIt(const std::string& s);
protected: // Private but inherited
	State() {} // What does this prevent?
	vector < std::pair <std::string, GameObject* >> m_objects;

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
	SDL_Rect m_button2;


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