#include <print>
#include <array>

int main() {
    std::array values{ 11, 22, 33 };
    auto [x, y, z] {values};
    std::println("x:{}, y:{}, z:{}", x, y, z);

    struct Point {
        double m_x, m_y, m_z;
    };
    Point point;
    point.m_x = 1.0;
    point.m_y = 2.0;
    point.m_z = 3.0;

    auto [a, b, c] {point};
    std::println("a:{}, b:{}, c:{}", a, b, c);

    std::pair my_pair{ "hello", 5 };
    auto [the_string, the_int] {my_pair};
    std::println("the_string:{}, the_int:{}", the_string, the_int);
}
