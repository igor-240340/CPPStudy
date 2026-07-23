export module spreadsheet;
export import spreadsheet_cell;

import std;

export class Spreadsheet {
public:
	Spreadsheet(std::size_t width, std::size_t height);
	~Spreadsheet();

	void set_cell_at(std::size_t x, std::size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& get_cell_at(std::size_t x, std::size_t y);

private:
	void verify_coordinate(std::size_t x, std::size_t y) const;
	std::size_t width = 0;
	std::size_t height = 0;
	SpreadsheetCell** cells = nullptr;
};
