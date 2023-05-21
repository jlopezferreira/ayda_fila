#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

template <typename T>
class Fila
{
private:
    // Definici�n de la estructura
    struct Nodo {
        T elemento;
        Nodo * siguiente;
    };
    // Atributo de clase
    Nodo * puntero_fila;
    // M�todo auxiliar
    void vaciar();

public:
    Fila(); // Constructor
    ~Fila(); // Destructor
    void agregar(const T & elemento);
    bool esVacia() const;
    const T & obtener() const; // pre: noVacia
    bool eliminar(); // pre: noVacia
};

#endif // FILA_H_INCLUDED
