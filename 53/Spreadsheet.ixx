export module spreadsheet;
export import spreadsheet_cell;

import std;

export class Spreadsheet {
public:
	explicit Spreadsheet(std::size_t width = 100, std::size_t height = 100);
	//Spreadsheet(const Spreadsheet& src) = delete;
	Spreadsheet(const Spreadsheet& src);
	Spreadsheet(Spreadsheet&& src) noexcept;
	~Spreadsheet();

	//Spreadsheet& operator=(const Spreadsheet& rhs) = delete;
	Spreadsheet& operator=(const Spreadsheet& rhs);
	Spreadsheet& operator=(Spreadsheet&& rhs) noexcept;
	void swap(Spreadsheet& other) noexcept;

	void set_cell_at(std::size_t x, std::size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& get_cell_at(std::size_t x, std::size_t y);
	const SpreadsheetCell& get_cell_at(std::size_t x, std::size_t y) const;

private:
	SpreadsheetCell& get_cell_at_helper(std::size_t x, std::size_t y) const;
	void cleanup() noexcept;
	void move_from(Spreadsheet& src) noexcept;

	void verify_coordinate(std::size_t x, std::size_t y) const;
	std::size_t width = 0;
	std::size_t height = 0;
	SpreadsheetCell** cells = nullptr;
};

export void swap(Spreadsheet& first, Spreadsheet& second) noexcept;
