#include <print>

int main() {
	int some_integer{ 256 };
	short some_short;
	long some_long;
	float some_float;
	double some_double;

	some_integer++;
	some_integer *= 2;
	some_short = static_cast<short>(some_integer);
	some_long = some_short * 10000;
	some_float = some_long + 0.785f;
	some_double = static_cast<double>(some_float) / 100000;
	std::println("{:.50f}", some_double);

	std::println("{:.50f}", some_float / 100000);

	return 0;
}
