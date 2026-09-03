export module spreadsheet;

export import spreadsheet_cell;

import std;

export class Spreadsheet {
public:
	explicit Spreadsheet(std::size_t width = max_width, std::size_t height = max_height);
	Spreadsheet(const Spreadsheet& src);
	Spreadsheet(Spreadsheet&&) noexcept;
	~Spreadsheet();

	Spreadsheet& operator=(const Spreadsheet& rhs);
	Spreadsheet& operator=(Spreadsheet&&) noexcept;

	void set_cell_at(std::size_t x, std::size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& get_cell_at(std::size_t x, std::size_t y);
	const SpreadsheetCell& get_cell_at(std::size_t x, std::size_t y) const;

	std::size_t get_id() const;

	static constexpr std::size_t max_height = 100;
	static constexpr std::size_t max_width = 100;

	void swap(Spreadsheet& other) noexcept;

private:
	class Impl;
	std::unique_ptr<Impl> impl;
};

export void swap(Spreadsheet& first, Spreadsheet& second) noexcept;
