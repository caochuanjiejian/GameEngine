#pragma once
#include "hzpch.h"
#include"Event.h"

namespace Hazel {


	/*
	创建对象的时候需要传入两个float型的参数以初始化成员变量m_MouseX, m_MouseY，
	有成员函数GetX，GetY用来获取成员变量m_MouseX, m_MouseY，
	有成员函数ToString()用来获取字符串"MouseMovedEvent: +m_MouseX+m_MouseY" 
	有个静态方法GetStaticType()用来获取EventType::MouseMoved(枚举类)，
	 有个成员函数GetEventType(),用来获取EventType::MouseMoved(枚举类)，
	 有个成员函数GetName()用来获取字符串“MouseMoved",
	 有个成员函数GetCategoryFlags(),用来获取EventCategoryMouse|EventCategoryInput（枚举），		  
	有个成员函数IsInCategory(EventCategory category)，接受一个枚举，如果是EventCategoryMouse或EventCategoryInput，则返回true，
	 有一个成员变量m_Handled，值为false
	*/
	class HAZEL_API MouseMovedEvent :public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			:m_MouseX(x), m_MouseY(y) {
		}
		inline float GetX()const { return m_MouseX; }
		inline float GetY()const { return m_MouseY; }
		std::string ToString()const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << "," << m_MouseY;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse|EventCategoryInput)
	private:
		float m_MouseX, m_MouseY;
	};



	/*
	创建对象的时候需要传入两个float型的参数以初始化成员变量m_XOffset, m_YOffset，
	有成员函数GetXOffset，GetYOffset用来获取成员变量m_XOffset, m_YOffset，
	有成员函数ToString()用来获取字符串"MouseScrolledEvent: +m_XOffset+m_YOffset"
	有个静态方法GetStaticType()用来获取EventType::MouseScrolled(枚举类)，
	 有个成员函数GetEventType(),用来获取EventType::MouseScrolled(枚举类)，
	 有个成员函数GetName()用来获取字符串“MouseScrolled",
	 有个成员函数GetCategoryFlags(),用来获取EventCategoryMouse|EventCategoryInput（枚举），
	有个成员函数IsInCategory(EventCategory category)，接受一个枚举，如果是EventCategoryMouse或EventCategoryInput，则返回true，
	 有一个成员变量m_Handled，值为false
	*/

	class HAZEL_API MouseScrolledEvent :public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			:m_XOffset(xOffset), m_YOffset(yOffset) {
		}
		inline float GetXOffset()const { return m_XOffset; }
		inline float GetYOffset()const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << "," << GetYOffset();
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse|EventCategoryInput)
	private:
		float m_XOffset, m_YOffset;
	};






	
	class HAZEL_API MouseButtonEvent :public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse|EventCategoryInput)
	protected:
		MouseButtonEvent(int button)
			:m_Button(button) {
		}
		int m_Button;
	};




	/*
	创建对象的时候需要传入一个int型的参数以初始化成员变量m_Button，
	有成员函数ToString()用来获取字符串"MouseButtonPressedEvent: +m_Button"
	有成员函数GetMouseButton()用来获取成员变量m_Button
	有个静态方法GetStaticType()用来获取EventType::MouseButtonPressed(枚举类)，
	 有个成员函数GetEventType(),用来获取EventType::MouseButtonPressed(枚举类)，
	 有个成员函数GetName()用来获取字符串“MouseButtonPressed",
	 有个成员函数GetCategoryFlags(),用来获取EventCategoryMouse|EventCategoryInput（枚举），
	有个成员函数IsInCategory(EventCategory category)，接受一个枚举，如果是EventCategoryMouse或EventCategoryInput，则返回true，
	 有一个成员变量m_Handled，值为false
	*/
	class HAZEL_API MouseButtonPressedEvent :public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			:MouseButtonEvent(button) {
		}
		std::string ToString()const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};





	/*
	创建对象的时候需要传入一个int型的参数以初始化成员变量m_Button，
	有成员函数ToString()用来获取字符串"MouseButtonReleasedEvent: +m_Button"
	有成员函数GetMouseButton()用来获取成员变量m_Button
	有个静态方法GetStaticType()用来获取EventType::MouseButtonReleased(枚举类)，
	 有个成员函数GetEventType(),用来获取EventType::MouseButtonReleased(枚举类)，
	 有个成员函数GetName()用来获取字符串“MouseButtonReleased",
	 有个成员函数GetCategoryFlags(),用来获取EventCategoryMouse|EventCategoryInput（枚举），
	有个成员函数IsInCategory(EventCategory category)，接受一个枚举，如果是EventCategoryMouse或EventCategoryInput，则返回true，
	 有一个成员变量m_Handled，值为false
	*/
	class HAZEL_API MouseButtonReleasedEvent :public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			:MouseButtonEvent(button) {
		}
		std::string ToString()const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}