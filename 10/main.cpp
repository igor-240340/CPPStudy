#include <print>

int add_numbers(int a, int b);
float add_numbers(float a, float b);

int main() {
	std::println("integer sum: {}", add_numbers(5, 6));
	std::println("float sum: {}", add_numbers(50.0f, 60.0f));
}

int add_numbers(int a, int b) {
	return a + b;
}

float add_numbers(float a, float b) {
	return a + b;
}
