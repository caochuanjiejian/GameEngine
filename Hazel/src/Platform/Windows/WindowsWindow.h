#pragma once
#include "Hazel/Window.h"
#include<GLFW/glfw3.h>

namespace Hazel {

	/*
	
	��������ʱ����WindowProps�ṹ�壬����ִ��Init(props)��
	�������󱻴ݻ�ʱ����ִ��Shutdown()������
	�и���Ա����OnUpdate()����ִ��glfwPollEvents()��glfwSwapBuffers(m_Window);
	�г�Ա����GetWidth()��GetHeight()��������ȡ��Ա����m_Data.Width��m_Data.Height
	�г�Ա����SetEventCallback������һ���������󣬸�ֵ����Ա���� m_Data.EventCallback
	�г�Ա����SetVSync�������ֵ�����Ϊ�濪����ֱͬ����ͬʱ�Ѵ�ʱ��������ֵ��ֵ����Ա���� m_Data.VSync
	�г�Ա����IsVSync()��ȡ��Ա���� m_Data.VSync

	��˽�г�Ա���� Init����WindowProps�ṹ�壬�ѽṹ������ݷֱ𴫸�m_Data.Title��m_Data.Width ��m_Data.Height��ִ��glfwInit()������һ��glfwWindow���󴫸���Ա����m_Window/
	ִ��glfwMakeContextCurrent(m_Window)���ѳ�Ա����m_Data�����ݴ���glfwWindow����m_Window��������ֱͬ���������ڵĿ�߱仯ʱ���������ڱ仯�¼��������ڹر�ʱ�������ڹر��¼�/
	�����̱�����ʱ���������¼�������궯��ʱ��������¼����������¼���������¼�,
	�г�Ա����Shutdown()�����ڴݻٳ�Ա����m_Window��
	
																	
	*/																
	class WindowsWindow :public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();
		void OnUpdate()override;
		inline unsigned int GetWidth()const override { return m_Data.Width; }
		inline unsigned int GetHeight()const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback)override { m_Data.EventCallback = callback; }//����һ����������ֵ�������EventCallback����
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