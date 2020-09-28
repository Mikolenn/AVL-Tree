#include "functions.h"

int create(float* list, Node ** root){

  for (int i = 0; i < sizeof(list); i++) {
    insert(*root,  list[i], root);
  }

  return 1;

}

int minGet(Node* node, Node** min)
{
    Node* current=node;
    while (current->left != NULL)
        // cout<<current->num<<endl;
        current= current->left;
        *min=current;
    return 1;
}

int maxGet(Node* node, Node** max)
{
    Node* current=node;
    while (current->right != NULL)
        // cout<<current->num<<endl;
        current= current->right;
        *max=current;
    return 1;
}

int height(Node *node)
{
    if (node == NULL)
        return -1;
    return node->height;
}

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
{
    if (node!= NULL) {

    }
    int return_val;
    Node* nuevo = new Node();
    //Caso en que el nodo este vacio
    if (node == NULL){

        nuevo->num = num;
        nuevo->left = NULL;
        nuevo->right = NULL;
        nuevo->height = 0;
        *root=nuevo;
        return 0;
        return return_val;}
    if (num > node->num){

        return_val = insert(node->right, num, &node->right);}
    else if (num <= node->num){

        return_val = insert(node->left, num, &node->left);}
    else {// No se pueden numeros iguales

        return -1;}

    // Actualizamos las alturas

    node->height = 1 + max(height(node->left),
                           height(node->right));

    // Encuentra el balance, y si no es adecuado, lo balancea, retorna el puntero a la raiz
    int balance = balanceAVL(num,node);


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
