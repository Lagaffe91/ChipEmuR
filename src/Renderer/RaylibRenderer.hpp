#pragma once

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

		void RenderInterpreterState() override;

		bool RenderShouldStop() override;
	};
}