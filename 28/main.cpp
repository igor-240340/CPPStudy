#include <format>
#include <print>

void example_1();
void example_2();
void example_3();
void example_4();

int main() {
	example_1();
	example_2();
	example_3();
	example_4();
}

void example_1() {
	// int& empty_ref; // Compile error.
}

void example_2() {
	int x{ 3 };
	int& x_ref{ x };

	x_ref = 10;
	std::println("x = {}", x);
}

void example_3() {
	int x{ 3 }, y{ 4 };

	int& x_ref{ x };
	std::println("x = {}, y = {}", x, y);

	x_ref = y;
	std::println("x = {}, y = {}", x, y);
}

void example_4() {
	int x{ 3 }, z{ 5 };
	int& x_ref{ x };
	int& z_ref{ z };
	z_ref = x_ref;

	std::println("x = {}, z = {}", x, z);
}