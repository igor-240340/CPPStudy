#include <print>
#include <optional>

std::optional<int> get_data(bool give_it);

int main() {
    std::optional<int> data1{ get_data(true) };
    std::optional<int> data2{ get_data(false) };

    std::println("data1.has_value = {}", data1.has_value());
    if (!data2)
        std::println("data2 has no value");

    std::println("data1.value = {}", data1.value());
    std::println("data1.value = {}", *data1);

    std::println("data2.value = {}", data2.value_or(0));
}

std::optional<int> get_data(bool give_it) {
    if (give_it)
        return 42;

    return std::nullopt;
}
