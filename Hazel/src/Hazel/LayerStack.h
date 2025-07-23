#pragma once
#include"Hazel/Core.h"
#include"Layer.h"
#include<vector>

namespace Hazel {

	/*
	
	1.创建实例时会把成员变量迭代器m_LayerInsert指向成员变量容器m_Layers的第一个元素
	2.当对象被摧毁时会释放成员变量m_Layers的内存
	3.PushLayer(Layer* layer)，把Layer*型的对象插入到成员变量m_Layers中，此时迭代器m_LayerInsert会指向此元素
	4.PushOverlay(Layer* overlay)，把Layer*型的对象插入到成员变量m_Layers的最后面
	5.PopLayer(Layer* layer)，在成员变量容器m_Layers中删除传入的Layer*型的对象
	6.PopOverlay(Layer* overlay)，在成员变量容器m_Layers中删除最后一个Layer*型的对象
	7.begin，end用来获取层的起始位置和最后的位置
	  
	
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