#pragma once
#include"Hazel/Core.h"
#include"Layer.h"
#include<vector>

namespace Hazel {

	/*
	
	1.
	2.
	3.��Ա����PushLayer(Layer* layer)����Layer*�͵Ķ�����뵽��Ա����m_Layers��
	4.��Ա����PushOverlay(Layer* layer)����Layer*�͵Ķ�����뵽��Ա����m_Layers�������
	5.��Ա����PopLayer(Layer* layer)���ڳ�Ա��������m_Layers��ɾ�������Layer*�͵Ķ���
	6.��Ա����PopOverlay(Layer* layer)���ڳ�Ա��������m_Layers��ɾ�����һ��Layer*�͵Ķ���
	7.��Ա����begin��end��������ȡ�����ʼλ�ú�����λ��
	  
	
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