#include <iostream> // Substitui <stdio.h> para entrada e saída
#include <cstdlib>  // Substitui <stdio.h> para std::system

// Função principal do programa (padrão c++)
int main() {
    // Imprime na tela usando std::cout
    std::cout << "Oi, mundo!";

    // Pausa o programa após executar
    // Adicionamos uma quebra de linha para a mensagem "pause" não ficar colada
     std::cout << "\n";
     std::system("pause"); // Em c++, é boa prática usar std::system

    return 0; // int main() deve retornar 0
}