#pragma once
#include "Core.h"
#include "Events/Event.h"
#include"Events/ApplicationEvent.h"
#include "Window.h"
namespace Hazel {

	/*
	�����������ʱ�򣬻ᴴ��һ��Window���͵Ķ���ֵ����Ա����m_Window��
	Ȼ��ѱ������OnEvent��������m_Window�ĳ�Ա����SetEventCallback��
	��һ����Ա����OnEvent����һ��Event���͵Ķ��󣬴���һ��EventDispatcher���͵Ķ���dispatcher
	
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

