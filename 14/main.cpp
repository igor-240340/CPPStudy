#include <print>
#include <vector>

int main() {
	std::vector<int> vec{ 11, 22 };
	vec.push_back(33);
	vec.push_back(44);
	std::println("1st element: {}", vec[0]);
}
