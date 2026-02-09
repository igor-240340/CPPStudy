#include <print>

enum class PieceType1 { King, Queen, Rook, Pawn };
enum class PieceType2 { King = 1, Queen, Rook = 10, Pawn };
enum class State { Unknown, Started, Finished };

using enum PieceType1;
using State::Unknown;

int main() {
	PieceType1 a{ King };
	State state{ Unknown };

	PieceType2 b{ PieceType2::Queen };
	PieceType2 c{ PieceType2::Pawn };
	std::println("PieceType2::Queen = {}", std::to_underlying(PieceType2::Queen));
	std::println("PieceType2::Pawn = {}", std::to_underlying(PieceType2::Pawn));
	//std::println("a == b: {}", a == b); // Ошибка.
	std::println("b == c: {}", b == c);

	return 0;
}
