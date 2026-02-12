#pragma once

#include <string>
#include <vector>

#include "Employee.h"

namespace Records {
	const int first_employee_number{ 1'000 };

	class Database {
	public:
		Employee& add_employee(const std::string& first_name, const std::string& last_name);
		Employee& get_employee(int employee_number);
		Employee& get_employee(const std::string& first_name, const std::string& last_name);

		void display_all() const;
		void display_current() const;
		void display_former() const;

	private:
		std::vector<Employee> employees;
		int next_employee_number{ first_employee_number };
	};
}
