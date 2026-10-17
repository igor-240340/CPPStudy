export module string_spreadsheet_cell;
export import spreadsheet_cell;
export import double_spreadsheet_cell;
import std;

export class StringSpreadsheetCell : public SpreadsheetCell {
public:
    StringSpreadsheetCell() = default;
    StringSpreadsheetCell(const DoubleSpreadsheetCell& cell) : value(cell.get_string()) {};

	void set(std::string_view value) override {
        this->value = value;
    };

    std::string get_string() const override {
        return value.value_or("");
    };

private:
    std::optional<std::string> value;
};

export StringSpreadsheetCell operator+(const StringSpreadsheetCell& lhs, const StringSpreadsheetCell& rhs) {
    StringSpreadsheetCell new_cell;
    new_cell.set(lhs.get_string() + rhs.get_string());
    return new_cell;
}
