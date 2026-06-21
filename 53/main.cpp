import spreadsheet_cell;
import std;

void on_stack();
void on_freestore();

int main() {
	on_stack();
	on_freestore();
}

void on_stack() {
	SpreadsheetCell my_cell, another_cell;
	my_cell.set_value(6);
	another_cell.set_string("3.2");

	std::println("cell 1: {}", my_cell.get_value());
	std::println("cell 2: {}", another_cell.get_value());

	std::println("cell 1: {}", my_cell.get_string());
	std::println("cell 2: {}", another_cell.get_string());
}

void on_freestore() {
	SpreadsheetCell* my_cell_p{ new SpreadsheetCell{} };

	my_cell_p->set_value(3.7);
	std::println("cell 1: {} {}", my_cell_p->get_value(), my_cell_p->get_string());
	delete my_cell_p;
	my_cell_p = nullptr;
}
