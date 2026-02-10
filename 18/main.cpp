#include <print>
#include <array>

int main() {
    int i{ 0 };
    while (i < 5) {
        std::println("This is silly {}", i + 1);
        ++i;
    }

    i = 100;
    do {
        std::println("This is silly");
        ++i;
    } while (i < 5);

    for (int i{ 0 }; i < 5; ++i)
        std::println("This is silly {}", i + 1);

    std::array arr{ 1, 2, 3, 4 };
    for (int i : arr)
        std::println("{}", i);

    for (std::array arr{ 1, 2, 3, 4 }; int i : arr)
        std::println("{}", i);
}
