#ifndef _SOURCE_H_
#define _SOURCE_H_
#include <iostream>
#include <cstdio>
#include <time.h>
#include <stdio.h>
#include <string.h>
//using namespace std;
enum Genus{Male, Female, Other};
class Birthday{
private:
    int Day, Month, Year;
public:
    Birthday(int, int, int);
    //char* GetBirthday();
    std::string GetBirthday();
};
class Person{
private:
    int ID, Run, Phone;
    std::string Names, FatherName, MotherName, Email;
    char DV; // DV = Digito verificador
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
    bool SetDV(char);
    bool SetFullName(std::string, std::string, std::string);
    bool SetEmail(std::string);
    bool SetBirthday(int, int, int);
    bool SetGender(int);

    //Getters    
    int GetID();
    //int GetPhone();
    //char GetDV();
    std::string GetRun();//Lo devuelve con digito verificador
    std::string GetNames();
    std::string GetFather();
    std::string GetMother();
    std::string GetFullName();
    std::string GetGender();
    std::string GetBirthday();
    std::string GetEmail();
    bool Borrar();
    void GetDeleteAt();

};

class User : public Person{
private:
    //std::string Password;
public:
    User();
    //bool SetPassword(std::string);
    //std::string GetPassword();
};

class Surveyed : public Person{
private:
    std::string Observation;
public:
    Surveyed();
    bool SetObservation(std::string);
    std::string GetObservation();
};

class Test{
private:
    int ID, CutPoint, MaxPoint;
    std::string Name, Observation;
    time_t DeleteAt;
public:
    Test();
    //Setters
    bool SetID(int);
    bool SetCutPoint(int); // punto de corte donde una persona se clasifica con depreshoun
    bool SetMaxPoint(int);
    bool SetName(std::string);
    bool SetObservation(std::string); // Se escribe el objetivo o motivo tipo automemoria o observacion interna del objetivo del test
    
    //Getters
    int GetID();
    int GetCutPoint();
    int GetMaxPoint();
    std::string GetName();
    std::string GetObservation();
    bool Borrar();
    void GetDeleteAt();
}; 

class Question{
private:
    int ID, FkId;
    std::string QuestionText, Description;
    time_t DeleteAt;
public:
    Question();
    //Setters
    bool SetID(int);
    bool SetQuestion(std::string);
    bool SetDescription(std::string);
    bool AssignedTest(Test);
    //Getters
    int GetID();
    int GetFkId();
    std::string GetQuestion();
    std::string GetDescription();
    bool Borrar();
    void GetDeleteAt();
};

class Answer{
private:
    int ID, Point, FkId; // True False, Desagro medianamente ni fu fa medianamente pos agrado
    std::string Text, Observation;
    time_t DeleteAt;
public:
    Answer();
    //Setters
    bool SetID(int);
    bool SetPoint(int);
    bool AssignedQuestion(Question);
    bool SetText(std::string);
    bool SetObservation(std::string);
    //Getters 
    int GetID();
    int GetPoint();
    int GetFkId();
    std::string GetObservation();
    std::string GetText();
    bool Borrar();
    void GetDeleteAt();
};
#endif
