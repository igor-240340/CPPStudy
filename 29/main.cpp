#include <format>
#include <print>
#include <string>

void example_1();
void example_2();
void example_3();
void example_4();
void example_5();
std::string get_string();

int main() {
	example_1();
	example_2();
	example_3();
	example_4();
	example_5();
}

void example_1() {
	// int& unnamed_ref1{5}; // Compile error.
	const int& unnamed_ref2{ 5 };
}

void example_2() {
	// std::string& string1{get_string()}; // Compile error.
	const std::string& string2{ get_string() };
}

void example_3() {
	int* int_p{ nullptr };
	int*& ptr_ref{ int_p };
	ptr_ref = new int;
	*ptr_ref = 5;

	delete ptr_ref;
	ptr_ref = nullptr;
}

void example_4() {
	int x{ 3 };
	std::println("x = {}", x);
	int& x_ref{ x };
	int* x_ptr{ &x_ref };
	*x_ptr = 100;
	std::println("x = {}", x);

	// std::println("x_ptr == x_ref", x_ptr == x_ref); // Compile error.
	std::println("(x_ptr == &x_ref) = {}", x_ptr == &x_ref);
}

// Structured bindings.
void example_5() {
	std::pair my_pair{ "hello", 5 };
	auto& [the_string, the_int] { my_pair };
	const auto& [the_string2, the_int2] { my_pair };
}

std::string get_string() {
	return "Hello world!";
}
