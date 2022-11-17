#include <bits/stdc++.h>
#include <fstream>
#include "source.h"
using namespace std;

//Functions
/*PascalCase*/
fstream UserFile("User/User.txt", ios::out | ios::in | ios::app);
fstream SurveyFile("Surveyed/Surveyed.txt", ios::out | ios::in | ios::app);
fstream TestFile("Test/Test.txt", ios::out | ios::in | ios::app);
fstream QuestionFile("Question/Question.txt", ios::out | ios::in | ios::app);
fstream AnswerFile("Answer/Answer.txt", ios::out | ios::in | ios::app);
int IdCouter = 0;
string Searcher(fstream&, string);
bool EmailChecker(char[255], fstream&);
void Menu(int);
void TestMenu(int);
//Global Variables
string StrAux, Aux, Aux2;

int main(){
    int Option;
    while (true)
    {
        cout << "=====Programa de Encuestas=====\n1) Crear Cuenta"<<
        "\n2) Iniciar Sesion" << "\n3) Salir"
        << endl;
        cin >> Option;
        Menu(Option);
    }
}


char Name[255], FatherName[255], MotherName[255], Dv,
    Email[255];
int Run, Day, Month, Year, GenderNumber, Phone;

void Menu(int Election){
    char Password[255];
    User Pollster = User(); // pollster = Encuestador
    switch (Election){
        case 1:
            //Pollster.SetID(IdCouter);
            //IdVerifier(Pollster, UserFile);
            Aux= "0";
            IdCouter = stoi(Searcher(UserFile, "Id:"))+1;
            Pollster.SetID(IdCouter);

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
            //scanf("%c", Dv);
            cin >> Dv;
            //cout << "Funciona" << endl;
            Pollster.SetDV(Dv);

            cout << "\nIngrese su Fecha de Nacimiento: \nDia:";
            cin >> Day;
            cout << "\nMes:";
            cin >> Month;
            cout << "\nYear:";
            cin >> Year;
            Pollster.SetBirthday(Day, Month, Year);

            cout << "\nElija su genero:\n1)Hombre\n2)Mujer\n3)Otros" << endl;
            cin >> GenderNumber;
            Pollster.SetGender(GenderNumber);
            //GenderNumber = 0;
            /*
            while (GenderNumber < 1 && GenderNumber > 3)
            {
                cin >> GenderNumber;
                Pollster.SetGender(GenderNumber);
            }*/

            cout << "\nIngrese su Correo: ";
            scanf("%s", Email);
            Pollster.SetEmail(Email);

            cout << "\nIngrese su Telefóno: ";
            cin >> Phone;
            Pollster.SetPhone(Phone);

            //cout << "\nIngrese su Contraseña: ";
            //scanf("%s", Password);
            //Pollster.SetPassword(Password);
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
            //UserFile << "Contraseña: " << Password << endl;
            UserFile << "DeleteAt: " << endl;
            cout << "Registro completado!" << endl;
            break;
        case 2:
            while (Election != 0)
            {
                cout << "\nIngrese su Correo: ";
                cin >> Email;
                int Option = 0;
                /*
                cout << "\nIngrese su Contraseña: ";
                scanf("%s", Password);*/

                if(EmailChecker(Email, UserFile) == true){
                    cout << "¡Sesion Iniciada!\n";
                    while (Option != 6){
                        cout << "=====Programa de Encuestas=====\n" <<
                        "1)Crear perfil de entrevistado\n" <<
                        "2)Crear test\n" << "3)Crear preguntas\n" << "4)Crear respuestas\n"<<
                        "5)Realizar test\n" << "6)Salir a menu principal" << endl;
                        cin >> Option;
                        TestMenu(Option);
                    }
                    /* Objetivos
                        +crear perfil de entrevistado Done
                        +crear test Done
                            -crear el propio test
                            -añadir preguntas
                        +crear preguntas y que se puede elegir a que test puede entrar Done
                        +Crear las respuestas Done
                        +realizar encuesta
                        +terminar de hacer la funcion IdVerifier Done
                    */
                    break;
                }else{
                    cout << "Ingrese los datos correctos" << endl;
                }
                cout << "Digite '0' para cancelar\nDigite cualquier numero para continuar" << endl;
                cin >> Election;
            }
            break;
        case 3:
            cout << "Bye bye!" << endl;
            exit(Election);
            break;
    }
}

char QuestionText[255], Description[255];
int MaxPoint, Point, TopPoint;
void TestMenu(int Election){
    Surveyed SurveyedPerson = Surveyed();
    Test NewTest = Test();
    Question NewQuestion = Question();
    Answer NewAnswer = Answer();
    switch (Election)
    {
    case 1:
        // crear perfil de encuestado
        //SurveyedPerson.SetID(IdCouter);
        //IdVerifier(SurveyedPerson, SurveyFile);
        Aux= "0";
        IdCouter = stoi(Searcher(SurveyFile, "Id:"))+1;
        SurveyedPerson.SetID(IdCouter);

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
        cin >> Dv;
        SurveyedPerson.SetDV(Dv);

        cout << "\nIngrese la Fecha de Nacimiento del entrevistado: \nDia:";
        cin >> Day;
        cout << "\nMes:";
        cin >> Month;
        cout << "\nYear:";
        cin >> Year;
        SurveyedPerson.SetBirthday(Day, Month, Year);

        cout << "\nElija el genero del entrevistado:\n1)Hombre\n2)Mujer\n3)Otros" << endl;
        cin >> GenderNumber;
        SurveyedPerson.SetGender(GenderNumber);

        cout << "\nIngrese el Correo del entrevistado: ";
        //scanf("%s", Email);
        cin >> Email;
        SurveyedPerson.SetEmail(Email);

        cout << "\nIngrese el Telefono del entrevistado: ";
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
        //IdVerifier(NewTest, TestFile);
        Aux= "0";
        IdCouter = stoi(Searcher(TestFile, "Id:"))+1;
        NewTest.SetID(IdCouter);

        cout << "Ingrese el titulo del test: ";
        cin >> Name;
        NewTest.SetName(Name);

        cout << "\nIngrese la razon del test: ";
        cin >> Description;
        NewTest.SetObservation(Description);

        cout << "\nIngrese el puntaje maximo del test: ";
        cin >> MaxPoint;
        NewTest.SetMaxPoint(MaxPoint);

        float PointModifier;
        cout << "\nIngrese el porcentaje para ajustar el punto de corte (Ej: 0.5 = 50%): ";
        cin >> PointModifier;
        NewTest.SetCutPoint(round(MaxPoint*PointModifier));

        TestFile << "/////////////" << endl;
        TestFile << "Id: " << NewTest.GetID() << endl;
        TestFile << "Titulo: " << NewTest.GetName() << endl;
        TestFile << "Puntaje Máximo: " << NewTest.GetMaxPoint() << endl;
        TestFile << "Puntaje de Corte: " << NewTest.GetCutPoint() << endl;
        TestFile << "Observación: " << NewTest.GetObservation() << endl;

        while(Election != 0){
            //IdVerifier(NewQuestion, QuestionFile);
            Aux= "0";
            IdCouter = stoi(Searcher(QuestionFile, "Id:"))+1;
            NewQuestion.SetID(IdCouter);
            NewQuestion.AssignedTest(NewTest);

            cout << "\nIngrese una pregunta: ";
            scanf("%s", QuestionText);
            NewQuestion.SetQuestion(QuestionText);

            cout << "\nIngrese una descripcion a la pregunta: ";
            scanf("%s", Description);
            NewQuestion.SetDescription(Description);

            QuestionFile << "/////////////" << endl;
            QuestionFile << "ID: " << NewQuestion.GetID() << endl;
            QuestionFile << "Foreign key Id: " << NewQuestion.GetFkId() << endl;
            QuestionFile << "Pregunta: " << NewQuestion.GetQuestion() << endl;
            QuestionFile << "Descripcion: " << NewQuestion.GetDescription() << endl;
            QuestionFile << "DeleteAt: " << endl;
            cout << "Desea salir?" << "\nPresione 0 para cerrar" <<
            "\nPresione cualquier numero para continuar"<< endl;
            cin >> Election;
        }

        break;
    case 3:
        //IdVerifier(NewQuestion, QuestionFile);
        Aux= "0";
        IdCouter = stoi(Searcher(QuestionFile, "Id:"))+1;
        NewQuestion.SetID(IdCouter);

        while(!TestFile.eof())
        {
            getline(TestFile,StrAux);
            if(StrAux.find("Id:") != string::npos || StrAux.find("Titulo:") != string::npos) cout << StrAux << endl;
        }
        TestFile.clear();
        TestFile.seekg (0, ios::beg);

        cout << "Ingrese la ID de la prueba a la que va dirigido esta pregunta: " << endl;
        cin >> Election;
        NewTest.SetID(Election);
        NewQuestion.AssignedTest(NewTest);
        
        cout << "\nIngrese una pregunta: ";
        scanf("%s", QuestionText);
        NewQuestion.SetQuestion(QuestionText);
        cout << "\nIngrese una descripcion a la pregunta: ";
        scanf("%s", Description);
        NewQuestion.SetDescription(Description);
        QuestionFile << "/////////////" << endl;
        QuestionFile << "ID: " << NewQuestion.GetID() << endl;
        QuestionFile << "Foreign key Id: " << NewQuestion.GetFkId() << endl;
        QuestionFile << "Pregunta: " << NewQuestion.GetQuestion() << endl;
        QuestionFile << "Descripcion: " << NewQuestion.GetDescription() << endl;
        QuestionFile << "DeleteAt: " << endl;
        break;
    case 4:
        //IdVerifier(NewAnswer, AnswerFile);
        Aux= "0";
        IdCouter = stoi(Searcher(AnswerFile, "ID:"))+1;
        NewAnswer.SetID(IdCouter);
        while(!QuestionFile.eof())
        {
            getline(QuestionFile,StrAux);
            if(StrAux.find("ID:") != string::npos || StrAux.find("Pregunta:") != string::npos) cout << StrAux << endl;
        }
        QuestionFile.clear();
        QuestionFile.seekg (0, ios::beg);

        cout << "Ingrese la ID de la prueba a la que va dirigido esta respuesta: ";
        cin >> Election;
        NewQuestion.SetID(Election);
        NewAnswer.AssignedQuestion(NewQuestion);

        Aux = "ID: "+ to_string(NewQuestion.GetFkId()); 
        while(!TestFile.eof())
        {
            getline(TestFile,StrAux);
            if(StrAux.find("ID:") != string::npos && StrAux == Aux){
                while (!StrAux.find("/////////////") != string::npos)
                {
                    getline(TestFile,StrAux);
                    if(StrAux.find("Puntaje Máximo:") != string::npos){
                        MaxPoint = stoi(Searcher(TestFile, StrAux));
                    }
                }
            }
        }
        TestFile.clear();
        TestFile.seekg (0, ios::beg);
        cout << "\nIngrese una respuesta: ";
        scanf("%s", QuestionText);
        NewAnswer.SetText(QuestionText);

        cout << "\nIngrese una observacion a la respuesta: ";
        scanf("%s", Description);
        NewAnswer.SetObservation(Description);

        cout << "\nIngrese el puntaje: ";
        cin >> Point;
        TopPoint += Point;
        if(MaxPoint > TopPoint){
            NewAnswer.SetPoint(Point);
        }else{
            NewAnswer.SetPoint(MaxPoint-TopPoint);
        }
        AnswerFile << "/////////////" << endl;
        AnswerFile << "ID: " << NewAnswer.GetID() << endl;
        AnswerFile << "Foreign key Id: " << NewAnswer.GetFkId() << endl;
        AnswerFile << "Puntaje: " << NewAnswer.GetPoint() << endl;
        AnswerFile << "Respuesta: " << NewAnswer.GetText() << endl;
        AnswerFile << "Observacion: " << NewAnswer.GetObservation() << endl;
        AnswerFile << "DeleteAt: " << endl;
        break;
    case 5:
        cout << "Seleccione la prueba a realizar: " << endl;
        while(!TestFile.eof())
        {
            getline(TestFile,StrAux);
            if(StrAux.find("Id:") != string::npos || StrAux.find("Titulo:") != string::npos) cout << StrAux << endl;
        }
        TestFile.clear();
        TestFile.seekg (0, ios::beg);
        cin >> Election;
        NewTest.SetID(Election);
        Aux = "Foreign key Id: "+ to_string(NewTest.GetID());
        Aux2 = "Foreign key Id: "+ to_string(NewQuestion.GetID());
        while(!QuestionFile.eof())
        {
            getline(QuestionFile,StrAux);
            if(StrAux.find("Foreign key Id:") != string::npos && StrAux == Aux) 
            {
                while (!StrAux.find("/////////////") != string::npos)
                {
                    getline(QuestionFile,StrAux);
                    if(StrAux.find("Pregunta:") != string::npos)
                    {
                        cout << StrAux << endl;
                        while(!AnswerFile.eof())
                        {
                            getline(AnswerFile,StrAux);
                            if(StrAux.find("Foreign key Id:") != string::npos && StrAux == Aux2)
                            {
                                while (!StrAux.find("/////////////") != string::npos)
                                {
                                    getline(AnswerFile,StrAux);
                                    if(StrAux.find("Respuesta:") != string::npos)
                                    {
                                        cout << StrAux << endl;
                                    }
                                }
                            }
                        }                                                
                    }
                } 
            }
        }
        QuestionFile.clear();
        AnswerFile.clear();
        AnswerFile.seekg (0, ios::beg);
        QuestionFile.seekg (0, ios::beg);
        break;
    default:
        cout << "Ingrese una opcion correcta" << endl;
        break;
    }
}

bool EmailChecker(char CheckEmail[255], fstream &File){
    while(!File.eof())
    {
        getline(UserFile,StrAux);
        if(StrAux.find("Correo:") != string::npos){
            //cout << StrAux.substr(StrAux.find(" ")+1,StrAux.length());
            if(CheckEmail == StrAux.substr(StrAux.find(" ")+1,StrAux.length())){
                File.clear();
                File.seekg (0, ios::beg);
                return true;
            }
        }
    }
    if(File.eof()){
        File.clear();
        File.seekg (0, ios::beg);
        return false; 
    } 
    
}

string Searcher(fstream &File, string KeyWord){

    getline(File, StrAux);
    if(StrAux.find(KeyWord) != string::npos){
        for (size_t i = 0; i < StrAux.length(); i++)
        {
            if (isdigit(StrAux[i]) == 1){
                if(StrAux[i] > stoi(Aux)){
                    Aux = StrAux[i];
                }
            }
        }
    }
    if(File.eof()) {  
        File.clear();
        File.seekg (0, ios::beg);
        return Aux;
    }
    return Searcher(File, KeyWord);
}
