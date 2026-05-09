#include <print>

void example1();
void example2();
void leaky();
void malloc_free();

int main() {
	example1();
	example2();
	leaky();
	malloc_free();
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

void malloc_free() {
	class Foo {
	public:
		Foo() { std::println("Foo() called"); };
		~Foo() { std::println("~Foo() called"); };
	};

	std::println("\nmalloc()");
	Foo* foo1{ (Foo*)malloc(sizeof(Foo)) };
	std::println("free()");
	free(foo1);

	std::println("\nnew");
	Foo* foo2{ new Foo };
	std::println("delete");
	delete foo2;
}
