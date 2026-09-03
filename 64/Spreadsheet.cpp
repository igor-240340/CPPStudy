module spreadsheet;

import std;

class Spreadsheet::Impl {
public:
	Impl(size_t width, size_t height);
	Impl(const Impl& src);
	Impl(Impl&&) noexcept = default;
	~Impl();
	Impl& operator=(const Impl& rhs);
	Impl& operator=(Impl&&) noexcept = default;

	void set_cell_at(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& get_cell_at(size_t x, size_t y);
	const SpreadsheetCell& get_cell_at(size_t x, size_t y) const;

	size_t get_id() const;

	void swap(Impl& other) noexcept;

private:
	void verify_coordinate(size_t x, size_t y) const;

	const size_t id = 0;
	size_t width = 0;
	size_t height = 0;
	SpreadsheetCell** cells = nullptr;

	static inline size_t counter = 0;
};

Spreadsheet::Impl::Impl(size_t width, size_t height)
: id(counter++)
, width(std::min(width, Spreadsheet::max_width))
, height(std::min(height, Spreadsheet::max_height)) {
	cells = new SpreadsheetCell*[width];
	for (size_t i = 0; i < width; i++) {
		cells[i] = new SpreadsheetCell[height];
	}
}

Spreadsheet::Impl::~Impl() {
	for (size_t i = 0; i < width; i++) {
		delete[] cells[i];
	}
	delete[] cells;
	cells = nullptr;
}

Spreadsheet::Impl::Impl(const Impl& src) : Impl(src.width, src.height) {
	// The ctor-initializer of this constructor delegates first to the
	// non-copy constructor to allocate the proper amount of memory.

	// The next step is to copy the data.
	for (size_t i = 0; i < width; i++) {
		for (size_t j = 0; j < height; j++) {
			cells[i][j] = src.cells[i][j];
		}
	}
}

void Spreadsheet::Impl::verify_coordinate(size_t x, size_t y) const {
	if (x >= width) {
		throw std::out_of_range(std::format("x ({}) must be less than width ({}).", x, width));
	}
	if (y >= height) {
		throw std::out_of_range(std::format("y ({}) must be less than height ({}).", y, height));
	}
}

void Spreadsheet::Impl::set_cell_at(size_t x, size_t y, const SpreadsheetCell& cell) {
	verify_coordinate(x, y);
	cells[x][y] = cell;
}

const SpreadsheetCell& Spreadsheet::Impl::get_cell_at(size_t x, size_t y) const {
	verify_coordinate(x, y);
	return cells[x][y];
}

SpreadsheetCell& Spreadsheet::Impl::get_cell_at(size_t x, size_t y) {
	return const_cast<SpreadsheetCell&>(std::as_const(*this).get_cell_at(x, y));
}

void Spreadsheet::Impl::swap(Impl& other) noexcept {
	std::swap(width, other.width);
	std::swap(height, other.height);
	std::swap(cells, other.cells);
}

Spreadsheet::Impl& Spreadsheet::Impl::operator=(const Impl& rhs) {
	// Copy-and-swap idiom
	Impl temp(rhs); // Do all the work in a temporary instance
	swap(temp); // Commit the work with only non-throwing operations
	return *this;
}

size_t Spreadsheet::Impl::get_id() const {
	return id;
}

Spreadsheet::Spreadsheet(size_t width, size_t height) : impl(std::make_unique<Impl>(width, height)) {}

Spreadsheet::Spreadsheet(const Spreadsheet& src) : impl(std::make_unique<Impl>(*src.impl)) {}

Spreadsheet::~Spreadsheet() = default;
Spreadsheet::Spreadsheet(Spreadsheet&&) noexcept = default;
Spreadsheet& Spreadsheet::operator=(Spreadsheet&&) noexcept = default;

void Spreadsheet::set_cell_at(size_t x, size_t y, const SpreadsheetCell& cell) {
	impl->set_cell_at(x, y, cell);
}

const SpreadsheetCell& Spreadsheet::get_cell_at(size_t x, size_t y) const {
	return impl->get_cell_at(x, y);
}

SpreadsheetCell& Spreadsheet::get_cell_at(size_t x, size_t y) {
	return impl->get_cell_at(x, y);
}

size_t Spreadsheet::get_id() const {
	return impl->get_id();
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs) {
	*impl = *rhs.impl;
	return *this;
}

void Spreadsheet::swap(Spreadsheet& other) noexcept {
	std::swap(impl, other.impl);
}

void swap(Spreadsheet& first, Spreadsheet& second) noexcept {
	first.swap(second);
}
