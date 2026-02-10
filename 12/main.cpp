#include <print>

int main() {
	int array1[3];
	array1[0] = 0;
	array1[1] = 0;
	array1[2] = 0;

	int array2[3] = { 0 };
	int array3[3] = {};
	int array4[3]{};
	int array5[]{ 1, 2, 3, 4 };
	int array6[3]{ 2 };

	std::println("array5 size: {}", std::size(array5));
}
