#pragma once
#include "hzpch.h"
#include "Core.h"



namespace Hazel{
	enum class EventType
	{
		None = 0,
		WindowClose,WindowResize,WindowFocus,WindowLostFocus,WindowMoved,
		AppTick,AppUpdate,AppRender,
		KeyPressed,KeyReleased,
		MouseButtonPressed,MouseButtonReleased,MouseMoved,MouseScrolled

	};
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

#define EVENT_CLASS_TYPE(type)	static EventType GetStaticType() {return EventType::type;}\
								 EventType GetEventType() const override {return GetStaticType();}\
								 const char* GetName() const override {return #type;}

#define EVENT_CLASS_CATEGORY(category)  int GetCategoryFlags() const override {return category;}

	//ToString()
	class HAZEL_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	
		bool m_Handled = false;
	};


	//事件分发器，创建对象时需要传入事件，用来初始化成员变量m_Event，
	// 有一个Dispatch成员函数，接受一个接收任意事件类型参数返回布尔值的函数对象，如果此时事件类型和创建对象传入的事件的类型相同，
	//则对传入的事件执行fun函数，并返回TRUE，否则返回false
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			:m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{

			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;

			}
			return false;
		}
	private:
		Event& m_Event;
	};
	

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}