#include <print>
#include <string>

char* copy_string(const char* str);
char* append_strings(const char* str1, const char* str2, const char* str3);

void example1();
void example2();
void example3();
void example4();
void example5();
void example6();

int main() {
	example1();
	std::println("");

	example2();
	std::println("");

	example3();
	std::println("");

	// example4(); // Segmentation fault.
	// std::println("");

	example5();
	std::println("");

	example6();

	return 0;
}

char* copy_string(const char* str) {
	char* result{ new char[strlen(str) + 1] };
	strcpy(result, str);
	return result;
}

char* append_strings(const char* str1, const char* str2, const char* str3) {
	char* result{ new char[strlen(str1) + strlen(str2) + strlen(str3) + 1] };
	strcpy(result, str1);
	strcat(result, str2);
	strcat(result, str3);
	return result;
}

void example1() {
	char str[]{ "Hello" };
	char* str_copy = copy_string(str);
	std::println("{}", std::string{ str });
	std::println("{}", std::string{ str_copy });
	delete[] str_copy;
}

void example2() {
	char str1[]{ "Hello" };
	char str2[]{ ", world!" };
	char str3[]{ "foo" };
	char* res = append_strings(str1, str2, str3);

	std::println("{}", std::string{ res });
}

void example3() {
	char text1[]{ "abcdef" };
	size_t s1{ sizeof(text1) };
	size_t s2{ strlen(text1) };
	std::println("sizeof(text1) = {}", s1);
	std::println("strlen(text1) = {}", s2);

	const char* text2{ "abcdef" };
	size_t s3{ sizeof(text2) };
	size_t s4{ strlen(text2) };
	std::println("sizeof(text2) = {}", s3);
	std::println("strlen(text2) = {}", s4);
}

void example4() {
	//char* ptr{ "hello" }; // Trying to change literal.
	//ptr[1] = 'a';
}

void example5() {
	char arr[]{ "hello" };
	arr[1] = 'a';
	std::println("arr = {}", arr);
}

void example6() {
	std::println(R"(Hello "World"!\n)");
	std::println(R"(
Line 1
Line 2
    )");
	std::println(R"-(Embedded )" characters)-"); // R"- -". Raw stirng witrh custom delimiter.
}
