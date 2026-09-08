#include <print>

class Base {
public:
	Base() {
		std::println("Base()");
	};
	//~Base() {};
	virtual ~Base() {
		std::println("~Base");
	};
};

class Derived : public Base {
public:
	Derived() {
		std::println("Derived()");

		str = new char[30];
		std::println("str allocated");
	}

	~Derived() {
		std::println("~Derived()");

		delete[] str;
		std::println("str deallocated");
	}

private:
	char* str;
};

int main() {
	Base* ptr = new Derived();
	delete ptr;
}
