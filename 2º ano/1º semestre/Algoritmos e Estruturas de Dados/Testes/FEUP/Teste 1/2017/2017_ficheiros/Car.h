/*
 * Car.h
 *
 *  Created on: 24/10/2017
 *      Author: hlc
 */

#ifndef SRC_CAR_H_
#define SRC_CAR_H_

#include <string>

class Car {
	const std::string brand;
	const std::string model;
	float price;
public:
	Car(std::string b, std::string m);
	virtual ~Car() {};
	std::string getBrand() const;
	std::string getModel() const;
	float getPrice() const;
	void setPrice(float price);
//	virtual float range() const = 0;
	bool operator == (const Car &car) const;
	friend std::ostream & operator<<(std::ostream & os, const Car &car);
};

class FuelCar : public Car {
	float tank;   // in liters
	float l_100km;
public:
	FuelCar(std::string b, std::string m);
	FuelCar(std::string brand, std::string model, float price, float tank, float l_100km);
	float getTank() const;
	void setTank(float t);
	float getL_100km() const;
	void setL_100km(float l_100km);
};

class ElectricCar : public Car {
	float battery; // in kWh
	float kWh_100km;
public:
	ElectricCar(std::string b, std::string m);
	ElectricCar(std::string brand, std::string model, float price, float battery, float kWh_100km);
	float getBattery() const;
	void setBattery(float b);
	float getKWh_100km() const;
	void setKWh_100km(float kWh_100km);
};

class HybridCar : public FuelCar, public ElectricCar {
public:
	HybridCar(std::string brand, std::string model);
	HybridCar(std::string brand, std::string model, float price, float tank, float l_100km, float battery, float kWh_100km);
};

#endif /* SRC_CAR_H_ */
