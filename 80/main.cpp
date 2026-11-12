import std;

class Gregarious {
public:
	virtual void talk() { std::println("Gregarious says hi!"); }
};

class Shy : public Gregarious {
protected:
	void talk() override { std::println("Shy reluctantly says hello."); }
};

class Secret {
protected:
	virtual void dont_tell() { std::println("I'll never tell."); }
};

class Blabber : public Secret {
public:
	virtual void tell() { dont_tell(); } // Даём публичный доступ к dont_tell базового класса.
};

class BlabberOverride : public Secret {
public:
	void dont_tell() override { std::println("I'll tell all!"); } // Даём публичный доступ к dont_tell базового, меняя его поведение.
};

class BlabberUsing : public Secret {
public:
	using Secret::dont_tell; // Даём публичный доступ, не меняя поведения.
};

int main() {
	Shy my_shy;
	//my_shy.talk(); // Error! Attempt to access protected member function.

	Gregarious& gregarious_ref = my_shy;
	gregarious_ref.talk();

	Blabber my_blabber;
	my_blabber.tell();

	BlabberOverride my_blabber_override;
	my_blabber_override.dont_tell();

	BlabberUsing my_blabber_using;
	my_blabber_using.dont_tell();

	Secret& secret_ref = my_blabber_using;
	Secret* secret_ptr = &my_blabber_using;
	//secret_ref.dont_tell(); // Error! Attempt to access protected member function.
	//secret_ptr->dont_tell(); // Error! Attempt to access protected member function.
}
