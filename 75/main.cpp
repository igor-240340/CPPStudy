import std;

class Base {
public:
	virtual ~Base() = default;
	explicit Base(std::string_view str) : str(str) {}

private:
	std::string str;
};

class Derived : public Base {
public:
	using Base::Base;
	explicit Derived(int i) : Base(""), integer(i) {}
private:
	int integer = 0; // Чтобы не оставить переменную неинициализированной в случае s2.
};

int main() {
	Derived s1(2);
	Derived s2("Hello world");
}
