module spreadsheet_cell;

import std;

SpreadsheetCell::SpreadsheetCell(double initial_value) : value{ initial_value } {}

SpreadsheetCell::SpreadsheetCell(std::string_view initial_value) : value(string_to_double(initial_value)) {}

void SpreadsheetCell::set(double value) {
	this->value = value;
}

double SpreadsheetCell::get_value() const {
	return value;
}

void SpreadsheetCell::set(std::string_view value) {
	this->value = string_to_double(value);
}

std::string SpreadsheetCell::get_string() const {
	return double_to_string(value);
}

std::string SpreadsheetCell::double_to_string(double value) {
	return std::to_string(value);
}

double SpreadsheetCell::string_to_double(std::string_view value) {
	double number = 0;
	std::from_chars(value.data(), value.data() + value.size(), number);
	return number;
}

void SpreadsheetCell::set_color(Color color) {
	this->color = color;
}

SpreadsheetCell::Color SpreadsheetCell::get_color() const {
	return color;
}
