#pragma once

#include "../Core/Utils.hpp"

namespace Renderer
{
	class IRenderer
	{
	public:
		IRenderer() = default;
		~IRenderer() = default;
	
		virtual void Init()		= 0;
		virtual void Release()	= 0;

		virtual void RenderInterpreterState(const Utils::InterpreterState& pInterpreterState) = 0;

		virtual bool RenderShouldStop() = 0;
	};
}