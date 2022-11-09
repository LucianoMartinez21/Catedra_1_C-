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
//Constructors
Person::Person(){
    ID = 0;
    Run = 0;
    Phone = 0;
    DV = '\0';
    DeleteAt = NULL;
    Birth = NULL;
}
Person::Person(int Dd, int Mm, int Year){
    ID = 0;
    Run = 0;
    Phone = 0;
    DV = '\0';// '\0' ese una forma de asignar un caracter nulo
    DeleteAt = NULL;
    Birth = new Birthday(Dd, Mm, Year);
}
//Setters
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
bool Person::SetBirthday(int Dd, int Mm, int Year){
    Birth = new Birthday(Dd, Mm, Year);
}

//Getters
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
    //std::cout << "hola"<< std::endl;
}
bool User::SetPassword(char Pass[255]){
    for(int i = 0; i < 255; i++) 
        Password[i] = Pass[i];
}


//Clase Entrevistado
Surveyed::Surveyed(){}

bool Surveyed::SetObservation(char Observation[255]){
    for(int i = 0; i < 255; i++) 
        this->Observation[i] = Observation[i];
}
void Surveyed::GetObservation(){
    std::cout << Observation << std::endl;
}
//Clase Examen
Test::Test(){
    ID = 0;
    CutPoint = 0;
    MaxPoint = 0;
}

//Setters
bool Test::SetID(int Id){
    ID = Id;
}
bool Test::SetCutPoint(int Cut){
    CutPoint = Cut;
}
bool Test::SetMaxPoint(int Max){
    MaxPoint = Max;
}
bool Test::SetName(char Name[30]){
    for(int i = 0; i < 255; i++)
        this->Name[i] = Name[i];
}
bool Test::SetObservation(char Observation[255]){
    for(int i = 0; i < 255; i++) 
        this->Observation[i] = Observation[i];
}

//Getters
int Test::GetID(){
    return ID;
}
int Test::GetCutPoint(){
    return CutPoint;
}
int Test::GetMaxPoint(){
    return MaxPoint;
}
void Test::GetName(){
    std::cout << Name << std::endl;
}


//Clase Pregunta

//Clase Respuesta