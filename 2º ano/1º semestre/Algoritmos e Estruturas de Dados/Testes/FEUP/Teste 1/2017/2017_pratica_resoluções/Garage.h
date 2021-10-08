/*
 * Garage.h
 *
 *  Created on: 24/10/2017
 *      Author: hlc
 */

#ifndef SRC_GARAGE_H_
#define SRC_GARAGE_H_

#include <vector>
#include <algorithm>

template <class Vehicle>
class Garage {
	std::vector<Vehicle *> vehicles;
	const unsigned int capacity;
public:
	Garage(int size);
	~Garage();
	std::vector<Vehicle *> getVehicles() const;
	void setVehicles(std::vector<Vehicle *> vehicles);
	int getCapacity() const;
	bool addVehicle(Vehicle *vehicle);
	Vehicle* removeVehicle(std::string brand, std::string model);
	float avgPrice(std::string brand) const;
	void sortVehicles();
};

class NoSuchVehicleException {
public:
	NoSuchVehicleException() { }
};

class NoSuchBrandException {
    std::string brand;
public:
    NoSuchBrandException(std::string brand) : brand(brand) {}
    std::string getBrand() const {
        return brand;
    }
};

template <class Vehicle>
Garage<Vehicle>::Garage(int size) : capacity(size) {
}

template <class Vehicle>
Garage<Vehicle>::~Garage() {
	typename std::vector<Vehicle *>::const_iterator it;
	for (it=vehicles.begin(); it!=vehicles.end(); it++) {
		delete *it;
	}
}

template<class Vehicle>
std::vector<Vehicle *> Garage<Vehicle>::getVehicles() const {
	return vehicles;
}

template<class Vehicle>
void Garage<Vehicle>::setVehicles(std::vector<Vehicle*> vehicles) {
	this->vehicles = vehicles;
}

template<class Vehicle>
int Garage<Vehicle>::getCapacity() const {
	return capacity;
}

template<class Vehicle>
bool Garage<Vehicle>::addVehicle(Vehicle *vehicle) {
    if (vehicles.size() == capacity) {
        return false;
    }

    for (typename std::vector<Vehicle *>::const_iterator it = vehicles.begin(); it != vehicles.end(); it++) {
        if (*(*it) == *vehicle) {
            return false;
        }
    }

    vehicles.push_back(vehicle);
    return true;
}

template<class Vehicle>
bool sortRule(Vehicle* lhs, Vehicle* rhs) {
    if ((*lhs).getBrand() == (*rhs).getBrand()) {
        return (*lhs).getPrice() > (*rhs).getPrice();
    }
    else {
        return (*lhs).getBrand() < (*rhs).getBrand();
    }
}

template<class Vehicle>
void Garage<Vehicle>::sortVehicles() {
    std::sort(vehicles.begin(), vehicles.end(), sortRule<Vehicle>);
}

template<class Vehicle>
Vehicle* Garage<Vehicle>::removeVehicle(std::string brand, std::string model) {
    Vehicle* removed;

    for (typename std::vector<Vehicle *>::iterator it = vehicles.begin(); it != vehicles.end(); it++) {
        if ((*it)->getBrand() == brand && (*it)->getModel() == model) {
            removed = *it;
            vehicles.erase(it);
            return removed;
        }
    }

    throw NoSuchVehicleException();
}

template<class Vehicle>
float Garage<Vehicle>::avgPrice(std::string brand) const {
    float sum = 0;
    unsigned int count = 0;

    for (typename std::vector<Vehicle *>::const_iterator it = vehicles.begin(); it != vehicles.end(); it++) {
        if ((*it)->getBrand() == brand) {
            sum += (*it)->getPrice();
            count++;
        }
    }

    if (count == 0) {
        throw NoSuchBrandException(brand);
    }
    else {
        return sum / (float)count;
    }
}

#endif /* SRC_GARAGE_H_ */
