#include "InputManager.h"
#include "InputManager.h"

void InputHandler::InputCheck(bool & gameRunning)
{
	while (SDL_PollEvent(m_e) != 0)
	{

		switch (m_e->type)
		{
		case SDL_QUIT:
			gameRunning = false;
			break;
		case SDL_KEYDOWN:
		{
			switch (m_e->key.keysym.sym)
			{
			case SDLK_RETURN:
				m_eventlisten->RETURN = true;
				break;
			case SDLK_ESCAPE:
				m_eventlisten->ESCAPE = true;
				break;
			case SDLK_SPACE:
				m_eventlisten->SPACE = true;
				break;
			case SDLK_a:
				m_eventlisten->A = true;
				break;
			case SDLK_d:
				m_eventlisten->D = true;
				break;
			case SDLK_s:
				m_eventlisten->S = true;
				break;
			case SDLK_w:
				m_eventlisten->W = true;
				break;
			case SDLK_UP:
				m_eventlisten->UP = true;
				break;
			case SDLK_DOWN:
				m_eventlisten->DOWN = true;
				break;
			case SDLK_LEFT:
				m_eventlisten->LEFT = true;
				break;
			case SDLK_RIGHT:
				m_eventlisten->RIGHT = true;
				break;
			case SDLK_LSHIFT:
				m_eventlisten->LEFTSHIFT = true;
				break;
			case SDLK_0:
				m_eventlisten->NUM_0 = true;
				break;
			case SDLK_1:
				m_eventlisten->NUM_1 = true;
				break;
			case SDLK_2:
				m_eventlisten->NUM_2 = true;
				break;
			case SDLK_3:
				m_eventlisten->NUM_3 = true;
				break;
			case SDLK_4:
				m_eventlisten->NUM_4 = true;
				break;
			case SDLK_5:
				m_eventlisten->NUM_5 = true;
				break;
			case SDLK_6:
				m_eventlisten->NUM_6 = true;
				break;
			case SDLK_7:
				m_eventlisten->NUM_7 = true;
				break;
			case SDLK_8:
				m_eventlisten->NUM_8 = true;
				break;
			case SDLK_9:
				m_eventlisten->NUM_9 = true;
				break;
			case SDLK_BACKSPACE:
				m_eventlisten->BACKSPACE = true;
				break;
			case SDLK_PERIOD:
				m_eventlisten->PERIOD = true;
				break;
			default:
				break;
			}
			break;
		}

		case SDL_KEYUP:
		{
			switch (m_e->key.keysym.sym)
			{
			case SDLK_RETURN:
				m_eventlisten->RETURN = false;
				break;
			case SDLK_ESCAPE:
				m_eventlisten->ESCAPE = false;
				break;
			case SDLK_SPACE:
				m_eventlisten->SPACE = false;
				break;
			case SDLK_a:
				m_eventlisten->A = false;
				break;
			case SDLK_d:
				m_eventlisten->D = false;
				break;
			case SDLK_s:
				m_eventlisten->S = false;
				break;
			case SDLK_w:
				m_eventlisten->W = false;
				break;
			case SDLK_UP:
				m_eventlisten->UP = false;
				break;
			case SDLK_DOWN:
				m_eventlisten->DOWN = false;
				break;
			case SDLK_LEFT:
				m_eventlisten->LEFT = false;
				break;
			case SDLK_RIGHT:
				m_eventlisten->RIGHT = false;
				break;
			case SDLK_LSHIFT:
				m_eventlisten->LEFTSHIFT = false;
				break;
			case SDLK_0:
				m_eventlisten->NUM_0 = false;
				break;
			case SDLK_1:
				m_eventlisten->NUM_1 = false;
				break;
			case SDLK_2:
				m_eventlisten->NUM_2 = false;
				break;
			case SDLK_3:
				m_eventlisten->NUM_3 = false;
				break;
			case SDLK_4:
				m_eventlisten->NUM_4 = false;
				break;
			case SDLK_5:
				m_eventlisten->NUM_5 = false;
				break;
			case SDLK_6:
				m_eventlisten->NUM_6 = false;
				break;
			case SDLK_7:
				m_eventlisten->NUM_7 = false;
				break;
			case SDLK_8:
				m_eventlisten->NUM_8 = false;
				break;
			case SDLK_9:
				m_eventlisten->NUM_9 = false;
				break;
			case SDLK_BACKSPACE:
				m_eventlisten->BACKSPACE = false;
				break;
			case SDLK_PERIOD:
				m_eventlisten->PERIOD = false;
				break;
			default:
				break;
			}
			break;
		}

		case SDL_MOUSEBUTTONDOWN:
		{
			switch (m_e->button.button)
			{
			case SDL_BUTTON_LEFT:
				m_eventlisten->LEFTMOUSE = true;
				break;
			case SDL_BUTTON_RIGHT:
				m_eventlisten->RIGHTMOUSE = true;
				break;
			case SDL_BUTTON_MIDDLE:
				m_eventlisten->WHEELCLICK = true;
				break;
			default:
				break;
			}
			break;
		}

		case SDL_MOUSEBUTTONUP:
		{
			switch (m_e->button.button)
			{
			case SDL_BUTTON_LEFT:
				m_eventlisten->LEFTMOUSE = false;
				break;
			case SDL_BUTTON_RIGHT:
				m_eventlisten->RIGHTMOUSE = false;
				break;
			case SDL_BUTTON_MIDDLE:
				m_eventlisten->WHEELCLICK = false;
				break;
			default:
				break;
			}
			break;


		case SDL_MOUSEMOTION:
		{
			SDL_GetMouseState(&m_eventlisten->mouseX, &m_eventlisten->mouseY);
			break;
		default:
			break;
		}
		}
		}
	}
}