import std;

class BaseStatic {
public:
	static void be_static() { std::println("BaseStatic being static."); }
};

class DerivedStatic : public BaseStatic {
public:
	static void be_static() { std::println("DerivedStatic keepin' it static."); }
};

int main() {
	BaseStatic::be_static();
	DerivedStatic::be_static();

	DerivedStatic my_derived_static;
	BaseStatic& ref = my_derived_static;
	my_derived_static.be_static();
	ref.be_static();
}
