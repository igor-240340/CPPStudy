#include <print>
#include <string>
#include <utility>

void example_1();
void example_2();

const std::string message{ "Test" };
const std::string& foo() {
	return message;
}
void example_3();

int main() {
	example_1();
	example_2();
	example_3();
}

void example_1() {
	// Copy list initialization.
	auto a = { 11 };
	auto b = { 11, 22 };
	// auto b = {11, 22.33}; // Error.

	// Direct list initialization.
	auto c{ 11 };
	// auto d{11, 22}; // Error.
}

void example_2() {
	int x{ 123 };
	decltype(x) y{ 456 };
}

void example_3() {
	decltype(foo()) f2{ foo() };
	// f2 = "foo"; // Error.
}
