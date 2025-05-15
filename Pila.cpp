#include "Pila.h"
#include <cctype>
#include <string>

// Inicializar Constructor
template <typename T>
Pila<T>::Pila() {
    cima = -1;
}


//Funcoiones
template <typename T>
bool Pila<T>::pilaVacia() {
    return cima == -1;
}

template <typename T>
bool Pila<T>::pilaLlena() {
    return cima == TamPila - 1;
}

template <typename T>
void Pila<T>::insertar(T elemento) {
    if (pilaLlena()) {
        throw std::overflow_error("La Pila esta llena");
    }
    listaPila[++cima] = elemento;
}

template <typename T>
T Pila<T>::quitar() {
    if (pilaVacia()) {
        throw std::underflow_error("No se puede quitar, LA pila esta vacia");
    }
    return listaPila[cima--];
}

template <typename T>
T Pila<T>::cimaPila() {
    if (pilaVacia()) {
        throw std::underflow_error("No hay datos registrados en la Pila");
    }
    return listaPila[cima];
}

template <typename T>
void Pila<T>::limpiarPila() {
    cima = -1;
}


//Palindromo
char QuitarTilde(char c) {
    switch (c) {
        case 'á': case 'Á': return 'a';
        case 'é': case 'É': return 'e';
        case 'í': case 'Í': return 'i';
        case 'ó': case 'Ó': return 'o';
        case 'ú': case 'Ú': return 'u';
        case 'ü': case 'Ü': return 'u';
        default:
            return std::tolower(static_cast<unsigned char>(c));
    }
}

template <typename T>
bool Pila<T>::esPalindromo(const std::string& frase) {
    std::string espacio = "";
    Pila<char> pila;

    //Buscar Caracteres Validos
    for (char c : frase) {
        if (std::isalnum(static_cast<unsigned char>(c))) {
            char minChar = QuitarTilde(c);
            espacio += minChar;
            pila.insertar(minChar);
        }
    }

    // Comparar las 2 pilas (normal y revez)
    for (char c : espacio) {
        char desdePila = pila.quitar();
        if (c != desdePila) {
            return false;
        }
    }

    return true;
}



template class Pila<char>;
