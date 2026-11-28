import datamodel; // Импорт всего модуля datamodel (оба подмодуля сразу).

import std;

int main() {
	DataModel::Person person("Kole", "Webb");
	DataModel::Address address; // Печатает Address::Address().
	DataModel::Persons persons;
	persons.push_back(person);

	std::println("{}, {}", persons[0].get_last_name(), persons[0].get_first_name());
}
