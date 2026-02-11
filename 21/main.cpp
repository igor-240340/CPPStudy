#include <print>

class Demo {
public:
	int get() {
		return 5;
	}
};

int get() {
	return 10;
}

namespace NS {
	int get() {
		return 20;
	}
}

int main() {
	Demo d;
	std::println("{}", d.get());
	std::println("{}", NS::get());
	std::println("{}", ::get());
	std::println("{}", get());
	return 0;
}
