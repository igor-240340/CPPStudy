#include <print>

int main() {
	std::println("int:");
	std::println("Max int value: {}", std::numeric_limits<int>::max());
	std::println("Min int value: {}", std::numeric_limits<int>::min());
	std::println("Lowest int value: {}", std::numeric_limits<int>::lowest());

	std::println("\nfloat:");
	std::println("Max float value: {}", std::numeric_limits<float>::max());
	std::println("Min float value: {}", std::numeric_limits<float>::min());
	std::println("Lowest float value: {}", std::numeric_limits<float>::lowest());

	return 0;
}
