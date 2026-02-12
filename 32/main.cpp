#include <print>
#include <string>

void print_string(const std::string& my_string);
void example_1();
void example_2();
void refcall(int& t);

int main() {
	example_1();
	//example_2(); // Runtime error.
}

void print_string(const std::string& my_string) {
	std::println("{}", my_string);
}

void example_1() {
	std::string some_string{ "Hello World" };
	print_string(some_string);
	print_string("Hello World");
}

void example_2() {
	int* ptr{ (int*)8 };
	refcall(*ptr);
}

void refcall(int& t) {
	++t;
}
