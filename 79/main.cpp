import std;

class Base {
public:
	virtual ~Base() = default;
	virtual void go(int i = 2) { std::println("Base's go with i={}", i); }
};

class Derived : public Base {
public:
	void go(int i = 7) override { std::println("Derived's go with i={}", i); }
};

int main() {
	Base my_base;
	Derived my_derived;
	Base& my_base_reference_to_derived = my_derived;
	my_base.go();
	my_derived.go();
	my_base_reference_to_derived.go();
}
