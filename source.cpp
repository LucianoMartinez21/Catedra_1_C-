#include "source.h"
//Clase Cumpleaños
Birthday::Birthday(int Dd, int Mm, int Year){
    Day = Dd;
    Month = Mm;
    this->Year = Year;
}
//char AuxStr1[10], AuxStr2[10], AuxStr3[10]; // Mas cinta americana
std::string Birthday::GetBirthday(){
    return std::to_string(Day) + "/" + std::to_string(Month) +
    "/" + std::to_string(Year);
    /*
    sprintf(AuxStr1, "%d", Day);
    sprintf(AuxStr2, "%d", Month);
    sprintf(AuxStr3, "%d", Year);
    strcat(AuxStr1,"/");
    strcat(AuxStr1, AuxStr2);
    strcat(AuxStr1,"/");
    strcat(AuxStr1, AuxStr3);*/
}

//Clase Persona
//Constructors
Person::Person(){
    Run = 0;
    Phone = 0;
    DV = '\0';
    DeleteAt = 0;
    Birth = NULL;
}
Person::Person(int Dd, int Mm, int Year){
    ID = 0;
    Run = 0;
    Phone = 0;
    //DV = '\0';// '\0' ese una forma de asignar un caracter nulo
    DeleteAt = 0;
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
bool Person::SetFullName(std::string Name, std::string FatherName, std::string MotherName){
    Names = Name;
    this->FatherName = FatherName;
    this->MotherName = MotherName;
}
bool Person::SetEmail(std::string Email){
    this->Email = Email;
}
bool Person::SetBirthday(int Dd, int Mm, int Year){
    Birth = new Birthday(Dd, Mm, Year);
}
bool Person::SetGender(int Option){
    switch (Option)
    {
    case 1:
        Gender = Male;
        break;
    case 2:
        Gender = Female;
        break;
    case 3:
        Gender = Other;
        break;
    default:
        std::cout << "Ingrese la opcion correcta" << std::endl;
        break;
    }
}

//Getters
int Person::GetID(){
    return ID;
}
//char RunAux[30]; //Pegado con cinta americana
std::string Person::GetRun(){
    return std::to_string(Run) + "-" + DV;
    /*
    sprintf(RunAux, "%d", Run);
    strcat(RunAux,"-");
    //strcat(RunAux, DV);
    strncat(RunAux, &DV, 1);*/
}
std::string Person::GetNames(){
    return Names;
    //std::cout << Names << std::endl;
}
std::string Person::GetFather(){
    return FatherName;
}
std::string Person::GetMother(){
    return MotherName;
}
//char FullName[765]; // Un desperdicio de espacio para un desliz
std::string Person::GetFullName(){ 

    /*strcat(FullName, Names);
    strcat(FullName, " ");
    strcat(FullName, FatherName);
    strcat(FullName, " ");
    strcat(FullName, MotherName);*/
    return Names + " " + FatherName + " " + MotherName;
}
std::string Person::GetGender(){
    switch (Gender)
        {
        case 0:
            return "Male";
            break;
        case 1:
            return "Female";
            break;
        case 2:
            return "Other";
            break;
    }
}
std::string Person::GetBirthday(){
    return Birth->GetBirthday();
}
std::string Person::GetEmail(){
    return Email;
}
bool Person::Borrar(){
    if(DeleteAt != 0){
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
    //printf("Delete at: %s\n", buf);
    std::cout << "Delete at: " << buf << std::endl;
}
//Clase Usuario
User::User(){
    //std::cout << "hola"<< std::endl;
}
/*
bool User::SetPassword(char Pass[255]){
    for(int i = 0; i < 255; i++) 
        Password[i] = Pass[i];
}

//Getters
char* User::GetPassword(){
    return Password;
}*/

//Clase Entrevistado
Surveyed::Surveyed(){}

bool Surveyed::SetObservation(std::string Observation){
    this->Observation = Observation;
}
std::string Surveyed::GetObservation(){
    return Observation;
    //std::cout << Observation << std::endl;
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
bool Test::SetName(std::string Name){
    this->Name = Name;
}
bool Test::SetObservation(std::string Observation){ 
    this->Observation = Observation;
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
std::string Test::GetName(){
    //std::cout << Name << std::endl;
    return Name;
}
std::string Test::GetObservation(){
    return Observation;
}
bool Test::Borrar(){
    if(DeleteAt != 0){
        return false;
    }else{
        // Get current time
        DeleteAt = time(&DeleteAt); 
        return true;
    }       
}
void Test::GetDeleteAt(){
    struct tm ts;
    char buf[80];
    ts = *localtime(&DeleteAt);
    // Format time, "ddd dd/mm/yyyy zzz"
    strftime(buf, sizeof(buf), "%a %d/%m/%Y %Z", &ts);
    std::cout << "Delete at: " << buf << std::endl;
}
//Clase Pregunta
Question::Question(){
    ID = 0;
    FkId = 0;
    DeleteAt = 0;
}

//Setters
bool Question::SetID(int Id){
    ID = Id;
}
bool Question::SetQuestion(std::string Question){ 
    QuestionText = Question;
}
bool Question::SetDescription(std::string Description){
    this->Description = Description;
}
bool Question::AssignedTest(Test Exam){
    FkId = Exam.GetID();
}

//Getters
int Question::GetID(){
    return ID;
}
int Question::GetFkId(){
    return FkId;
}
std::string Question::GetQuestion(){
    //std::cout << QuestionText << std::endl;
    return QuestionText;
}
std::string Question::GetDescription(){
    //std::cout << Description << std::endl;
    return Description;
}
bool Question::Borrar(){
    if(DeleteAt != 0){
        return false;
    }else{
        // Get current time
        DeleteAt = time(&DeleteAt); 
        return true;
    }       
}
void Question::GetDeleteAt(){
    struct tm ts;
    char buf[80];
    ts = *localtime(&DeleteAt);
    // Format time, "ddd dd/mm/yyyy zzz"
    strftime(buf, sizeof(buf), "%a %d/%m/%Y %Z", &ts);
    //printf("Delete at: %s\n", buf);
    std::cout << "Delete at: " << buf << std::endl;
}

// ASSIGNEDTEST(TEST){FKID == TEST.GETID()}
//Clase Respuesta
Answer::Answer(){
    ID = 0;
    Point = 0;
    FkId = 0;
    DeleteAt = 0;
}

//Setters
bool Answer::SetID(int Id){
    ID = Id;
}
bool Answer::SetPoint(int Point){
    this->Point = Point;
}
bool Answer::AssignedQuestion(Question Query){
    FkId = Query.GetID();
}
bool Answer::SetText(std::string Text){ 
    this->Text = Text;
}
bool Answer::SetObservation(std::string Observation){
    this->Observation = Observation;
}

//Getters
int Answer::GetID(){
    return ID;
}
int Answer::GetPoint(){
    return Point;
}
int Answer::GetFkId(){
    return FkId;
}
std::string Answer::GetObservation(){
    return Observation;
}
std::string Answer::GetText(){
    //std::cout << Text << std::endl;
    return Text;
}
bool Answer::Borrar(){
    if(DeleteAt != 0){
        return false;
    }else{
        // Get current time
        DeleteAt = time(&DeleteAt); 
        return true;
    }       
}
void Answer::GetDeleteAt(){
    struct tm ts;
    char buf[80];
    ts = *localtime(&DeleteAt);
    // Format time, "ddd dd/mm/yyyy zzz"
    strftime(buf, sizeof(buf), "%a %d/%m/%Y %Z", &ts);
    std::cout << "Delete at: " << buf << std::endl;
}