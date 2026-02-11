#include <print>

struct CircleStruct {
	int x, y;
	double radius;
};

class CircleClass {
public:
	CircleClass(int x, int y, double radius) : x{ x }, y{ y }, radius{ radius } {};

private:
	int x;
	int y;
	double radius;
};

class MyClass {
public:
	MyClass() : arr{ 0, 1, 2, 3 } {};

private:
	int arr[4];
};

int main() {
	// Pre-C++11.
	CircleStruct my_circle1 = { 10, 10, 2.5 };
	CircleClass my_circle2(10, 10, 2.5);

	CircleStruct my_circle3 = { 10, 10, 2.5 };
	CircleClass my_circle4 = { 10, 10, 2.5 };

	CircleStruct my_circle5{ 10, 10, 2.5 };
	CircleClass my_circle6{ 10, 10, 2.5 };

	int a = 3;
	int b(3);
	int c = { 3 };
	int d{ 3 };
	int e{};
	// int x{3.14}; // Error because narrowing.

	MyClass my_class;

	return 0;
}
