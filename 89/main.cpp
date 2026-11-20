import std;

int main() {
	float as_float = 1.23f;
	// Те же 4 байта интерпретируются как unsigned int.
	unsigned int as_uint = std::bit_cast<unsigned int>(as_float);
	if (std::bit_cast<float>(as_uint) == as_float) { std::println("Roundtrip success."); }

	// Применение: побайтовый ввод-вывод тривиально копируемых типов.
	// Байты можно записать в файл, а после чтения собрать из них значение обратно.
	std::array<std::byte, sizeof(float)> bytes = std::bit_cast<std::array<std::byte, sizeof(float)>>(as_float);
	float restored = std::bit_cast<float>(bytes);
	std::println("Restored: {}", restored);
}
