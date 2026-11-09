import std;

class Base {
public:
	virtual ~Base() = default;
	Base() = default;
	explicit Base(std::string_view str) {}
	explicit Base(float f) {}
};

class Derived : public Base {
public:
	using Base::Base; // Мы не наследуем буквально все конструкторы базового: дефолтный и копирующий для Derived неявно генерируются компилятором.
	explicit Derived(float f) {}    // Перекрывает Base(float f).
};

int main() {
	Derived derived1("Hello");	// Base(std::string_view str).
	Derived derived2(1.23f);	// Derived(float f).
	Derived derived3;			// Вызывает неявно сгенерированный Derived(), в котором затем вызывается Base().
}
