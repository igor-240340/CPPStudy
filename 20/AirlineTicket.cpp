#include "AirlineTicket.h"

AirlineTicket::AirlineTicket() {}

AirlineTicket::~AirlineTicket() {}

double AirlineTicket::calculate_price_in_dollars() {
	if (has_elite_super_rewards_status())
		return 0;

	return get_number_of_miles() * 0.1;
}

std::string AirlineTicket::get_passenger_name() {
	return passenger_name;
}

void AirlineTicket::set_passenger_name(std::string name) {
	passenger_name = name;
}

int AirlineTicket::get_number_of_miles() {
	return number_of_miles;
}

void AirlineTicket::set_number_of_miles(int miles) {
	number_of_miles = miles;
}

bool AirlineTicket::has_elite_super_rewards_status() {
	return elite_super_rewards_status;
}

void AirlineTicket::set_elite_super_rewards_status(bool status) {
	elite_super_rewards_status = status;
}
