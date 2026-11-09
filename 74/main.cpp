import std;

class Base1 {
public:
	virtual ~Base1() = default;
	Base1() = default;
	explicit Base1(float f) {}
};

class Base2 {
public:
	virtual ~Base2() = default;
	Base2() = default;
	explicit Base2(std::string_view str) {}
	explicit Base2(float f) {}
};

class Derived : public Base1, public Base2 {
public:
	using Base1::Base1; // Затаскиваем сюда оба конструктора: Base2(float) и Base1(float)
	using Base2::Base2; // тем самым создавая двусмысленность.
	explicit Derived(char c) {}
	//explicit Derived(float f) {} // Явно убираем двусмысленность так.
	explicit Derived(float f) : Base1(f), Base2(f) {} // Или даже так.
};

int main() {
	Derived d(1.2f);
}
