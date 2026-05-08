#include <print>

void example1();
void example2();
void leaky();

int main() {
	example1();
	example2();
	leaky();
}

void example1() {
	int* ptr{ nullptr };
	ptr = new int;
	delete ptr;
	ptr = nullptr;
}

void example2() {
	int** handle;
	handle = new int*;
	*handle = new int;
	delete* handle;
	delete handle;
	handle = nullptr;
}

void leaky() {
	new int;
	std::println("I just leaked an int!");
}
