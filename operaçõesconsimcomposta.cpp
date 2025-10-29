#include <iostream>
#include <cstdlib>

int main(){

    int a = 4, opcao = 3;
    float b = 2.5;
    char c = 'x';

    if(a == 5){
        std::cout <<"\n A variavel a = 5";
    }
    if(b == 2.5){
        std::cout <<"\n A variavel b = 2.5";
    }
    if(c == 'x'){
        std::cout <<"\n A variavel c = letra x";
    }

    //condição composta, verificar valores impar e par

    if(a % 2 == 1){
        std::cout <<"\n A variavel a eh impar: ";
    }else{
        std::cout <<"\n A variavel a eh par: ";
    }

    //condição composta
    if(opcao == 1){
        std::cout <<"\n A opção = 1";
    }else if(opcao == 2){
        std::cout <<"\n A opção = 2 ";
    }else{
        std::cout <<"\n A opção não eh igual a 1 e nem 2 ";
    }
    std::cout <<"\n";
    std::system("pause");

    return 0;
}