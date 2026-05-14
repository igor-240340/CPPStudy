#include <print>
#include <array>

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
void array_pointer();
void double_ints(int* the_array, size_t size);

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
	array_pointer();
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

void array_pointer() {
	std::println("\narray_pointer()");
	int my_int_array[10]{};
	int* my_int_ptr{ my_int_array };
	my_int_ptr[4] = 5;

	//
	size_t arr_size{ 4 };
	int* free_store_array{ new int[arr_size] { 1, 5, 3, 4 } };
	std::print("free_store_array: [");
	for (size_t i{ 0 }; i < arr_size; ++i) {
		std::print(" {} ", free_store_array[i]);
	}
	std::println("]");
	double_ints(free_store_array, arr_size);
	std::print("free_store_array: [");
	for (size_t i{ 0 }; i < arr_size; ++i) {
		std::print(" {} ", free_store_array[i]);
	}
	std::println("]");
	delete[] free_store_array;
	free_store_array = nullptr;

	int stack_array[]{ 5, 7, 9, 11 };
	arr_size = std::size(stack_array); // New way.
	std::print("stack_array: [");
	for (size_t i{ 0 }; i < arr_size; ++i) {
		std::print(" {} ", stack_array[i]);
	}
	std::println("]");
	//arr_size = sizeof(stack_array) / sizeof(stack_array[0]); // Old way.
	double_ints(stack_array, arr_size);
	std::print("stack_array: [");
	for (size_t i{ 0 }; i < arr_size; ++i) {
		std::print(" {} ", stack_array[i]);
	}
	std::println("]");
	double_ints(&stack_array[0], arr_size);
	std::print("stack_array: [");
	for (size_t i{ 0 }; i < arr_size; ++i) {
		std::print(" {} ", stack_array[i]);
	}
	std::println("]");
}

void double_ints(int* the_array, size_t size) {
	for (size_t i{ 0 }; i < size; ++i) {
		the_array[i] *= 2;
	}
}

