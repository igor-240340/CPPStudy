export module spreadsheet;

import std;

export class SpreadsheetApplication {};

export class Spreadsheet {
public:
	class Cell;

	Spreadsheet(std::size_t width, std::size_t height, const SpreadsheetApplication& app);
	Spreadsheet(const Spreadsheet& src);
	~Spreadsheet();
	Spreadsheet& operator=(const Spreadsheet& rhs);

	void set_cell_at(std::size_t x, std::size_t y, const Cell& cell);
	Cell& get_cell_at(std::size_t x, std::size_t y);
	const Cell& get_cell_at(std::size_t x, std::size_t y) const;

	std::size_t get_id() const;

	void swap(Spreadsheet& other) noexcept;

	static constexpr std::size_t max_height = 100;
	static constexpr std::size_t max_width = 100;

private:
	void verify_coordinate(std::size_t x, std::size_t y) const;

	std::size_t id = 0;
	std::size_t width = 0;
	std::size_t height = 0;
	Cell** cells = nullptr;

	const SpreadsheetApplication& app;

	inline static std::size_t counter = 0;
};

class Spreadsheet::Cell {
public:
	Cell() = default;
	Cell(double initial_value);
	Cell(std::string_view initial_value);

	void set(double value);
	void set(std::string_view value);

	double get_value() const;
	std::string get_string() const;

private:
	std::string double_to_string(double value) const;
	double string_to_double(std::string_view value) const;

	double value = 0;
};

export void swap(Spreadsheet& first, Spreadsheet& second) noexcept;
