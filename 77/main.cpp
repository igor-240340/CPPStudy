import std;

class Base {
public:
	virtual ~Base() = default;
	virtual void overload() { std::println("Base's overload()"); }
	virtual void overload(int i) { std::println("Base's overload(int i)"); }
};

class Derived : public Base {
public:
	void overload() override { std::println("Derived's overload()"); } // Остальные перегрузки базового скрыты.
};

class DerivedUsing : public Base {
public:
	using Base::overload; // Затаскиваем все перегрузки в дочерний класс.
	void overload() override { std::println("DerivedUsing's overload()"); } // Но переопределяем только одну функцию.
};

int main() {
	Derived my_derived;
	my_derived.overload();
	//my_derived.overload(2); // Ошибка. В дочернем недоступна перегрузка базового.

	Base& ref = my_derived;
	ref.overload(7);

	DerivedUsing my_derived_using;
	my_derived_using.overload();
	my_derived_using.overload(2); // Перегрузка базового доступна.
}
