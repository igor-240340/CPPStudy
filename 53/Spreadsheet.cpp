module spreadsheet;

import std;

Spreadsheet::Spreadsheet(std::size_t width, std::size_t height)
: id(counter++), width(std::min(width, max_width)), height(std::min(height, max_height)) {
	std::println("Normal constructor");

	cells = new SpreadsheetCell*[width];
	for (std::size_t i = 0; i < width; i++) {
		cells[i] = new SpreadsheetCell[height];
	}
}

Spreadsheet::Spreadsheet(const Spreadsheet& src) : Spreadsheet(src.width, src.height) {
	std::println("Copy constructor");

	for (size_t i = 0; i < width; i++) {
		for (size_t j = 0; j < height; j++) {
			cells[i][j] = src.cells[i][j];
		}
	}
}

Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept {
	std::println("Move constructor");
	swap(src);
}

Spreadsheet::~Spreadsheet() {
	for (size_t i = 0; i < width; i++) {
		delete[] cells[i];
	}
	
	delete[] cells;
	cells = nullptr;
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs) {
	std::println("Copy assignment operator");

	Spreadsheet temp(rhs);
	swap(temp);
	return *this;
}

Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept {
	std::println("Move assignment operator");

	Spreadsheet moved = std::move(rhs);
	swap(moved);
	return *this;
}

void Spreadsheet::swap(Spreadsheet& other) noexcept {
	std::swap(width, other.width);
	std::swap(height, other.height);
	std::swap(cells, other.cells);
}

void Spreadsheet::set_cell_at(std::size_t x, std::size_t y, const SpreadsheetCell& cell) {
	verify_coordinate(x, y);
	cells[x][y] = cell;
}

//SpreadsheetCell& Spreadsheet::get_cell_at(std::size_t x, std::size_t y) {
//	return const_cast<SpreadsheetCell&>(std::as_const(*this).get_cell_at(x, y));
//}

SpreadsheetCell& Spreadsheet::get_cell_at(std::size_t x, std::size_t y) {
	return get_cell_at_helper(x, y);
}

//const SpreadsheetCell& Spreadsheet::get_cell_at(std::size_t x, std::size_t y) const {
//	verify_coordinate(x, y);
//	return cells[x][y];
//}

const SpreadsheetCell& Spreadsheet::get_cell_at(std::size_t x, std::size_t y) const {
	return get_cell_at_helper(x, y);
}

std::size_t Spreadsheet::get_id() const {
	return std::size_t();
}

SpreadsheetCell& Spreadsheet::get_cell_at_helper(std::size_t x, std::size_t y) const {
	verify_coordinate(x, y);
	return cells[x][y];
}

void Spreadsheet::cleanup() noexcept {
	for (size_t i = 0; i < width; i++) {
		delete[] cells[i];
	}
	delete[] cells;

	cells = nullptr;
	width = height = 0;
}

void Spreadsheet::move_from(Spreadsheet& src) noexcept {
	width = std::exchange(src.width, 0);
	height = std::exchange(src.height, 0);
	cells = std::exchange(src.cells, nullptr);
}

void Spreadsheet::verify_coordinate(std::size_t x, std::size_t y) const {
	if (x >= width) {
		throw std::out_of_range{ std::format("x ({}) must be less than  width ({}).", x, width) };
	}
	if (y >= height) {
		throw std::out_of_range{ std::format("y ({}) must be less than height ({}).", x, height) };
	}
}

void swap(Spreadsheet& first, Spreadsheet& second) noexcept {
	first.swap(second);
}