import std;

class Animal {
public:
	explicit Animal(double weight) : weight(weight) {}
	virtual double get_weight() const { return weight; }

protected:
	Animal() = default;

private:
	double weight = 0.0;
};

class Dog : public virtual Animal {
public:
	// Animal(weight) игнорируется.
	explicit Dog(double weight, std::string name) : Animal(weight), name(std::move(name)) {}

private:
	std::string name;
};

class Bird : public virtual Animal{
public:
	// Animal(weight) игнорируется.
	explicit Bird(double weight, bool can_fly) : Animal(weight), can_fly(can_fly) {}

private:
	bool can_fly = false;
};

class DogBird : public Dog, public Bird {
public:
	// Поскольку оба класса наследуют Animal виртуально, существует только один подобъект Animal:
	// DogBird
	// ├── Dog ──────┐
	// │             ├──► Animal
	// └── Bird ─────┘       └── double weight
	// Но DogBird вызывает оба конструктора: для Dog и для Bird,
	// В случае не виртуального наследования Animal, каждый конструктор иницилизирует свой подобъект.
	// Но в нашем случае подобъект один, поэтому компилятор не вызывает Animal(double weight) вовсе, чтобы не было двойного вызова.
	// Вместо этого один раз вызывается дефолтный конструктор для Animal (отсюда и необходимость его определить).
	explicit DogBird(double weight, std::string name, bool can_fly) : Dog(weight, std::move(name)), Bird(weight, can_fly) {}
};

class CorrectDog : public virtual Animal {
public:
	explicit CorrectDog(double weight, std::string name) : Animal(weight), name(std::move(name)) {}

protected:
	explicit CorrectDog(std::string name) : name(std::move(name)) {}

private:
	std::string name;
};

class CorrectBird : public virtual Animal {
public:
	// По-прежнему игнорируется вызов Animal(weight) при "ромбовидном" наследовании.
	// Но вызов Animal(weight) мы всё-равно оставляем, поскольку мы можем захотеть создать самостоятельный экземпляр CorrectBird.
	explicit CorrectBird(double weight, bool can_fly) : Animal(weight), can_fly(can_fly) {}

protected:
	explicit CorrectBird(bool can_fly) : can_fly(can_fly) {}

private:
	bool can_fly = false;
};

class CorrectDogBird : public CorrectDog, public CorrectBird {
public:
	// Самый нижний в иерархии класс сам инициализирует единственный подобъект Animal.
	// В данном случае дефолтный Animal() уже не вызывается.
	explicit CorrectDogBird(double weight, std::string name, bool can_fly)
		: Animal(weight), CorrectDog(std::move(name)), CorrectBird(can_fly) {}
};

int main() {
	DogBird dog_bird(22.33, "Bella", true);
	std::println("Weight: {}", dog_bird.get_weight()); // weight = 0.

	CorrectDogBird correct_dog_bird(22.33, "Bella", true);
	std::println("Weight: {}", correct_dog_bird.get_weight()); // weight = 22.33.
}
