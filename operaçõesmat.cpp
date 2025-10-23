#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int idade;
    double salario, altura;
    char genero;
    string nome;

    idade = 20;
    salario = 5.000;
    altura = 1.83;
    genero = 'M';
    nome = "Miguel Angel Roa Rondon";

    cout << fixed << setprecision(2);
    cout << "IDADE: " << idade << endl;
    cout << "SALARIO: " << salario << endl;
    cout << "ALTURA: " << altura << endl;
    cout << "GENERO: " << genero << endl;
    cout << "NOME: " << nome << endl;

    return 0;

}
