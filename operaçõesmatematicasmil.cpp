#include <iostream>

int main() {

    int a = 6;
    int b = 4;

    //Soma
    std::cout << "\n A soma de " << a << " e " << b << " = " << (a + b);

    //Subtração
    std::cout <<"\n A subtração de " << a << " e " << b << " = " << (a-b);

    //Divisão
    // (Nota: Como 'a' e 'b' são inteiros, esta é uma divisão inteira: 6 / 4 = 1)
    std::cout << "\n A divisão de " << a << " e " << b << " = " << (a / b);

    //Multiplicação
    std::cout << "\n A multiplicação de " << a << " e " << b << " = " << (a * b);

    //Resto da Divisão
    std::cout << "\n O resto da divisão entre" << a << " e " << b << " = " << (a % b);

    //Valor Absoluto (usando std::abs de <cstdlib> ou < cmath>)
    std::cout << "\n O valor absoluto de -3 = " << std::abs(-3);

    //Pausa o programa após executar
    std::cout << "\n"; // Adiciona uma quebra de linha antes do pause
    system("pause");

    return 0; // Retorno padrão da main
}