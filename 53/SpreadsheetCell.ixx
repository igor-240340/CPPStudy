export module SpreadsheetCell;

export class SpreadsheetCell {
public:
	void set_value(double value);
	double get_value() const;

private:
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
