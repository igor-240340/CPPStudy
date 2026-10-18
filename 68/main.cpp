import std;

class Base {
public:
	virtual void do_something() = 0;
};

void Base::do_something() {
	std::println("Base::do_something()");
}

class Derived : public Base {
public:
	void do_something() override {
		Base::do_something();
		std::println("Derived::do_something()");
	}
};

int main() {
	Derived derived;
	Base& base = derived;
	base.do_something();
}
