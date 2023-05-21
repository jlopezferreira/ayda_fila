#include <iostream>
#include "Fila.h"

using namespace std;

int main()
{
    Fila<int> fila;
    int num;
    cout << "Ingrese numero: " << endl;
    cin >> num;
    for (int i = 1; i <= num; i++)
        fila.agregar(i);
    while (!fila.esVacia()) {
        cout << "Primero de la fila:" << fila.obtener() << endl;
        fila.eliminar();
    }
    return 0;
}
