import std;

class Loggable {
public:
	virtual ~Loggable() = default;
	virtual std::string get_log_message() const = 0;
};

class Foo : public Loggable {
public:
	std::string get_log_message() const override { return "Hello logger."; }
};

// Сгенерированный код читает vptr переданного объекта,
// по нему попадает в vtable Foo, от туда по RTTI locator
// извлекает сырое название класса ".?AVFoo@@" и конвертирует в "class Foo".
void log_object(const Loggable& loggable_object) {
	std::print("{}: ", typeid(loggable_object).name());
	std::println("{}", loggable_object.get_log_message());
}

int main() {
	log_object(Foo());
}
