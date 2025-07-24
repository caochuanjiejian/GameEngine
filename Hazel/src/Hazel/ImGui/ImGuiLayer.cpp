#include "hzpch.h"
#include "ImGuiLayer.h"
#include"imgui.h"
#include"Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include"GLFW/glfw3.h"

namespace Hazel {
	ImGuiLayer::ImGuiLayer()
		:Layer("ImGuiLayer")
	{
	}
	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGui

	}
	void ImGuiLayer::OnDetach()
	{
	}

	void ImGuiLayer::OnUpdate()
	{
	}
	void ImGuiLayer::OnEvent(Event& event)
	{

	}
}