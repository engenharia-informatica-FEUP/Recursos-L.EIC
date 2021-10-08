
#include "Hospital.h"

#include <algorithm>
#include <stack>
#include <iostream>



Hospital::Hospital(unsigned trayC):trayCapacity(trayC)
{ }

void Hospital::addDoctor(const Doctor &d1) {
    doctors.push_back(d1);
}

list<Doctor> Hospital::getDoctors() const {
    return doctors;
}

void Hospital::addTrays(stack<Patient> tray1) {
    letterTray.push_back(tray1);
}

list<stack<Patient> > Hospital::getTrays() const {
    return letterTray;
}



unsigned Hospital::numPatients(string medicalSpecialty) const
{
    unsigned result = 0;
    for (auto it = doctors.begin(); it != doctors.end(); it++) {
        if ((*it).getMedicalSpecialty() == medicalSpecialty) {
            result += (*it).getPatients().size();
        }
    }
    return result;
}

bool compareDoctors(const Doctor &d1, const Doctor &d2) {
    if (d1.getPatients().size() < d2.getPatients().size())
        return true;
    if (d1.getPatients().size() > d2.getPatients().size())
        return false;
    if (d1.getMedicalSpecialty() < d2.getMedicalSpecialty())
        return true;
    if (d1.getMedicalSpecialty() > d2.getMedicalSpecialty())
        return false;
    return d1.getCode() < d2.getCode();
}

void Hospital::sortDoctors() {
    doctors.sort(compareDoctors);
}



bool Hospital::addDoctor(unsigned codM1, string medicalSpecialty1) {

    unsigned countDoctors = 0;
    for (auto it = doctors.begin(); it != doctors.end(); it++) {
        if ((*it).getMedicalSpecialty() == medicalSpecialty1)
            countDoctors++;
    }
    if (countDoctors >= 3)
        return false;

    Doctor d(codM1, medicalSpecialty1);
    doctors.push_back(d);

    return true;
}



queue<Patient> Hospital::removeDoctor(unsigned codM1) {

    queue<Patient> p1;

    for (auto it = doctors.begin(); it != doctors.end(); it++) {
        if ((*it).getCode() == codM1) {
            p1 = (*it).getPatients();
            doctors.erase(it);
            return p1;
        }
    }

    throw DoctorInexistent();
}


bool Hospital::putInLessBusyDoctor(unsigned cod1, string medicalSpecialty1) {

    list<Doctor> doctorsSpecialty;
    for (auto it = doctors.begin(); it != doctors.end(); it++) {
        if ((*it).getMedicalSpecialty() == medicalSpecialty1) {
            doctorsSpecialty.push_back((*it));
        }
    }
    if (doctorsSpecialty.empty())
        return false;

    Patient p(cod1, medicalSpecialty1);

    Doctor menosOcupado = doctorsSpecialty.front();

    for (auto it = doctorsSpecialty.begin(); it != doctorsSpecialty.end(); it++) {
        if ((*it).getPatients().size() < menosOcupado.getPatients().size())
            menosOcupado = *it;
    }

    for (auto it = doctors.begin(); it != doctors.end(); it++) {
        if ((*it).getCode() == menosOcupado.getCode())
            (*it).addPatient(p);
    }

    return true;
}



void Hospital::processPatient(unsigned codM1) {

    bool finished = false;
    Patient p;
    for (auto it = doctors.begin(); it != doctors.end(); it++) {
        if (((*it).getCode() == codM1) && ((*it).getPatients().size() > 0)) {
            p = (*it).removeNextPatient();
            for (auto itr = letterTray.begin(); itr != letterTray.end(); itr++) {
                if ((*itr).size() < trayCapacity) {
                    (*itr).push(p);
                    finished = true;
                    break;
                }
            }
            if (!finished) {
                stack<Patient> s;
                s.push(p);
                letterTray.push_back(s);
                break;
            }
        }
    }
}


unsigned Hospital::removePatients(unsigned codP1) {

    unsigned result = 0;

    for (auto it = letterTray.begin(); it != letterTray.end(); it++) {

        if ((*it).top().getCode() == codP1) {
            (*it).pop();
            result++;

            if ((*it).size() == 0)
                it = --letterTray.erase(it);
        }
    }
    return result;
}
