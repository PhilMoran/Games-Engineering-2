#include <SDL.h>
#include <SDL_image.h>
#include <SDL_thread.h>
#include <SDL_timer.h>
#include <iostream>
#include "Game.h"
#include "Solver.h"
#include "AI.h"
#include <thread>
#include <string>
using namespace std;

static SDL_mutex* mutex = SDL_CreateMutex();

class Physics
{
public:
	unsigned int update(void* data)
	{
		DEBUG_MSG("Physics Updating");
		return 0;
		
	}
};

class ArtificialIntelligence
{
public:
	unsigned int update(void* data)
	{
		DEBUG_MSG("Artificial Intelligence Updating");
		return 0;
	}
};

class RenderObjects
{
public:
	RenderObjects(){}
	RenderObjects(const Game& game) : m_Game(game)
	{
		m_Game.LoadContent();
	}
	~RenderObjects(){};
	void run()
	{
		DEBUG_MSG("Thread Running");
		while(m_Game.IsRunning())
		{
			
			m_Game.Render();
			m_Game.Update();
			DEBUG_MSG("EventHandle");
			m_Game.HandleEvents();
		}
	}
private:
	Game m_Game;
};

class ProcessPhysics
{
public:
	static int run(void* data)
	{
		Physics physics;
		unsigned int result = 0;
		DEBUG_MSG("Process Physics Running");

		Uint32 update, elapsed = 0;
		update = 2000;

		while(true)
		{
			elapsed = SDL_GetTicks();

			if(elapsed >= update)
			{
				if(SDL_mutexP(mutex) == -1)
				{
					DEBUG_MSG("Process Physics Spinning");
				}
				DEBUG_MSG("Process Physics Locked Mutex");
				result = physics.update(data);

				if(SDL_mutexV(mutex)==-1)
				{
					DEBUG_MSG("Unlock failed Spinning");
				}
				DEBUG_MSG("Process Physics Unlocked Mutex");
				elapsed = 0;
			}
		}
		return result;
	}
};

class ProcessArtificialIntelligence
{
public:
	static int run(void* data)
	{
		//AI* ai = new AI();
		ArtificialIntelligence ai;
		unsigned int result = 0;
		DEBUG_MSG("Process Artificial Intelligence Running");

		Uint32 update, elapsed = 0;
		update = 1000;

		while(true)
		{
			elapsed = SDL_GetTicks();

			if(elapsed >= update)
			{
				if(SDL_mutexP(mutex) == -1)
				{
					DEBUG_MSG("Process Artificial Intelligence Spinning");
				}
				DEBUG_MSG("Process Artificial Intelligence Locked Mutex");
				result = ai.update(data);

				if(SDL_mutexV(mutex)==-1)
				{
					DEBUG_MSG("Unlock failed Spinning");
				}
				DEBUG_MSG("Process Artificial Intelligence Unlocked Mutex");
				elapsed = 0;
			}
		}
		return result;
	}
};

int main(int argc, char** argv){

	DEBUG_MSG("Game Object Created");
	  
	Game* game = new Game();
	AI * ai = new AI();
	Solver solve(Vector2(0, 0), Vector2(19, 19), 20);
	//Adjust screen positions as needed
	game->Initialize("DGPP Skelatol",300,100,1920,1080, SDL_WINDOW_INPUT_FOCUS);
    //DEBUG_MSG("Game Initialised");
	//game->LoadContent();
	
	SDL_LockMutex(mutex); 
	thread RenderGame(&RenderObjects::run, RenderObjects((*(game)))); //Passing references
	RenderGame.detach(); //detaches from SDL mainline
	SDL_UnlockMutex(mutex);

	

	//DEBUG_MSG("Game Loop Starting......");*/
	while (game->IsRunning())
	{
		/*game->Render();
		game->Update();
		game->HandleEvents();*/
		//solve.aStar();
	}

	//DEBUG_MSG("Calling Cleanup");
	game->CleanUp();
	game->UnloadContent();

	SDL_DestroyMutex(mutex);
	
	return 0;
}

