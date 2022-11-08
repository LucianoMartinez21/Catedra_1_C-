#ifndef _SOURCE_H_
#define _SOURCE_H_
#include <iostream>
#include <cstdio>
class Birthday{
private:
    int Day, Month, Year;
public:
    Birthday();
};
class Person{
private:
    int ID, Run, Phone;
    char DV, Names[255], FatherName[255],
    MotherName[255], Email[255];
    time_t DeleteAt;
public:
    Person();
    bool SetID(int);
    int GetID();
    bool SetRun(int);
    int GetRun();
    bool SetPhone(int);
    //int GetPhone();
    bool SetDV(char);
    char GetDV();
    bool SetNames(char[255]);
    char GetNames();
    bool SetFather(char[255]);
    char GetFather();
    bool SetMother(char[255]);
    char GetMother();
    void GetNombreCompleto();
    //bool SetPassword(char[255]);
    //char GetPassword();
    bool SetEmail(char[255]);
    //char GetEmail();
    bool Borrar();
    void GetDeleteAt();
};

class User : public Person{
private:
    char Password[255];
public:
    bool SetPassword(char[255]);
    //char GetPassword();
};

class Surveyed : public Person{
private:
    char Observation[255];
public:
    bool SetObservation(char[255]);
    char GetObservation();
};
#endif
