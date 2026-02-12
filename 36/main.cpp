#include <print>
#include <string>
#include <utility>

void example_1();
void example_2();

int main() {
	example_1();
	example_2();
}

void example_1() {
	std::string str{ "C++" };
	auto result{ as_const(str) };  // Copy is made.

	result = "New string";
	std::println("str = {}", str);
	std::println("result = {}", result);
}

void example_2() {
	int i{ 123 };
	auto p{ &i }; // int*.

	const auto p1{ &i }; // Actually makes int* const not const int*
	*p1 = 456; // Works fine.

	const auto* p2{ &i };
	// *p2 = 456; // Now does not compile.
}
