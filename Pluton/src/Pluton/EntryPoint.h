#pragma once


#ifdef PL_PLATFORM_WINDOWS
extern Pluton::Application* Pluton::CreateApplication();
int main(int argc, char** argv) {
	auto app = Pluton::CreateApplication();
	app->Run();
	delete app;
}
#else
	#error Pluton only supports Windows!
#endif
