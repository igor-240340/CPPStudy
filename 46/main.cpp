#include <string>
#include <vector>
#include <print>
#include <utility>

void example1();
void example2();
void example3();
void example4();
void example5();

int main() {
	example1();
	std::println("");

	example2();
	std::println("");

	example4();
	std::println("");
	
	example5();
	std::println("");
}

void example1() {
	std::vector<int> values{ 11, 22, 33 };
	std::println("{}", values);
	std::println("{:n}", values);

	std::println("{{{:n}}}", values);

	std::println("{:*^16}", values);
	std::println("{:*^16n}", values);

	std::println("{::*^6}", values);
	std::println("{:n:*^6}", values);
}

void example2() {
	using namespace std::string_literals;
	std::vector strings{ "Hello"s, "World!\t2023"s };
	std::println("{}", strings);
	std::println("{:}", strings);
	std::println("{::}", strings);
	std::println("{:n:}", strings);
}

void example3() {
	std::vector chars{ 'W', 'o', 'r', 'l', 'd', '\t', '!' };
	std::println("{}", chars);
	std::println("{::#x}", chars);
	std::println("{:s}", chars);
	std::println("{:?s}", chars);
}

void example4() {
	std::pair p{ 11, 22 };
	std::println("{}", p);
	std::println("{:n}", p);
	std::println("{:m}", p);
}

void example5() {
	std::vector<std::vector<int>> vv{ {11, 22}, {33, 44, 55} };
	std::println("{}", vv);
	std::println("{:n}", vv);
	std::println("{:n:n}", vv);
	std::println("{:n:n:*^4}", vv);
}
