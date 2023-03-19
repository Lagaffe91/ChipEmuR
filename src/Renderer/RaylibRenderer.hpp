#pragma once

#include "../Core/Utils.hpp"

#include "IRenderer.hpp"

namespace Renderer
{
	class RaylibRenderer : public IRenderer
	{
	public:
		RaylibRenderer();
		~RaylibRenderer();

	private:

		//
		//IRenderer
		//

	public:
		void Init() override;
		void Release() override;

		void RenderInterpreterState(const Utils::InterpreterState& pInterpreterState) override;

		bool RenderShouldStop() override;
	};
}