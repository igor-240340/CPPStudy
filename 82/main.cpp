import std;

class Animal {
public:
	virtual ~Animal() = default;
};

class Dog : public Animal {};
class Bird : public Animal {};

// typeid отбрасывает const и &.
void speak(const Animal& animal) {
	std::println("typeid(animal).name() = {}", typeid(animal).name());
	std::println("typeid(Dog).name() = {}", typeid(Dog).name());
	std::println("typeid(Bird).name() = {}", typeid(Bird).name());

	if (typeid(animal) == typeid(Dog)) {
		std::println("Woof!");
	}
	else if (typeid(animal) == typeid(Bird)) {
		std::println("Chirp!");
	}
}

int main() {
	speak(Dog());
	speak(Bird());
}
