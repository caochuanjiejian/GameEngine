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
	����ʱ�����������β����Գ�ʼ�����ĳ�Ա����m_KeyCode��m_RepeatCount,
	��GetKeyCode()�Ի�ȡ��Ա����m_KeyCode
	�г�Ա����GetRepeatCount(),������ȡ��Ա����m_RepeatCount��
	�г�Ա����ToString()������ȡ�ַ���"KeyPressedEvent:+m_KeyCode+(+m_RepeatCount+repeats),
	�и���̬����GetStaticType()������ȡEventType::KeyPressed(ö����)��
	 �и���Ա����GetEventType(),������ȡEventType::KeyPressed(ö����)��
	 �и���Ա����GetName()������ȡ�ַ�����KeyPressed",
	 �и���Ա����GetCategoryFlags(),������ȡEventCategoryKeyboard | EventCategoryInput��ö�٣���
	 �и���Ա����IsInCategory(EventCategory category)������һ��ö�٣������EventCategoryKeyboard ���� EventCategoryInput���򷵻�true��
	 ��һ����Ա����m_Handled��ֵΪfalse
	
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
	����ʱ����һ�����β����Գ�ʼ�����ĳ�Ա����m_KeyCode,
	��GetKeyCode()�Ի�ȡ��Ա����m_KeyCode
	�г�Ա����ToString()������ȡ�ַ���"KeyReleasedEvent:+m_KeyCode,
	�и���̬����GetStaticType()������ȡEventType::KeyReleased(ö����)��
	 �и���Ա����GetEventType(),������ȡEventType::KeyReleased(ö����)��
	 �и���Ա����GetName()������ȡ�ַ�����KeyReleased",
	 �и���Ա����GetCategoryFlags(),������ȡEventCategoryKeyboard | EventCategoryInput��ö�٣���
	 �и���Ա����IsInCategory(EventCategory category)������һ��ö�٣������EventCategoryKeyboard ���� EventCategoryInput���򷵻�true��
	 ��һ����Ա����m_Handled��ֵΪfalse

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