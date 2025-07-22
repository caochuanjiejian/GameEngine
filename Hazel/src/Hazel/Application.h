#pragma once
#include "Core.h"
#include "Events/Event.h"
#include"Events/ApplicationEvent.h"
#include "Window.h"
namespace Hazel {

	/*
	创建对象的是时候，会创建一个Window类型的对象赋值给成员变量m_Window，
	然后把本对象的OnEvent函数传给m_Window的成员函数SetEventCallback，
	有一个成员函数OnEvent接受一个Event类型的对象，创建一个EventDispatcher类型的对象dispatcher
	
	*/
	class HAZEL_API Application
	{
	public:
		Application();
		virtual~Application();
		void Run();
		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};







	Application* CreateApplication();
}

