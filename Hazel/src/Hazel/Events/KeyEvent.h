#pragma once
#include "hzpch.h"
#include "Event.h"

namespace Hazel {
	/*
	
	
	*/
	class HAZEL_API KeyEvent :public Event
	{
	public:
		inline int GetKeyCode()const { return m_KeyCode; }
		int GetCategoryFlags() const override { return EventCategoryKeyboard | EventCategoryInput; }
		
	protected:
		KeyEvent(int keycode)
			:m_KeyCode(keycode) {
		}
		int m_KeyCode;
	};
	/*
	创建时传入两个整形参数以初始化它的成员变量m_KeyCode和m_RepeatCount,
	有GetKeyCode()以获取成员变量m_KeyCode
	有成员函数GetRepeatCount(),用来获取成员变量m_RepeatCount，
	有成员函数ToString()用来获取字符串"KeyPressedEvent:+m_KeyCode+(+m_RepeatCount+repeats),
	有个静态方法GetStaticType()用来获取EventType::KeyPressed(枚举类)，
	 有个成员函数GetEventType(),用来获取EventType::KeyPressed(枚举类)，
	 有个成员函数GetName()用来获取字符串“KeyPressed",
	 有个成员函数GetCategoryFlags(),用来获取EventCategoryKeyboard | EventCategoryInput（枚举），
	 有个成员函数IsInCategory(EventCategory category)，接受一个枚举，如果是EventCategoryKeyboard 或者 EventCategoryInput，则返回true，
	 有一个成员变量m_Handled，值为false
	
	*/
	class HAZEL_API KeyPressedEvent :public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			:KeyEvent(keycode), m_RepeatCount(repeatCount) {
		}
		inline int GetRepeatCount()const { return m_RepeatCount; }
		std::string ToString()const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << "(" << m_RepeatCount << "repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};



	/*
	创建时传入一个整形参数以初始化它的成员变量m_KeyCode,
	有GetKeyCode()以获取成员变量m_KeyCode
	有成员函数ToString()用来获取字符串"KeyReleasedEvent:+m_KeyCode,
	有个静态方法GetStaticType()用来获取EventType::KeyReleased(枚举类)，
	 有个成员函数GetEventType(),用来获取EventType::KeyReleased(枚举类)，
	 有个成员函数GetName()用来获取字符串“KeyReleased",
	 有个成员函数GetCategoryFlags(),用来获取EventCategoryKeyboard | EventCategoryInput（枚举），
	 有个成员函数IsInCategory(EventCategory category)，接受一个枚举，如果是EventCategoryKeyboard 或者 EventCategoryInput，则返回true，
	 有一个成员变量m_Handled，值为false

	*/
	class HAZEL_API KeyReleasedEvent :public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			:KeyEvent(keycode) {
		}
		std::string ToString()const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyReleased)
	};
}