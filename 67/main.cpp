import double_spreadsheet_cell;
import string_spreadsheet_cell;

import std;

int main() {
	std::vector<std::unique_ptr<SpreadsheetCell>> cell_array;
	cell_array.push_back(std::make_unique<StringSpreadsheetCell>());
	cell_array.push_back(std::make_unique<StringSpreadsheetCell>());
	cell_array.push_back(std::make_unique<DoubleSpreadsheetCell>());

	cell_array[0]->set("hello");
	cell_array[1]->set("10");
	cell_array[2]->set("18");
	//cell_array[2]->set("hell");

	std::println("Vector: [{},{},{}]",
		cell_array[0]->get_string(),
		cell_array[1]->get_string(),
		cell_array[2]->get_string()
	);
}
