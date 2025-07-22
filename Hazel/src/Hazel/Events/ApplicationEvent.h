#pragma once
#include "hzpch.h"
#include "Event.h"

namespace Hazel {

	/*创建时传入两个无符号整型用来初始化它的m_Width和m_Height成员变量
	 ，有两个成员函数GetWidth()和GetHeight()用来获取它的成员变量m_Width和m_Height,
	 有成员函数ToString()用来获取"WindowResizeEvent: "+m_Width+m_Height字符串,
	 有个静态方法GetStaticType()用来获取EventType::WindowResize(枚举类)，
	 有个成员函数GetEventType(),用来获取EventType::WindowResize(枚举类)，
	 有个成员函数GetName()用来获取字符串“WindowResize",
	 有个成员函数GetCategoryFlags(),用来获取EventCategoryApplication（枚举），
	 有个成员函数IsInCategory(EventCategory category)，接受一个枚举，如果是EventCategoryApplication，则返回true，
	 有一个成员变量m_Handled，值为false*/
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
	
	有个静态方法GetStaticType()用来获取EventType::WindowClose(枚举类)，
	 有个成员函数GetEventType(),用来获取EventType::WindowClose(枚举类)，
	 有个成员函数GetName()用来获取字符串“WindowClose",
	 有个成员函数GetCategoryFlags(),用来获取EventCategoryApplication（枚举），
	 有个成员函数IsInCategory(EventCategory category)，接受一个枚举，如果是EventCategoryApplication，则返回true，
	 有一个成员变量m_Handled，值为false
	 有成员函数ToString()用来获取字符串“WindowClose"
	
	*/
	class HAZEL_API WindowCloseEvent :public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	/*

	有个静态方法GetStaticType()用来获取EventType::AppTick(枚举类)，
	 有个成员函数GetEventType(),用来获取EventType::AppTick(枚举类)，
	 有个成员函数GetName()用来获取字符串“AppTick",
	 有个成员函数GetCategoryFlags(),用来获取EventCategoryApplication（枚举），
	 有个成员函数IsInCategory(EventCategory category)，接受一个枚举，如果是EventCategoryApplication，则返回true，
	 有一个成员变量m_Handled，值为false
	 有成员函数ToString()用来获取字符串“AppTick"

	*/
	class HAZEL_API AppTickEvent :public Event
	{
	public:
		AppTickEvent() {}
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};

	/*

	有个静态方法GetStaticType()用来获取EventType::AppUpdate(枚举类)，
	 有个成员函数GetEventType(),用来获取EventType::AppUpdate(枚举类)，
	 有个成员函数GetName()用来获取字符串“AppUpdate",
	 有个成员函数GetCategoryFlags(),用来获取EventCategoryApplication（枚举），
	 有个成员函数IsInCategory(EventCategory category)，接受一个枚举，如果是EventCategoryApplication，则返回true，
	 有一个成员变量m_Handled，值为false
	 有成员函数ToString()用来获取字符串“AppUpdate"

	*/
	class HAZEL_API AppUpdateEvent :public Event
	{
	public:
		AppUpdateEvent() {}
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	/*

	有个静态方法GetStaticType()用来获取EventType::AppRender(枚举类)，
	 有个成员函数GetEventType(),用来获取EventType::AppRender(枚举类)，
	 有个成员函数GetName()用来获取字符串“AppRender",
	 有个成员函数GetCategoryFlags(),用来获取EventCategoryApplication（枚举），
	 有个成员函数IsInCategory(EventCategory category)，接受一个枚举，如果是EventCategoryApplication，则返回true，
	 有一个成员变量m_Handled，值为false
	 有成员函数ToString()用来获取字符串“AppRender"

	*/
	class HAZEL_API AppRenderEvent :public Event
	{
	public:
		AppRenderEvent() {}
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};



}
