#include <string>
#include <print>
#include <string_view>

void example1() {
	int i{ 42 };

	std::println("|{:5}|", i);
	std::println("|{:{}}|", i, 7);
	std::println("|{1:{0}}|", 7, i);
}

int main() {
	example1();
}
