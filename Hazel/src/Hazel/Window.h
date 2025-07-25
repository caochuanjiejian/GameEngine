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


		/*
		创建对象时接收WindowProps结构体（用来指定glfw窗口的宽、高和标题），同时创建一个glfw窗口，当此窗口发生事件时会执行EventCallback
		成员函数OnUpdate()：执行glfwPollEvents()和glfwSwapBuffers(m_Window);
		成员函数GetWidth()和GetHeight()：获取成员变量m_Data.Width，m_Data.Height
		成员函数SetEventCallback：接受一个函数对象赋值给EventCallback（接受一个事件类型的参数）
		成员函数SetVSync：接收真假值，如果为真开启垂直同步，同时把此时传入的真假值赋值给成员变量 m_Data.VSync
		有成员函数IsVSync()获取成员变量 m_Data.VSync
		*/
		static Window* Create(const WindowProps& props = WindowProps());

	};


}