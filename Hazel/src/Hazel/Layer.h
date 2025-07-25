#pragma once
#include"Hazel/Core.h"
#include"Hazel/Events/Event.h"

namespace Hazel {
	/*
	创建实例时会初始化成员变量m_DebugName为"Layer"或者传入字符串
	GetName()，用来获取m_DebugName
	*/
	class HAZEL_API Layer
	{
	public:
		Layer(const std::string& m_debugname = "Layer");
		virtual ~Layer();
		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};



}

