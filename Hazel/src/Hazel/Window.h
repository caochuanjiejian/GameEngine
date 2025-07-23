#pragma once
#include "hzpch.h"
#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"

namespace Hazel {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		WindowProps(const std::string& title = "Hazel Engine", unsigned int width = 1280, unsigned int height = 720)
			:Title(title), Width(width), Height(height)
		{
		}
	};


	class HAZEL_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;//给函数起名字
		virtual ~Window() {}
		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidth()const = 0;
		virtual unsigned int GetHeight()const = 0;
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync()const = 0;
		//创建一个WindowsWindow对象，默认标题为Hazel Engine，宽度为1280，高为720传给m_Data.Title，m_Data.Width ，m_Data.Height，
		//执行glfwInit()，创建一个glfwWindow对象传给成员变量m_Window/
		//执行glfwMakeContextCurrent(m_Window)，把成员变量m_Data的数据传给glfwWindow对象m_Window，开启垂直同步，当窗口的宽高变化时，触发窗口变化事件，当窗口关闭时触发窗口关闭事件 /
			//当键盘被按下时触发键盘事件，当鼠标动作时触发鼠标事件，鼠标滚轮事件，鼠标光标事件,
		static Window* Create(const WindowProps& props = WindowProps());

	};


}