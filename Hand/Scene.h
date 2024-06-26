#pragma once
#include <SDL.h>
#include <Event.h>
#include <queue>
using namespace std;

class Scene {
public:
	Scene();
	virtual ~Scene();

	virtual int Rendering() abstract;
	int RegisterRenderer(SDL_Renderer* ren);
	int PushEvent(EventType type, SDL_Keycode key);
	int PushEvent(EventType type, int x, int y, int x_rel, int y_rel, EventMouse mt);
	bool IsRun();

	int __Process__();

	void SceneQuitReady();

protected:
	bool run = false;
	bool process_completed = false;

	SDL_Renderer* ren;

	queue<Event> event_queue;
	
	virtual int EventProcess(Event &evt) abstract;
	virtual int NormalProcess() abstract;
};

