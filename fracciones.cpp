#include <iostream>
#include <cmath>
using namespace std;

int mcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void simplificar(int& numerador, int& denominador) {
    if (denominador == 0) {
        return;
    }
    int divisor = mcd(numerador, denominador);
    numerador /= divisor;
    denominador /= divisor;
    if (denominador < 0) {
        numerador = -numerador;
        denominador = -denominador;
    }
}

void sumar(int n1, int d1, int n2, int d2, int& nResultado, int& dResultado) {
    nResultado = n1 * d2 + n2 * d1;
    dResultado = d1 * d2;
    simplificar(nResultado, dResultado);
}

void restar(int n1, int d1, int n2, int d2, int& nResultado, int& dResultado) {
    nResultado = n1 * d2 - n2 * d1;
    dResultado = d1 * d2;
    simplificar(nResultado, dResultado);
}

void multiplicar(int n1, int d1, int n2, int d2, int& nResultado, int& dResultado) {
    nResultado = n1 * n2;
    dResultado = d1 * d2;
    simplificar(nResultado, dResultado);
}

void dividir(int n1, int d1, int n2, int d2, int& nResultado, int& dResultado) {
    if (n2 == 0) {
        nResultado = 0;
        dResultado = 1;
        return;
    }
    nResultado = n1 * d2;
    dResultado = d1 * n2;
    simplificar(nResultado, dResultado);
}

void mostrarFraccion(int numerador, int denominador) {
    if (denominador == 0) {
        cout << "Indefinido";
        return;
    }
    if (denominador == 1) {
        cout << numerador;
    } else if (numerador == 0) {
        cout << "0";
    } else {
        cout << numerador << "/" << denominador;
    }
}

int main() {
    int n1 = 2, d1 = 3;
    int n2 = 1, d2 = 4;
    int nResultado, dResultado;

cout<<"====================================";
cout<<"=====FRACCIONES CON ESTRUCTURAS=====";
cout<<"====================================";

    cout << "Fraccion 1: ";
    mostrarFraccion(n1, d1);
    cout << endl;

    cout << "Fraccion 2: ";
    mostrarFraccion(n2, d2);
    cout << endl;

    sumar(n1, d1, n2, d2, nResultado, dResultado);
    cout << "Suma: ";
    mostrarFraccion(nResultado, dResultado);
    cout << endl;

    restar(n1, d1, n2, d2, nResultado, dResultado);
    cout << "Resta: ";
    mostrarFraccion(nResultado, dResultado);
    cout << endl;

    multiplicar(n1, d1, n2, d2, nResultado, dResultado);
    cout << "Multiplicacion: ";
    mostrarFraccion(nResultado, dResultado);
    cout << endl;

    dividir(n1, d1, n2, d2, nResultado, dResultado);
    cout << "Division: ";
    mostrarFraccion(nResultado, dResultado);
    cout << endl;

    return 0;
}
