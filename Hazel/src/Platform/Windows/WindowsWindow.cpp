#include "hzpch.h"
#include "WindowsWindow.h"

namespace Hazel {
	static bool s_GLFWInitialized = false;

	//接收一个WindowProps类型的的参数（有默认参数，为WindowProps构造），
	// 创造一个WindowsWindow类型的对象，把此对象的地址值返回给此函数(变成父类，多态)
	Window* Window::Create(const WindowProps& props ) {
	
		return new WindowsWindow(props);
	
	}


	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}
	WindowsWindow::~WindowsWindow() { Shutdown(); }



	//接收一个WindowProps类型的参数，把这个参数的成员变量赋值给m_Data,把成员变量的值打印到控制台，初始化glfwInit,根据传入的WindowProps类型的参数创建glfw窗口
	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		HZ_CORE_INFO("Creating window{0}({1},{2})", props.Title, props.Width, props.Height);
		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			HZ_CORE_ASSERT(success, "Could not intialize GLFW");
			s_GLFWInitialized = true;
		}
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}
	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(m_Window);
	
	}
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
		m_Data.VSync = enabled;
	}
	bool WindowsWindow::IsVSync()const
	{
		return m_Data.VSync;
	}


}