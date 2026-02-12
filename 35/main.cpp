#include <print>
#include <stdexcept>

double divide_numbers(double numerator, double denominator);

int main() {
	try {
		std::println("{}", divide_numbers(2.5, 0.5));
		std::println("{}", divide_numbers(2.3, 0.0));
		std::println("{}", divide_numbers(4.5, 2.5));
	}
	catch (const std::invalid_argument& exception) {
		std::println("Exception caught: {}", exception.what());
	}
}

double divide_numbers(double numerator, double denominator) {
	if (denominator == 0)
		throw std::invalid_argument{ "Denominator cannot be 0." };

	return numerator / denominator;
}
