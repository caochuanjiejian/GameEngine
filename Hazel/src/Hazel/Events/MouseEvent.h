#pragma once
#include "hzpch.h"
#include"Event.h"

namespace Hazel {


	/*
	���������ʱ����Ҫ��������float�͵Ĳ����Գ�ʼ����Ա����m_MouseX, m_MouseY��
	�г�Ա����GetX��GetY������ȡ��Ա����m_MouseX, m_MouseY��
	�г�Ա����ToString()������ȡ�ַ���"MouseMovedEvent: +m_MouseX+m_MouseY" 
	�и���̬����GetStaticType()������ȡEventType::MouseMoved(ö����)��
	 �и���Ա����GetEventType(),������ȡEventType::MouseMoved(ö����)��
	 �и���Ա����GetName()������ȡ�ַ�����MouseMoved",
	 �и���Ա����GetCategoryFlags(),������ȡEventCategoryMouse|EventCategoryInput��ö�٣���		  
	�и���Ա����IsInCategory(EventCategory category)������һ��ö�٣������EventCategoryMouse��EventCategoryInput���򷵻�true��
	 ��һ����Ա����m_Handled��ֵΪfalse
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
	���������ʱ����Ҫ��������float�͵Ĳ����Գ�ʼ����Ա����m_XOffset, m_YOffset��
	�г�Ա����GetXOffset��GetYOffset������ȡ��Ա����m_XOffset, m_YOffset��
	�г�Ա����ToString()������ȡ�ַ���"MouseScrolledEvent: +m_XOffset+m_YOffset"
	�и���̬����GetStaticType()������ȡEventType::MouseScrolled(ö����)��
	 �и���Ա����GetEventType(),������ȡEventType::MouseScrolled(ö����)��
	 �и���Ա����GetName()������ȡ�ַ�����MouseScrolled",
	 �и���Ա����GetCategoryFlags(),������ȡEventCategoryMouse|EventCategoryInput��ö�٣���
	�и���Ա����IsInCategory(EventCategory category)������һ��ö�٣������EventCategoryMouse��EventCategoryInput���򷵻�true��
	 ��һ����Ա����m_Handled��ֵΪfalse
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
	���������ʱ����Ҫ����һ��int�͵Ĳ����Գ�ʼ����Ա����m_Button��
	�г�Ա����ToString()������ȡ�ַ���"MouseButtonPressedEvent: +m_Button"
	�г�Ա����GetMouseButton()������ȡ��Ա����m_Button
	�и���̬����GetStaticType()������ȡEventType::MouseButtonPressed(ö����)��
	 �и���Ա����GetEventType(),������ȡEventType::MouseButtonPressed(ö����)��
	 �и���Ա����GetName()������ȡ�ַ�����MouseButtonPressed",
	 �и���Ա����GetCategoryFlags(),������ȡEventCategoryMouse|EventCategoryInput��ö�٣���
	�и���Ա����IsInCategory(EventCategory category)������һ��ö�٣������EventCategoryMouse��EventCategoryInput���򷵻�true��
	 ��һ����Ա����m_Handled��ֵΪfalse
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
	���������ʱ����Ҫ����һ��int�͵Ĳ����Գ�ʼ����Ա����m_Button��
	�г�Ա����ToString()������ȡ�ַ���"MouseButtonReleasedEvent: +m_Button"
	�г�Ա����GetMouseButton()������ȡ��Ա����m_Button
	�и���̬����GetStaticType()������ȡEventType::MouseButtonReleased(ö����)��
	 �и���Ա����GetEventType(),������ȡEventType::MouseButtonReleased(ö����)��
	 �и���Ա����GetName()������ȡ�ַ�����MouseButtonReleased",
	 �и���Ա����GetCategoryFlags(),������ȡEventCategoryMouse|EventCategoryInput��ö�٣���
	�и���Ա����IsInCategory(EventCategory category)������һ��ö�٣������EventCategoryMouse��EventCategoryInput���򷵻�true��
	 ��һ����Ա����m_Handled��ֵΪfalse
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