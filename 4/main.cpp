#include <print>

int main() {
	std::byte b{ 42 };
	std::println("b: 0x{:02X}", std::to_integer<unsigned int>(b));

	return 0;
}
