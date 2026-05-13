#include <print>

void example1();
void example2();
void leaky();
void malloc_free();
void arrays();
void array_of_objects();
void array_of_pointers_to_objects();
void multidim_stack_array();
void multidim_heap_array();
void access_violation();
void pointer_casting();

int main() {
	example1();
	example2();
	leaky();
	malloc_free();
	arrays();
	array_of_objects();
	array_of_pointers_to_objects();
	multidim_stack_array();
	multidim_heap_array();
	//access_violation(); // Crashes with 0xc0000005.
	pointer_casting();
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
	std::println("\narray_of_objects()");
	class Simple {
	public:
		Simple() { std::println("Simple constructor called!"); }
		~Simple() { std::println("Simple destructor called!"); }
	};

	Simple* my_simple_array{ new Simple[4] };
	std::println();
	delete[] my_simple_array;
	my_simple_array = nullptr;
}

void array_of_pointers_to_objects() {
	std::println("\narray_of_pointers_to_objects()");
	class Simple {
	public:
		Simple() { std::println("Simple constructor called!"); }
		~Simple() { std::println("Simple destructor called!"); }
	};

	const size_t size{ 4 };
	Simple** my_simple_ptr_array{ new Simple*[size] };
	for (size_t i{ 0 }; i < size; ++i) {
		my_simple_ptr_array[i] = new Simple{};
	}
	std::println();
	for (size_t i{ 0 }; i < size; ++i) {
		delete my_simple_ptr_array[i];
		my_simple_ptr_array[i] = nullptr;
	}

	delete[] my_simple_ptr_array;
	my_simple_ptr_array = nullptr;
}

void multidim_stack_array() {
	std::println("\nmultidim_stack_array()");
	char board[3][3]{};
	board[0][0] = 'X';
	board[2][1] = 'O';
}

void multidim_heap_array() {
	std::println("\nmultidim_heap_array()");
	char** my_array{ new char* [3] };
	for (size_t i{ 0 }; i < 3; ++i) {
		my_array[i] = new char[3];
	}

	for (size_t i{ 0 }; i < 3; ++i) {
		delete[] my_array[i];
		my_array[i] = nullptr;
	}
	delete[] my_array;
	my_array = nullptr;
}

void access_violation() {
	std::println("\naccess_violation()");
	char* invalid_memory_location{ (char*)113 };
	*invalid_memory_location = 'H';
}

void pointer_casting() {
	std::println("\npointer_casting()");
	class Simple {
	public:
		Simple() { std::println("Simple constructor called!"); }
		~Simple() { std::println("Simple destructor called!"); }
	};

	Simple* s1{ new Simple };
	char* char_ptr1{ (char*)s1 };
	std::println("Simple as char: '{}'", *char_ptr1);

	// Won't let casting to unrelated type.
	//Simple* s2{ new Simple };
	//char* char_ptr2{ static_cast<char*>(s2) };
	//std::println("Simple as char: '{}'", *char_ptr2);
}
