#pragma once

#include <string>

class AirlineTicket {
public:
	AirlineTicket();
	~AirlineTicket();

	double calculate_price_in_dollars();

	std::string get_passenger_name();
	void set_passenger_name(std::string name);

	int get_number_of_miles();
	void set_number_of_miles(int miles);

	bool has_elite_super_rewards_status();
	void set_elite_super_rewards_status(bool status);

private:
	std::string passenger_name{ "Unknown Passenger" };
	int number_of_miles{ 0 };
	bool elite_super_rewards_status{ false };
};
