#include <Hazel.h>
//新增

/*
创建实例时会初始化成员变量m_DebugName为"Example"，
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
创建对象的是时候，会创建一个WindowsWindow对象，默认标题为Hazel Engine，宽度为1280，高为720传给m_Data.Title，m_Data.Width ，m_Data.Height，
创建一个glfwWindow对象传给成员变量m_Window
当窗口的宽高变化时，触发窗口变化事件，当窗口关闭时触发窗口关闭事件 /
当键盘被按下时触发键盘事件，当鼠标动作时触发鼠标事件，鼠标滚轮事件，鼠标光标事件,
然后把本对象的OnEvent函数传给m_Window的成员函数SetEventCallback，
有一个成员函数OnEvent接受一个WindowCloseEvent类型的对象，把成员函数m_Running设为false，把此事件的m_Handled设为true，
有一个成员函数Run()，一直接收事件，同时把窗口画成粉红色
*/
class Sandbox :public Hazel::Application {

public:
	Sandbox() {

		PushLayer(new ExampleLayer());//新增
		PushOverlay(new Hazel::ImGuiLayer());
	}
	~Sandbox() {
	}

};


Hazel::Application* Hazel::CreateApplication() {
	return new Sandbox();

}