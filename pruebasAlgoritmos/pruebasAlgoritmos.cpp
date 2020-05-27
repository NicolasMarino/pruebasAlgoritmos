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
		else if(raiz->dato < dato) raiz = raiz->der;
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

NodoLista* agregarCabeza(int dato, NodoLista* siguiente)
{
	NodoLista* nuevoNL = new NodoLista();
	nuevoNL->dato = dato;
	nuevoNL->sig = siguiente;
	return nuevoNL;
}

void agregarCabezaReferencia(int dato, NodoLista*& siguiente)
{
	NodoLista* nuevoNL = new NodoLista();
	nuevoNL->dato = dato;
	nuevoNL->sig = siguiente;
	siguiente = nuevoNL;
}

void eliminarCabeza(NodoLista*& nodo) {
	if (nodo != nullptr) {
		NodoLista* aux = nodo;
		nodo = nodo->sig;
		delete aux;
	}
}

/*****************************************/

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

NodoLista* ordenadaSinRepetidos(NodoLista* l1) {

	NodoLista* retorno = NULL;
	int dato = 0;
	if (l1 != NULL)
	dato = l1->dato;
	
	while (l1 != NULL) {
		if (l1->dato != dato || retorno == NULL)
		{
			dato = l1->dato;
		}
		l1 = l1->sig;
	}
	return retorno;
}

void eliminarElemento(NodoLista*& lista, int pos) {
	NodoLista* aux = lista;
	int contador = 0;
	if (pos == 0) {
		eliminarCabeza(aux->sig);
	}
	else {
		while (aux != nullptr && pos -1 != contador)
		{
			aux = aux->sig;
			contador++;
		}
		if (aux != nullptr && contador == pos - 1)
			eliminarCabeza(aux->sig);
	}
}

void eliminarLista(NodoLista*& l) {
	while (l != nullptr)
	{
		eliminarCabeza(l);
	}
}

void eliminarMayor(int x, NodoLista*& l) {
	while (l != nullptr && l->dato > x)
	{
		eliminarCabeza(l);
	}
	NodoLista* listaAux = l;
	while (listaAux != nullptr && listaAux->sig != nullptr && listaAux->sig->dato <= x) {
		listaAux = listaAux->sig;
	}	
	if(listaAux != nullptr)	eliminarLista(listaAux->sig);
}

NodoLista* concatRecursivo(NodoLista* l1, NodoLista* l2) {
	if (l1 == nullptr) {
		return l2;
	}
	l1->sig = concatRecursivo(l1->sig, l2);
	return l1;
}

void agregarAlFinal(NodoLista* l1, NodoLista* l2) {

}

NodoLista* concatIterativo(NodoLista* l1, NodoLista* l2) {
	if (l1 == nullptr) {
		return l2;
	}
	else {
		while (l1->sig != nullptr)
		{
			l1 = l1->sig;
		}
		l1->sig = l2;
	}
	return l1;
}

void impNivel(NodoAG* t, int k) {
	if (t != NULL && k > 0) {
		if (k == 1) std::cout << t->dato;
		else impNivel(t->ph, k - 1);
		impNivel(t->sh, k);
	}
}

void insertarPosK(NodoLista*& l, unsigned int k, int dato) {
	if (k == 0) {
		agregarCabezaReferencia(dato, l);
	}
	else {
		int contador = 0;
		NodoLista* aux = l;
		while (aux != nullptr && k != 0)
		{
			aux = aux->sig;
			k--;
		}
		NodoLista* nuevo = new NodoLista();
		nuevo->dato = dato;
		if (aux != nullptr && aux->sig == nullptr) {
			aux->sig = nuevo;
			nuevo->sig = aux->sig;
		}
		else if(aux != nullptr && aux->sig != nullptr){
			nuevo->sig = aux->sig;
			aux->sig = nuevo;
		}
	}
}

void imprimirPreOrder(NodoAB* raiz) {
	if (raiz != nullptr)
	{
		imprimirPreOrder(raiz->izq);
		std::cout << raiz->dato;
		imprimirPreOrder(raiz->der);
	}
}

NodoLista* ordenadaSinRepetidos2(NodoLista*& l) {
	if (l == nullptr) return nullptr;
	NodoLista* listaRetorno = nullptr;
	NodoLista* ultimo = nullptr;
	while (l != nullptr && l->sig != nullptr && l->dato == l->sig->dato) {
		NodoLista* aux = new NodoLista(); 
			l = l->sig;
		delete aux;
	}
	while (l != nullptr ) {
		if (l->sig != nullptr && l->dato == l->sig->dato) {
			NodoLista* aux = new NodoLista();
			l = l->sig;
			delete aux;
		}
		else {
			if (listaRetorno == nullptr)
			{
				listaRetorno = new NodoLista();
				listaRetorno->dato = l->dato;
				listaRetorno->sig = nullptr;
				ultimo = listaRetorno;
				l = l-> sig;
			}
			else {
				NodoLista* nuevoNodo = new NodoLista();
				nuevoNodo->dato = l->dato;
				nuevoNodo->sig = nullptr;
				ultimo->sig = nuevoNodo;
				ultimo = nuevoNodo;
				l = l->sig;
			}
		}
	}

	return listaRetorno;
}

NodoLista* caminoAG(NodoAG* arbol, int dato) {
	if (arbol == nullptr) return nullptr;
	if (arbol->dato == dato) {
		NodoLista* ultimoDato = new NodoLista();
		ultimoDato->dato = dato;
		ultimoDato->sig = nullptr;
		return ultimoDato;
	}
	else {
		NodoLista* aux = caminoAG(arbol->ph, dato);
		if (aux != nullptr) {
			NodoLista* siguienteNodo = new NodoLista();
			siguienteNodo->dato = dato;
			siguienteNodo->sig = aux;
			aux = siguienteNodo;
			return aux;
		}
		else {
			return  caminoAG(arbol->sh, dato);
		}
	}
}

void nivelDeElementoAUX(NodoAG* a, int x, int nivelActual, int nivelX) {
	if (a != NULL) {
		if (a->dato == x) nivelX = nivelActual;
		else {
			nivelDeElementoAUX(a->ph, x, nivelActual + 1, nivelX);
			nivelDeElementoAUX(a->sh, x, nivelActual, nivelX);
		}
	}
}

int nivelDeElemento(NodoAG* A, int x) {
	int nivelX = 0;
	nivelDeElementoAUX(A, x, 1, nivelX);
	return nivelX;
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
		
	NodoLista* lista = new NodoLista();
	lista->dato = 1;
	NodoLista* lista2 = new NodoLista();
	lista2->dato = 2;
	lista->sig = lista2;
	NodoLista* lista3 = new NodoLista();
	lista3->dato = 2;
	lista2->sig = lista3;
	NodoLista* lista4 = new NodoLista();
	lista4->dato = 3;
	lista3->sig = lista4;
	NodoLista* lista5 = nullptr;
	lista4->sig = lista5;

	NodoLista* lista23 = new NodoLista();
	lista23->dato = 4;
	NodoLista* lista22 = new NodoLista();
	lista22->dato = 4;
	lista23->sig = lista22;
	NodoLista* lista32 = new NodoLista();
	lista32->dato = 5;
	lista22->sig = lista32;
	NodoLista* lista42 = new NodoLista();
	lista42->dato = 6;
	lista32->sig = lista42;
	NodoLista* lista52 = nullptr;
	lista42->sig = lista52;

	NodoAG* unNodoGeneral = new NodoAG();
	unNodoGeneral->dato = 1;
	NodoAG* unNodoGeneral2 = new NodoAG();
	unNodoGeneral2->dato = 1;
	NodoAG* unNodoGeneral3 = new NodoAG();
	unNodoGeneral3->dato = 1;


	insertarABB(unArbol, 10);
	bool estaEl10 = buscarElementoEnNABB(unArbol, 10);
	bool estaEl6 = buscarElementoEnNABB(unArbol, 6);
    //eliminarMayor(2, lista);
	//insertarPosK(lista, 0, 5);
	//NodoLista* unNodo = concatRecursivo(lista, lista23);
	NodoLista* unNodoDos = concatIterativo(lista, lista23);
	NodoLista* unNodo2 = ordenadaSinRepetidos(lista);

	int test = 0;
}
