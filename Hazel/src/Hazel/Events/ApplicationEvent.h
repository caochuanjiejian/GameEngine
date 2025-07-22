#pragma once
#include "hzpch.h"
#include "Event.h"

namespace Hazel {

	/*����ʱ���������޷�������������ʼ������m_Width��m_Height��Ա����
	 ����������Ա����GetWidth()��GetHeight()������ȡ���ĳ�Ա����m_Width��m_Height,
	 �г�Ա����ToString()������ȡ"WindowResizeEvent: "+m_Width+m_Height�ַ���,
	 �и���̬����GetStaticType()������ȡEventType::WindowResize(ö����)��
	 �и���Ա����GetEventType(),������ȡEventType::WindowResize(ö����)��
	 �и���Ա����GetName()������ȡ�ַ�����WindowResize",
	 �и���Ա����GetCategoryFlags(),������ȡEventCategoryApplication��ö�٣���
	 �и���Ա����IsInCategory(EventCategory category)������һ��ö�٣������EventCategoryApplication���򷵻�true��
	 ��һ����Ա����m_Handled��ֵΪfalse*/
	class HAZEL_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			:m_Width(width), m_Height(height) {
		}
		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << "," << m_Height;
			return ss.str();
		}
		static EventType GetStaticType() { return EventType::WindowResize; }
		EventType GetEventType() const override { return GetStaticType(); }
		const char* GetName() const override { return "WindowResize"; }
		int GetCategoryFlags() const override { return EventCategoryApplication; }
		//EVENT_CLASS_TYPE(WindowResize)
		//EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_Width, m_Height;
	};


	/*
	
	�и���̬����GetStaticType()������ȡEventType::WindowClose(ö����)��
	 �и���Ա����GetEventType(),������ȡEventType::WindowClose(ö����)��
	 �и���Ա����GetName()������ȡ�ַ�����WindowClose",
	 �и���Ա����GetCategoryFlags(),������ȡEventCategoryApplication��ö�٣���
	 �и���Ա����IsInCategory(EventCategory category)������һ��ö�٣������EventCategoryApplication���򷵻�true��
	 ��һ����Ա����m_Handled��ֵΪfalse
	 �г�Ա����ToString()������ȡ�ַ�����WindowClose"
	
	*/
	class HAZEL_API WindowCloseEvent :public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	/*

	�и���̬����GetStaticType()������ȡEventType::AppTick(ö����)��
	 �и���Ա����GetEventType(),������ȡEventType::AppTick(ö����)��
	 �и���Ա����GetName()������ȡ�ַ�����AppTick",
	 �и���Ա����GetCategoryFlags(),������ȡEventCategoryApplication��ö�٣���
	 �и���Ա����IsInCategory(EventCategory category)������һ��ö�٣������EventCategoryApplication���򷵻�true��
	 ��һ����Ա����m_Handled��ֵΪfalse
	 �г�Ա����ToString()������ȡ�ַ�����AppTick"

	*/
	class HAZEL_API AppTickEvent :public Event
	{
	public:
		AppTickEvent() {}
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};

	/*

	�и���̬����GetStaticType()������ȡEventType::AppUpdate(ö����)��
	 �и���Ա����GetEventType(),������ȡEventType::AppUpdate(ö����)��
	 �и���Ա����GetName()������ȡ�ַ�����AppUpdate",
	 �и���Ա����GetCategoryFlags(),������ȡEventCategoryApplication��ö�٣���
	 �и���Ա����IsInCategory(EventCategory category)������һ��ö�٣������EventCategoryApplication���򷵻�true��
	 ��һ����Ա����m_Handled��ֵΪfalse
	 �г�Ա����ToString()������ȡ�ַ�����AppUpdate"

	*/
	class HAZEL_API AppUpdateEvent :public Event
	{
	public:
		AppUpdateEvent() {}
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	/*

	�и���̬����GetStaticType()������ȡEventType::AppRender(ö����)��
	 �и���Ա����GetEventType(),������ȡEventType::AppRender(ö����)��
	 �и���Ա����GetName()������ȡ�ַ�����AppRender",
	 �и���Ա����GetCategoryFlags(),������ȡEventCategoryApplication��ö�٣���
	 �и���Ա����IsInCategory(EventCategory category)������һ��ö�٣������EventCategoryApplication���򷵻�true��
	 ��һ����Ա����m_Handled��ֵΪfalse
	 �г�Ա����ToString()������ȡ�ַ�����AppRender"

	*/
	class HAZEL_API AppRenderEvent :public Event
	{
	public:
		AppRenderEvent() {}
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};



}
