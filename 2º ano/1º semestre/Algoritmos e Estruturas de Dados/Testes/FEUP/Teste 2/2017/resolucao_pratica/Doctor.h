
#ifndef TESTE_2017_DOCTOR_H
#define TESTE_2017_DOCTOR_H


#include <string>
#include <queue>


using namespace std;

class Patient {
    unsigned codeP;
    string medicalSpecialty;
public:
    Patient();
    Patient(unsigned cod, string mS);
    string getMedicalSpecialty() const;
    unsigned getCode() const;
    void operator=(const Patient &p1);
};


class Doctor {
    unsigned codeM;
    string medicalSpecialty;
    queue<Patient> patients;
public:
    Doctor(unsigned codM, string mS);
    Doctor(unsigned codM, string mS, queue<Patient> patients1);
    unsigned getCode() const;
    string getMedicalSpecialty() const;
    queue<Patient> getPatients() const;
    void addPatient(const Patient &p1);
    Patient removeNextPatient();
    void operator=(const Doctor &d1);

    void moveToFront(unsigned codP1);

    class PatientInexistent {};

};


#endif //TESTE_2017_DOCTOR_H
