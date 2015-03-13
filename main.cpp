#include "NodoArbolBinario.h"
#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <list>          // std::list
using namespace std;

//Devuelve la suma de todos los numeros del arbol con la raiz dada.
int suma(NodoArbolBinario* raiz)
{
    int numeros = 0;   //se declara la variable numeros y se inicializa en cero
    if(raiz == NULL) //se verifica si la raiz es vacia
    {
        return 0; //si la raiz esta vacia, retorna cero
    }
    if(raiz || NULL)//se verifica si la raiz tiene elementos
    {
        numeros += raiz->num;//se suman los elementos de la raiz
        numeros += suma(raiz->hijo_der) + suma(raiz->hijo_izq);//se llaman a los hijos de las raiz recursivamente y se suman
    }
    return numeros; // devuelve el total de la suma de los hijos de la raiz
}

//Devuelve la cantidad de nodos que tiene el arbol con la raiz dada.
int cantidadNodos(NodoArbolBinario* raiz)
{
    int cantidad = 0; //se declara la variable cantidad y se inicializa en cero
    if(raiz != NULL)//se verifica que la raiz no este vacia
    {
        cantidad++;// se aumenta la variable cantidad
        return cantidad += cantidadNodos(raiz->hijo_der) + cantidadNodos(raiz->hijo_izq);//devuelve la cantidad total de la raiz y luego los suma
        }
}

//Devuelve el promedio de los numeros que tiene el arbol con la raiz dada.
int promedio(NodoArbolBinario* raiz)
{
    if(raiz==NULL) //se verifica si la raiz es null
        return -1;
    return suma(raiz) / cantidadNodos(raiz);//se dividen las funciones anteriores para sacar el promedio
}

//Devuelve la cantidad de pasos que tiene que dar el algoritmo para llegar a un numero dado.
//Ejemplo: http://www.comp.nus.edu.sg/~stevenha/visualization/bst.html
//Para llegar al nodo 7 se ocupan 3 pasos (15,6,7)
//Para llegar al nodo 5 se ocupan 4 pasos (15,6,4,5)
//Para llegar al nodo 15 se ocupa 1 paso (15)
int cuantosPasos(NodoArbolBinario* raiz,int num)
{
        int contador=1;//se declara una variable contador
    if(raiz<=NULL)// vericamos si la raiz es menor o igual a NULL
        return contador; //devuelve la variable contador
    else if(raiz->num==num) //se compara el valor de la raiz con el valor que se esta buscando
        return contador; //si encuentra el valor devuelve la variable contador
    else if(raiz->num<num) //se compara el valor de la raiz con el valor que se esta buscando
        contador+= cuantosPasos(raiz->hijo_der,num); // se verifica cuantos pasos hay en los hijos de la derecha
    else if(raiz->num>num) //se compara el valor de la raiz con el valor que se esta buscando
        contador+= cuantosPasos(raiz->hijo_izq,num); // se verifica cuantos pasos hay en los hijos de la izquierda
    return contador; //devuelve la variable contador
}

//Devuelve la cantidad de hojas que tiene el arbol con la raiz dada
int sumaHojas(NodoArbolBinario* raiz)
{
    if(raiz==NULL) //se verifica si la raiz esta vacia
    return 0;//si esta vacia devuelve cero

    if(raiz->hijo_izq==NULL && raiz->hijo_der==NULL) //se verifica si los hijos derechos e izquierdos de la raiz son nulos
    {
        return 1; //si son nulos devolvemos uno
    }
    else
    {
        return sumaHojas(raiz->hijo_izq)+sumaHojas(raiz->hijo_der); //se suman las hojas de cada lado recursivamente
    }
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 1;
}
