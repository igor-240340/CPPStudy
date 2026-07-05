import std;

class EvenSequence {
public:
    EvenSequence(std::initializer_list<double> values) {
        if (values.size() % 2 != 0) {
            throw std::invalid_argument{ "initializer_list should contain even number of elements" };
        }
        sequence.reserve(values.size());
        for (const double& value : values) {
            sequence.push_back(value);
        }
        //sequence.assign(values);
    }

    void print() const {
        for (const double& value : sequence) {
            std::print("{}, ", value);
        }
        std::println("");
    }
private:
    std::vector<double> sequence;
};

int main() {
    try {
		EvenSequence p1{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
        p1.print();

        EvenSequence p2{ 1.0, 2.0, 3.0 };
    }
    catch (const std::invalid_argument& e) {
        std::println("{}", e.what());
    }
}
