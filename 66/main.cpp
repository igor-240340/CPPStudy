import my_weather_prediction;
import std;

int main() {
	MyWeatherPrediction p;
	p.set_current_temp_celsius(33);
	p.set_position_of_jupiter(80);
	p.show_result();
	std::println("{}", p.get_temperature());
}
