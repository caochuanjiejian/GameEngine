#pragma once
#include "Hazel/Window.h"
#include<GLFW/glfw3.h>


namespace Hazel {

	/*
	

	创建对象时接收WindowProps结构体（用来指定glfw窗口的宽、高和标题），同时创建一个glfw窗口，当此窗口发生事件时会执行EventCallback
	
	成员函数OnUpdate()：执行glfwPollEvents()和glfwSwapBuffers(m_Window);
	成员函数GetWidth()和GetHeight()：获取成员变量m_Data.Width，m_Data.Height
	成员函数SetEventCallback：接受一个函数对象赋值给EventCallback（接受一个事件类型的参数）
	成员函数SetVSync：接收真假值，如果为真开启垂直同步，同时把此时传入的真假值赋值给成员变量 m_Data.VSync
	有成员函数IsVSync()获取成员变量 m_Data.VSync															
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