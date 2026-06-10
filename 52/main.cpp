#include <print>
#include <memory>

class Simple {
public:
	Simple() { std::println("Simple constructor called!"); }
	~Simple() { std::println("Simple destructor called!"); }
};

void use_resource(std::weak_ptr<Simple>& weak_simple) {
	std::shared_ptr<Simple> resource{ weak_simple.lock()};
	if (resource) {
		std::println("Resource still alive.");
	}
	else {
		std::println("Resource has been freed!");
	}
}

int main() {
	std::shared_ptr<Simple> shared_simple{ std::make_shared<Simple>() };
	std::weak_ptr<Simple> weak_simple{ shared_simple };

	use_resource(weak_simple);
	shared_simple.reset();
	use_resource(weak_simple);
}
