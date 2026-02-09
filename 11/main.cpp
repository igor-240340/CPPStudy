#include <cstddef>
#include <print>

int main() {
	struct S {
		int a;
		char b;
		char c;
	};

	std::println("{}", sizeof(S));
	std::println("{}", alignof(S));
	std::println("{}", offsetof(S, a));
	std::println("{}", offsetof(S, b));
	std::println("{}", offsetof(S, c));
}
