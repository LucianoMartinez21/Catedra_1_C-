#include "source.h"
//Clase Cumpleaños
Birthday::Birthday(int Dd, int Mm, int Year){
    Day = Dd;
    Month = Mm;
    this->Year = Year;
}
void Birthday::GetBirthday(){
    std::cout<<Day<<"/"<<Month<<"/"<<Year<<std::endl;
}
//Clase Persona
Person::Person(int Dd, int Mm, int Year){
    Birth = new Birthday(Dd, Mm, Year);
}
bool Person::SetID(int Id){
    ID = Id;
}
bool Person::SetRun(int Rut){
    Run = Rut;
}
bool Person::SetPhone(int Num){
    Phone = Num;
}
bool Person::SetDV(char Dv){
    DV = Dv;
}
bool Person::SetFullName(char Name[255],char FatherName[255], char MotherName[255]){
    for(int i = 0; i < 255; i++){
        Names[i] = Name[i];
        this->FatherName[i] = FatherName[i];
        this->MotherName[i] = MotherName[i];
    }
}
bool Person::SetID(int id){
    ID = id;
}

//Clase Usuario

//Clase Entrevistado

//Clase Examen

//Clase Pregunta

//Clase Respuesta