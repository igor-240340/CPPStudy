export module string_spreadsheet_cell;
export import spreadsheet_cell;
import std;

export class StringSpreadsheetCell : public SpreadsheetCell {
public:
	void set(std::string_view value) override {
        this->value = value;
    };

    std::string get_string() const override {
        return value.value_or("");
    };

private:
    std::optional<std::string> value;
};
