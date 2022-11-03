#pragma once

#include "plpch.h"
#include "Core.h"
#include "Window.h"
namespace Pluton {
	class PLUTON_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_running = true;
	};
	//tbd in client
	Application* CreateApplication();
}