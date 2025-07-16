#include <Hazel.h>
#include<iostream>
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
class Sandbox :public Hazel::Application {

public:
	Sandbox() {
	}
	~Sandbox() {
	}

};


Hazel::Application* Hazel::CreateApplication() {
	return new Sandbox();

}