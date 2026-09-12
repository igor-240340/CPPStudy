export module weather_prediction;

import std;

export class WeatherPrediction {
public:
	virtual ~WeatherPrediction();

	virtual void set_current_temp_fahrenheit(int temp);
	virtual void set_position_of_jupiter(int distanceFromMars);
	virtual int get_tomorrow_temp_fahrenheit() const;
	virtual double get_chance_of_rain() const;
	virtual void show_result() const;
	virtual std::string get_temperature() const;

private:
	int current_temp_fahrenheit = 0;
	int distance_from_mars = 0;
};
