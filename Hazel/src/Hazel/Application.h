#pragma once
#include "Core.h"
#include "Window.h"
#include"Hazel/LayerStack.h"
#include "Hazel/Events/Event.h"
#include"Hazel/Events/ApplicationEvent.h"

namespace Hazel {

	/*
	创建对象的是时候，会创建一个WindowsWindow对象，默认标题为Hazel Engine，宽度为1280，高为720传给m_Data.Title，m_Data.Width ，m_Data.Height，
	执行glfwInit()，创建一个glfwWindow对象传给成员变量m_Window
	执行glfwMakeContextCurrent(m_Window)，把成员变量m_Data的数据传给glfwWindow对象m_Window，开启垂直同步，当窗口的宽高变化时，触发窗口变化事件，当窗口关闭时触发窗口关闭事件 /
	当键盘被按下时触发键盘事件，当鼠标动作时触发鼠标事件，鼠标滚轮事件，鼠标光标事件,
	然后把本对象的OnEvent函数传给m_Window的成员函数SetEventCallback，
	OnEvent接受一个WindowCloseEvent类型的对象，把成员函数m_Running设为false，把此事件的m_Handled设为true，
	有一个成员函数Run()，一直接收事件，同时把窗口画成粉红色

	PushLayer(Layer* layer)，把Layer*型的对象插入到成员变量 m_LayerStack的m_Layers容器中，此时成员变量 m_LayerStack的m_LayerInsert迭代器会指向此元素
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

