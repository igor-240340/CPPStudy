#include <string>
#include <print>

std::string extract_extension(std::string_view filename);

int main() {
	std::string filename{ R"(c:\temp\my file.ext)" };
	std::println("C++ string: {}", extract_extension(filename));

	const char* c_string{ R"(c:\temp\my file.ext)" };
	std::println("C string: {}", extract_extension(c_string));

	std::println("Literal: {}", extract_extension(R"(c:\temp\my file.ext)"));

	const char* raw{ R"(c:\temp\my file.ext)" };
	size_t length{ 19 };
	std::println("Raw: {}", extract_extension(std::string_view{ raw, length }));

	return 0;
}

std::string extract_extension(std::string_view filename) {
	return std::string{filename.substr(filename.rfind('.'))};
}
