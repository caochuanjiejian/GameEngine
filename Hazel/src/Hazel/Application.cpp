#include "hzpch.h"
#include "Application.h"

#include"Events/ApplicationEvent.h"
#include"Log.h"
#include <GLFW/glfw3.h>

namespace Hazel {
	//为Appliction类的构造函数， 创造一个WindowsWindow类型的对象,把地址值以多态（父类）的方式返回给m_Window
	Application::Application() {
		m_Window =std::unique_ptr<Window>( Window::Create());
	}

	Application::~Application() {
	}
	void Application::Run()	
	{
		
		
		
		
		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();//调用glfwPollEvents()和glfwSwapBuffers(m_Window);
			
		}
	}
}