import std;

class MilesEstimator {
public:
	virtual ~MilesEstimator() = default;

	int get_miles_left() const { return get_miles_per_gallon() * get_gallons_left(); }
	virtual void set_gallons_left(int gallons) { gallons_left = gallons; }
	virtual int get_gallons_left() const { return gallons_left; }
private:
	int gallons_left = 0;
	virtual int get_miles_per_gallon() const { return 20; }
};

class EfficientCarMilesEstimator : public MilesEstimator {
private:
	int get_miles_per_gallon() const override { return 35; }
};

int main() {
	MilesEstimator my_miles_estimator;
	my_miles_estimator.set_gallons_left(2);
	std::println("Normal estimator can go {} more miles.", my_miles_estimator.get_miles_left());

	EfficientCarMilesEstimator my_efficient_estimator;
	my_efficient_estimator.set_gallons_left(2);
	std::println("Efficient estimator can go {} more miles.", my_efficient_estimator.get_miles_left());
}
