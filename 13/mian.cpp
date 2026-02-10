#include <print>
#include <array>

int main() {
	std::array<int, 3> arr{ 1, 2, 3 };
	std::println("Array size = {}", arr.size());
	std::println("2nd element = {}", arr[1]);
}
