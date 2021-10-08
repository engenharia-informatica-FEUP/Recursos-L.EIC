#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Garage.h"
#include "Car.h"
#include <vector>
#include <string>

using testing::Eq;

TEST(test, test_a) {
	FuelCar fc("ford", "fiesta", 30000, 60, 5);
	ElectricCar ec("tesla", "s", 70000, 30, 10);

	ASSERT_EQ("ford", fc.getBrand());
	ASSERT_EQ("fiesta", fc.getModel());
	ASSERT_EQ(30000, fc.getPrice());
	ASSERT_EQ(60, fc.getTank());
	ASSERT_EQ(5, fc.getL_100km());

	ASSERT_EQ("tesla", ec.getBrand());
	ASSERT_EQ("s", ec.getModel());
	ASSERT_EQ(70000, ec.getPrice());
	ASSERT_EQ(30, ec.getBattery());
	ASSERT_EQ(10, ec.getKWh_100km());
}

TEST(test, test_b) {
	FuelCar fc1("ford", "fiesta");
	FuelCar fc2("ford", "fiesta");
	ElectricCar ec3("tesla", "s");
	HybridCar hc4("tesla", "s");

	ASSERT_EQ(fc1, fc2);
	ASSERT_EQ(false, fc1 == ec3);
	ASSERT_EQ(ec3, (FuelCar) hc4);
}

TEST(test, test_c) {
	FuelCar fc("ford", "fiesta");
	fc.setTank(60);
	fc.setL_100km(5);
	ElectricCar ec("tesla", "s");
	ec.setBattery(30);
	ec.setKWh_100km(10);
	HybridCar hc("toyota", "prius");
	hc.setTank(60);
	hc.setL_100km(5);
	hc.setBattery(30);
	hc.setKWh_100km(10);

	ASSERT_EQ(1200, fc.range());
	ASSERT_EQ(300, ec.range());
	ASSERT_EQ(1500, hc.range());
}

TEST(test, test_d) {
	FuelCar* fc1 = new FuelCar("ford", "fiesta");
	FuelCar* fc2 = new FuelCar("ford", "fiesta");
	ElectricCar* ec3 = new ElectricCar("tesla", "s");
	ElectricCar* ec4 = new ElectricCar("tesla", "m");

	Garage<Car> g(2);

	ASSERT_EQ(true, g.addVehicle(fc1));
	ASSERT_EQ(false, g.addVehicle(fc2));
	ASSERT_EQ(true, g.addVehicle(ec3));
	ASSERT_EQ(false, g.addVehicle(ec4));
}

TEST(test, test_e) {
	FuelCar* fc1 = new FuelCar("peugeot", "3008");
	fc1->setPrice(30000);
	fc1->setTank(60);
	fc1->setL_100km(5);
	FuelCar* fc2 = new FuelCar("ford", "fiesta");
	fc2->setPrice(38000);
	fc2->setTank(60);
	fc2->setL_100km(5);
	ElectricCar* ec3 = new ElectricCar("tesla", "s");
	ec3->setPrice(70000);
	ec3->setBattery(30);
	ec3->setKWh_100km(10);
	ElectricCar* ec4 = new ElectricCar("tesla", "m");
	ec4->setPrice(78000);
	ec4->setBattery(30);
	ec4->setKWh_100km(11);

	Garage<Car> g(5);
	std::vector<Car *> cars;
	cars.push_back(fc1);
	cars.push_back(fc2);
	cars.push_back(ec3);
	cars.push_back(ec4);
	g.setVehicles(cars);
	g.sortVehicles();
	cars = g.getVehicles();

	ASSERT_EQ("peugeot", cars[1]->getBrand());
	ASSERT_EQ(30000, cars[1]->getPrice());
	ASSERT_EQ("ford", cars[0]->getBrand());
	ASSERT_EQ(38000, cars[0]->getPrice());
	ASSERT_EQ("tesla", cars[3]->getBrand());
	ASSERT_EQ(70000, cars[3]->getPrice());
	ASSERT_EQ("tesla", cars[2]->getBrand());
	ASSERT_EQ(78000, cars[2]->getPrice());
}

TEST(test, test_f) {
	FuelCar* fc1 = new FuelCar("peugeot", "3008");
	fc1->setPrice(30000);
	fc1->setTank(60);
	fc1->setL_100km(5);
	FuelCar* fc2 = new FuelCar("ford", "fiesta");
	fc2->setPrice(38000);
	fc2->setTank(60);
	fc2->setL_100km(5);
	ElectricCar* ec3 = new ElectricCar("tesla", "s");
	ec3->setPrice(70000);
	ec3->setBattery(30);
	ec3->setKWh_100km(10);
	ElectricCar* ec4 = new ElectricCar("tesla", "m");
	ec4->setPrice(78000);
	ec4->setBattery(30);
	ec4->setKWh_100km(11);

	Garage<Car> g(5);
	std::vector<Car *> cars;
	cars.push_back(fc1);
	cars.push_back(fc2);
	cars.push_back(ec3);
	cars.push_back(ec4);
	g.setVehicles(cars);

    ASSERT_EQ(fc1, g.removeVehicle("peugeot", "3008"));
    ASSERT_EQ(3, g.getVehicles().size());
    ASSERT_THROW(g.removeVehicle("ford", "focus"), NoSuchVehicleException);
    ASSERT_EQ(ec4, g.removeVehicle("tesla", "m"));
    ASSERT_EQ(2, g.getVehicles().size());
}

TEST(test, test_g) {
	FuelCar* fc1 = new FuelCar("peugeot", "3008");
	fc1->setPrice(30000);
	fc1->setTank(60);
	fc1->setL_100km(5);
	FuelCar* fc2 = new FuelCar("peugeot", "2008");
	fc2->setPrice(20000);
	fc2->setTank(55);
	fc2->setL_100km(4);
	ElectricCar* ec3 = new ElectricCar("peugeot", "ion");
	ec3->setPrice(13000);
	ec3->setBattery(30);
	ec3->setKWh_100km(10);
	ElectricCar* ec4 = new ElectricCar("tesla", "m");
	ec4->setPrice(78000);
	ec4->setBattery(30);
	ec4->setKWh_100km(11);

	Garage<Car> g(5);
	std::vector<Car *> cars;
	cars.push_back(fc1);
	cars.push_back(fc2);
	cars.push_back(ec3);
	cars.push_back(ec4);
	g.setVehicles(cars);

	ASSERT_THROW(g.avgPrice("ford"), NoSuchBrandException);
	try {
		g.avgPrice("ford");
	} catch(NoSuchBrandException &e) {
		ASSERT_EQ("ford", e.getBrand());
	}
	ASSERT_EQ(21000, g.avgPrice("peugeot"));
}

TEST(test, test_h) {
	FuelCar fc("toyota", "auris");
	fc.setPrice(30000);
	fc.setTank(60);
	fc.setL_100km(5);
	ElectricCar ec("toyota", "yaris");
	ec.setPrice(20000);
	ec.setBattery(30);
	ec.setKWh_100km(10);
	HybridCar hc("toyota", "prius", 40000, 60, 5, 30, 10);

	std::stringstream ss1;
	ss1 << fc;
	ASSERT_EQ("toyota auris (30000)", ss1.str());
    std::stringstream ss2;
	ss2 << ec;
	ASSERT_EQ("toyota yaris (20000)", ss2.str());
    std::stringstream ss3;
	ss3 << (FuelCar) hc;
	ASSERT_EQ("toyota prius (40000)", ss3.str());
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

