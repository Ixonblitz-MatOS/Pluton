#include "plpch.h"
#include "WindowsWindow.h"

namespace Pluton {
	static bool s_GLFWInitialized = false;
	Window* Window::Create(const WindowsProps& props){return new WindowsWindow(props);}
	WindowsWindow::WindowsWindow(const WindowsProps& props) { Init(props); }
	WindowsWindow::~WindowsWindow() { Shutdown(); }
	void WindowsWindow::Init(const WindowsProps& props) {
		m_data.Title = props.Title;
		m_data.Width = props.Width;
		m_data.Height = props.Height;
		PL_CORE_INFO("Creating window {0} ({1},{2})",props.Title,props.Width,props.Height);
		if (!s_GLFWInitialized) {
			int success = glfwInit();
			PL_CORE_ASSERT("GLFW NOT INITIALIZED");
			s_GLFWInitialized = true;
		}
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window,&m_data);
		SetVSync(true);

	}
	void WindowsWindow::Shutdown() { glfwDestroyWindow(m_Window); }
	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}
	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
		m_data.VSync = enabled;
	}
	bool WindowsWindow::IsVSync() const { return m_data.VSync; }
}