#include "mge/Application.hpp"

#include <SDL.h>

#include <iostream>

namespace Nora
{
	namespace Mge
	{
		Application::Application(unsigned int width, unsigned int height, const std::string& title, const RenderingSettings& settings)
			: m_window(nullptr)
			, m_renderer(nullptr)
			, m_fps(0)
			, m_limitFramerate(false)
		{
			if (SDL_Init(SDL_INIT_VIDEO))
			{

			}

			if (settings.antialiasing)
			{
				SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
			}

			m_limitFramerate = !settings.vsync;
			m_fps = settings.framerate;

			m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
			if (m_window == nullptr)
			{

			}

			m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		}

		void Application::update(double dt)
		{
			std::cout << "Delta time " << dt << std::endl;
		}

		void Application::draw()
		{

		}

		const uint64_t Application::getFPS() const
		{
			return m_fps;
		}

		void Application::run()
		{
			bool running = true;
			SDL_Event e;
			Uint32 frameDelay =  1 / m_fps * 1000;
			Uint64 currentTime = SDL_GetPerformanceCounter();
			Uint64 lastTime = 0;
			while (running)
			{
				Uint32 frameStart = SDL_GetTicks();
				lastTime = currentTime;
				currentTime = SDL_GetPerformanceCounter();

				double dt = static_cast<double>(1000 * (currentTime - lastTime)) / static_cast<double>(SDL_GetPerformanceFrequency());
				while (SDL_PollEvent(&e))
				{
					if (e.type == SDL_QUIT)
					{
						running = false;
					}
				}

				update(dt);

				SDL_RenderClear(m_renderer);

				draw();

				SDL_RenderPresent(m_renderer);

				// if the refresh rate is not automaticaly handle (thanks vsync) do it manualy.
				Uint32 frameTime = SDL_GetTicks() - frameStart;
				if (m_limitFramerate && frameDelay > frameTime)
				{
					SDL_Delay(frameDelay - frameTime);
				}
			}
		}

		Application::~Application()
		{
			if (SDL_WasInit(SDL_INIT_VIDEO) != 0)
			{
				SDL_DestroyRenderer(m_renderer);
				SDL_DestroyWindow(m_window);
				SDL_Quit();
			}
		}
	}
}