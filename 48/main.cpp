#include <print>

void example1();
void example2();
void leaky();
void malloc_free();
void arrays();
void array_of_objects();

int main() {
	example1();
	example2();
	leaky();
	malloc_free();
	arrays();
	array_of_objects();
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

void arrays() {
	int array1[5];
	int array2[5]{ 1, 2, 3, 4, 5 };
	int array3[5]{ 1, 2 };
	int array4[5]{};
	int array5[]{ 1, 2, 3, 4, 5 };

	int* array6{ new int[5] };
	delete[] array6;
	array6 = nullptr;

	int* array7{ new int[] { 1, 2, 3, 4, 5 } };
	delete[] array7;
	array7 = nullptr;
}

void array_of_objects() {
	class Simple {
	public:
		Simple() { std::println("Simple constructor called!"); }
		~Simple() { std::println("Simple destructor called!"); }
	};

	Simple* my_simple_array{ new Simple[4] };
	delete[] my_simple_array;
}
