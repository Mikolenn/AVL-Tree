#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>


using namespace std;



enum avl_error_codes {
 AVL_SUCCESS = 0,
 AVL_INVALID_PARAM = -1,
 AVL_OUT_OF_RANGE = -2,
 AVL_TIMEOUT = -3,
 AVL_NOT_FOUND = -4,
 // Pueden añadir más
};

class Node
{
    public:
    float num;
    int height;
    Node *left;
    Node *right;
};

int height(Node *node);
int rightRotate(Node *y, Node** root);
int leftRotate(Node *x, Node** root);
int balanceAVL(int num, Node *node);
int insert(Node* node, float num, Node** root);
void printAVL(Node *root);
int minGet(Node* node, Node** min);
int maxGet(Node* node, Node** max);
int create(float* list, Node ** root);
int search(Node * root, float num_searched, Node ** nodo);
//int remove(Node* node, float num, Node** root );
int deleteNode(Node* root, float num, Node** new_root);

#endif
