#include <print>

int sum(std::initializer_list<int> values);

int main() {
	int a{ sum({1, 2, 3}) };
	int b{ sum({10, 20, 30, 40, 50, 60}) };
	std::println("a: {}", a);
	std::println("b: {}", b);
}

int sum(std::initializer_list<int> values) {
	int total{ 0 };
	for (int value : values)
		total += value;

	return total;
}
