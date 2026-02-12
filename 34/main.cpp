#include <print>
#include <string>

void third_party_library(char* str);
void f(const char* str);

int main() {
	std::string str{ "hello" };
	f(str.c_str());
}

void third_party_library(char* str) {
	str[0] = 'T'; // Just for example.
	std::println("third_party_library: str = {}", str);
}

void f(const char* str) {
	std::println("f: str = {}", str);
	third_party_library(const_cast<char*>(str));
}
