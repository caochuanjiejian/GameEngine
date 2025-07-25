#pragma once
#include "hzpch.h"
#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"

namespace Hazel {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		WindowProps(const std::string& title = "Hazel Engine", unsigned int width = 1280, unsigned int height = 720)
			:Title(title), Width(width), Height(height)
		{
		}
	};


	class HAZEL_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;//������������
		virtual ~Window() {}
		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidth()const = 0;
		virtual unsigned int GetHeight()const = 0;
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync()const = 0;


		/*
		��������ʱ����WindowProps�ṹ�壨����ָ��glfw���ڵĿ��ߺͱ��⣩��ͬʱ����һ��glfw���ڣ����˴��ڷ����¼�ʱ��ִ��EventCallback
		��Ա����OnUpdate()��ִ��glfwPollEvents()��glfwSwapBuffers(m_Window);
		��Ա����GetWidth()��GetHeight()����ȡ��Ա����m_Data.Width��m_Data.Height
		��Ա����SetEventCallback������һ����������ֵ��EventCallback������һ���¼����͵Ĳ�����
		��Ա����SetVSync���������ֵ�����Ϊ�濪����ֱͬ����ͬʱ�Ѵ�ʱ��������ֵ��ֵ����Ա���� m_Data.VSync
		�г�Ա����IsVSync()��ȡ��Ա���� m_Data.VSync
		*/
		static Window* Create(const WindowProps& props = WindowProps());

	};


}