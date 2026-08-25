import spreadsheet_cell;

using namespace std;

int main() {
	SpreadsheetCell my_cell(5);
	my_cell.set_color(SpreadsheetCell::Color::blue);
	SpreadsheetCell::Color color = my_cell.get_color();
}