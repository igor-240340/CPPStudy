#include <format>
#include <print>
#include <string>

void example_1();

int main() {
	example_1();
}

void example_1() {
	class MyClass {
	public:
		MyClass(int& ref) : m_ref{ ref } {}

	private:
		int& m_ref;
	};

	int a = 6;
	MyClass my_class{ a };
}
