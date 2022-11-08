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
    char DV, Names[255], FatherName[255], // DV = Digito verificador
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
    bool SetFullName(char[255], char[255], char[255]);
    //bool SetNames(char[255]);
    //bool SetFather(char[255]);
    //bool SetMother(char[255]);
    bool SetEmail(char[255]);
    bool SetBirthday(Birthday);
    bool SetGender(Genus);

    //Getters    
    int GetID();
    int GetRun();
    //int GetPhone();
    char GetDV();
    char GetNames();
    char GetFather();
    char GetMother();
    void GetFullName();

    //char GetEmail();
    bool Borrar();
    void GetDeleteAt();

};

class User : public Person{
private:
    char Password[255];
public:
    User();
    bool SetPassword(char[255]);
    //char GetPassword();
};

class Surveyed : public Person{
private:
    char Observation[255];
public:
    Surveyed();
    bool SetObservation(char[255]);
    char GetObservation();
};

class Test{
private:
    int ID, CutPoint, MaxPoint;
    char Name[30], Observation[255];
public:
    Test();
    //Setters
    bool SetID(int);
    bool SetCutPoint(int);
    bool SetMaxPoint(int);
    bool SetName(char[30]);
    bool SetObservation(char[255]);
    //Getters
    int GetID();
    int GetCutPoint();
    int GetMaxPoint();
    void GetName();
    char GetObservation();
}; 

class Question{
private:
    int ID;
    char QuestionText[255], Description[255];
    time_t DeleteAt;
public:
    Question();
    //Setters
    bool SetID(int);
    bool SetQuestion(char[255]);
    bool SetDescription(char[255]);
    void AssignedTest(Test);
    //Getters
    int GetID();
    void PrintQuestion();
    void PrintDescription();
    bool Borrar();
    void GetDeleteAt();
};

class Answer{
private:
    int ID, Point;
    char Text[255], Observation[255];
    time_t DeleteAt;
public:
    Answer();
    //Setters
    bool SetID(int);
    bool SetPoint(int);
    void AssignedQuestion(Question);
    bool SetObservation(char[255]);
    //Getters 
    int GetID();
    int GetPoint();
    char GetObservation();
    bool Borrar();
    void GetDeleteAt();
};
#endif
