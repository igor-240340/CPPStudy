#include <print>

void mystery_function(const std::string* some_string) {
	//*some_string = "Test"; // Compile error.
}
int main() {
	std::string my_string{ "The string" };
	mystery_function(&my_string);
}
