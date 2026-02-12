#include <print>

void add_one_value(int i);
void add_one_ref(int& i);

void swap(int& first, int& second);
void swap_example1();
void swap_example2();

int main() {
	int a{ 4 };

	add_one_value(a);
	std::println("a = {}", a);

	add_one_ref(a);
	std::println("a = {}", a);

	std::println();
	swap_example1();

	std::println();
	swap_example2();
}

void add_one_value(int i) {
	i++;
}

void add_one_ref(int& i) {
	i++;
}

void swap(int& first, int& second) {
	int temp{ first };
	first = second;
	second = temp;
}

void swap_example1() {
	int x{ 5 };
	int y{ 6 };
	std::println("x = {}", x);
	std::println("y = {}", y);
	swap(x, y);

	std::println("x = {}", x);
	std::println("y = {}", y);
}

void swap_example2() {
	int x{ 5 };
	int y{ 6 };
	int* xp{ &x };
	int* yp{ &y };
	std::println("x = {}", x);
	std::println("y = {}", y);
	swap(*xp, *yp);

	std::println("x = {}", x);
	std::println("y = {}", y);
}
