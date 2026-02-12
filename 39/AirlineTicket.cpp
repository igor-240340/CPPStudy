#include "AirlineTicket.h"

AirlineTicket::AirlineTicket() {}

AirlineTicket::~AirlineTicket() {}

double AirlineTicket::calculate_price_in_dollars() const {
	if (has_elite_super_rewards_status())
		return 0;

	return get_number_of_miles() * 0.1;
}

const std::string& AirlineTicket::get_passenger_name() const {
	return passenger_name;
}

void AirlineTicket::set_passenger_name(const std::string& name) {
	passenger_name = name;
}

void AirlineTicket::set_frequent_flyer_number(int number) {
	frequent_flyer_number = number;
}

std::optional<int> AirlineTicket::get_frequent_flyer_number() {
	return frequent_flyer_number;
}

int AirlineTicket::get_number_of_miles() const {
	return number_of_miles;
}

void AirlineTicket::set_number_of_miles(int miles) {
	number_of_miles = miles;
}

bool AirlineTicket::has_elite_super_rewards_status() const {
	return elite_super_rewards_status;
}

void AirlineTicket::set_elite_super_rewards_status(bool status) {
	elite_super_rewards_status = status;
}
