import std;

class PowerSource {
public:
	virtual void print_type() = 0;
};

class GasolinePowerSource : public PowerSource {
public:
	void print_type() override { std::println("GasolinePowerSource"); }
	virtual void fill_tank() { std::println("Gasoline tank filled up."); }
};

class ElectricalPowerSource : public PowerSource {
public:
	void print_type() override { std::println("ElectricalPowerSource"); }
	virtual void charge_batteries() { std::println("Batteries charged."); }
};

class Car {
public:
	virtual PowerSource& get_filled_up_power_source() = 0;
};

class GasolineCar : public Car {
public:
	GasolinePowerSource& get_filled_up_power_source() {
		engine.fill_tank();
		return engine;
	}

private:
	GasolinePowerSource engine;
};

class ElectricalCar : public Car {
public:
	ElectricalPowerSource& get_filled_up_power_source() override {
		engine.charge_batteries();
		return engine;
	}
private:
	ElectricalPowerSource engine;
};

int main() {
	GasolineCar gc;
	gc.get_filled_up_power_source().print_type();
	std::println();
	ElectricalCar ec;
	ec.get_filled_up_power_source().print_type();
}
