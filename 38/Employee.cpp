#include <string>
#include <print>

#include "Employee.h"

namespace Records {
	Employee::Employee(const std::string& first_name, const std::string& last_name) : first_name{ first_name }, last_name{ last_name } {
	}

	void Employee::promote(int raise_amount) {
		set_salary(get_salary() + raise_amount);
	}

	void Employee::demote(int demerit_amount) {
		set_salary(get_salary() - demerit_amount);
	}

	void Employee::hire() {
		hired = true;
	}

	void Employee::fire() {
		hired = false;
	}

	void Employee::display() const {
		std::println("Employee: {}, {}", get_last_name(), get_first_name());
		std::println("-----------------------------");
		std::println("{}", (is_hired() ? "Current Employee" : "Former Employee"));
		std::println("Employee Number: {}", get_employee_number());
		std::println("Salary: ${}", get_salary());
		std::println("");
	}

	void Employee::set_first_name(const std::string& first_name) {
		this->first_name = first_name;
	}

	const std::string& Employee::get_first_name() const {
		return first_name;
	}

	void Employee::set_last_name(const std::string& last_name) {
		this->last_name = last_name;
	}

	const std::string& Employee::get_last_name() const {
		return last_name;
	}

	void Employee::set_employee_number(int employee_number) {
		this->employee_number = employee_number;
	}

	int Employee::get_employee_number() const {
		return employee_number;
	}

	void Employee::set_salary(int salary) {
		this->salary = salary;
	}

	int Employee::get_salary() const {
		return salary;
	}

	bool Employee::is_hired() const {
		return hired;
	}
}
