module my_weather_prediction;

import std;

void MyWeatherPrediction::set_current_temp_celsius(int temp) {
	int fahrenheit_temp = convert_celsius_to_fahrenheit(temp);
	set_current_temp_fahrenheit(fahrenheit_temp);
}

int MyWeatherPrediction::get_tomorrow_temp_celsius() const {
	int fahrenheit_temp = get_tomorrow_temp_fahrenheit();
	return convert_fahrenheit_to_celsius(fahrenheit_temp);
}

void MyWeatherPrediction::show_result() const {
	std::println("Tomorrow will be {} degrees Celsius ({} degrees Fahrenheit)",
		get_tomorrow_temp_celsius(), get_tomorrow_temp_fahrenheit());

	std::println("Chance of rain is {}%", get_chance_of_rain() * 100);

	if (get_chance_of_rain() > 0.5) {
		std::println("Bring an umbrella!");
	}
}

int MyWeatherPrediction::convert_celsius_to_fahrenheit(int celsius) {
	return static_cast<int>((9.0 / 5.0) * celsius + 32);
}

int MyWeatherPrediction::convert_fahrenheit_to_celsius(int fahrenheit) {
	return static_cast<int>((5.0 / 9.0) * (fahrenheit - 32));
}

std::string MyWeatherPrediction::get_temperature() const {
	return WeatherPrediction::get_temperature() + "\u00B0F";
}
