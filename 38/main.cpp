#include <iostream>
#include <print>

#include "Database.h"
#include "Employee.h"

using namespace Records;

int display_menu();
void do_hire(Database& db);
void do_fire(Database& db);
void do_promote(Database& db);

int main() {
	Database employee_db;

	bool done{ false };
	while (!done) {
		int selection{ display_menu() };

		switch (selection) {
		case 0:
			done = true;
			break;
		case 1:
			do_hire(employee_db);
			break;
		case 2:
			do_fire(employee_db);
			break;
		case 3:
			do_promote(employee_db);
			break;
		case 4:
			employee_db.display_all();
			break;
		case 5:
			employee_db.display_current();
			break;
		case 6:
			employee_db.display_former();
			break;
		default:
			std::println("Unknown command.");
			break;
		}
	}
}

int display_menu() {
	int selection;

	std::println("");
	std::println("Employee Database");
	std::println("-----------------");
	std::println("1) Hire a new employee");
	std::println("2) Fire an employee");
	std::println("3) Promote an employee");
	std::println("4) List all employees");
	std::println("5) List all current employees");
	std::println("6) List all former employees");
	std::println("0) Quit");
	std::println("");
	std::print("--->");

	std::cin >> selection;

	return selection;
}

void do_hire(Database& db) {
	std::string first_name;
	std::print("First name? ");
	std::cin >> first_name;

	std::string last_name;
	std::print("Last name? ");
	std::cin >> last_name;

	Employee& employee{ db.add_employee(first_name, last_name) };
	std::println("Hired employee {} {} with employee number {}.",
		first_name,
		last_name,
		employee.get_employee_number()
	);
}

void do_fire(Database& db) {
	int employee_number;

	std::print("Employee number? ");
	std::cin >> employee_number;
	try {
		Employee& emp{ db.get_employee(employee_number) };
		emp.fire();
		std::println("Employee {} terminated.", employee_number);
	}
	catch (const std::runtime_error& e) {
		std::println("Unable to terminate employee: {}", e.what());
	}
}

void do_promote(Database& db) {
	int employee_number;

	std::print("Employee number? ");
	std::cin >> employee_number;

	int raise_amount;
	std::print("How much of a raise? ");
	std::cin >> raise_amount;

	try {
		Employee& emp{ db.get_employee(employee_number) };
		emp.promote(raise_amount);
	}
	catch (const std::runtime_error& e) {
		std::println("Unable to promote employee: {}", e.what());
	}
}
