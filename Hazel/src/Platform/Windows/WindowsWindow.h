#pragma once
#include "Hazel/Window.h"
#include<GLFW/glfw3.h>


namespace Hazel {

	/*
	

	��������ʱ����WindowProps�ṹ�壨����ָ��glfw���ڵĿ��ߺͱ��⣩��ͬʱ����һ��glfw���ڣ����˴��ڷ����¼�ʱ��ִ��EventCallback
	
	��Ա����OnUpdate()��ִ��glfwPollEvents()��glfwSwapBuffers(m_Window);
	��Ա����GetWidth()��GetHeight()����ȡ��Ա����m_Data.Width��m_Data.Height
	��Ա����SetEventCallback������һ����������ֵ��EventCallback������һ���¼����͵Ĳ�����
	��Ա����SetVSync���������ֵ�����Ϊ�濪����ֱͬ����ͬʱ�Ѵ�ʱ��������ֵ��ֵ����Ա���� m_Data.VSync
	�г�Ա����IsVSync()��ȡ��Ա���� m_Data.VSync															
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