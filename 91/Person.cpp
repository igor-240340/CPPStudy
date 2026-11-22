module person; // Какому модулю принадлежит данная реализация.

// Импорт std не нужен: файл реализации — часть модуля person,
// поэтому он неявно наследует import std из файла интерфейса.

Person::Person(std::string first_name, std::string last_name)
	: first_name(std::move(first_name)), last_name(std::move(last_name)) {}

const std::string& Person::get_first_name() const {
	return first_name;
}

const std::string& Person::get_last_name() const {
	return last_name;
}
