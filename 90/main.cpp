import person;
import std;

int main() {
	Person person("Kole", "Webb");
	std::println("{}, {}", person.get_last_name(), person.get_first_name());
}
