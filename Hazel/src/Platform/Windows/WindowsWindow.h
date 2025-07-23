#pragma once
#include "Hazel/Window.h"
#include<GLFW/glfw3.h>

namespace Hazel {

	/*
	
	创建对象时接收WindowProps结构体，用来执行Init(props)，
	当本对象被摧毁时，会执行Shutdown()函数，
	有个成员函数OnUpdate()用来执行glfwPollEvents()和glfwSwapBuffers(m_Window);
	有成员函数GetWidth()和GetHeight()，用来获取成员变量m_Data.Width，m_Data.Height
	有成员函数SetEventCallback，接受一个函数对象，赋值给成员变量 m_Data.EventCallback
	有成员函数SetVSync接收真假值，如果为真开启垂直同步，同时把此时传入的真假值赋值给成员变量 m_Data.VSync
	有成员函数IsVSync()获取成员变量 m_Data.VSync

	有私有成员函数 Init接收WindowProps结构体，把结构体的数据分别传给m_Data.Title，m_Data.Width ，m_Data.Height，执行glfwInit()，创建一个glfwWindow对象传给成员变量m_Window/
	执行glfwMakeContextCurrent(m_Window)，把成员变量m_Data的数据传给glfwWindow对象m_Window，开启垂直同步，当窗口的宽高变化时，触发窗口变化事件，当窗口关闭时触发窗口关闭事件/
	当键盘被按下时触发键盘事件，当鼠标动作时触发鼠标事件，鼠标滚轮事件，鼠标光标事件,
	有成员函数Shutdown()，用于摧毁成员变量m_Window，
	
																	
	*/																
	class WindowsWindow :public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();
		void OnUpdate()override;
		inline unsigned int GetWidth()const override { return m_Data.Width; }
		inline unsigned int GetHeight()const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback)override { m_Data.EventCallback = callback; }//接受一个函数名赋值给本类的EventCallback变量
		void SetVSync(bool enabled)override;
		bool IsVSync()const override;
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			EventCallbackFn EventCallback;
		};
		WindowData m_Data;
	};
	


}