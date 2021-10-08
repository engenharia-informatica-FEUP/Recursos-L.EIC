#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Room.h"
#include "Hotel.h"
#include <string>
#include <vector>
#include <list>

using testing::Eq;
using namespace std;

TEST(test_1, test_a){
    try {
        RegularRoom rr1("rr1", 4);
        RegularRoom rr2("rr1", 4);
        FamilyRoom fr3("fr3", 6);
        LuxuryRoom lr4("fr3", 6);

        EXPECT_EQ(rr1, rr2);
        EXPECT_EQ(false, rr1 == fr3);
    }
    catch(...) {
        EXPECT_EQ(true,false);
    }

}

TEST(test_1, test_b){
    try {
        RegularRoom rr("rr1", 4);
        rr.setLength(300);
        rr.setWidth(400);
        FamilyRoom fr("fr1", 5);
        fr.setWidth(600);
        fr.setLength(550);
        LuxuryRoom lr("lr1", 6);
        lr.setLength(850);
        lr.setWidth(700);

        EXPECT_EQ(48, rr.price());
        EXPECT_EQ(132, fr.price());
        EXPECT_FLOAT_EQ(271.4, lr.price());
    }
    catch(...) {
        EXPECT_EQ(true,false);
    }
}

TEST(test_1, test_c){
    try {
        RegularRoom *rr1 = new RegularRoom("rr1", 1);
        RegularRoom *rr2 = new RegularRoom("rr1", 1);
        FamilyRoom *fr3 = new FamilyRoom("fr3", 1);
        FamilyRoom *fr4 = new FamilyRoom("fr3", 2);

        Hotel<Room> h(2, "Lisbon");

        EXPECT_EQ(true, h.addChamber(rr1));
        EXPECT_EQ(false, h.addChamber(rr2));
        EXPECT_EQ(true, h.addChamber(fr3));
    }
    catch(...) {
        EXPECT_EQ(true,false);
    }
}

TEST(test_1, test_d){
    try {
        RegularRoom *rr1 = new RegularRoom("rr1", 1);
        rr1->setLength(350);
        rr1->setWidth(300);
        RegularRoom *rr2 = new RegularRoom("rr2", 1);
        rr2->setLength(370);
        rr2->setWidth(450);
        FamilyRoom *fr3 = new FamilyRoom("fr3", 1);
        fr3->setLength(500);
        fr3->setWidth(600);
        FamilyRoom *fr4 = new FamilyRoom("fr3", 2);
        fr4->setLength(550);
        fr4->setWidth(600);

        Hotel<Room> h(5, "Lisbon");
        vector<Room *> rooms;
        rooms.push_back(rr1);
        rooms.push_back(rr2);
        rooms.push_back(fr3);
        rooms.push_back(fr4);
        h.setChambers(rooms);
        h.sortChambers();
        rooms = h.getChambers();

        EXPECT_EQ("fr3", rooms.at(1)->getCode());
        EXPECT_EQ(500, rooms.at(1)->getLength());
        EXPECT_EQ("fr3", rooms.at(0)->getCode());
        EXPECT_EQ(550, rooms.at(0)->getLength());
        EXPECT_EQ("rr2", rooms.at(3)->getCode());
        EXPECT_EQ(370, rooms.at(3)->getLength());
        EXPECT_EQ("rr1", rooms.at(2)->getCode());
        EXPECT_EQ(350, rooms.at(2)->getLength());
    }
    catch(...) {
        EXPECT_EQ(true,false);
    }
}

TEST(test_1, test_e){
    try {
        RegularRoom *rr1 = new RegularRoom("rr1", 1);
        FamilyRoom *fr2 = new FamilyRoom("fr2", 1);
        FamilyRoom *fr3 = new FamilyRoom("fr3", 2);

        Hotel<Room> h(4, "Lisbon");
        vector<Room *> rooms;
        rooms.push_back(rr1);
        rooms.push_back(fr2);
        rooms.push_back(fr3);
        h.setChambers(rooms);

        EXPECT_EQ(rr1, h.removeChamber("rr1", 1));
        EXPECT_EQ(2, h.getChambers().size());
        EXPECT_THROW(h.removeChamber("rr2", 1), NoSuchChamberException);
        EXPECT_EQ(fr3, h.removeChamber("fr3", 2));
        EXPECT_EQ(1, h.getChambers().size());
    }
    catch(...) {
        EXPECT_EQ(true,false);
    }
}

TEST(test_1, test_f){
    try {
        RegularRoom *rr1 = new RegularRoom("rr1", 1);
        rr1->setWidth(300);
        rr1->setLength(400);
        RegularRoom *rr2 = new RegularRoom("rr2", 2);
        FamilyRoom *fr3 = new FamilyRoom("fr3", 1);
        fr3->setWidth(300);
        fr3->setLength(400);
        FamilyRoom *fr4 = new FamilyRoom("fr4", 2);


        Hotel<Room> h(5, "Lisbon");
        vector<Room *> rooms;
        rooms.push_back(rr1);
        rooms.push_back(rr2);
        rooms.push_back(fr3);
        rooms.push_back(fr4);
        h.setChambers(rooms);

        EXPECT_THROW(h.avgArea(5), NoSuchFloorException);
        try {
            h.avgArea(5);
        } catch (NoSuchFloorException &e) {
            EXPECT_EQ(5, e.getFloor());
        }
        EXPECT_EQ(12, h.avgArea(1));
    }
    catch(...) {
        EXPECT_EQ(true,false);
    }
}


TEST(test_1, test_g){
    try {
        RegularRoom *rr1 = new RegularRoom("rr1", 1);
        FamilyRoom *fr2 = new FamilyRoom("fr2", 1);
        FamilyRoom *fr3 = new FamilyRoom("fr3", 2);

        Hotel<Room> h(4, "Lisbon");
        vector<Room *> rooms;
        rooms.push_back(rr1);
        rooms.push_back(fr2);
        rooms.push_back(fr3);
        h.setChambers(rooms);

        EXPECT_EQ(true, h.doReservation("rr1", 1));
        EXPECT_EQ(1, h.getReservationsDone().size());
        if (h.getReservationsDone().size()==1)
            EXPECT_EQ("rr1", h.getReservationsDone().back().getCode());
        EXPECT_EQ(3, h.getChambers().size());
        EXPECT_EQ(false, h.doReservation("rr1", 1));
        EXPECT_EQ(1, h.getReservationsDone().size());
        EXPECT_EQ(false, h.doReservation("rr1", 2));
        EXPECT_EQ(1, h.getReservationsDone().size());
        EXPECT_EQ(true, h.doReservation("fr3", 2));
        EXPECT_EQ(2, h.getReservationsDone().size());
    }
    catch(...) {
        EXPECT_EQ(true,false);
    }
}


TEST(test_1, test_h){
    try {
        RegularRoom *rr1 = new RegularRoom("rr1", 1);
        FamilyRoom *fr2 = new FamilyRoom("fr2", 1);
        FamilyRoom *fr3 = new FamilyRoom("fr3", 2);
        FamilyRoom *fr4 = new FamilyRoom("fr4", 2);

        Hotel<Room> h(8, "Lisbon");
        vector<Room *> rooms;
        rooms.push_back(rr1);
        rooms.push_back(fr2);
        rooms.push_back(fr3);
        rooms.push_back(fr4);
        h.setChambers(rooms);

        std::list<Room> res;

        res = h.roomsNeverReserved();
        EXPECT_EQ(4, res.size());

        h.addReservationDone(*fr3);
        res = h.roomsNeverReserved();
        EXPECT_EQ(3, res.size());

        h.addReservationDone(*fr4);
        h.addReservationDone(*rr1);
        res = h.roomsNeverReserved();
        EXPECT_EQ(1, res.size());
        if (res.size()==1)
            EXPECT_EQ("fr2", res.back().getCode());
    }
    catch(...) {
        EXPECT_EQ(true,false);
    }
}