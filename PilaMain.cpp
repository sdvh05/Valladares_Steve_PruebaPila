#include <iostream>
#include "Pila.h"
#include <limits>
//#include <QString>


int main() {
    std::string frase;

    int Num=0;

    //frase="Anita lava la tina";

    // Limpiar buffers ??
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


      while (true) {
        std::cout << "Ingrese una Frase: " << std::endl;
        //std:: cin >> frase;
        std::getline(std::cin, frase);

        if (frase.empty()) {
            std::cout << "Programa terminado." << std::endl;
            break;
        }

        if (Pila<char>::esPalindromo(frase)) {
            std::cout << "La frase: |" <<frase << "| es un palindromo." << std::endl;
        } else {
            std::cout << "La frase: |" <<frase << "| NO es un palindromo." << std::endl;
        }
        frase.clear();
    }
    return 0;
}
