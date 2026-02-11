#include <print>

struct Employee {
	char first_initial;
	char last_initial;
	int employee_number;
	int salary{ 75'000 };
};

void example_1();
void example_2();
void example_3();

int main() {
	example_1();
	example_2();
	example_3();

	return 0;
}

void example_1() {
	int* my_integer_pointer{ nullptr };
	my_integer_pointer = new int;

	*my_integer_pointer = 8;
	std::println("my_integer_pointer = {}", *my_integer_pointer);

	delete my_integer_pointer;
	my_integer_pointer = nullptr;
}

void example_2() {
	int i = 3;
	int* my_integer_pointer{ &i };
	std::println("my_integer_pointer = {}", *my_integer_pointer);
}

void example_3() {
	Employee* an_employee{ new Employee{'J', 'D', 42, 80'000} };
	std::println("(*an_employee).salary = {}", (*an_employee).salary);
	std::println("an_employee->salary = {}", an_employee->salary);
	delete an_employee;
	an_employee = nullptr;
}
