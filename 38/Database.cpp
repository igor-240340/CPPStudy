#include <string>
#include <stdexcept>

#include "Database.h"
#include "Employee.h"

namespace Records {
	Employee& Database::add_employee(const std::string& first_name, const std::string& last_name) {
		Employee the_employee{ first_name, last_name };
		the_employee.set_employee_number(next_employee_number++);
		the_employee.hire();
		employees.push_back(the_employee);
		return employees.back();
	}

	Employee& Database::get_employee(int employee_number) {
		for (auto& employee : employees) {
			if (employee.get_employee_number() == employee_number)
				return employee;
		}
		throw std::runtime_error{ "No employee found." };
	}

	Employee& Database::get_employee(const std::string& first_name, const std::string& last_name) {
		for (auto& employee : employees) {
			if (employee.get_first_name() == first_name && employee.get_last_name() == last_name)
				return employee;
		}
		throw std::runtime_error{ "No employee found." };
	}

	void Database::display_all() const {
		for (const auto& employee : employees)
			employee.display();
	}

	void Database::display_current() const {
		for (const auto& employee : employees) {
			if (employee.is_hired())
				employee.display();
		}
	}

	void Database::display_former() const {
		for (const auto& employee : employees) {
			if (!employee.is_hired())
				employee.display();
		}
	}
}
