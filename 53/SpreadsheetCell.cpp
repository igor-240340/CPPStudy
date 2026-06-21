module spreadsheet_cell;

import std;

void SpreadsheetCell::set_value(double value) {
	this->value = value;
}

double SpreadsheetCell::get_value() const {
	return value;
}

void SpreadsheetCell::set_string(std::string_view string_value) {
	value = string_to_double(string_value);
}

std::string SpreadsheetCell::get_string() const {
	return double_to_string(value);
}

std::string SpreadsheetCell::double_to_string(double value) const {
	return std::to_string(value);
}

double SpreadsheetCell::string_to_double(std::string_view value) const {
	double number{ 0 };
	std::from_chars(value.data(), value.data() + value.size(), number);
	return number;
}
