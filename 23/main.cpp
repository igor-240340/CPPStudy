#include <print>

struct Employee {
	char first_initial;
	char last_initial;
	int employee_number;
	int salary{ 75'000 };
};

int main() {
	Employee an_employee{ .first_initial = 'J',
						 .last_initial = 'D',
						 .employee_number = 42,
						 .salary = 80'000 };

	Employee an_employee2{ .first_initial = 'J',
						 .last_initial = 'D',
						 .salary = 80'000 };
	std::print("an_employee2.employee_number = {}\n", an_employee2.employee_number);

	Employee an_employee3{ .first_initial = 'J', .last_initial = 'D' };
	std::print("an_employee3.employee_number = {}\n", an_employee3.employee_number);
	std::print("an_employee3.salary = {}\n", an_employee3.salary);

	return 0;
}
