import std;

class Dog {
public:
	virtual void bark() {
		std::println("Woof!");
	}

	virtual void eat() {
		std::println("The dog ate.");
	}
};

class Bird {
public:
	virtual void chirp() {
		std::println("Chirp!");
	}

	virtual void eat() {
		std::println("The bird ate.");
	}
};

class DogBird : public Dog, public Bird {
};

int main()
{
	DogBird my_confused_animal;
	//my_confused_animal.eat();
}
