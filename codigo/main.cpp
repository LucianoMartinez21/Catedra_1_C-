#include <bits/stdc++.h>
#include <fstream>
#include "source.h"
#include <locale.h>
using namespace std;

//Functions
void Menu(int);
/*PascalCase*/
//Global Variables
fstream UserFile("User/User.txt");
fstream SurveyFile("Surveyed/Surveyed.txt");
fstream TestFile("Test/Test.txt");
fstream QuestionFile("Question/Question.txt");
fstream AnswerFile("Answer/Answer.txt");
string MainDir("/Catedra_1_C-");
int Option, IdCouter;
void IdVerifier(User);
void IdVerifier(Surveyed);
void IdVerifier(Test);
void IdVerifier(Question);
void IdVerifier(Answer);
string Searcher(fstream&, string);
void Menu(int);
void TestMenu(int);
string StrAux;

int main(){
    setlocale(LC_ALL, "spanish");
    while (true)
    {
        cout << "=====Programa de Encuestas=====\n1) Crear Cuenta"<<
        "\n2) Iniciar Sesion" << "\n3) Salir"
        << endl;
        cin >> Option;
        Menu(Option);
    }
}

char Name[255], FatherName[255], MotherName[255], *Dv,
    Email[255];
int Run, Day, Month, Year, GenderNumber, Phone;

void Menu(int Election){

    char Password[255];
    User Pollster = User(); // pollster = Encuestador
    switch (Election){
        case 1:
            //Pollster.SetID(IdCouter);
            IdVerifier(Pollster);
            cout << "Ingrese su nombre: ";
            scanf("%s", Name);
            cout << "\nIngrese su Apellido Paterno: ";
            scanf("%s", FatherName);
            cout << "\nIngrese su Apellido Materno: ";
            scanf("%s", MotherName);
            Pollster.SetFullName(Name, FatherName, MotherName);

            cout << "\nIngrese su Run (sin el digito verificador): ";
            cin >> Run;
            Pollster.SetRun(Run);

            cout << "\nIngrese su digito verificador: ";
            scanf("%c", Dv);
            Pollster.SetDV(Dv);

            cout << "\nIngrese su Fecha de Nacimiento: \nDia:";
            cin >> Day;
            cout << "\nMes:";
            cin >> Month;
            cout << "\nAño:";
            cin >> Year;
            Pollster.SetBirthday(Day, Month, Year);

            cout << "\nElija su genero:\n1)Hombre\n2)Mujer\n3)Otros";
            while (GenderNumber < 1 && GenderNumber > 3)
            {
                cin >> GenderNumber;
                Pollster.SetGender(GenderNumber);
            }

            cout << "\nIngrese su Correo: ";
            scanf("%s", Email);
            Pollster.SetEmail(Email);

            cout << "\nIngrese su Telefóno: ";
            cin >> Phone;
            Pollster.SetPhone(Phone);

            cout << "\nIngrese su Contraseña: ";
            scanf("%s", Password);
            Pollster.SetPassword(Password);

            UserFile << "/////////////" << endl;
            UserFile << "Id: " << Pollster.GetID() << endl;
            UserFile << "Nombre: " << Name << endl;
            UserFile << "Apellido Paterno: " << FatherName << endl;
            UserFile << "Apellido Materno: " << MotherName << endl;
            UserFile << "Run: " << Pollster.GetRun() << endl;
            UserFile << "Fecha de Nacimiento: " << Pollster.GetBirthday() << endl;
            UserFile << "Genero: " << Pollster.GetGender() << endl;
            UserFile << "Correo: " << Email << endl;
            UserFile << "Telefóno: " << Phone << endl;
            UserFile << "Contraseña: " << Password << endl;
            UserFile << "DeleteAt: " << endl;
            break;
        case 2:
            while (Email != "0")
            {
                cout << "\nIngrese su Correo (Digite '0' para cancelar): ";
                scanf("%s", Email);
                cout << "\nIngrese su Contraseña: ";
                scanf("%s", Password);
                if(strcmp(Email, Pollster.GetEmail()) == 0 && strcmp(Password,Pollster.GetPassword())){
                    cout << "¡Sesion Iniciada!\n" << "=====Programa de Encuestas=====\n" <<
                    "1)Crear perfil de entrevistado\n" <<
                    "2)Crear test\n" << "3)Crear preguntas\n" << "4)Realizar test\n" << endl;
                    while (Election < 1 && Election > 3){
                        cin >> Election;
                        TestMenu(Election);
                    }
                    /* Objetivos
                        +crear perfil de entrevistado Done
                        +crear test
                            -crear el propio test
                            -añadir preguntas
                        +crear preguntas y que se puede elegir a que test puede entrar
                        +realizar encuesta
                            -Se crea constantemente respuestas hasta que el limite de preguntas del test termina
                        +terminar de hacer la funcion IdVerifier Done
                    */
                    break;
                }else{
                    cout << "Ingrese los datos correctos" << endl;
                }
            }
            break;
        case 3:
            cout << "Bye bye!" << endl;
            exit(Election);
            break;
    }
}
void TestMenu(int Election){
    Surveyed SurveyedPerson = Surveyed();
    Test NewTest = Test();
    Question NewQuestion = Question();
    Answer NewAnswer = Answer();
    switch (Election)
    {
    case 1: // crear perfil de encuestado
        //SurveyedPerson.SetID(IdCouter);
        IdVerifier(SurveyedPerson);

        cout << "Ingrese el nombre del entrevistado: ";
        scanf("%s", Name);
        cout << "\nIngrese el Apellido Paterno del entrevistado: ";
        scanf("%s", FatherName);
        cout << "\nIngrese el Apellido Materno del entrevistado: ";
        scanf("%s", MotherName);
        SurveyedPerson.SetFullName(Name, FatherName, MotherName);

        cout << "\nIngrese el Run del entrevistado(sin el digito verificador): ";
        cin >> Run;
        SurveyedPerson.SetRun(Run);

        cout << "\nIngrese el digito verificador del entrevistado: ";
        scanf("%c", Dv);
        SurveyedPerson.SetDV(Dv);

        cout << "\nIngrese la Fecha de Nacimiento del entrevistado: \nDia:";
        cin >> Day;
        cout << "\nMes:";
        cin >> Month;
        cout << "\nAño:";
        cin >> Year;
        SurveyedPerson.SetBirthday(Day, Month, Year);

        cout << "\nElija su genero:\n1)Hombre\n2)Mujer\n3)Otros";
        while (GenderNumber < 1 && GenderNumber > 3)
        {
            cin >> GenderNumber;
            SurveyedPerson.SetGender(GenderNumber);
        }

        cout << "\nIngrese su Correo: ";
        scanf("%s", Email);
        SurveyedPerson.SetEmail(Email);

        cout << "\nIngrese su Telefóno: ";
        cin >> Phone;
        SurveyedPerson.SetPhone(Phone);

        SurveyFile << "/////////////" << endl;
        SurveyFile << "Id: " << SurveyedPerson.GetID() << endl;
        SurveyFile << "Nombre: " << Name << endl;
        SurveyFile << "Apellido Paterno: " << FatherName << endl;
        SurveyFile << "Apellido Materno: " << MotherName << endl;
        SurveyFile << "Run: " << SurveyedPerson.GetRun() << endl;
        SurveyFile << "Fecha de Nacimiento: " << SurveyedPerson.GetBirthday() << endl;
        SurveyFile << "Genero: " << SurveyedPerson.GetGender() << endl;
        SurveyFile << "Correo: " << Email << endl;
        SurveyFile << "Telefóno: " << Phone << endl;
        SurveyFile << "DeleteAt: " << endl;
        break;
    case 2:
        IdVerifier(NewTest);
        cout << "Ingrese el titulo del test: ";
        scanf("%s", Name);
        NewTest.SetName(Name);
        cout << "Ingrese la razón del test: ";
        scanf("%s", Name);
        NewTest.SetObservation(Name);
        
        break;
    case 3:
        break;
    default:
        break;
    }
}

string AuxiliarString;
void IdVerifier(User AuxUser){
    getline(UserFile, AuxiliarString);
    if(IdCouter == NULL || AuxiliarString.length() == 0){
        IdCouter = 1;
    }else{
        IdCouter = stoi(Searcher(UserFile, "Id:"));
    }
    AuxUser.SetID(IdCouter);
}
void IdVerifier(Surveyed AuxSurveyed){
    
    getline(SurveyFile, AuxiliarString);
    if(IdCouter == NULL || AuxiliarString.length() == 0){
        IdCouter = 1;
    }else{
        IdCouter = stoi(Searcher(SurveyFile, "Id:"));
    }
    AuxSurveyed.SetID(IdCouter);
}
void IdVerifier(Test AuxTest){
    getline(TestFile, AuxiliarString);
    if(IdCouter == NULL || AuxiliarString.length() == 0){
        IdCouter = 1;
    }else{
        IdCouter = stoi(Searcher(TestFile, "Id:"));
    }
    AuxTest.SetID(IdCouter);
}
void IdVerifier(Question AuxQuestion){
    getline(QuestionFile, AuxiliarString);
    if(IdCouter == NULL || AuxiliarString.length() == 0){
        IdCouter = 1;
    }else{
        IdCouter = stoi(Searcher(QuestionFile, "Id:"));
    }
    AuxQuestion.SetID(IdCouter);
}
void IdVerifier(Answer AuxAnswer){
    getline(AnswerFile, AuxiliarString);
    if(IdCouter == NULL || AuxiliarString.length() == 0){
        IdCouter = 1;
    }else{
        IdCouter = stoi(Searcher(AnswerFile, "Id:"));
    }
    AuxAnswer.SetID(IdCouter);
}

string Searcher(fstream &f, string keyWord){
    string aux= "0";
    getline(f, StrAux);
    for (size_t i = 0; i < StrAux.length(); i++)
    {
        if (isdigit(StrAux[i]) == 1){
            if(StrAux[i] > stoi(aux)){
                aux = StrAux[i];
            }
        }
    }
    if(f.eof()) return aux;
    return Searcher(f, keyWord);
}