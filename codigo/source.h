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
    bool SetRun(int);
    bool SetDV(char);
    bool SetNames(char[255]);
    bool SetFather(char[255]);
    bool SetMother(char[255]);
    bool SetPassword(char[255]);
    bool SetEmail(char[255]);
    bool Borrar();
};
#endif
