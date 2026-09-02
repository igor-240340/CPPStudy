module spreadsheet_cell;

import std;

using namespace std;

SpreadsheetCell::SpreadsheetCell(double initial_value) : value(initial_value) {}

SpreadsheetCell::SpreadsheetCell(string_view initial_value) : value(string_to_double(initial_value)) {}

void SpreadsheetCell::set(double value) {
	this->value = value;
}

double SpreadsheetCell::get_value() const {
	return value;
}

void SpreadsheetCell::set(string_view value) {
	this->value = string_to_double(value);
}

string SpreadsheetCell::get_string() const {
	return double_to_string(value);
}

string SpreadsheetCell::double_to_string(double value) {
	return to_string(value);
}

double SpreadsheetCell::string_to_double(string_view value) {
	double number = 0;
	from_chars(value.data(), value.data() + value.size(), number);
	return number;
}

SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
	SpreadsheetCell result(lhs);
	result += rhs;
	return result;

	//return SpreadsheetCell { lhs.get_value() + rhs.get_value() };
}

SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
	SpreadsheetCell result(lhs);
	result -= rhs;
	return result;

	//return SpreadsheetCell { lhs.get_value() - rhs.get_value() };
}

SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
	SpreadsheetCell result(lhs);
	result *= rhs;
	return result;

	//return SpreadsheetCell { lhs.get_value() * rhs.get_value() };
}

SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
	SpreadsheetCell result(lhs);
	result /= rhs;
	return result;

	//if (rhs.get_value() == 0) {
	//	throw invalid_argument { "Divide by zero." };
	//}
	//return SpreadsheetCell { lhs.get_value() / rhs.get_value() };
}

SpreadsheetCell& SpreadsheetCell::operator+=(const SpreadsheetCell& rhs) {
	set(get_value() + rhs.get_value());
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator-=(const SpreadsheetCell& rhs) {
	set(get_value() - rhs.get_value());
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator*=(const SpreadsheetCell& rhs) {
	set(get_value() * rhs.get_value());
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator/=(const SpreadsheetCell& rhs) {
	if (rhs.get_value() == 0) {
		throw invalid_argument{ "Divide by zero." };
	}
	set(get_value() / rhs.get_value());
	return *this;
}

bool SpreadsheetCell::operator==(double rhs) const {
	return get_value() == rhs;
}

partial_ordering SpreadsheetCell::operator<=>(double rhs) const {
	return get_value() <=> rhs;
}