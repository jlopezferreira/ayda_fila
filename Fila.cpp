#include <cassert>
#include "Fila.h"

template <typename T>
Fila<T>::Fila()
{
    puntero_fila = NULL;
}

template <typename T>
Fila<T>::~Fila()
{
    vaciar();
}

template <typename T>
void Fila<T>::agregar(const T & elemento)
{
    Nodo * nuevo = new Nodo;
    nuevo->elemento = elemento;
    nuevo->siguiente = puntero_fila;
    puntero_fila = nuevo;
}

template <typename T>
bool Fila<T>::esVacia() const
{
    return puntero_fila == NULL;
}

// pre: noVacia
template <typename T>
const T & Fila<T>::obtener() const
{
    assert(!esVacia());
    T * elem;
    Nodo * cursor = puntero_fila;
    while (cursor != NULL) {
        if (cursor->siguiente == NULL)
            elem = &(cursor->elemento);
        cursor = cursor->siguiente;
    }
    return (*elem);
}

// pre: noVacia
template <typename T>
bool Fila<T>::eliminar()
{
    bool is_deleted = false;
    if (puntero_fila != NULL) {
        Nodo * cursor = puntero_fila;
        Nodo * anterior = NULL;
        while (cursor != NULL && !is_deleted) {
            if (cursor->siguiente == NULL) {
                if (anterior != NULL)
                    anterior->siguiente = NULL;
                is_deleted = true;
            }
            anterior = cursor;
            cursor = cursor->siguiente;
        }
        if (anterior == puntero_fila)
            puntero_fila = NULL;
        if (is_deleted)
            delete anterior;
   }
    return is_deleted;
}

template <typename T>
void Fila<T>::vaciar()
{
    Nodo * aux;
    while (puntero_fila != NULL) {
        aux = puntero_fila->siguiente;
        delete puntero_fila;
        puntero_fila = aux;
    }
    puntero_fila = NULL;
}

template class Fila<int>;
template class Fila<float>;
