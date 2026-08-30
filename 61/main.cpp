import spreadsheet_cell;
import std;

using namespace std;

int main() {
	SpreadsheetCell my_cell(4), another_cell(5);
	SpreadsheetCell a_third_cell(my_cell + another_cell);

	string str("hello");
	a_third_cell = my_cell + string_view(str);

	a_third_cell = my_cell + 5.6;
	a_third_cell = my_cell + 4;

	a_third_cell = 4 + my_cell;
	a_third_cell = 5.6 + my_cell;
	a_third_cell = 4.5 + 5.5;

	a_third_cell = my_cell - another_cell;
	a_third_cell = my_cell * another_cell;
	a_third_cell = my_cell / another_cell;

	try {
		a_third_cell = my_cell / 0;
	}
	catch (const invalid_argument& e) {
		println("Caught: {}", e.what());
	}

	a_third_cell -= my_cell;
	a_third_cell += 5.4;
	a_third_cell *= my_cell;
	a_third_cell /= my_cell;

	if (my_cell > a_third_cell || my_cell < 10) {
		println("{}", my_cell.get_value());
	}

	if (my_cell == 10) { println("my_cell == 10"); }
	if (10 == my_cell) { println("10 == my_cell"); }

	if (my_cell < a_third_cell) { println("my_cell < a_third_cell"); }
	if (a_third_cell < my_cell) { println("a_third_cell < my_cell"); }

	if (my_cell <= a_third_cell) { println("my_cell <= a_third_cell"); }
	if (a_third_cell <= my_cell) { println("a_third_cell <= my_cell"); }

	if (my_cell > a_third_cell) { println("my_cell> a_third_cell"); }
	if (a_third_cell > my_cell) { println("a_third_cell> my_cell"); }

	if (my_cell >= a_third_cell) { println("my_cell>= a_third_cell"); }
	if (a_third_cell >= my_cell) { println("a_third_cell>= my_cell"); }

	if (my_cell == a_third_cell) { println("my_cell == a_third_cell"); }
	if (a_third_cell == my_cell) { println("a_third_cell == my_cell"); }

	if (my_cell != a_third_cell) { println("my_cell != a_third_cell"); }
	if (a_third_cell != my_cell) { println("a_third_cell != my_cell"); }

	if (my_cell < 10) { println("my_cell < 10"); }
	if (10 < my_cell) { println("10 < my_cell"); }
	if (10 != my_cell) { println("10 != my_cell"); }

	if (another_cell == my_cell) {
		println("cells are equal");
	}
	else {
		println("cells are not equal");
	}
}
