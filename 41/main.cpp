#include <string>
#include <print>
#include <vector>

void example1();
void example2();
void example3();
void example4();
void example5();
void example6();
void example7();

int main() {
	example1();
	example2();
	example3();
	example4();
	example5();
	example6();
	example7();

	return 0;
}

void example1() {
	std::string a{ "12" };
	std::string b{ "34" };
	std::string c{ a + b };

	std::println("{}", c);
}

void example2() {
	std::string a{ "Hello" };
	std::string b{ "World" };
	std::println("'{}' < '{}' = {}", a, b, a < b);
	std::println("'{}' > '{}' = {}", a, b, a > b);
}

void example3() {
	std::string a{ "12" };
	std::string b{ "34" };

	int result{ a.compare(b) };
	if (result < 0) {
		std::println("less");
	}
	if (result > 0) {
		std::println("greater");
	}
	if (result == 0) {
		std::println("equal");
	}
}

void example4() {
	std::string a{ "12" };
	std::string b{ "34" };

	auto result{ a <=> b };
	if (is_gt(result)) { std::println("greater"); }
	if (is_lt(result)) { std::println("less"); }
	if (is_eq(result)) { std::println("equal"); }
}

void example5() {
	std::string my_string{ "hello" };
	my_string += ", there";
	std::string my_other_string{ my_string };
	if (my_string == my_other_string) {
		my_other_string[0] = 'H';
	}
	std::println("{}", my_string);
	std::println("{}", my_other_string);
}

void example6() {
	std::string str_hello{ "Hello!!" };
	std::string str_world{ "The World..." };
	auto position{ str_hello.find("!!") };
	if (position != std::string::npos) {
		// Found the "!!" substring, now replace it.
		str_hello.replace(position, 2, str_world.substr(3, 6));
	}
	std::println("{}", str_hello);

	// Test contains().
	std::string to_find{ "World" };
	std::println("{}", str_world.contains(to_find));
	std::println("{}", str_world.contains('.'));
	std::println("{}", str_world.contains("Hello"));
}

void example7() {
	using namespace std::literals;
	std::vector names1{ "John", "Sam", "Joe" }; // std::vector<const char*>.
	std::vector names2{ "John"s, "Sam"s, "Joe"s }; // std::vector<std::string>.
}
