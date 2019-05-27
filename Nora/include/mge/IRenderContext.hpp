#pragma once

#include "export.hpp"
#include "SpriteBatch.hpp"

namespace Nora
{
	namespace Mge
	{
		class NORA_MGE_API_EXPORT IRenderContext
		{
		public:
			virtual const SpriteBatch& getBatch() const = 0;
		};
	}
}