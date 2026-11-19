import std;

// dynamic_cast работает только с полиморфными типами:
// в классе должен быть хотя бы один виртуальный метод (здесь — виртуальный деструктор).
class Base {
public:
	virtual ~Base() = default;
};

class Derived : public Base {
public:
	virtual ~Derived() = default;
};

int main() {
	Base* b = nullptr;
	Derived* d = new Derived();
	b = d;
	// Проверка во время выполнения: объект действительно является Derived.
	d = dynamic_cast<Derived*>(b);
	std::println("Даункаст до Derived* сработал: {}", d != nullptr);

	Base* pure_base = new Base();
	// Объект не является Derived, поэтому dynamic_cast возвращает nullptr.
	Derived* bad = dynamic_cast<Derived*>(pure_base);
	std::println("Даункаст до Derived* сработал: {}", bad != nullptr);

	Base base;
	Base& br = base;
	try {
		// Приведение ссылки невозможно, поэтому выбрасывается std::bad_cast.
		Derived& dr = dynamic_cast<Derived&>(br);
	} catch (const std::bad_cast&) {
		std::println("Bad cast!");
	}

	delete d;
	delete pure_base;
}
