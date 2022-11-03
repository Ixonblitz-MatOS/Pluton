#include <Pluton.h>
class Sandbox : public Pluton::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};


Pluton::Application* Pluton::CreateApplication() {
	return new Sandbox();
}
