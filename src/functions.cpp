#include "functions.h"


int height(Node *node)
{
    if (node == NULL)
        return -1;
    return node->height;
}

Node* newNode(int num)
{
    Node* node = new Node();
    node->num = num;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;

    return(node);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *temp = x->right;


    x->right = y;
    y->left = temp;

    y->height =1+ max(height(y->left),
                    height(y->right));
    x->height =1+ max(height(x->left),
                    height(x->right));

    return x;
}


Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *temp = y->left;


    y->left = x;
    x->right = temp;

    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;


    return y;
}




Node* balanceAVL(int num,Node *node){
  int balance;
  if (node == NULL){balance= -1;}
  else {balance=height(node->left) - height(node->right);}

  // Left Left Case
  if (balance > 1 && num < node->left->num)
      return rightRotate(node);

  // Right Right Case
  if (balance < -1 && num > node->right->num)
      return leftRotate(node);

  // Left Right Case
  if (balance > 1 && num > node->left->num)
  {
      node->left = leftRotate(node->left);
      return rightRotate(node);
  }

  // Right Left Case
  if (balance < -1 && num < node->right->num)
  {
      node->right = rightRotate(node->right);
      return leftRotate(node);
  }


  return node;
}

Node* insert(Node* node, int num)
{
    //Caso en que el nodo este vacio
    if (node == NULL)
        return(newNode(num));
    if (num > node->num)
        node->right = insert(node->right, num);
    else if (num < node->num)
        node->left = insert(node->left, num);
    else // No se pueden numeros iguales
        return node;

    // Actualizamos las alturas

    node->height = 1 + max(height(node->left),
                           height(node->right));

    // Encuentra el balance, y si no es adecuado, lo balancea, retorna el puntero a la raiz
    return balanceAVL(num,node);
}





void printAVL(Node *root)
{
    if(root != NULL)
    {
        cout << root->num << " ";
        printAVL(root->left);
        printAVL(root->right);
    }
}
