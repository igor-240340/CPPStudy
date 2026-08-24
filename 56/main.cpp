import spreadsheet;
import std;

int main() {
	SpreadsheetApplication app;
	Spreadsheet s1(5, 6, app);

	Spreadsheet::Cell c1(4), c2(5);
	Spreadsheet::Cell c3(c1);
	c2 = c3;

	std::println("{}", c1.get_value());

	s1.get_id();
}