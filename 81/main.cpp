import std;

class Base {
public:
	virtual ~Base() = default;
	Base() = default;
	Base(const Base& src) { std::println("Base(const Base& src)"); }
	
	Base& operator=(const Base& rhs) {
		if (&rhs == this) {
			return *this;
		}
		std::println("Base& operator=(const Base& rhs)");
		return *this;
	}
};

class Derived : public Base {
public:
	Derived() = default;
	Derived(const Derived& src) : Base(src) { std::println("Derived(const Derived& src)"); }

	Derived& operator=(const Derived& rhs) {
		std::println("Derived& operator=(const Derived& rhs)");

		if (&rhs == this) {
			return *this;
		}

		Base::operator=(rhs); // Копирование полей базового класса.
		// Здесь выполняется копирование полей производного класса.
		return *this;
	}
};

int main() {
	Derived first;
	Derived second(first); // Вызывает конструктор копирования Derived, а тот — конструктор копирования Base.
	second = first; // Вызывает оператор присваивания Derived, а тот — оператор присваивания Base.
	second = second; // Присваивает самого себя: оператор присваивания ничего не делает.
}
