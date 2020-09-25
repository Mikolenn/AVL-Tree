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
    int num;
    int height;
    Node *left;
    Node *right;
};

int height(Node *node);
// int newNode(int num, Node* root);
int rightRotate(Node *y, Node* root);
int leftRotate(Node *x, Node* root);
int balanceAVL(int num,Node *node);
int insert(Node* node, int num, Node** root);
void printAVL(Node *root);

#endif
