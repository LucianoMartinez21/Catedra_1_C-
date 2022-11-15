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
void IdVerifier();
int main(){
    IdVerifier();
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

void Menu(int Election){
    switch (Election){
        case 1:
            User Pollster = User(); // pollster = Encuestador
            char Name[255], FatherName[255], MotherName[255], *Dv,
            Email[255], Password[255];
            int Run, Day, Month, Year, GenderNumber, Phone;
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
            while (GenderNumber != 1 && GenderNumber != 2 && GenderNumber != 3)
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

            break;
        case 2:
            break;
        case 3:
            cout << "Bye bye!" << endl;
            exit(Election);
            break;
    }
}

void IdVerifier(){
    string AuxiliarString;
    getline(UserFile, AuxiliarString);
    if(IdCouter == NULL && AuxiliarString.length() == 0){
        IdCouter = 1;
    }else{
        //Aqui seria el buscador en el archivo de texto
    }
}
/* Objetivos
    *Creacion Clase Usuario
    *Creacion Clase Pacientes
    *Creacion Clase Preguntas
    *Creacion Clase Encuesta
    *Creacion Clase Respuesta
    *Creacion Clase Examen
    *
    * 
    * 
    * 
    * 
    * 
    * 
*/
