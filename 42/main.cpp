#include <string>
#include <charconv>
#include <print>

void example1();
void example2();
void example3();
void example4();
void example5();
void example6();

int main() {
	example1();
	example2();
	example3();
	example4();
	example5();
	example6();

	return 0;
}

void example1() {
	float f{ 0.1f };
	std::string f_s{ std::to_string(f) };

	std::println("f_s = {}", f_s);
}

void example2() {
	const std::string to_parse{ "123USD" };
	size_t index{ 0 };
	int value{ std::stoi(to_parse, &index) };
	std::println("Parsed value: {}", value);
	std::println("First non-parsed character: '{}'", to_parse[index]);
}

void example3() {
	const std::string to_parse{ "0xAAF3%^" };
	size_t index{ 0 };
	int value{ std::stoi(to_parse, &index, 16) };
	std::println("Parsed value: {}", value);
	std::println("First non-parsed character: '{}'", to_parse[index]);
}

void example4() {
	const size_t buffer_size{ 50 };
	std::string out(buffer_size, ' ');
	auto [ptr, error] {std::to_chars(out.data(), out.data() + out.size(), 12345)};
	if (error == std::errc{}) {
		std::println("{}", out);
	}
}

void example5() {
	const size_t buffer_size{ 50 };
	std::string out(buffer_size, ' ');
	double value{ 0.314 };
	auto [ptr, error] {std::to_chars(out.data(), out.data() + out.size(), value)};
	if (error == std::errc{}) {
		println("{}", out);
	}
}

void example6() {
	/* Deleted function.
	double value1{0.314};
	const size_t buffer_size{50};
	std::string out(buffer_size, ' ');
	auto [ptr1, error1]{std::to_chars(out.data(), out.data() + out.size(), value1)};
	if (error1 == std::errc{}) {
		std::println("{}", out);
	}

	double value2;
	auto [ptr2, error2]{std::from_chars(out.data(), out.data() + out.size(), value2)};
	if (error2 == std::errc{}) {
		if (value1 == value2) {
			std::println("Perfect roundtrip");
		} else {
			std::println("No perfect roundtrip?!?");
		}
	}
	*/
}
