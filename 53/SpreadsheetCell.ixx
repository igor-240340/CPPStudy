export module spreadsheet_cell;

import std;

export class SpreadsheetCell {
public:
	SpreadsheetCell() = default;
	SpreadsheetCell(double initial_value);
	SpreadsheetCell(std::string_view initial_value);

	void set_value(double value);
	double get_value() const;

	void set_string(std::string_view value);
	std::string get_string() const;

private:
	std::string double_to_string(double value) const;
	double string_to_double(std::string_view value) const;
	double value{ 0 };
};

/*
export class SpreadsheetCell {
public:
	void set_value(double value) {
		this->value = value;
	};
	double get_value() const {
		return value;
	};

private:
	double value{ 0 };
};
*/
