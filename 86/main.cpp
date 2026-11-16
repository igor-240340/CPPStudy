import std;

class Base {
public:
	virtual ~Base() = default;
};

class Derived : public Base {
public:
	virtual ~Derived() = default;

	void meth() { std::println("a={}, b={}", a, b); };

private:
	int a = 6;
	int b = 7;
};

int main() {
	int i = 3;
	int j = 4;
	double result = static_cast<double>(i) / j;
	std::println("{}", result);

	Base* b = nullptr;
	Derived* d = new Derived();
	// Вверх по иерархии явное приведение не нужно.
	// NOTE:
	// В данном случае у Derived один невиртуальный Base, поэтому подобъект Base лежит по смещению 0 и b = d не меняет адрес.
	// Но это справедливо не для каждого апкаста (upcast), например, в случае множественного или виртуального наследования адрес может измениться.
	b = d;
	d = static_cast<Derived*>(b); // Вниз по иерархии нужен static_cast.
	delete b; // У базового есть виртуальный деструктор.

	// То же самое для ссылок.
	Base base;
	Derived derived;
	Base& br = derived;
	Derived& dr = static_cast<Derived&>(br);

	// static_cast не проверяет тип во время выполнения.
	// Такое приведение компилируется, но указателем пользоваться нельзя: объект на самом деле не Derived.
	Base* pure_base = new Base();
	Derived* bad_derived = static_cast<Derived*>(pure_base);
	bad_derived->meth(); // UB!

	Derived* pure_derived = new Derived();
	Base* base_is_derived = pure_derived;
	Derived* good_derived = static_cast<Derived*>(base_is_derived);
	good_derived->meth(); // Всё ок.
	
	delete pure_base;
	delete pure_derived;
}
