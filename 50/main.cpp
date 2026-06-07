#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
		#define new DBG_NEW
	#endif
#endif

#include <print>

class Simple {
public:
	Simple() { int_ptr = new int{}; }
	void set_value(int value) { *int_ptr = value; }

private:
	int* int_ptr;
};

void mem_leak();

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	mem_leak();
}

void mem_leak() {
	Simple* my_simple_ptr{ new Simple{} };
}
