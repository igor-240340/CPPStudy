export module SpreadsheetCell;

export class SpreadsheetCell {
public:
	void set_value(double value);
	double get_value() const;

private:
	double value{ 0 };
};
