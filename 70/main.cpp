import std;

class Animal {
public:
	virtual void eat() = 0;
};

class Dog : public Animal {
public:
	virtual void bark() { std::println("Woof!"); }
	void eat() override { std::println("The dog ate."); }
};

class Bird : public Animal {
public:
	virtual void chirp() { std::println("Chirp!"); }
	void eat() override { std::println("The bird ate."); }
};

class DogBird : public Dog, public Bird {
public:
	using Dog::eat;
};

int main() {
	Dog dog;
	Bird bird;
	DogBird db;

	std::print("dog.bark(): "); dog.bark();
	std::print("dog.eat(): "); dog.eat();
	
	std::print("bird.chirp(): "); bird.chirp();
	std::print("bird.eat(): "); bird.eat();
	
	std::print("db.bark(): "); db.bark();
	std::print("db.chirp(): "); db.chirp();
	std::print("db.eat(): "); db.eat();

	Animal& a1 = dog;
	Animal& a2 = bird;

	std::print("a1.eat(): "); a1.eat();
	std::print("a2.eat(): "); a2.eat();

	//Animal& a3 = db;
}
