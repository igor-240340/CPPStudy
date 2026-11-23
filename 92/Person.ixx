export module person;
import std;

export class Person {
public:
	Person(std::string first_name, std::string last_name);
	const std::string& get_first_name() const;
	const std::string& get_last_name() const;

private:
	std::string first_name;
	std::string last_name;
};

// Реализации в том же файле интерфейса модуля.
Person::Person(std::string first_name, std::string last_name)
	: first_name(std::move(first_name)), last_name(std::move(last_name)) {}

const std::string& Person::get_first_name() const {
	return first_name;
}

const std::string& Person::get_last_name() const {
	return last_name;
}
