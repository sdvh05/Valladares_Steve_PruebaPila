#ifndef PILA_H
#define PILA_H

#include <stdexcept>

const int TamPila = 49;

template <typename T>
class Pila {
private:
    T listaPila[TamPila];
    int cima;

public:
    //Funciones Pila Generica
    Pila();
    bool pilaVacia();
    bool pilaLlena();
    void insertar(T elemento);
    T quitar();
    T cimaPila();
    void limpiarPila();

    //Verificar si es Palindromo
    static bool esPalindromo(const std::string& frase);
};

#endif // PILA_H

