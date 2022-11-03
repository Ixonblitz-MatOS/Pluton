#pragma once

#include "plpch.h"
#include "Pluton/Core.h"
#include "Pluton/Events/Event.h"
namespace Pluton {
	struct WindowsProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		WindowsProps(const std::string& title = "Pluton Engine", unsigned int width = 1280, unsigned height = 720) : Title(title), Width(width), Height(height)
		{

		}
	};
	class PLUTON_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		virtual ~Window() {}
		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;
		static Window* Create(const WindowsProps& props = WindowsProps());
	};
}