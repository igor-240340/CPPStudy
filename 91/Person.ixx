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
