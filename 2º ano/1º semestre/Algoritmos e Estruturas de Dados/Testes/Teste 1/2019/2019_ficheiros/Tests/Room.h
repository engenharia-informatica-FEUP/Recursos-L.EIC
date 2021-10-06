#ifndef SRC_ROOM_H_
#define SRC_ROOM_H_

#include <string>

class Room {
	const std::string code;
	const int floor;
    int roomWidth;  // in cm
    int roomLength; // in cm
	float area; // in m2
	bool reservation;
public:
    Room();
	Room(std::string c, int f);
    Room(std::string c, int f, int w, int l);
	virtual ~Room() {};
	std::string getCode() const;
	int getFloor() const;
    int getWidth() const;
    void setWidth(int roomWith);
    int getLength() const;
    void setLength(int roomLength);
    bool getReservation() const;
    void setReservation(bool roomReserv);
    float getArea() const;
	bool operator == (const Room &room) const;
};

class RegularRoom : public Room {
public:
	RegularRoom(std::string c, int f);
    RegularRoom(std::string c, int f, int w, int l);
    float price() const;
};

class FamilyRoom : public Room {
	int numChildrenBed;
public:
	FamilyRoom(std::string c, int f);
    FamilyRoom(std::string c, int f, int w, int l, float numCB);
	int getNumChildrenBed() const;
	void setNumChildrenBed(int numCB);
    float price() const;
};

class LuxuryRoom : public Room{
    std::string typeBed;
public:
	LuxuryRoom(std::string c, int f);
	LuxuryRoom(std::string c, int f, int w, int l, std::string typeBed);
    std::string getTypeBed() const;
    void setTypeBed(std::string tB);
    float price() const;
};

#endif /* SRC_ROOM_H_ */
