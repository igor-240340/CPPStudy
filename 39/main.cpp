#include <print>
#include <array>
#include <string>
#include <vector>

#include "AirlineTicket.h"

namespace HR {
	enum class Title { manager, engineer, senior_engineer };

	struct Employee {
		std::string first_name;
		std::string last_name;
		int employee_number;
		int salary{ 75'000 };
		Title title;
	};
}

using namespace HR;

void print_employee_title(const Employee& employee);

void airline_ticket_mod();

int main() {
	Employee employee1{ .first_name = "John",
					   .last_name = "Doe",
					   .employee_number = 42,
					   .salary = 80'000,
					   .title = static_cast<Title>(198) };
	Employee employee2{ .first_name = "Jane",
					   .last_name = "Doe",
					   .salary = 80'000,
					   .title = Title::engineer };
	Employee employee3{ .first_name = "Jeffrey", .last_name = "Doe" };

	std::array<Employee, 3> employees1{ employee1, employee2, employee3 };
	for (Employee e : employees1)
		print_employee_title(e);

	std::vector<Employee> employees2;
	employees2.push_back(employee1);
	employees2.push_back(employee2);
	employees2.push_back(employee3);

	std::println("===");

	for (Employee e : employees2) {
		std::println("{} {}", e.first_name, e.last_name);
		print_employee_title(e);
		std::println("");
	}

	airline_ticket_mod();

	return 0;
}

void print_employee_title(const Employee& employee) {
	switch (employee.title) {
	case Title::manager:
		std::println("Manager");
		break;
	case Title::engineer:
		std::println("Engineer");
		break;
	case Title::senior_engineer:
		std::println("Senior Engineer");
		break;
	default:
		std::println("Invalid title: {}", static_cast<int>(employee.title));
		break;
	}
}

void airline_ticket_mod() {
	AirlineTicket ticket1;
	ticket1.set_passenger_name("Sherman T. Socketwrench");
	ticket1.set_number_of_miles(700);
	double cost{ ticket1.calculate_price_in_dollars() };

	std::println("This ticket will cost ${}", cost);
	std::optional<int> frequent_flyer_number1 = ticket1.get_frequent_flyer_number();
	if (frequent_flyer_number1)
		std::println("frequent-flyer number {}", frequent_flyer_number1.value());

	AirlineTicket ticket2;
	ticket2.set_frequent_flyer_number(123);

	std::optional<int> frequent_flyer_number2 = ticket2.get_frequent_flyer_number();
	if (frequent_flyer_number2)
		std::println("frequent-flyer number {}", frequent_flyer_number2.value());
}
