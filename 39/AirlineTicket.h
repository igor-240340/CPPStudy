#pragma once

#include <string>
#include <optional>

class AirlineTicket {
public:
	AirlineTicket();
	~AirlineTicket();

	double calculate_price_in_dollars() const;

	const std::string& get_passenger_name() const;
	void set_passenger_name(const std::string& name);

	int get_number_of_miles() const;
	void set_number_of_miles(int miles);

	bool has_elite_super_rewards_status() const;
	void set_elite_super_rewards_status(bool status);

	void set_frequent_flyer_number(int number);
	std::optional<int> get_frequent_flyer_number();

private:
	std::string passenger_name{ "Unknown Passenger" };
	int number_of_miles{ 0 };
	bool elite_super_rewards_status{ false };
	std::optional<int> frequent_flyer_number;
};
