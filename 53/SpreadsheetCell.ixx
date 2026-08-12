export module spreadsheet_cell;

import std;

export class SpreadsheetCell {
public:
	SpreadsheetCell() = default;
	SpreadsheetCell(double initial_value);
	explicit SpreadsheetCell(std::string_view initial_value);
	SpreadsheetCell(const SpreadsheetCell& src);

	void set(double value);
	void set(std::string_view value);

	double get_value() const;
	std::string get_string() const;

public:
	//SpreadsheetCell& operator=(const SpreadsheetCell& rhs) = default;
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);

private:
	static std::string double_to_string(double value);
	static double string_to_double(std::string_view value);

private:
	double value = 0;
	mutable unsigned int num_accesses = 0;
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
