export module my_weather_prediction;

import weather_prediction;
import std;

export class MyWeatherPrediction : public WeatherPrediction {
public:
	virtual void set_current_temp_celsius(int temp);
	virtual int get_tomorrow_temp_celsius() const;
	void show_result() const override;
	std::string get_temperature() const override;

private:
	static int convert_celsius_to_fahrenheit(int celsius);
	static int convert_fahrenheit_to_celsius(int fahrenheit);
};
