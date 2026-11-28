export module datamodel.person; // Подмодуль datamodel.person.

import std;

export namespace DataModel {
	class Person {
	public:
		Person(std::string first_name, std::string last_name)
			: first_name(std::move(first_name)), last_name(std::move(last_name)) {}

		const std::string& get_first_name() const { return first_name; }
		const std::string& get_last_name() const { return last_name; }

	private:
		std::string first_name;
		std::string last_name;
	};
}
