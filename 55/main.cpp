import std;

class Matrix {
public:
	Matrix() = default; // Implicitly constexpr

	constexpr explicit Matrix(unsigned rows, unsigned columns) : rows(rows), columns(columns) {
	}

	constexpr unsigned get_size() const {
		return rows * columns;
	}

private:
	unsigned rows = 0;
	unsigned columns = 0;
};


int main() {
	constexpr Matrix matrix(8, 2);
	int linearized_matrix[matrix.get_size()];
	std::println("Size of linearized_matrix = {}", std::size(linearized_matrix));

	constexpr Matrix matrix_default;
}
