#include "source.h"
//Clase Cumpleaños
Birthday::Birthday(int Dd, int Mm, int Year){
    Day = Dd;
    Month = Mm;
    this->Year = Year;
}
char AuxStr1[10], AuxStr2[10], AuxStr3[10]; // Mas cinta americana
char* Birthday::GetBirthday(){
    sprintf(AuxStr1, "%d", Day);
    sprintf(AuxStr2, "%d", Month);
    sprintf(AuxStr3, "%d", Year);
    strcat(AuxStr1,"/");
    strcat(AuxStr1, AuxStr2);
    strcat(AuxStr1,"/");
    strcat(AuxStr1, AuxStr3);
    return AuxStr1;
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
bool Person::SetDV(char *Dv){
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
char RunAux[30]; //Pegado con cinta americana
char* Person::GetRun(){
    sprintf(RunAux, "%d", Run);
    strcat(RunAux,"-");
    strcat(RunAux, DV);
    return RunAux;
}
char* Person::GetNames(){
    return Names;
    //std::cout << Names << std::endl;
}
char* Person::GetFather(){
    return FatherName;
}
char* Person::GetMother(){
    return MotherName;
}
char* Person::GetFullName(){
    char FullName[255*3]; // Un desperdicio de espacio para un desliz
    strcat(FullName, Names);
    strcat(FullName, " ");
    strcat(FullName, FatherName);
    strcat(FullName, " ");
    strcat(FullName, MotherName);
    return FullName;
}
char* Person::GetGender(){
    switch (Gender)
        {
        case 0:
            return const_cast<char*>("Male");
            break;
        case 1:
            return const_cast<char*>("Female");
            break;
        case 2:
            return const_cast<char*>("Other");
            break;
    }
}
char* Person::GetBirthday(){
    return Birth->GetBirthday();
}
char* Person::GetEmail(){
    return Email;
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
    //printf("Delete at: %s\n", buf);
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

//Getters
char* User::GetPassword(){
    return Password;
}

//Clase Entrevistado
Surveyed::Surveyed(){}

bool Surveyed::SetObservation(char Observation[255]){
    for(int i = 0; i < 255; i++) 
        this->Observation[i] = Observation[i];
}
char* Surveyed::GetObservation(){
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
bool Test::SetName(char Name[30]){
    for(int i = 0; i < 30; i++)
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
char* Test::GetName(){
    //std::cout << Name << std::endl;
    return Name;
}
char* Test::GetObservation(){
    return Observation;
}

//Clase Pregunta
Question::Question(){
    ID = 0;
    FkId = 0;
    DeleteAt = NULL;
}

//Setters
bool Question::SetID(int Id){
    ID = Id;
}
bool Question::SetQuestion(char Question[255]){
    for(int i = 0; i < 255; i++) 
        QuestionText[i] = Question[i];
}
bool Question::SetDescription(char Description[255]){
    for(int i = 0; i < 255; i++) 
        this->Description[i] = Description[i];
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
char* Question::GetQuestion(){
    //std::cout << QuestionText << std::endl;
    return QuestionText;
}
char* Question::GetDescription(){
    //std::cout << Description << std::endl;
    return Description;
}
bool Question::Borrar(){
    if(DeleteAt != NULL){
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
    DeleteAt = NULL;
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
bool Answer::SetText(char Text[255]){
    for(int i = 0; i < 255; i++) 
        this->Text[i] = Text[i];
}
bool Answer::SetObservation(char Observation[255]){
    for(int i = 0; i < 255; i++) 
        this->Observation[i] = Observation[i];
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
char* Answer::GetObservation(){
    return Observation;
}
char* Answer::GetText(){
    //std::cout << Text << std::endl;
    return Text;
}
bool Answer::Borrar(){
    if(DeleteAt != NULL){
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
    printf("Delete at: %s\n", buf);
    std::cout << "Delete at: " << buf << std::endl;
}