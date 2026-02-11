#include <format>
#include <print>

#include "AirlineTicket.h"

int main() {
	AirlineTicket my_ticket;
	my_ticket.set_passenger_name("Sherman T. Socketwrench");
	my_ticket.set_number_of_miles(700);
	double cost{ my_ticket.calculate_price_in_dollars() };

	std::println("This ticket will cost ${}", cost);
}
