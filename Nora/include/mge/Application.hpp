#ifndef NORA_MGE_APPLICATION_H
#define NORA_MGE_APPLICATION_H

#include "export.hpp"
#include <string>

#include "SpriteBatch.hpp"

struct SDL_Window;
struct SDL_Renderer;

namespace Nora
{
	namespace Mge
	{
		struct NORA_MGE_API_EXPORT RenderingSettings
		{
			explicit RenderingSettings(short _framerate = 60, bool _vsync = true, bool _antialiasing = false, bool _software = false)
				: framerate(_framerate)
				, vsync(_vsync)
				, antialiasing(_antialiasing)
				, software(_software)
			{
			}

			short framerate;
			bool vsync;
			bool antialiasing;
			bool software;
		};

		class NORA_MGE_API_EXPORT Application
		{
		public:
			Application(unsigned int width, unsigned int height, const std::string& title, const RenderingSettings& settings = RenderingSettings());
			virtual ~Application();

			void run();
			const uint64_t getFPS() const;
		private:
			void update(double dt);
			void draw(const SpriteBatch* batch);

		private:
			SDL_Window* m_window;
			SDL_Renderer* m_renderer;
			uint64_t m_fps;
			bool m_limitFramerate;
		};
	}
}

#endif // NORA_MGE_APPLICATION_H