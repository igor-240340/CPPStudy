import std;

class X {};
class Y {};

int main() {
	X x;
	Y y;
	X* xp = &x;
	Y* yp = &y;
	// Для преобразования указателя между несвязанными классами нужен reinterpret_cast; static_cast не работает.
	xp = reinterpret_cast<X*>(yp);
	// Для приведения указателя к void* явный каст не нужен.
	void* p = xp;
	// Для преобразования указателя из void* достаточно static_cast.
	xp = static_cast<X*>(p);
	// Для преобразования ссылки между несвязанными классами нужен reinterpret_cast; static_cast не работает.
	X& xr = x;
	Y& yr = reinterpret_cast<Y&>(xr);
}
