#include <iostream>

//lista doblemente enlazada

struct NDoble {
    int dato;
    NDoble* next;
    NDoble* prev;

    NDoble(int val) : dato(val), next(NULL), prev(NULL) {} //se inicia next y prev y lo llamandola null
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////7
//la siguiente funcion es para imprimir una lista 
void imprimirLista(NDoble* c) {
    NDoble* actual = c;
    while (actual != NULL) {
        std::cout << actual->dato << " , ";
        actual = actual->next;
    }
    std::cout << std::endl;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//la siguiente funcion es para insertar un dato a las lista 
void insertarDato(NDoble*& c, int nDato) {
    NDoble* nNodo = new NDoble(nDato);
    nNodo->next = c; //se encabeza el nuevo nodo al nodo siguiente.
    if (c != NULL) {
        c->prev = nNodo; // si la cabeza no es null, se establece el nodo anterior de la cabeza como el nuevo nodo.
    }
    c = nNodo; //se actualiza la cabeza de la lista 
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//funcion para acctualizar un dato de la lista
void actualizarDato(NDoble* c, int datoAnterior, int nDato) {
    NDoble* actual = c;
    while (actual != NULL) {
        if (actual->dato == datoAnterior) {
            actual->dato = nDato; //actualizamos el dato del nodo actual
            return;
        }
        actual = actual->next;
    }
    std::cout << "EL DATO NO SE ENCUENTRA EN LA LISTA." << std::endl;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////7
// funcion para eliminar un dato de la lista
void eliminarDato(NDoble*& c, int datoAEliminar) {
    NDoble* actual = c;
    
    while (actual != NULL) {
        if (actual->dato == datoAEliminar) {
            if (actual->prev != NULL) {
                actual->prev->next = actual->next; // se enlazo el nodo anterior al nodo siguiente
            } else {
                c = actual->next; // si es la cabeza, se actualiza 
            }
            if (actual->next != NULL) {
                actual->next->prev = actual->prev; // enlazamos el nodo siguiente al nodo anterior 
            }
            delete actual;// eliminamos el nodo actual
            return;
        }
        actual = actual->next;
    }
    std::cout << "EL DATO NO SE ENCUENTRA EN LA LISTA." << std::endl;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    NDoble* c = NULL;

    for (int i = 1; i <= 20; ++i) {
        insertarDato(c, i);
    }

    imprimirLista(c);

    int opcion;
    do {
        std::cout << "Opciones:" << std::endl;
        std::cout << "1. INSERTAR DATO" << std::endl;
        std::cout << "2. MOSTRAR LISTA" << std::endl;
        std::cout << "3. ACTUALIZAR DATO" << std::endl;
        std::cout << "4. ELIMINAR DATO" << std::endl;
        std::cout << "0. SALIR" << std::endl;
        std::cout << "INGRESE UNA OPCION: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                int nDato;
                std::cout << "Ingrese el nuevo dato: ";
                std::cin >> nDato;
                insertarDato(c, nDato);
                break;
            case 2:
                imprimirLista(c);
                break;
            case 3:
                int datoAnterior;
                std::cout << "Ingrese el dato a actualizar: ";
                std::cin >> datoAnterior;
                std::cout << "Ingrese el nuevo valor: ";
                std::cin >> nDato;
                actualizarDato(c, datoAnterior, nDato);
                break;
            case 4:
                int datoAEliminar;
                std::cout << "Ingrese el dato a eliminar: ";
                std::cin >> datoAEliminar;
                eliminarDato(c, datoAEliminar);
                break;
            case 0:
                break;
            default:
                std::cout << "Opción no válida. Intente nuevamente." << std::endl;
        }
    } while (opcion != 0);

    // Liberar memoria
    while (c != NULL) {
        NDoble* temp = c;
        c = c->next;
        delete temp;
    }

    return 0;
}
