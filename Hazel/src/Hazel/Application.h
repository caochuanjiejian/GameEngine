#pragma once
#include "Core.h"
#include "Window.h"
#include"Hazel/LayerStack.h"
#include "Hazel/Events/Event.h"
#include"Hazel/Events/ApplicationEvent.h"

namespace Hazel {

	/*
	��������ڷ����¼�ʱ��ִ��OnEvent����
	OnEvent��Ա����������һ��WindowCloseEvent���͵Ķ���ʱ���ѳ�Ա����m_Running��Ϊfalse���Ѵ��¼���m_Handled��Ϊtrue
	��Ա����Run()��һֱ�����¼���ͬʱ�Ѵ��ڻ��ɷۺ�ɫ
	��Ա����PushLayer����Layer*�͵Ķ�����뵽��Ա���� m_LayerStack��m_Layers�����У���ʱ��Ա���� m_LayerStack��m_LayerInsert��������ָ���Ԫ��
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

