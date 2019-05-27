#pragma once

#include <SDL_render.h>

#include "mge/export.hpp"
#include "mge/IRenderContext.hpp"

namespace Nora
{
	namespace Mge
	{
		class NORA_MGE_API_EXPORT SDLRenderContext : public IRenderContext
		{
		public:
			SDLRenderContext(const SDL_Renderer& renderer);
			virtual ~SDLRenderContext();
			const SpriteBatch& getBatch() const;
		private:
			const SDL_Renderer& m_renderer;
		};
	}
}