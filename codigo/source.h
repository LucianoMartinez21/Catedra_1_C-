#ifndef _SOURCE_H_
#define _SOURCE_H_
#include <iostream>
#include <cstdio>
enum Genus{Male, Female, Other};
class Birthday{
private:
    int Day, Month, Year;
public:
    Birthday(int, int, int);
    void GetBirthday();
};

class Person{
private:
    int ID, Run, Phone;
    char DV, Names[255], FatherName[255],
    MotherName[255], Email[255];
    Birthday Birth;
    enum Genus Gender;
    time_t DeleteAt;
public:
    Person();
    
    //Setters
    bool SetID(int);
    bool SetRun(int);
    bool SetPhone(int);
    bool SetDV(char);
    bool SetNames(char[255]);
    bool SetFather(char[255]);
    bool SetMother(char[255]);
    bool SetEmail(char[255]);
    
    //Getters    
    int GetID();
    int GetRun();
    //int GetPhone();
    char GetDV();
    char GetNames();
    char GetFather();
    char GetMother();
    void GetNombreCompleto();
    //bool SetPassword(char[255]);
    //char GetPassword();
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
