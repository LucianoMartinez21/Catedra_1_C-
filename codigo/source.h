#ifndef _SOURCE_H_
#define _SOURCE_H_
#include <iostream>
#include <cstdio>
#include <time.h>
#include <stdio.h>
#include <string.h>
enum Genus{Male, Female, Other};
class Birthday{
private:
    int Day, Month, Year;
public:
    Birthday(int, int, int);
    char* GetBirthday();
};

class Person{
private:
    int ID, Run, Phone;
    char *DV, Names[255], FatherName[255], // DV = Digito verificador
    MotherName[255], Email[255];
    Birthday *Birth;
    enum Genus Gender;
    time_t DeleteAt;
public:
    Person();
    Person(int,int,int);
    
    //Setters
    bool SetID(int);
    bool SetRun(int);
    bool SetPhone(int);
    bool SetDV(char*);
    bool SetFullName(char[255], char[255], char[255]);
    //bool SetNames(char[255]);
    //bool SetFather(char[255]);
    //bool SetMother(char[255]);
    bool SetEmail(char[255]);
    bool SetBirthday(int, int, int);
    bool SetGender(int);

    //Getters    
    int GetID();
    //int GetPhone();
    //char GetDV();
    char* GetRun();//Lo devuelve con digito verificador
    char* GetNames();
    char* GetFather();
    char* GetMother();
    char* GetFullName();
    char* GetGender();
    char* GetBirthday();
    char* GetEmail();
    bool Borrar();
    void GetDeleteAt();

};

class User : public Person{
private:
    char Password[255];
public:
    User();
    bool SetPassword(char[255]);
    char* GetPassword();
};

class Surveyed : public Person{
private:
    char Observation[255];
public:
    Surveyed();
    bool SetObservation(char[255]);
    char* GetObservation();
};

class Test{
private:
    int ID, CutPoint, MaxPoint;
    char Name[30], Observation[255];
public:
    Test();
    //Setters
    bool SetID(int);
    bool SetCutPoint(int); // punto de corte donde una persona se clasifica con depreshoun
    bool SetMaxPoint(int);
    bool SetName(char[30]);
    bool SetObservation(char[255]); // Se escribe el objetivo o motivo tipo automemoria o observacion interna del objetivo del test
    //Getters
    int GetID();
    int GetCutPoint();
    int GetMaxPoint();
    char* GetName();
    char* GetObservation();
}; 

class Question{
private:
    int ID, FkId;
    char QuestionText[255], Description[255];
    time_t DeleteAt;
public:
    Question();
    //Setters
    bool SetID(int);
    bool SetQuestion(char[255]);
    bool SetDescription(char[255]);
    bool AssignedTest(Test);
    //Getters
    int GetID();
    int GetFkId();
    char* GetQuestion();
    char* GetDescription();
    bool Borrar();
    void GetDeleteAt();
};

class Answer{
private:
    int ID, Point, FkId;
    char Text[255], Observation[255];
    time_t DeleteAt;
public:
    Answer();
    //Setters
    bool SetID(int);
    bool SetPoint(int);
    bool AssignedQuestion(Question);
    bool SetText(char[255]);
    bool SetObservation(char[255]);
    //Getters 
    int GetID();
    int GetPoint();
    int GetFkId();
    char* GetObservation();
    char* GetText();
    bool Borrar();
    void GetDeleteAt();
};
#endif