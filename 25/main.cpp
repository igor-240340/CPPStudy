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

	return 0;
}

void example_1() {
	int const* ip;
	ip = new int[10];
	// ip[4] = 5; // Compile error.
}

void example_2() {
	int* const ip{ nullptr };
	// ip = new int[10]; // Compile error.
	// ip[4] = 5; // Runtime error.
}

void example_3() {
	int* const ip{ new int[10] };
	ip[4] = 5;
}

void example_4() {
	const int* const ip{ nullptr };
}
