iterativa
devuelvo una lista ordenada de mayor a menor, sin elementos repetidos.
si la lista es vacia el resultado es vacio.

Lista ordenadaSinRepetidos(Lista l){ 
	if(l == nullptr) return nullptr;
	Lista listaRetorno = new Lista();
	Lista ultimo = new Lista();
	while (l != nullptr && l->dato == l->sig->dato){
		Lista aux = new Lista();1
		l = lista->sig;
		delete aux;
	}
	while(l != nullptr && l->sig != nullptr){
		if(l->dato == l->sig->dato){
            Lista aux = new Lista();
            l = lista->sig;
            delete aux;
		}else{
	          if(listaRetorno == nullptr)
              {
                  listaRetorno = new Lista();
                  listaRetorno->dato = l->dato;
                  listaRetorno->sig = nullptr;
                  ultimo = listaRetorno;
              }
              else{
                  Lista nuevoNodo = new Lista();
                  nuevoNodo->dato = l->dato;
                  nuevoNodo->sig = nullptr;
                  ultimo->sig = nuevoNodo;
                  ultimo = nuevoNodo;
              }
		}
	}
    return listaRetorno;
}


NodoLista* camino(NodoAB* arbol, int x)
{
	if (arbol == NULL) return NULL;
	NodoLista* ret = new NodoLista;
    ret->dato = arbol->dato;
	ret->sig = NULL;
	if (x > arbol->dato)
	{
		ret->sig = camino(arbol->der, x);
	}
	else
	{
		ret->sig = camino(arbol->izq, x);
	}
	return ret;
}

void eliminarMayor(int x, NodoLista*& l) {
	while (l != nullptr && l->dato > x)
	{
		eliminarCabeza(l);
	}
	NodoLista* listaAux = l;
	while (listaAux != nullptr && listaAux->sig != nullptr) {
		if (listaAux->dato < x)
		{
			listaAux = listaAux->sig;
		}
		else
		{
			if(listaAux->sig != nullptr && listaAux->sig->dato > x){
				while (listaAux->sig) {
					eliminarCabeza(listaAux->sig);
				}
			}
		}
	}	
}



bool Insertar(NodoAG*& a, int padre, int ultimoHijo){
	if(a==nullptr) return false;
	if(a->dato != padre)
	{
		if(Insertar(a->ph, padre, ultimoHijo)) return true;
		return Insertar(a->sh, padre, ultimoHijo);
	}
	//parado sobre el padre.

	NodoAG* nuevo = new NodoAG;
	nuevo->sh = nullptr;
	nuevo->ph = nullptr;
	
	if(a->ph == nullptr){
		a->ph = nuevo;
	}
	else{
		NodoAG* ant = a->ph;
		while(ant->sh != nullptr) ant = ant->sh;
		ant->sh = nuevo;
	}
	return true;
}



void agregarAlFinal(AG*& raiz, int dato){
	if(raiz == nullptr){
		raiz = new AG();
		raiz->dato == dato;
		raiz->ph = nullptr;
		raiz->sh = nullptr;
	}
	else	
		agregarAlFinal(raiz->s	h, dato);
}