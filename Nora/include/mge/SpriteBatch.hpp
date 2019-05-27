#pragma once

#include <SDL_render.h>
#include "export.hpp"

struct IDrawable;

namespace Nora
{
	namespace Mge
	{
		class NORA_MGE_API_EXPORT SpriteBatch
		{
		public:
			SpriteBatch();
			virtual ~SpriteBatch();

			void drawSprite(IDrawable* drawable);
		private:
			const SDL_Renderer& m_renderer;
		};
	}
}