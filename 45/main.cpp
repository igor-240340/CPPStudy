#include <string>
#include <iostream>
#include <print>

void example1();
void example2();
void example3();
void example4();
void example5();
void example6();
void example7();
void example8();
void example9();
void example10();

int main() {
	example1();
	example2();
	example3();
	example4();
	example5();
	example6();
	example7();
	example8();
	example9();
	example10();
}

void example1() {
	int i{ 42 };

	std::println("|{:5}|", i);
	std::println("|{:{}}|", i, 7);
	std::println("|{1:{0}}|", 7, i);
}

void example2() {
	int i{ 42 };

	std::println("|{:7}|", i);
	std::println("|{:<7}|", i);
	std::println("|{:_>7}|", i);
	std::println("|{:_^7}|", i);
}

void example3() {
	std::println("|{:=>16}|", "");
}

void example4() {
	int i{ 42 };

	std::println("|{:<5}|", i);
	std::println("|{:<+5}|", i);
	std::println("|{:< 5}|", i);
	std::println("|{:< 5}|", -i);
}

void example5() {
	int i{ 42 };

	std::println("|{:10d}|", i);
	std::println("|{:10b}|", i);
	std::println("|{:#10b}|", i);
	std::println("|{:10X}|", i);
	std::println("|{:#10X}|", i);
}

void example6() {
	std::string s{ "ProCpp" };
	std::println("|{:_^10}|", s);
}

void example7() {
	double d{ 3.1415 / 2.3 };
	std::println("|{:12g}|", d);
	std::println("|{:12.2}|", d);
	std::println("|{:12e}|", d);

	int width{ 12 };
	int precision{ 3 };
	std::println("|{2:{0}.{1}f}|", width, precision, d);
	std::println("|{2:{0}.{1}}|", width, precision, d);
}

void example8() {
	int i{ 42 };

	std::println("|{:06d}|", i);
	std::println("|{:+06d}|", i);
	std::println("|{:06X}|", i);
	std::println("|{:#06x}|", i);
}

void example9() {
	float f{ 1.2f };
	std::cout << format(std::locale{ "nl" }, "|{:Lg}|\n", f);
}

void example10() {
	std::println("|{:?}|", "Hello\tWorld!\n");
	std::println("|{:?}|", "\"");
	std::println("|{:?}|", '\'');
	std::println("|{:?}|", '"');
}
