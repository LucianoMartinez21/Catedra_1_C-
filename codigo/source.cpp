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
    DeleteAt = NULL;
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

bool Person::SetEmail(char Email[255]){
    for(int i = 0; i < 255; i++)
        this->Email[i] = Email[i];
}

int Person::GetID(){
    return ID;
}
void Person::GetRun(){
    std::cout << Run << "-" << DV << std::endl;
}
void Person::GetNames(){
    std::cout << Names << std::endl;
}
void Person::GetFather(){
    std::cout << FatherName << std::endl;
}
void Person::GetMother(){
    std::cout << MotherName << std::endl;
}
void Person::GetFullName(){
    std::cout << Names << " " << FatherName << " " << MotherName << std::endl;
}

bool Person::Borrar(){
    if(DeleteAt != NULL){
        return false;
    }else{
        // Get current time
        DeleteAt = time(&DeleteAt); 
        return true;
    }
       
}
void Person::GetDeleteAt(){
    struct tm ts;
    char buf[80];
    ts = *localtime(&DeleteAt);
    // Format time, "ddd dd/mm/yyyy zzz"
    strftime(buf, sizeof(buf), "%a %d/%m/%Y %Z", &ts);
    printf("Delete at: %s\n", buf);
    std::cout << "Delete at: " << buf << std::endl;
}
//Clase Usuario
User::User(){
    std::cout << "hola"<< std::endl;
}
//Clase Entrevistado

//Clase Examen

//Clase Pregunta

//Clase Respuesta