#include "functions.h"


int height(Node *node)
{
    if (node == NULL)
        return -1;
    return node->height;
}

// int newNode(int num, Node** root)
// {
//     root->num = num;
//     root->left = NULL;
//     root->right = NULL;
//     root->height = 0;
//
//     return 0;
// }

int rightRotate(Node *y,Node** root )
{
    Node *x = y->left;
    Node *temp = x->right;


    x->right = y;
    y->left = temp;

    y->height =1+ max(height(y->left),
                    height(y->right));
    x->height =1+ max(height(x->left),
                    height(x->right));

    *root= x;
    return 0;
}


int leftRotate(Node *x,Node** root)
{
    Node *y = x->right;
    Node *temp = y->left;


    y->left = x;
    x->right = temp;

    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;


    *root = y;
    return 0;
}



int balanceAVL(int num,Node *node){
  int balance;
  if (node == NULL){balance= -1;}
  else {balance=height(node->left) - height(node->right);}
  return balance;
}


int insert(Node* node, int num, Node** root)
{   cout<<"Voy a insertar  " << num<<endl;
    if (node!= NULL) {
      cout<<"La raiz es " << node->num<<endl;
      cout<<"Su puntero es " << node<<endl;
    }
    int return_val;
    Node* nuevo = new Node();
    //Caso en que el nodo este vacio
    if (node == NULL){
        cout<<"Estoy en caso de crear  " << num<<endl;
        nuevo->num = num;
        nuevo->left = NULL;
        nuevo->right = NULL;
        nuevo->height = 0;
        *root=nuevo;
        return 0;
        return return_val;}
    if (num > node->num){
        cout<<"Insertar en el nodo derecho  " << num<<endl;
        return_val = insert(node->right, num, &node->right);}
    else if (num <= node->num){
        cout<<"Insertar en el nodo izquierdo  " << num<<endl;
        return_val = insert(node->left, num, &node->left);}
    else {// No se pueden numeros iguales
        cout<<"No deberia estar aca"<<endl;
        return -1;}

    // Actualizamos las alturas

    node->height = 1 + max(height(node->left),
                           height(node->right));

    // Encuentra el balance, y si no es adecuado, lo balancea, retorna el puntero a la raiz
    int balance = balanceAVL(num,node);
    cout<<"Balance  " << balance<<endl;

    // Left Left Case
    if (balance > 1 && num < node->left->num)
        return rightRotate(node, root);

    // Right Right Case
    if (balance < -1 && num > node->right->num)
        return leftRotate(node, root);

    // Left Right Case
    if (balance > 1 && num > node->left->num)
    {
        return_val = leftRotate(node->left, &node->left);
        return rightRotate(node, root);
    }

    // Right Left Case
    if (balance < -1 && num < node->right->num)
    {
        return_val = rightRotate(node->right, &node->right);
        return leftRotate(node, root);
    }


    return 1;


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
