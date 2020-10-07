#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

/**
* Clase que define un nodo de la estructura de datos
*
*/
class Node
{
    public:

    /** Número flotante asociado al nodo */
    float num;

    /** Altura del nodo */
    int height;

    /** Puntero al nodo hijo izquierdo */
    Node *left;

    /** Puntero al nodo hijo derecho */
    Node *right;
};

/**
* avl_create
* Toma una lista de números flotantes, y crea la estructura de datos deseada.
* Retorna el nodo raíz del árbol.
*
* @param [in] size es el tamaño del array de entrada
* @param [in] list es la lista de números flotantes de entrada
* @param [out] new_root es el puntero al nodo raíz del árbol creado
*
* @returns error_code un código de error indicando el éxito o error
* de la función
*
*/
int avl_create(
    int size,
    float* list,
    Node ** new_root);


/**
* avl_node_add
* Toma un número flotante, crea un nodo a partir de él y lo inserta en la 
* estructura de datos.
* Una nueva raíz puede ser obtenida.
*
* @param [in] in_root es el nodo raíz original del árbol
* @param [in] num es el número flotante por insertar
* @param [out] new_root es el puntero al nuevo nodo raíz del árbol
*
* @returns error_code un código de error indicando el éxito o error
* de la función
*
*/
int avl_node_add(
    Node* in_root,
    float num,
    Node** new_root);


/**
* avl_node_remove
* Toma el número flotante arbitrario, busca un nodo que lo contenga y lo 
* elimina de la estructura de datos.
* Da error si el valor no pertenece a algún nodo del árbol.
*
* @param [in] in_root es el nodo raíz original del árbol
* @param [in] node_to_remove es el nodo por eliminar
* @param [out] new_root
* es el puntero al nuevo nodo raíz del árbol
*
* @returns error_code un código de error indicando el éxito o error 
* de la función
*
*/
int avl_node_remove(
    Node* in_root,
    float num,
    Node** new_root);


/**
* avl_search
* Toma un número flotante, lo busca y se devuelve el nodo al que pertenece.
* Si existieran varios nodos con el mismo valor, se devuelve cualquiera.
* Da error si el valor no existe en ningún nodo.
*
* @param [in] root es el nodo raíz original del árbol
* @param [in] num_searched es el número flotante por buscar
* @param [out] node es el nodo encontrado que contiene el valor
*
* @returns error_code un código de error indicando el éxito o error
* de la función
*
*/
int avl_search(
    Node * root,
    float num_searched,
    Node ** nodo);


/**
* avl_max_get
* Se obtiene el nodo que contenga el valor máximo en todo el árbol.
*
* @param [in] root es el nodo raíz original del árbol
* @param [out] max_node es el nodo encontrado que contiene el valor máximo
*
* @returns error_code un código de error indicando el éxito o error
* de la función
*
*/
int avl_max_get(
    Node* root,
    Node** max_node);


/**
* avl_min_get
* Se obtiene el nodo que contenga el valor mínimo en todo el árbol.
*
* @param [in] root es el nodo raíz original del árbol
* @param [out] min_node es el nodo encontrado que contiene el valor mínimo
*
* @returns error_code un código de error indicando el éxito o error
* de la función
*
*/
int avl_min_get(
    Node* root,
    Node** min_node);


/**
* avl_print
* Se imprime el árbol en terminal.
*
* @param [in] root es el nodo raíz original del árbol
*
* @returns error_code un código de error indicando el éxito o error
* de la función
*
*/
int avl_print(
    Node *root);


/**
* height
* Devuelve la altura del arbol o sub-árbol
*
* @param [in] root es la raíz del arbol o sub-árbol
*
* @returns height altura del arbol o sub-árbol
*
*/
int height(
    Node *root);


/**
* rightRotate
* Realiza una rotación a la derecha del arbol o sub-árbol que recibe
*
* @param [in] y es la raíz del arbol o sub-árbol a rotar
* @param [in] root es la nueva raíz del arbol o sub-árbol rotado
*
* @returns código de error
*
*/
int rightRotate(
    Node *y,
    Node** root);


/**
* leftRotate
* Realiza una rotación a la derecha del arbol o sub-árbol que recibe
*
* @param [in] x es la raíz del arbol o sub-árbol a rotar
* @param [in] root es la nueva raíz del arbol o sub-árbol rotado
*
* @returns código de error
*
*/
int leftRotate(
    Node *x,
    Node** root);


/**
* balanceAVL
* Obtiene el balance del arbol
*
* @param [in] root es la raíz del arbol
*
* @returns balance entero con el valor del balance del arbol
*
*/
int balanceAVL(Node *root);


/**
* Códigos de error
*
*/
enum avl_error_codes {
    AVL_SUCCESS = 0,
    AVL_INVALID_PARAM = -1,
    AVL_OUT_OF_RANGE = -2,
    AVL_TIMEOUT = -3,
    AVL_NOT_FOUND = -4,
};

#endif

