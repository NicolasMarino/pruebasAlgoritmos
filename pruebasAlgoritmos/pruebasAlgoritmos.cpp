// pruebasAlgoritmos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

struct NodoLista {
	int dato;
	NodoLista* sig;
	NodoLista() {}
	NodoLista(int d) : dato(d), sig(NULL) {}
};

struct NodoAB {
	int dato;
	NodoAB* izq;
	NodoAB* der;
	NodoAB() {}
	NodoAB(int d) : dato(d), izq(NULL), der(NULL) {}
};

struct NodoAG {
	int dato;
	NodoAG* ph;
	NodoAG* sh;
	NodoAG() {}
	NodoAG(int d) : dato(d), ph(NULL), sh(NULL) {}
};


bool buscarElementoEnNABB(NodoAB* raiz, int dato) {
	while (raiz != nullptr)
	{
		if (raiz->dato == dato) return true;
		else if (raiz->dato > dato) raiz = raiz->izq;
		else raiz = raiz->der;

	}
	return false;
}

NodoAB* crearNodoAB(int dato, NodoAB* datoIzq, NodoAB* datoDer) {
	NodoAB* nuevo = new NodoAB();
	nuevo->dato = dato;
	nuevo->izq = datoIzq;
	nuevo->der = datoDer;
	return nuevo;
}

void insertarABB(NodoAB*& raiz, int elemento) {
	NodoAB* aux = raiz;
	NodoAB* insertar = crearNodoAB(elemento, NULL, NULL);
	if (raiz == nullptr) 
	{
		raiz = insertar;
	}
	else
	{
		while (aux != nullptr) {
			if (aux->dato > elemento) {
				if (aux->izq == nullptr) {
					aux->izq = insertar;
					aux = aux->izq;
				}
				aux = aux->izq;
			}
			else if (aux->dato < elemento) {
				if (aux->der == nullptr) {
					aux->der = insertar;
					aux = aux->der;
				}
				aux = aux->der;
			}
		}
	}
		
		

}

int main()
{
	NodoAB* unArbolNull1 = nullptr;

	NodoAB* unArbol = new NodoAB();
	unArbol->dato = 5;
	
	NodoAB* unArbolIzq2 = new NodoAB();
	unArbolIzq2->dato = 1;
	unArbolIzq2->izq = unArbolNull1;
	unArbolIzq2->der = unArbolNull1;

	NodoAB* unArbolDer2 = new NodoAB();
	unArbolDer2->dato = 3;
	unArbolDer2->izq = unArbolNull1;
	unArbolDer2->der = unArbolNull1;

	NodoAB* unArbolIzq1 = new NodoAB();
	unArbolIzq1->dato = 2;
	unArbolIzq1->izq = unArbolIzq2;
	unArbolIzq1->der = unArbolDer2;
	unArbol->izq = unArbolIzq1;

	

	NodoAB* unArbolIzq3 = new NodoAB();
	unArbolIzq3->dato = 6;
	unArbolIzq3->izq = unArbolNull1;
	unArbolIzq3->der = unArbolNull1;

	NodoAB* unArbolDer4 = new NodoAB();
	unArbolDer4->dato = 9;
	unArbolDer4->izq = unArbolNull1;
	unArbolDer4->der = unArbolNull1;

	NodoAB* unArbolDer3 = new NodoAB();
	unArbolDer3->dato = 8;
	unArbolDer3->izq = nullptr;
	unArbolDer3->der = unArbolDer4;

	NodoAB* unArbolDer1 = new NodoAB();
	unArbolDer1->dato = 7;
	unArbolDer1->izq = unArbolIzq3;
	unArbolDer1->der = unArbolDer3;
	unArbol->der = unArbolDer1;


	insertarABB(unArbol, 10);
	bool estaEl10 = buscarElementoEnNABB(unArbol, 10);
	bool estaEl6 = buscarElementoEnNABB(unArbol, 6);

	int test = 0;
}
