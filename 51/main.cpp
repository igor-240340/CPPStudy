#include <print>
#include <memory>

class Foo {
public:
    Foo(int value) : m_data{ value } {}
    int m_data;
};


int main() {
    std::shared_ptr<Foo> foo{ std::make_shared<Foo>(42) };
    std::shared_ptr<int> aliasing{ std::shared_ptr<int> { foo, &foo->m_data } };
}
