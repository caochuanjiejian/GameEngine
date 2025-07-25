#pragma once
#include "Core.h"
#include "Window.h"
#include"Hazel/LayerStack.h"
#include "Hazel/Events/Event.h"
#include"Hazel/Events/ApplicationEvent.h"

namespace Hazel {

	/*
	当这个窗口发生事件时会执行OnEvent函数
	OnEvent成员函数：接受一个WindowCloseEvent类型的对象时，把成员函数m_Running设为false，把此事件的m_Handled设为true
	成员函数Run()：一直接收事件，同时把窗口画成粉红色
	成员函数PushLayer：把Layer*型的对象插入到成员变量 m_LayerStack的m_Layers容器中，此时成员变量 m_LayerStack的m_LayerInsert迭代器会指向此元素
	PushOverlay(Layer* layer），在成员变量容器m_LayerStack的m_Layers中删除最后一个Layer*型的对象

	*/
	class HAZEL_API Application
	{
	public:
		Application();
		virtual~Application();
		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);//新增
		void PushOverlay(Layer* layer);//新增
		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;//新增

	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}

