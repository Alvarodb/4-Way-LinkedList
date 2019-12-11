//Autor Alvaro Delgado Brenes
// ListaCuadruple.cpp
// Definición de la clase Lista

#include "list.h"
#include <fstream>

ListaCuadruple::ListaCuadruple() {
	inicio = nullptr;
}

ListaCuadruple::~ListaCuadruple() {
	borrarLista();
}

int ListaCuadruple::cargar() {
	char letra;
	std::ifstream archivo("map.txt", std::ifstream::in);

	Nodo* tmp = nullptr;
	Nodo* tmp2 = nullptr;
	Nodo* tmp3 = nullptr;
	Nodo* tmp4 = nullptr;
	Nodo* nuevo = nullptr;
	bool ban = true;
	if (archivo.good()) {
		while (archivo >> std::noskipws >> letra) {
			if (letra != FIN_LINEA) {
				if (!nuevo) {
					try
					{
						nuevo = new Nodo;
					}
					catch (std::bad_alloc exception)
					{
						return -1;
					}
					nuevo->valor = letra;
					nuevo->next = nullptr;
					nuevo->prev = nullptr;
					nuevo->up = nullptr;
					nuevo->down = nullptr;
					ban = true;
				}
				else {
					nuevo->valor = letra;
					ban = false;
				}
				if (inicio == nullptr) {
					inicio = nuevo;
					tmp2 = inicio;
				}
				else if (ban) {
					if (tmp3) {
						tmp = inicio;
						while (tmp->next) {
							tmp = tmp->next;
							tmp3 = tmp3->next;
						}
						tmp3 = tmp3->next;
						tmp->next = nuevo;
						nuevo->prev = tmp;
						nuevo->up = tmp3;
						tmp3->down = nuevo;
						tmp3 = tmp4;
						ban = false;
					}
					else {
						tmp = inicio;
						while (tmp->next) {
							tmp = tmp->next;
						}
						tmp->next = nuevo;
						nuevo->prev = tmp;
					}
				}
				nuevo = nullptr;
			}
			else {
				try
				{
					nuevo = new Nodo;
				}
				catch (std::bad_alloc exception)
				{
					return -1;
				}
				nuevo->next = nullptr;
				nuevo->prev = nullptr;
				nuevo->up = inicio;
				inicio->down = nuevo;
				nuevo->down = nullptr;
				tmp3 = inicio;
				tmp4 = tmp3;
				inicio = nuevo;
			}
		}
	}
	else {
		return -1;
	}
	inicio = tmp2;
}
void ListaCuadruple::mostrarLista() {

	if (listaVacia()) {
		std::cout << std::endl << std::endl << "La lista no tiene elementos." << std::endl;
	}
	else
	{
		Nodo* tmp;
		Nodo* tmp2;
		tmp = inicio;
		tmp2 = inicio;
		while (tmp2) {
			while (tmp) {
				std::cout << tmp->valor;
				tmp = tmp->next;
			}
			tmp2 = tmp2->down;
			tmp = tmp2;
			std::cout << std::endl;  
		}
	}
}
void ListaCuadruple::borrarLista() {
	Nodo* tmp;
	Nodo* tmp2 = inicio;
	Nodo* tmp3 = inicio;
	while (tmp2 != nullptr) {
		while (inicio != nullptr) {
			tmp3 = inicio->down;
			tmp = inicio;
			inicio = inicio->next;
			delete tmp;
		}
		tmp2 = tmp3;
		inicio = tmp2;
	}
}
bool ListaCuadruple::listaVacia() {
	if (inicio == nullptr)
		return true;
	return false;
}