//Autor Alvaro Delgado Brenes
// lista.h
// Declaración de la clase Lista

#ifndef LIST_H
#define LIST_H

#include <iostream>

#define FIN_LINEA '\n'

// Estructura que contiene los datos de cada nodo de la lista
// En este caso se implementa una lista de caracteres 
//cuadruplemente enlazada
struct Nodo {
	char valor;
	Nodo* next;
	Nodo* prev;
	Nodo* up;
	Nodo* down;
};

// Contiene las operaciones de la Lista Enlazada
// Note que el puntero al primer nodo de la lista
// se mantiene oculto al usuario (privado)
class ListaCuadruple {
public:
	ListaCuadruple();   
	~ListaCuadruple();
	int cargar(); //metodo que lee desde un archivo 'map.txt' y lo carga en una lista cuadruplemente enlazada
	void mostrarLista(); //metodo que recorre la lista para mostrar en pantalla
	void borrarLista(); //metodo auxiliar para eliminar la memoria utilizada
	bool listaVacia(); //metodo que retorna true si la lista esta vacia, false en caso contrario
private:
	Nodo* inicio;
};

#endif