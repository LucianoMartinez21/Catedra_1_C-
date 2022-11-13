#include <bits/stdc++.h>
#include <fstream>
#include "source.h"
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
    while (true)
    {
        cout << "=====Programa de Encuestas=====\n1) Crear Cuenta"<<
        "\n2) Iniciar Secion" << "\n3) Salir"
        << endl;
        cin >> Option; 
        Menu(Option);
    }   
}

void Menu(int Election){
    switch (Election){
        case 1:
            User Pollster = User(); // pollster = Encuestador
            char Name[255], FatherName[255], MotherName[255];
            Pollster.SetID(IdCouter);
            cout << "Ingrese su nombre: ";
            scanf("%s", Name);
            cout << "Ingrese su Apellido Paterno: ";
            scanf("%s", FatherName);
            cout << "Ingrese su Apellido Materno: ";
            scanf("%s", MotherName);
            Pollster.SetFullName(Name, FatherName, MotherName);
            cout << "Ingrese su Run (sin el digito verificador): ";
            
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
