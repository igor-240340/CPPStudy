module weather_prediction;

import std;

WeatherPrediction::~WeatherPrediction() {}

void WeatherPrediction::set_current_temp_fahrenheit(int temp) {
	current_temp_fahrenheit = temp;
}

void WeatherPrediction::set_position_of_jupiter(int distanceFromMars) {
	distance_from_mars = distanceFromMars;
}

int WeatherPrediction::get_tomorrow_temp_fahrenheit() const {
	return (distance_from_mars / 1000) + current_temp_fahrenheit;
}

double WeatherPrediction::get_chance_of_rain() const {
	return 0.5;
}

void WeatherPrediction::show_result() const {
	std::println("Result: {} chance.  Temp. {}", get_chance_of_rain() * 100, get_tomorrow_temp_fahrenheit());
}

std::string WeatherPrediction::get_temperature() const {
	return std::to_string(current_temp_fahrenheit);
}
