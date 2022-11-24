#include <bits/stdc++.h>
#include <fstream>
#include "source.h"
#include <string>
#include <vector>
using namespace std;

//Functions
/*PascalCase*/
string Searcher(fstream&, string);
bool EmailChecker(string, fstream&);
void Menu(int);
void TestMenu(int);
int PointVerifier(fstream&);
User Recovery(User, string, int);
Surveyed Recovery(Surveyed, string, int);
Test Recovery(Test, string, int);
Question Recovery(Question, string, int);
Answer Recovery(Answer, string, int);
//Global Variables
fstream UserFile("User/User.txt", ios::out | ios::in | ios::app);
fstream SurveyFile("Surveyed/Surveyed.txt", ios::out | ios::in | ios::app);
fstream TestFile("Test/Test.txt", ios::out | ios::in | ios::app);
fstream QuestionFile("Question/Question.txt", ios::out | ios::in | ios::app);
fstream AnswerFile("Answer/Answer.txt", ios::out | ios::in | ios::app);
int IdCouter = 0, Run, Day, Month, Year, GenderNumber, Phone, IdUser;
string StrAux, StrAux2, Aux, Aux2, Name, FatherName, MotherName, Email;
char Dv;
bool Check = false;

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

void Menu(int Election)
{
    //char Password[255];
    User Pollster = User(); // pollster = Encuestador
    switch (Election)
    {
        case 1:
            //Pollster.SetID(IdCouter);
            //IdVerifier(Pollster, UserFile);
            Aux= "0";
            IdCouter = stoi(Searcher(UserFile, "ID:"))+1;
            Pollster.SetID(IdCouter);

            cout << "Ingrese su nombre: ";
            getline(cin >> ws, Name);
            cout << "\nIngrese su Apellido Paterno: ";
            getline(cin >> ws, FatherName);
            cout << "\nIngrese su Apellido Materno: ";
            getline(cin >> ws, MotherName);
            Pollster.SetFullName(Name, FatherName, MotherName);

            cout << "\nIngrese su Run (sin el digito verificador): ";
            cin >> Run;
            Pollster.SetRun(Run);

            cout << "\nIngrese su digito verificador: ";
            cin >> Dv;
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

            cout << "\nIngrese su Correo: ";
            getline(cin >> ws, Email);
            Pollster.SetEmail(Email);

            cout << "\nIngrese su Telefono: ";
            cin >> Phone;
            Pollster.SetPhone(Phone);

            //cout << "\nIngrese su Contraseña: ";
            //scanf("%s", Password);
            //Pollster.SetPassword(Password);
            UserFile << "/////////////" << endl;
            UserFile << "ID: " << Pollster.GetID() << endl;
            UserFile << "Nombre: " << Name << endl;
            UserFile << "Apellido Paterno: " << FatherName << endl;
            UserFile << "Apellido Materno: " << MotherName << endl;
            UserFile << "Run: " << Pollster.GetRun() << endl;
            UserFile << "Fecha de Nacimiento: " << Pollster.GetBirthday() << endl;
            UserFile << "Genero: " << Pollster.GetGender() << endl;
            UserFile << "Correo: " << Pollster.GetEmail() << endl;
            UserFile << "Telefono: " << Phone << endl;
            //UserFile << "Contraseña: " << Password << endl;
            UserFile << "DeleteAt: " << endl;
            cout << "Registro completado!" << endl;
            UserFile.clear();
            UserFile.seekg (0, ios::beg);
            break;
        case 2:
            while (Election != 0)
            {
                Email = "";
                cout << "\nIngrese su Correo: ";

                getline(cin >> ws, Email);
                int Option = 0;

                while(getline(UserFile,StrAux))
                {
                    if(StrAux == "Correo: " + Email)
                        Check = true;
                    if(Check == true){
                        if(StrAux.find("ID:") != string::npos){
                            cout << "A" << endl;
                            IdUser = stoi(StrAux.substr(StrAux.find(" ") + 1, StrAux.length())) - 1;
                            Check = false;
                        }
                    }
                }
                if(IdUser == 0) IdUser = 1;
                Check = false;
                UserFile.clear();
                UserFile.seekg(0, ios::beg);
                /*
                cout << "\nIngrese su Contraseña: ";
                scanf("%s", Password);*/

                if(EmailChecker(Email, UserFile) == true)
                {
                    cout << "Sesion Iniciada!\n";
                    while (Option != 6)
                    {
                        cout << "=====Programa de Encuestas=====\n" <<
                        "1)Crear perfil de entrevistado\n" <<
                        "2)Crear test\n" << "3)Crear preguntas\n" << "4)Crear respuestas\n"<<
                        "5)Realizar test\n" << "6)Salir a menu principal" << endl;
                        cin >> Option;
                        TestMenu(Option);
                    }
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

void TestMenu(int Election)
{
    string QuestionText, Description;
    int MaxPoint, Point, TopPoint=0, QuestionLength, AnswerLength, NumOfAnswers;
    User UserPerson = User();
    Surveyed SurveyedPerson = Surveyed();
    Test NewTest = Test();
    Question NewQuestion = Question();
    Answer NewAnswer = Answer();
    vector<string> AnswerArray;
    switch (Election)
    {
    case 1:
        // crear perfil de encuestado
        //SurveyedPerson.SetID(IdCouter);
        //IdVerifier(SurveyedPerson, SurveyFile);
        Aux= "0";
        IdCouter = stoi(Searcher(SurveyFile, "ID:"))+1;
        SurveyedPerson.SetID(IdCouter);

        cout << "Ingrese el nombre del entrevistado: ";
        getline(cin >> ws, Name);
        cout << "\nIngrese el Apellido Paterno del entrevistado: ";
        getline(cin >> ws, FatherName);
        cout << "\nIngrese el Apellido Materno del entrevistado: ";
        getline(cin >> ws, MotherName);
        SurveyedPerson.SetFullName(Name, FatherName, MotherName);

        cout << "\nIngrese el Run del entrevistado(sin el digito verificador): ";
        cin >> Run;
        SurveyedPerson.SetRun(Run);

        cout << "\nIngrese el digito verificador del entrevistado: ";
        cin >> Dv;
        SurveyedPerson.SetDV(Dv);

        cout << "\nIngrese la Fecha de Nacimiento del entrevistado: \nDia: ";
        cin >> Day;
        cout << "\nMes: ";
        cin >> Month;
        cout << "\nYear: ";
        cin >> Year;
        SurveyedPerson.SetBirthday(Day, Month, Year);

        cout << "\nElija el genero del entrevistado:\n1)Hombre\n2)Mujer\n3)Otros" << endl;
        cin >> GenderNumber;
        SurveyedPerson.SetGender(GenderNumber);

        cout << "\nIngrese el Correo del entrevistado: ";
        getline(cin >> ws, Email);
        SurveyedPerson.SetEmail(Email);

        cout << "\nIngrese el Telefono del entrevistado: ";
        cin >> Phone;
        SurveyedPerson.SetPhone(Phone);

        SurveyFile << "/////////////" << endl;
        SurveyFile << "ID: " << SurveyedPerson.GetID() << endl;
        SurveyFile << "Nombre: " << Name << endl;
        SurveyFile << "Apellido Paterno: " << FatherName << endl;
        SurveyFile << "Apellido Materno: " << MotherName << endl;
        SurveyFile << "Run: " << SurveyedPerson.GetRun() << endl;
        SurveyFile << "Fecha de Nacimiento: " << SurveyedPerson.GetBirthday() << endl;
        SurveyFile << "Genero: " << SurveyedPerson.GetGender() << endl;
        SurveyFile << "Correo: " << Email << endl;
        SurveyFile << "Telefono: " << Phone << endl;
        SurveyFile << "Observacion: -" << endl;
        SurveyFile << "DeleteAt: " << endl;
        SurveyFile.clear();
        SurveyFile.seekg (0, ios::beg);
        break;
    case 2:
        Aux= "0";
        IdCouter = stoi(Searcher(TestFile, "ID:"))+1;
        NewTest.SetID(IdCouter);

        cout << "Ingrese el titulo del test: ";
        getline(cin >> ws, Name);
        NewTest.SetName(Name);

        cout << "\nIngrese la razon del test: ";
        getline(cin >> ws, Description);
        NewTest.SetObservation(Description);

        cout << "\nIngrese el puntaje maximo del test: ";
        cin >> MaxPoint;
        NewTest.SetMaxPoint(MaxPoint);

        float PointModifier;
        cout << "\nIngrese el porcentaje para ajustar el punto de corte (Ej: 0.5 = 50%): ";
        cin >> PointModifier;
        NewTest.SetCutPoint(round(MaxPoint*PointModifier));

        TestFile << "/////////////" << endl;
        TestFile << "ID: " << NewTest.GetID() << endl;
        TestFile << "Titulo: " << NewTest.GetName() << endl;
        TestFile << "Puntaje Maximo: " << NewTest.GetMaxPoint() << endl;
        TestFile << "Puntaje de Corte: " << NewTest.GetCutPoint() << endl;
        TestFile << "Observacion: " << NewTest.GetObservation() << endl;
        TestFile.clear();
        TestFile.seekg (0, ios::beg);
        while(Election != 0)
        {
            //IdVerifier(NewQuestion, QuestionFile);
            Aux= "0";
            IdCouter = stoi(Searcher(QuestionFile, "ID:"))+1;
            NewQuestion.SetID(IdCouter);
            NewQuestion.AssignedTest(NewTest);

            cout << "\nIngrese una pregunta: ";
            //scanf("%s", QuestionText);
            getline(cin >> ws, QuestionText);
            NewQuestion.SetQuestion(QuestionText);

            cout << "\nIngrese una descripcion a la pregunta: ";
            //scanf("%s", Description);
            getline(cin >> ws, Description);
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
            QuestionFile.clear();
            QuestionFile.seekg(0, ios::beg);
        }
        
        break;
    case 3:
        Aux= "0";
        IdCouter = stoi(Searcher(QuestionFile, "ID:"))+1;
        NewQuestion.SetID(IdCouter);

        while(getline(TestFile,StrAux))
            if(StrAux.find("ID:") != string::npos || StrAux.find("Titulo:") != string::npos) cout << StrAux << endl;
        TestFile.clear();
        TestFile.seekg (0, ios::beg);

        cout << "Ingrese la ID de la prueba a la que va dirigido esta pregunta: " << endl;
        cin >> Election;
        NewTest = Recovery(NewTest, "ID", Election);
        NewQuestion.AssignedTest(NewTest);

        cout << "\nIngrese una pregunta: ";
        getline(cin >> ws, QuestionText);
        NewQuestion.SetQuestion(QuestionText);

        cout << "\nIngrese una descripcion a la pregunta: ";
        getline(cin >> ws, Description);
        NewQuestion.SetDescription(Description);

        QuestionFile << "/////////////" << endl;
        QuestionFile << "ID: " << NewQuestion.GetID() << endl;
        QuestionFile << "Foreign key Id: " << NewQuestion.GetFkId() << endl;
        QuestionFile << "Pregunta: " << NewQuestion.GetQuestion() << endl;
        QuestionFile << "Descripcion: " << NewQuestion.GetDescription() << endl;
        QuestionFile << "DeleteAt: " << endl;
        QuestionFile.clear();
        QuestionFile.seekg (0, ios::beg);
        break;
    case 4:
        //IdVerifier(NewAnswer, AnswerFile);
        Aux= "0";
        IdCouter = stoi(Searcher(AnswerFile, "ID:"))+1;
        NewAnswer.SetID(IdCouter);

        while(getline(QuestionFile,StrAux))
            if(StrAux.find("ID:") != string::npos || StrAux.find("Pregunta:") != string::npos) cout << StrAux << endl;
        QuestionFile.clear();
        QuestionFile.seekg (0, ios::beg);

        cout << "Ingrese la ID de la pregunta a la que va dirigido esta respuesta: ";
        cin >> Election;
        NewQuestion = Recovery(NewQuestion, "ID", Election);
        NewTest = Recovery(NewTest, "ID", NewQuestion.GetFkId());
        NewAnswer.AssignedQuestion(NewQuestion);

        cout << "\nIngrese una respuesta: ";
        getline(cin >> ws, QuestionText);
        NewAnswer.SetText(QuestionText);

        cout << "\nIngrese una observacion a la respuesta: ";
        getline(cin >> ws, Description);
        NewAnswer.SetObservation(Description);

        cout << "\nIngrese el puntaje: ";
        cin >> Point;
        if(stoi(Searcher(AnswerFile, "ID:")) != 0)
        {
            TopPoint += Point;
            if(NewTest.GetMaxPoint() > TopPoint)
            {
                NewAnswer.SetPoint(Point);
            }else
            {
                NewAnswer.SetPoint(NewTest.GetMaxPoint()-Point);
            }
        }else
        {
            NewAnswer.SetPoint(Point);
        }


        AnswerFile << "/////////////" << endl;
        AnswerFile << "ID: " << NewAnswer.GetID() << endl;
        AnswerFile << "Foreign key Id: " << NewAnswer.GetFkId() << endl;
        AnswerFile << "Puntaje: " << NewAnswer.GetPoint() << endl;
        AnswerFile << "Respuesta: " << NewAnswer.GetText() << endl;
        AnswerFile << "Observacion: " << NewAnswer.GetObservation() << endl;
        AnswerFile << "DeleteAt: " << endl;
        AnswerFile.clear();
        AnswerFile.seekg (0, ios::beg);
        break;
    case 5:
        cout << "Seleccione al paciente: " << endl;
        while(getline(SurveyFile, StrAux))
            if(StrAux.find("ID:") != string::npos || StrAux.find("Nombre:") != string::npos) cout << StrAux << endl;
        SurveyFile.clear();
        SurveyFile.seekg (0, ios::beg);
        cin >> Election;
        SurveyedPerson = Recovery(SurveyedPerson, "ID", Election);

        cout << "Seleccione la prueba a realizar: " << endl;
        while(getline(TestFile, StrAux))
            if(StrAux.find("ID:") != string::npos || StrAux.find("Titulo:") != string::npos) cout << StrAux << endl;
        TestFile.clear();
        TestFile.seekg (0, ios::beg);
        cin >> Election;

        NewTest = Recovery(NewTest, "ID", Election);
        UserPerson = Recovery(UserPerson, "ID", IdUser);
        cout << IdUser << endl;
        cout << UserPerson.GetID() << endl;
        Aux= "0";
        QuestionLength = stoi(Searcher(QuestionFile, "ID:"));
        Aux= "0";
        AnswerLength = stoi(Searcher(AnswerFile, "ID:"));
        TopPoint = 0;
        for(int i = 1; i <= QuestionLength; i++)
        {
            if(NewTest.GetID() == Recovery(NewQuestion, "ID", i).GetFkId())
            {
                cout << Recovery(NewQuestion, "ID", i).GetQuestion() << endl;
                NumOfAnswers = 0;
                for (int j = 1; j <= AnswerLength; j++)
                {
                    if(Recovery(NewQuestion, "ID", i).GetID() == Recovery(NewAnswer, "ID", j).GetFkId())
                    {
                        cout << NumOfAnswers+1 << ")" << Recovery(NewAnswer, "ID", j).GetText() << " ";
                        AnswerArray.push_back(Recovery(NewAnswer, "ID", j).GetText());
                        NumOfAnswers++;
                    }
                }
                cout << "\nElija una respuesta: ";
                cin >> Point; //1)Si 2)NO index 0: Si index 1: No
                for (vector<int>::size_type k = 0; k < AnswerArray.size(); k++) {
                    if(Point-1 == k)
                    {
                        for (int j = 1; j <= AnswerLength; j++)
                        {
                            if(AnswerArray.at(k) == Recovery(NewAnswer, "ID", j).GetText())
                            {
                                if(Recovery(NewQuestion, "ID", i).GetID() == Recovery(NewAnswer, "ID", j).GetFkId())
                                {
                                    TopPoint += Recovery(NewAnswer, "ID", j).GetPoint();
                                }
                            }
                        }

                    }
                }
                AnswerArray.clear();
            }

        }
        //cout << TopPoint << endl;
        cout << "=====Resultados de la encuesta=====" << endl;
        cout << "Paciente: " << SurveyedPerson.GetFullName() << endl;
        cout << "Puntaje obtenido: " << TopPoint << endl;
        cout << "Conclusion: ";
        if(TopPoint >= NewTest.GetMaxPoint())
        {
            cout << "Necesitas ayuda urgente!" << endl;
        }else if(TopPoint >= NewTest.GetCutPoint())
        {
            cout << "Necesitas tratamiento." << endl; // x < 2 y x > 2*50%
        }else if(TopPoint < NewTest.GetCutPoint() && TopPoint > NewTest.GetCutPoint()*0.5)
        {
            cout << "Tendencia a la depresion" << endl;
        }else if(TopPoint < NewTest.GetCutPoint()*0.5)
        {
            cout << "Puede que sea un mal dia" << endl;
        }
        cout << "Encuesta realizada por: " << UserPerson.GetFullName() << endl;
        /*
        * Por limitaciones de tiempo
        * El archivo Surveyed no podra cambiar
        * su observacion. :(
        */
        break;
    default:
        cout << "Ingrese una opcion correcta" << endl;
        break;
    }
}

bool EmailChecker(string CheckEmail, fstream &File){
    while(getline(File, StrAux))
    {
        if(StrAux.find("Correo:") != string::npos){
            if(CheckEmail == StrAux.substr(StrAux.find(" ")+1,StrAux.length())){
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
            if(stoi(StrAux.substr(StrAux.rfind(" ")+1,StrAux.length())) > stoi(Aux))
            {
                Aux = StrAux.substr(StrAux.rfind(" ")+1,StrAux.length());
            }
            
            /*
            if (isdigit(StrAux[i]) == 1){
                if(StrAux[i] > stoi(Aux)){
                    Aux = StrAux[i];
                }
            }*/
        }
    }
    if(File.eof()) {
        File.clear();
        File.seekg(0, ios::beg);
        return Aux;
    }
    return Searcher(File, KeyWord);
}

User Recovery(User UserRecover, string KeyWord, int NumberKey) // Id: 1 (, "Id", 1)
{
    string NameAux, FatherAux; //MotherAux;
    UserFile.clear();
    UserFile.seekg(0, ios::beg);
    while (getline(UserFile, StrAux))
    {
        if(StrAux != "/////////////"){
            if(StrAux == KeyWord + ": " + to_string(NumberKey))
            {
                Check = true;
                UserRecover.SetID(NumberKey);
            }
            if(Check == true)
            {
                if(StrAux.find("Nombre:") != string::npos)
                    NameAux = StrAux.substr(StrAux.find(" ")+1,StrAux.length());

                else if(StrAux.find("Apellido Paterno:") != string::npos)
                    FatherAux = StrAux.substr(StrAux.rfind(" ")+1,StrAux.length());

                else if(StrAux.find("Apellido Materno:") != string::npos)
                    UserRecover.SetFullName(NameAux, FatherAux, StrAux.substr(StrAux.rfind(" ")+1,StrAux.length()));

                else if(StrAux.find("Run:") != string::npos)
                {
                    UserRecover.SetRun(stoi(StrAux.substr(StrAux.find(" ")+1,StrAux.length()-2))); // :(espacio) run-DV; desde el espacio hasta el final menos el dv y el -
                    UserRecover.SetDV(StrAux[StrAux.length()]);

                }else if(StrAux.find("Fecha de Nacimiento:") != string::npos)
                {
                    NameAux = StrAux.substr(StrAux.rfind(" ")+1,StrAux.length());// 10/1/2022
                    if(NameAux.substr(0, NameAux.find("/")).length() == 2)
                        FatherAux = NameAux.substr(NameAux.find_first_of("/")+1, NameAux.rfind("/")-3);
                    else
                        FatherAux = NameAux.substr(NameAux.find_first_of("/")+1, NameAux.rfind("/")-2);
                    UserRecover.SetBirthday(stoi(NameAux.substr(0, NameAux.find("/"))), //Day
                    stoi(FatherAux),  //Month
                    stoi(NameAux.substr(NameAux.length()-4,NameAux.length()))); //Year

                }else if(StrAux.find("Genero:") != string::npos)
                {
                    if(StrAux.substr(StrAux.find(" ")+1,StrAux.length()) == "Male")
                        UserRecover.SetGender(1);
                    else if(StrAux.substr(StrAux.find(" ")+1,StrAux.length()) == "Female")
                        UserRecover.SetGender(2);
                    else
                        UserRecover.SetGender(3);

                }else if(StrAux.find("Correo:") != string::npos)
                    UserRecover.SetEmail(StrAux.substr(StrAux.find(" ")+1,StrAux.length()));
                else if(StrAux.find("Telefono:") != string::npos)
                {
                    UserRecover.SetPhone(stoi(StrAux.substr(StrAux.find(" ")+1,StrAux.length())));
                    Check = false;
                }
            }
        }else Check = false;
    }
    if(UserFile.eof())
    {
        UserFile.clear();
        UserFile.seekg (0, ios::beg);
        return UserRecover;
    }
}
Surveyed Recovery(Surveyed SurveyedRecover, string KeyWord, int NumberKey)
{
    string NameAux, FatherAux;
    while (getline(SurveyFile, StrAux))
    {
        if(StrAux != "/////////////"){
            if(StrAux == (KeyWord + ": " + to_string(NumberKey)))
            {
                Check = true;
                SurveyedRecover.SetID(NumberKey);
            }
            if(Check == true)
            {
                if(StrAux.find("Nombre:") != string::npos)
                    NameAux = StrAux.substr(StrAux.find(" ")+1,StrAux.length());

                else if(StrAux.find("Apellido Paterno:") != string::npos)
                    FatherAux = StrAux.substr(StrAux.rfind(" ")+1,StrAux.length());

                else if(StrAux.find("Apellido Materno:") != string::npos)
                    SurveyedRecover.SetFullName(NameAux, FatherAux, StrAux.substr(StrAux.rfind(" ")+1,StrAux.length()));

                else if(StrAux.find("Run:") != string::npos)
                {
                    SurveyedRecover.SetRun(stoi(StrAux.substr(StrAux.find(" ")+1,StrAux.length()-2))); // :(espacio) run-DV; desde el espacio hasta el final menos el dv y el -
                    SurveyedRecover.SetDV(StrAux[StrAux.length()]);

                }else if(StrAux.find("Fecha de Nacimiento:") != string::npos)
                {
                    NameAux = StrAux.substr(StrAux.rfind(" ")+1,StrAux.length());
                    if(NameAux.substr(0, NameAux.find("/")).length() == 2)
                        FatherAux = NameAux.substr(NameAux.find_first_of("/")+1, NameAux.rfind("/")-3);
                    else
                        FatherAux = NameAux.substr(NameAux.find_first_of("/")+1, NameAux.rfind("/")-2);
                    SurveyedRecover.SetBirthday(stoi(NameAux.substr(0, NameAux.find("/"))), //Day
                    stoi(FatherAux),  //Month
                    stoi(NameAux.substr(NameAux.length()-4,NameAux.length()))); //Year

                }else if(StrAux.find("Genero:") != string::npos)
                {
                    if(StrAux.substr(StrAux.find(" ")+1,StrAux.length()) == "Male")
                        SurveyedRecover.SetGender(1);
                    else if(StrAux.substr(StrAux.find(" ")+1,StrAux.length()) == "Female")
                        SurveyedRecover.SetGender(2);
                    else
                        SurveyedRecover.SetGender(3);

                }else if(StrAux.find("Correo:") != string::npos)
                    SurveyedRecover.SetEmail(StrAux.substr(StrAux.find(" ")+1,StrAux.length()));
                else if(StrAux.find("Telefono:") != string::npos)
                {
                    SurveyedRecover.SetPhone(stoi(StrAux.substr(StrAux.find(" ")+1,StrAux.length())));
                    Check = false;
                }
            }
        }else Check = false;
    }
    if(SurveyFile.eof())
    {
        SurveyFile.clear();
        SurveyFile.seekg (0, ios::beg);
        return SurveyedRecover;
    }
}
Test Recovery(Test TestRecover, string KeyWord, int NumberKey)
{
    while (getline(TestFile, StrAux))
    {
        if(StrAux != "/////////////")
        {
            if(StrAux == (KeyWord + ": " + to_string(NumberKey)))
            {
                Check = true;
                TestRecover.SetID(NumberKey);
            }
            if(Check == true)
            {
                if(StrAux.find("Titulo:") != string::npos)
                    TestRecover.SetName(StrAux.substr(StrAux.find(" ") + 1, StrAux.length()));
                else if(StrAux.find("Maximo:") != string::npos)
                    TestRecover.SetMaxPoint(stoi(StrAux.substr(StrAux.rfind(" ") + 1, StrAux.length())));
                else if(StrAux.find("de Corte:") != string::npos)
                    TestRecover.SetCutPoint(stoi(StrAux.substr(StrAux.rfind(" ") + 1, StrAux.length())));
                else if(StrAux.find("Observacion:") != string::npos)
                {
                    TestRecover.SetObservation(StrAux.substr(StrAux.find(" ") + 1, StrAux.length()));
                    Check = false;
                }

                //cout << "hola" << endl;
            }

        }else Check = false;
    }
    if(TestFile.eof())
    {
        TestFile.clear();
        TestFile.seekg (0, ios::beg);
        return TestRecover;
    }
}
Question Recovery(Question QuestionRecover, string KeyWord, int NumberKey)
{
    Test AuxTest = Test();
    while (getline(QuestionFile, StrAux))
    {
        if(StrAux != "/////////////")
        {
            //cout << "a" << endl;
            if(StrAux == (KeyWord + ": " + to_string(NumberKey)))
            {
                Check = true;
                QuestionRecover.SetID(NumberKey);
            }
            if(Check == true)
            {
                //cout << "c" << endl;
                if(StrAux.find("key ") != string::npos)
                {
                    AuxTest.SetID(stoi(StrAux.substr(StrAux.rfind(" ") + 1, StrAux.length())));
                    QuestionRecover.AssignedTest(AuxTest);
                }
                else if(StrAux.find("Pregunta:") != string::npos)
                    QuestionRecover.SetQuestion(StrAux.substr(StrAux.find(" ") + 1,StrAux.length()));
                else if(StrAux.find("Descripcion:") != string::npos)
                {
                    QuestionRecover.SetDescription(StrAux.substr(StrAux.find(" ") + 1,StrAux.length()));
                    Check = false;
                }

            }

        }else Check = false;
    }
    if(QuestionFile.eof()) {
        QuestionFile.clear();
        QuestionFile.seekg (0, ios::beg);
        return QuestionRecover;
    }

}
Answer Recovery(Answer AnswerRecover, string KeyWord, int NumberKey)
{
    Question AuxQuestion = Question();
    while (getline(AnswerFile, StrAux))
    {
        if(StrAux != "/////////////")
        {
            if(StrAux == (KeyWord + ": " + to_string(NumberKey)))
            {
                Check = true;
                AnswerRecover.SetID(NumberKey);
            }
            if(Check == true)
            {
                if(StrAux.find("key ") != string::npos)
                {
                    AuxQuestion.SetID(stoi(StrAux.substr(StrAux.rfind(" ") + 1, StrAux.length())));
                    AnswerRecover.AssignedQuestion(AuxQuestion);
                }
                else if(StrAux.find("Puntaje:") != string::npos)
                    AnswerRecover.SetPoint(stoi(StrAux.substr(StrAux.find(" ") + 1,StrAux.length())));
                else if(StrAux.find("Respuesta:") != string::npos)
                    AnswerRecover.SetText(StrAux.substr(StrAux.find(" ") + 1,StrAux.length()));
                else if(StrAux.find("Observacion:") != string::npos)
                {
                    AnswerRecover.SetObservation(StrAux.substr(StrAux.find(" ") + 1,StrAux.length()));
                    Check = false;
                }

            }

        }else Check = false;
    }
    if(AnswerFile.eof())
    {
        AnswerFile.clear();
        AnswerFile.seekg(0, ios::beg);
        return AnswerRecover;
    }

}
