
class Base {
public:
	virtual ~Base() = default;
	Base() = default;
	explicit Base(int i) {}
};

class Derived : public Base {
public:
	//explicit Derived(int i) : Base(i) {}
	// NOTE: Наследуем все недефолтный конструкторы базового класса. Дефолтный генерится для Dervied компилятором.
	using Base::Base;
};

int main() {
	Base base(1);
	Derived derived1(2);
	Derived derived2; // Компилятор ругается, если нет дефолтного конструктора в Derived.
}
