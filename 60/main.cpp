#include "SpreadsheetCell.h"
#include <iostream>

using namespace std;

int main() {
	SpreadsheetCell my_cell(4), another_cell(5);
	SpreadsheetCell a_third_cell(my_cell + another_cell);

	string str("hello");
	a_third_cell = my_cell + string_view(str);

	a_third_cell = my_cell + 5.6;
	a_third_cell = my_cell + 4;

	a_third_cell = 5.6 + my_cell;
	a_third_cell = 4 + my_cell;
	a_third_cell = 4.5 + 5.5;

	a_third_cell = my_cell - another_cell;
	a_third_cell = my_cell * another_cell;
	a_third_cell = my_cell / another_cell;

	try {
		a_third_cell = my_cell / 0;
	}
	catch (const invalid_argument& e) {
		cout << "Caught: " << e.what() << endl;
	}

	a_third_cell -= my_cell;
	a_third_cell += 5.4;
	a_third_cell *= my_cell;
	a_third_cell /= my_cell;

	if (my_cell > a_third_cell || my_cell < 10) {
		cout << my_cell.get_value() << endl;
	}

	if (my_cell < 10) {
		cout << "my_cell < 10" << endl;
	}

	if (10 < my_cell) {
		cout << "10 < my_cell" << endl;
	}

	if (another_cell == my_cell) {
		cout << "cells are equal" << endl;
	}
	else {
		cout << "cells are not equal" << endl;
	}
}
