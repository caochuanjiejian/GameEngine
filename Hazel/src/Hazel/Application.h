#pragma once
#include "Core.h"
#include "Window.h"
#include"Hazel/LayerStack.h"
#include "Hazel/Events/Event.h"
#include"Hazel/Events/ApplicationEvent.h"

namespace Hazel {

	/*
	�����������ʱ�򣬻ᴴ��һ��WindowsWindow����Ĭ�ϱ���ΪHazel Engine�����Ϊ1280����Ϊ720����m_Data.Title��m_Data.Width ��m_Data.Height��
	ִ��glfwInit()������һ��glfwWindow���󴫸���Ա����m_Window
	ִ��glfwMakeContextCurrent(m_Window)���ѳ�Ա����m_Data�����ݴ���glfwWindow����m_Window��������ֱͬ���������ڵĿ�߱仯ʱ���������ڱ仯�¼��������ڹر�ʱ�������ڹر��¼� /
	�����̱�����ʱ���������¼�������궯��ʱ��������¼����������¼���������¼�,
	Ȼ��ѱ������OnEvent��������m_Window�ĳ�Ա����SetEventCallback��
	OnEvent����һ��WindowCloseEvent���͵Ķ��󣬰ѳ�Ա����m_Running��Ϊfalse���Ѵ��¼���m_Handled��Ϊtrue��
	��һ����Ա����Run()��һֱ�����¼���ͬʱ�Ѵ��ڻ��ɷۺ�ɫ

	PushLayer(Layer* layer)����Layer*�͵Ķ�����뵽��Ա���� m_LayerStack��m_Layers�����У���ʱ��Ա���� m_LayerStack��m_LayerInsert��������ָ���Ԫ��
	PushOverlay(Layer* layer�����ڳ�Ա��������m_LayerStack��m_Layers��ɾ�����һ��Layer*�͵Ķ���

	*/
	class HAZEL_API Application
	{
	public:
		Application();
		virtual~Application();
		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);//����
		void PushOverlay(Layer* layer);//����
		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;//����

	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}

