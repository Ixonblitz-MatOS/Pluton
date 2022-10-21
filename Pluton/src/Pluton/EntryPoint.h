#pragma once
#include "Log.h"

#ifdef PL_PLATFORM_WINDOWS
extern Pluton::Application* Pluton::CreateApplication();
int main(int argc, char** argv) {
	Pluton::Log::Init();
	PL_CORE_INFO("Initialized Core Logger!");
	PL_CORE_INFO("Initialized Client Logger");
	auto app = Pluton::CreateApplication();
	app->Run();
	delete app;
}
#endif
