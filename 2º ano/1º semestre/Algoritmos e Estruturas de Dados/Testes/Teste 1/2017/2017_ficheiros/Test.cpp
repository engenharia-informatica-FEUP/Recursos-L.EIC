#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "Garage.h"
#include "Car.h"
#include <vector>
#include <string>

using namespace std;

void test_a() {
/*
	FuelCar fc("ford", "fiesta", 30000, 60, 5);
	ElectricCar ec("tesla", "s", 70000, 30, 10);

	ASSERT_EQUAL("ford", fc.getBrand());
	ASSERT_EQUAL("fiesta", fc.getModel());
	ASSERT_EQUAL(30000, fc.getPrice());
	ASSERT_EQUAL(60, fc.getTank());
	ASSERT_EQUAL(5, fc.getL_100km());

	ASSERT_EQUAL("tesla", ec.getBrand());
	ASSERT_EQUAL("s", ec.getModel());
	ASSERT_EQUAL(70000, ec.getPrice());
	ASSERT_EQUAL(30, ec.getBattery());
	ASSERT_EQUAL(10, ec.getKWh_100km());
*/
}

void test_b() {
/*
	FuelCar fc1("ford", "fiesta");
	FuelCar fc2("ford", "fiesta");
	ElectricCar ec3("tesla", "s");
	HybridCar hc4("tesla", "s");

	ASSERT_EQUAL(fc1, fc2);
	ASSERT_EQUAL(false, fc1 == ec3);
	ASSERT_EQUAL(ec3, (FuelCar) hc4);
*/
}

void test_c() {
/*
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

	ASSERT_EQUAL(1200, fc.range());
	ASSERT_EQUAL(300, ec.range());
	ASSERT_EQUAL(1500, hc.range());
*/
}

void test_d() {
/*
	FuelCar* fc1 = new FuelCar("ford", "fiesta");
	FuelCar* fc2 = new FuelCar("ford", "fiesta");
	ElectricCar* ec3 = new ElectricCar("tesla", "s");
	ElectricCar* ec4 = new ElectricCar("tesla", "m");

	Garage<Car> g(2);

	ASSERT_EQUAL(true, g.addVehicle(fc1));
	ASSERT_EQUAL(false, g.addVehicle(fc2));
	ASSERT_EQUAL(true, g.addVehicle(ec3));
	ASSERT_EQUAL(false, g.addVehicle(ec4));
*/
}

void test_e() {
/*
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
	vector<Car *> cars;
	cars.push_back(fc1);
	cars.push_back(fc2);
	cars.push_back(ec3);
	cars.push_back(ec4);
	g.setVehicles(cars);
	g.sortVehicles();
	cars = g.getVehicles();

	ASSERT_EQUAL("peugeot", cars[1]->getBrand());
	ASSERT_EQUAL(30000, cars[1]->getPrice());
	ASSERT_EQUAL("ford", cars[0]->getBrand());
	ASSERT_EQUAL(38000, cars[0]->getPrice());
	ASSERT_EQUAL("tesla", cars[3]->getBrand());
	ASSERT_EQUAL(70000, cars[3]->getPrice());
	ASSERT_EQUAL("tesla", cars[2]->getBrand());
	ASSERT_EQUAL(78000, cars[2]->getPrice());
*/
}

void test_f() {
/*
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
	vector<Car *> cars;
	cars.push_back(fc1);
	cars.push_back(fc2);
	cars.push_back(ec3);
	cars.push_back(ec4);
	g.setVehicles(cars);

    ASSERT_EQUAL(fc1, g.removeVehicle("peugeot", "3008"));
    ASSERT_EQUAL(3, g.getVehicles().size());
    ASSERT_THROWS(g.removeVehicle("ford", "focus"), NoSuchVehicleException);
    ASSERT_EQUAL(ec4, g.removeVehicle("tesla", "m"));
    ASSERT_EQUAL(2, g.getVehicles().size());
*/
}

void test_g() {
/*
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
	vector<Car *> cars;
	cars.push_back(fc1);
	cars.push_back(fc2);
	cars.push_back(ec3);
	cars.push_back(ec4);
	g.setVehicles(cars);

	ASSERT_THROWS(g.avgPrice("ford"), NoSuchBrandException);
	try {
		g.avgPrice("ford");
	} catch(NoSuchBrandException &e) {
		ASSERT_EQUAL("ford", e.getBrand());
	}
	ASSERT_EQUAL(21000, g.avgPrice("peugeot"));
*/
}

void test_h() {
/*
	FuelCar fc("toyota", "auris");
	fc.setPrice(30000);
	fc.setTank(60);
	fc.setL_100km(5);
	ElectricCar ec("toyota", "yaris");
	ec.setPrice(20000);
	ec.setBattery(30);
	ec.setKWh_100km(10);
	HybridCar hc("toyota", "prius", 40000, 60, 5, 30, 10);

	stringstream ss1;
	ss1 << fc;
	ASSERT_EQUAL("toyota auris (30000)", ss1.str());
	stringstream ss2;
	ss2 << ec;
	ASSERT_EQUAL("toyota yaris (20000)", ss2.str());
	stringstream ss3;
	ss3 << (FuelCar) hc;
	ASSERT_EQUAL("toyota prius (40000)", ss3.str());
*/
}


void runSuite(){
	cute::suite s;
	s.push_back(CUTE(test_a));
	s.push_back(CUTE(test_b));
	s.push_back(CUTE(test_c));
	s.push_back(CUTE(test_d));
	s.push_back(CUTE(test_e));
	s.push_back(CUTE(test_f));
	s.push_back(CUTE(test_g));
	s.push_back(CUTE(test_h));
	cute::ide_listener<> lis;
	cute::makeRunner(lis)(s, "AEDA 2017/2018 - Componente Individual 1 - Testes Unitarios Estudantes");
}

int main(){
    runSuite();
    return 0;
}

