#pragma once

#include "plpch.h"
#include "Core.h"

namespace Pluton {
	class PLUTON_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	//tbd in client
	Application* CreateApplication();
}