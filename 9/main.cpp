#include <print>

int add_numbers(int a, int b);

int main() {
	add_numbers(5, 6);
}

int add_numbers(int a, int b) {
	std::println("Function: {}", __func__);
	return a + b;
}
