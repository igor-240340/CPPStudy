#include <print>

int main() {
	int uninitialized;
	int initialized{ 5 };
	std::println("uninitialized: {}", uninitialized);
	std::println("initialized: {}", initialized);

	return 0;
}
