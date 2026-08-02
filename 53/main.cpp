import spreadsheet_cell;
import spreadsheet;
import std;

void on_stack();
void on_freestore();
void multiple_ctors();
void default_ctor();
void explicit_ctor();

Spreadsheet create_object() {
	return Spreadsheet(3, 2);
}
void move_ops();

int main() {
	//on_stack();
	//on_freestore();
	//multiple_ctors();
	//default_ctor();
	//explicit_ctor();
	move_ops();
}

void on_stack() {
	SpreadsheetCell my_cell{ 5 }, another_cell{ 4 };
	
	std::println("cell 1: {}", my_cell.get_value());
	std::println("cell 2: {}", another_cell.get_value());

	std::println("cell 1: {}", my_cell.get_string());
	std::println("cell 2: {}", another_cell.get_string());
}

void on_freestore() {
	std::unique_ptr<SpreadsheetCell> smart_cell_p{ std::make_unique<SpreadsheetCell>(4) };

	SpreadsheetCell* my_cell_p{ new SpreadsheetCell{ 5 } };

	SpreadsheetCell* another_cell_p{ nullptr };
	another_cell_p = new SpreadsheetCell{ 4 };
	delete my_cell_p;
	my_cell_p = nullptr;
	delete another_cell_p;
	another_cell_p = nullptr;
}

void multiple_ctors() {
	SpreadsheetCell a_third_cell{ "test" };
	SpreadsheetCell a_fourth_cell{ 4.4 };
	std::unique_ptr<SpreadsheetCell> a_fifth_cell_p{ std::make_unique<SpreadsheetCell>("5.5") };
	std::println("a_third_cell: {}", a_third_cell.get_value());
	std::println("a_fourth_cell: {}", a_fourth_cell.get_value());
	std::println("a_fifth_cell_p: {}", a_fifth_cell_p->get_value());
}

void default_ctor() {
	//SpreadsheetCell my_cell(); // Объявление функции, а не вызов дефолтного конструктора.
	SpreadsheetCell my_cell{};
	my_cell.set_value(6);
	std::println("cell 1: {}", my_cell.get_value());

	SpreadsheetCell cells[3];
	SpreadsheetCell* my_cell_p{ new SpreadsheetCell[10] };

	std::unique_ptr<SpreadsheetCell> smart_cell_p{ std::make_unique<SpreadsheetCell>() };
	// Or with a raw pointer (not recommended)
	SpreadsheetCell* myCellp{ new SpreadsheetCell{} };
	// Or
	// SpreadsheetCell* my_cell_p { new SpreadsheetCell };
	// Or
	// SpreadsheetCell* my_cell_p { new SpreadsheetCell() };
	// ... use my_cell_p
	delete my_cell_p;
	my_cell_p = nullptr;
}

void explicit_ctor() {
	using namespace std::literals::string_view_literals;

	SpreadsheetCell my_cell{ 4 };
	std::println("my_cell = {}", my_cell.get_value());
	my_cell = 5;
	std::println("my_cell = {}", my_cell.get_value());
	//my_cell = "6"sv; // Не скомпилируется.
	//std::println("my_cell = {}", my_cell.get_value());
}

void move_ops() {
	std::vector<Spreadsheet> vec;
	for (size_t i = 0; i < 2; i++) {
		std::println("Iteration {}", i);
		vec.push_back(Spreadsheet(100, 100));
		std::println("");
	}

	Spreadsheet s(2, 3);
	s = create_object();

	std::println("");

	Spreadsheet s2(5, 6);
	s2 = s;
}
