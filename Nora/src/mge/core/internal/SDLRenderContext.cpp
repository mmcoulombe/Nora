#include "mge/core/internal/SDLRenderContext.hpp"

namespace Nora
{
	namespace Mge
	{
		SDLRenderContext::SDLRenderContext(const SDL_Renderer& renderer)
			: m_renderer(renderer)
		{

		}

		SDLRenderContext::~SDLRenderContext()
		{

		}
		
		const SpriteBatch& SDLRenderContext::getBatch() const
		{

		}
	}
}