#pragma once

#include <string>

namespace Records {
	const int default_starting_salary{ 30'000 };
	const int default_raise_and_demerit_amount{ 1'000 };

	class Employee {
	public:
		Employee(const std::string& first_name, const std::string& last_name);

		void promote(int raise_amount = default_raise_and_demerit_amount);
		void demote(int demerit_amount = default_raise_and_demerit_amount);
		void hire();
		void fire();
		void display() const;

		void set_first_name(const std::string& first_name);
		const std::string& get_first_name() const;
		void set_last_name(const std::string& last_name);
		const std::string& get_last_name() const;
		void set_employee_number(int employee_number);
		int get_employee_number() const;
		void set_salary(int new_salary);
		int get_salary() const;
		bool is_hired() const;

	private:
		std::string first_name;
		std::string last_name;
		int employee_number{ -1 };
		int salary{ default_starting_salary };
		bool hired{ false };
	};
}

