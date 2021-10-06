#ifndef SRC_HOTEL_H_
#define SRC_HOTEL_H_

#include <vector>
#include <list>
#include <algorithm>
using namespace std;
template <class Chamber>
class Hotel {
	std::vector<Chamber *> chambers;
	const unsigned int maxCapacity;
	const std::string city;
    std::list<Chamber> reservationsDone;
public:
	Hotel(int size, std::string municipality);
	~Hotel();
	std::vector<Chamber *> getChambers() const;
	void setChambers(std::vector<Chamber *> chambers);
	int getCapacity() const;
    std::list<Chamber> getReservationsDone() const;
	bool addChamber(Chamber *chamber);
    void addReservationDone(Chamber chamber);
    Chamber* removeChamber(std::string code, int floor);
	float avgArea(int floor) const;
	void sortChambers();
	bool doReservation(std::string code, int floor);
    std::list<Chamber> roomsNeverReserved() const;
};

class NoSuchChamberException {
public:
	NoSuchChamberException() { }
};

class NoSuchFloorException {
    int floor;
public:
    NoSuchFloorException(int f) : floor(f){}
    int getFloor() const { return floor;}
};


template <class Chamber>
Hotel<Chamber>::Hotel(int size, std::string municipality) : maxCapacity(size), city(municipality) {
}

template <class Chamber>
Hotel<Chamber>::~Hotel(){
	typename std::vector<Chamber *>::const_iterator it;
	for (it=chambers.begin(); it!=chambers.end(); it++) {
		delete *it;
	}
}

template<class Chamber>
std::vector<Chamber *> Hotel<Chamber>::getChambers() const {
	return chambers;
}

template<class Chamber>
void Hotel<Chamber>::setChambers(std::vector<Chamber*> chambers) {
	this->chambers = chambers;
}

template<class Chamber>
int Hotel<Chamber>::getCapacity() const {
	return maxCapacity;
}

template<class Chamber>
void Hotel<Chamber>::addReservationDone(Chamber chamber) {
    reservationsDone.push_back(chamber);
}

template<class Chamber>
std::list<Chamber> Hotel<Chamber>::getReservationsDone() const {
    return reservationsDone;
}

//------------------------------------------------------
//------------------------------------------------------

//TODO
template<class Chamber>
bool Hotel<Chamber>::addChamber(Chamber *chamber) {
    if(chambers.size() == Hotel<Chamber>::getCapacity())
        return false;
    for(typename vector<Chamber*>::const_iterator it = chambers.begin(); it < chambers.end(); it++)
    {
        if(*chamber == *(*it))
            return false;
    }
    chambers.push_back(chamber);
    return true;

}

bool compRoom(const Room *r1, const Room *r2)
{
    if(r1->getCode() == r2 ->getCode())
        return(r1->getFloor()>r2->getFloor());
    return (r1->getCode() < r2 ->getCode());
}

//TODO
template<class Chamber>
void Hotel<Chamber>::sortChambers() {
    sort(chambers.begin(), chambers.end(), compRoom);
}

//TODO
template<class Chamber>
Chamber* Hotel<Chamber>::removeChamber(std::string code, int floor) {
    for (typename vector<Chamber *>::const_iterator it = chambers.begin(); it < chambers.end(); it++) {
        if ((*it)->getFloor() == floor) {
            if ((*it)->getCode() == code) {
                Chamber * temp = *it;
                chambers.erase(it);
                return temp;
            }
            throw(NoSuchChamberException());
        }
    }
    throw(NoSuchChamberException());
}

//TODO
template<class Chamber>
float Hotel<Chamber>::avgArea(int floor) const {
    float numRooms = 0;
    float sumAreas = 0;
    for (typename vector<Chamber *>::const_iterator it = chambers.begin(); it < chambers.end(); it++)
    {
        if((*it)->getFloor() == floor)
        {
            sumAreas += (*it)->getArea();
            numRooms ++;
        }
    }
    if(numRooms==0)
        throw (NoSuchFloorException(floor));

    return sumAreas/numRooms;
}

//TODO
template<class Chamber>
bool Hotel<Chamber>::doReservation(std::string code, int floor){
    for (typename vector<Room *>::const_iterator it = chambers.begin(); it < chambers.end(); it++)
    {
        if ((*it)->getFloor() == floor)
        {
            if ((*it)->getCode() == code)
            {
                if((*it)->getReservation())
                    return false;
                (*it)->setReservation(true);
                reservationsDone.push_back(*(*it));
                return true;
            }
        }
    }
    return false;
}

//TODO
template<class Chamber>
std::list<Chamber> Hotel<Chamber>::roomsNeverReserved() const {
    std::list<Chamber> res;
    typename list<Room>::const_iterator num_tent = reservationsDone.begin();
    for(typename vector<Room *>::const_iterator it = chambers.begin(); it < chambers.end(); it++)
    {
        for(typename list<Room>::const_iterator it1 = reservationsDone.begin(); it1 != reservationsDone.end(); it1++)
        {
            if((*it)->getFloor() == it1->getFloor() && (*it)->getCode() == it1->getCode())
                break;
            else {num_tent++;}
        }
        if (num_tent == reservationsDone.end())
            res.push_back(*(*it));
        num_tent = reservationsDone.begin();
    }
    return res;
}
#endif /* SRC_HOTEL_H_ */
