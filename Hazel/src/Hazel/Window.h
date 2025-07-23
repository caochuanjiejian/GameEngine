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
		//����һ��WindowsWindow����Ĭ�ϱ���ΪHazel Engine�����Ϊ1280����Ϊ720����m_Data.Title��m_Data.Width ��m_Data.Height��
		//ִ��glfwInit()������һ��glfwWindow���󴫸���Ա����m_Window/
		//ִ��glfwMakeContextCurrent(m_Window)���ѳ�Ա����m_Data�����ݴ���glfwWindow����m_Window��������ֱͬ���������ڵĿ�߱仯ʱ���������ڱ仯�¼��������ڹر�ʱ�������ڹر��¼� /
			//�����̱�����ʱ���������¼�������궯��ʱ��������¼����������¼���������¼�,
		static Window* Create(const WindowProps& props = WindowProps());

	};


}