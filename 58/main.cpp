import spreadsheet_cell;
import std;

using namespace std;

int main()
{
	SpreadsheetCell my_cell(4), another_cell(5);
	SpreadsheetCell a_third_cell{ my_cell + another_cell };
	//SpreadsheetCell a_third_cell{ my_cell.operator+(another_cell) };
	auto a_fourth_cell(a_third_cell + another_cell);
	println("{}", a_third_cell.get_value());

	string str("hello");
	a_third_cell = my_cell + string_view(str);

	a_third_cell = my_cell + 5.6;
	a_third_cell = my_cell + 4;

	// The following two lines don't compile
	// a_third_cell = 5.6 + my_cell; // FAILS TO COMPILE!
	// a_third_cell = 4 + my_cell;   // FAILS TO COMPILE!
}