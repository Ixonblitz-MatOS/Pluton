
#include "plpch.h"
#include "Application.h"
#include "Pluton/Events/ApplicationEvent.h"
#include "Pluton/Log.h"
#include <GLFW/glfw3.h>
namespace Pluton {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}
	void Application::Run() {
		while (m_running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}