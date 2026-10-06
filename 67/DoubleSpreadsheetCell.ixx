export module double_spreadsheet_cell;
import spreadsheet_cell;

import std;

export class DoubleSpreadsheetCell : public SpreadsheetCell {
public:
	virtual void set(double value) {
		this->value = value;
	};
	virtual double get_value() const {
		return value.value_or(0.0); 
	};

	void set(std::string_view value) override {
		this->value = string_to_double(value);
	};
	std::string get_string() const override { 
		return value.has_value() ? double_to_string(value.value()) : "";
	};

private:
	static std::string double_to_string(double value) {
		return std::to_string(value);
	};
	static double string_to_double(std::string_view value) {
		double number = 0.0;
		std::from_chars(value.data(), value.data() + value.size(), number);
		return number;
	};

	std::optional<double> value;
};
