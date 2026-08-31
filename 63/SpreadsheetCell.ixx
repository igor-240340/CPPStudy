export module spreadsheet_cell;

import std;

export class SpreadsheetCell {
public:
	SpreadsheetCell() = default;
	SpreadsheetCell(double initial_value);
	SpreadsheetCell(std::string_view initial_value);

	void set(double value);
	void set(std::string_view value);

	double get_value() const;
	std::string get_string() const;

	SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);

	[[nodiscard]] auto operator<=>(const SpreadsheetCell&) const = default;
	[[nodiscard]] bool operator==(const SpreadsheetCell&) const = default;

	[[nodiscard]] bool operator==(double rhs) const;
	[[nodiscard]] std::partial_ordering operator<=>(double rhs) const;

private:
	static std::string double_to_string(double value);
	static double string_to_double(std::string_view value);

	double value = 0;
};

export SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
export SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
export SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
export SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
