#include <print>
#include <utility>

int main() {
	std::pair<double, int> p{ 1.23, 5 };
	std::println("{} {}", p.first, p.second);
}
