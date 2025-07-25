#pragma once
#include"Hazel/Core.h"
#include"Layer.h"
#include<vector>

namespace Hazel {

	/*
	
	1.
	2.
	3.成员函数PushLayer(Layer* layer)：把Layer*型的对象插入到成员变量m_Layers中
	4.成员函数PushOverlay(Layer* layer)：把Layer*型的对象插入到成员变量m_Layers的最后面
	5.成员函数PopLayer(Layer* layer)：在成员变量容器m_Layers中删除传入的Layer*型的对象
	6.成员函数PopOverlay(Layer* layer)：在成员变量容器m_Layers中删除最后一个Layer*型的对象
	7.成员函数begin，end：用来获取层的起始位置和最后的位置
	  
	
	*/
	class HAZEL_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	};

}