#include <print>

class Simple {
public:
	Simple() { int_ptr = new int{}; }
	void set_value(int value) { *int_ptr = value; }

private:
	int* int_ptr;
};

void mem_leak();
void do_something(Simple*& out_simple_ptr);

int main() {
	mem_leak();
}

void mem_leak() {
	Simple* simple_ptr{ new Simple{} };
	do_something(simple_ptr);
	delete simple_ptr; // Only cleans up the second object.
}

void do_something(Simple*& out_simple_ptr) {
	out_simple_ptr = new Simple{}; // BUG! Doesn't delete the original.
}
