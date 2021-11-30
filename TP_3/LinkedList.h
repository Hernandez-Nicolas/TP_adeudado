/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
Node* test_getNode(LinkedList* this, int nodeIndex);

LinkedList* ll_newLinkedList(void);
//Crea una nueva lista en memoria

int ll_add(LinkedList* this, void* pElement);
//Agrega un nodo a la lista

int ll_len(LinkedList* this);
//La cantidad de nodos conetados a la lista

void* ll_get(LinkedList* this, int index);
//Devuelve un puntero hacia el dato del nodo pasando la pocicion del nodo en la que esta

int ll_set(LinkedList* this, int index,void* pElement);
//Carga un dato en la posision del nodo que se desee

int ll_push(LinkedList* this, int index, void* pElement);
//Crea un nodo con su dato entre dos nodos, justo despues de la posicion que se paso

int ll_remove(LinkedList* this,int index);
//Borra un nodo

void* ll_pop(LinkedList* this,int index);
//Igual a remove pero me devuelve el dato

int ll_clear(LinkedList* this);
//Elimina todos los nodos pero no la lista

int ll_deleteLinkedList(LinkedList* this);
//Borra la toda la lista

int ll_indexOf(LinkedList* this, void* pElement);
//Busca un dato i devuelve la pocicion en la lista

int ll_isEmpty(LinkedList* this);
//Verifica si la lista esta sin nodos, retorna 0 en caso de haber nodos y 1 en caso de estar vacio

int ll_contains(LinkedList* this, void* pElement);
//Verifica si un nodo contiene ese elemento

int ll_containsAll(LinkedList* this,LinkedList* this2);
//Si una lista esta contenida en la otra

LinkedList* ll_subList(LinkedList* this,int from,int to);
//Crea una sub lista desde cierto indice hasta otro

LinkedList* ll_clone(LinkedList* this);
//Copia la lista

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
//Ordena la lista con un criterio pasado con un puntero a funcion
