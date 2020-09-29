#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>


using namespace std;

class Node
{
    public:
    int num;
    int height;
    Node *left;
    Node *right;
};

int height(Node *node);
Node* newNode(int num);
Node* rightRotate(Node *y);
Node* leftRotate(Node *x);
Node* balanceAVL(int num,Node *node);
Node* insert(Node* node, int num);
void printAVL(Node *root);

#endif
