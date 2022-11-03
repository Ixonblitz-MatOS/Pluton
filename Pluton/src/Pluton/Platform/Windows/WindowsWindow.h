#pragma once
#include "Pluton/Window.h"
#include "GLFW/glfw3.h"
namespace Pluton {
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowsProps& props);
		virtual ~WindowsWindow();
		void OnUpdate() override;
		inline unsigned int GetWidth() const override { return m_data.Width; }
		inline unsigned int GetHeight() const override { return m_data.Height; }
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowsProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;
		struct WindowData {
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			EventCallbackFn EventCallback;
		};
		WindowData m_data;
	};
	

}