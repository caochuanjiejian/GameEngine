#include <Hazel.h>
//����

/*
����ʵ��ʱ���ʼ����Ա����m_DebugNameΪ"Example"��
*/
class ExampleLayer :public Hazel::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{
	}
	void OnUpdate() override
	{
		HZ_INFO("cheche");
	}
	void OnEvent(Hazel::Event& event)override
	{
		HZ_TRACE("bobo");
	}


};

#ifdef HZ_PLATFORM_WINDOWS
extern Hazel::Application* Hazel::CreateApplication();
int main(int argc, char** argv) {
	
	Hazel::Log::Init();
	HZ_CORE_WARN("Initialized Log!");
	int a = 5;
	HZ_INFO("Hello! Var={0}", a);

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;

}

#endif

/*
�����������ʱ�򣬻ᴴ��һ��WindowsWindow����Ĭ�ϱ���ΪHazel Engine�����Ϊ1280����Ϊ720����m_Data.Title��m_Data.Width ��m_Data.Height��
����һ��glfwWindow���󴫸���Ա����m_Window
�����ڵĿ�߱仯ʱ���������ڱ仯�¼��������ڹر�ʱ�������ڹر��¼� /
�����̱�����ʱ���������¼�������궯��ʱ��������¼����������¼���������¼�,
Ȼ��ѱ������OnEvent��������m_Window�ĳ�Ա����SetEventCallback��
��һ����Ա����OnEvent����һ��WindowCloseEvent���͵Ķ��󣬰ѳ�Ա����m_Running��Ϊfalse���Ѵ��¼���m_Handled��Ϊtrue��
��һ����Ա����Run()��һֱ�����¼���ͬʱ�Ѵ��ڻ��ɷۺ�ɫ
*/
class Sandbox :public Hazel::Application {

public:
	Sandbox() {

		PushLayer(new ExampleLayer());//����
		PushOverlay(new Hazel::ImGuiLayer());
	}
	~Sandbox() {
	}

};


Hazel::Application* Hazel::CreateApplication() {
	return new Sandbox();

}