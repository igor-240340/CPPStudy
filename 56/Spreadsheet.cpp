module spreadsheet;

import std;

Spreadsheet::Spreadsheet(size_t width, size_t height, const SpreadsheetApplication& app)
: id(counter++)
, width(std::min(width, max_width))
, height(std::min(height, max_height))
, app(app) {
	cells = new Cell*[width];
	for (size_t i{ 0 }; i < width; i++) {
		cells[i] = new Cell[height];
	}
}

Spreadsheet::~Spreadsheet() {
	for (size_t i{ 0 }; i < width; i++) {
		delete[] cells[i];
	}
	delete[] cells;
	cells = nullptr;
}

Spreadsheet::Spreadsheet(const Spreadsheet& src) : Spreadsheet(src.width, src.height, src.app) {
	for (size_t i{ 0 }; i < width; i++) {
		for (size_t j{ 0 }; j < height; j++) {
			cells[i][j] = src.cells[i][j];
		}
	}
}

void Spreadsheet::verify_coordinate(size_t x, size_t y) const {
	if (x >= width) {
		throw std::out_of_range(std::format("x ({}) must be less than width ({}).", x, width));
	}
	if (y >= height) {
		throw std::out_of_range(std::format("y ({}) must be less than height ({}).", y, height));
	}
}

void Spreadsheet::set_cell_at(size_t x, size_t y, const Cell& cell) {
	verify_coordinate(x, y);
	cells[x][y] = cell;
}

const Spreadsheet::Cell& Spreadsheet::get_cell_at(size_t x, size_t y) const {
	verify_coordinate(x, y);
	return cells[x][y];
}

Spreadsheet::Cell& Spreadsheet::get_cell_at(size_t x, size_t y) {
	return const_cast<Spreadsheet::Cell&>(std::as_const(*this).get_cell_at(x, y));
}

void Spreadsheet::swap(Spreadsheet& other) noexcept {
	std::swap(width, other.width);
	std::swap(height, other.height);
	std::swap(cells, other.cells);
}

void swap(Spreadsheet& first, Spreadsheet& second) noexcept {
	first.swap(second);
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs) {
	// Copy-and-swap idiom
	Spreadsheet temp(rhs);
	swap(temp);
	return *this;
}

size_t Spreadsheet::get_id() const {
	return id;
}

Spreadsheet::Cell::Cell(double initial_value) : value(initial_value) {
}

Spreadsheet::Cell::Cell(std::string_view initial_value) : value(string_to_double(initial_value)) {
}

void Spreadsheet::Cell::set(double value) {
	value = value;
}

double Spreadsheet::Cell::get_value() const {
	return value;
}

void Spreadsheet::Cell::set(std::string_view value) {
	this->value = string_to_double(value);
}

std::string Spreadsheet::Cell::get_string() const
{
	return double_to_string(value);
}

std::string Spreadsheet::Cell::double_to_string(double value) const {
	return std::to_string(value);
}

double Spreadsheet::Cell::string_to_double(std::string_view value) const {
	double number = 0;
	std::from_chars(value.data(), value.data() + value.size(), number);
	return number;
}