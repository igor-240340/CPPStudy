#include <print>

#include "employee.h"

int main() {
	Employee employee;
	employee.first_initial = 'J';
	employee.last_initial = 'D';
	employee.employee_number = 42;
	employee.salary = 80000;

	std::println("Employee: {}{}", employee.first_initial, employee.last_initial);
	std::println("Number: {}", employee.employee_number);
	std::println("Salary: ${}", employee.salary);
}
