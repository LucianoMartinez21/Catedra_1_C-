#ifndef _SOURCE_H_
#define _SOURCE_H_
#include <iostream>
#include <cstdio>
class person{
private:
    int ID, Run;
    char DV, Names[255], FatherName[255],
    MotherName[255], Password[255], 
    Email[255];
    time_t DeleteAt;
public:
    person();
    bool SetID(int);
    int GetID();
    bool SetRun(int);
    int GetRun();
    bool SetDV(char);
    char GetDV();
    bool SetNames(char[255]);
    char GetNames();
    bool SetFather(char[255]);
    char GetFather();
    bool SetMother(char[255]);
    char GetMother();
    void GetNombreCompleto();
    bool SetPassword(char[255]);
    //char GetPassword();
    bool SetEmail(char[255]);
    //char GetEmail();
    bool Borrar();
    void GetDeleteAt();
};
#endif
