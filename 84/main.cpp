import std;

class Animal {
public:
	virtual void eat() = 0;
	virtual void sleep() { std::println("zzzzz...."); }
};

class Dog : public virtual Animal {
public:
	virtual void bark() { std::println("Woof!"); }
	void eat() override { std::println("The dog ate."); }
};

class Bird : public virtual Animal {
public:
	virtual void chirp() { std::println("Chirp!"); }
	void eat() override { std::println("The bird ate."); }
};

class DogBird : public Dog, public Bird {
public:
	void eat() override { Dog::eat(); }
};

int main() {
	DogBird my_confused_animal;
	my_confused_animal.sleep(); // Нет неоднозначности.
}
