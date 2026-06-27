import spreadsheet_cell;
import std;

void on_stack();
void on_freestore();

int main() {
	on_stack();
	on_freestore();
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
