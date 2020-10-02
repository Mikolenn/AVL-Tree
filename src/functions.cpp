#include "functions.h"

int deleteNode(Node* root, float num, Node** new_root)  
{  
    Node* temp = new Node();
    int error_code=-4;
      
    if (root == NULL){
        *new_root=root;  
        return error_code; 
    } 
  
    // Si el valor buscado es
    //menor, se va a la izquierda 
    if ( num < root->num )  

        error_code = deleteNode(root->left, num, &(root->left));  
   
    else if( num > root->num )

        error_code = deleteNode(root->right, num, &(root->right));

    else if(num != root->num){

        *new_root = root;
        return -4;
    }
 
    else
    {  
 
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            temp = root->left ?  
                         root->left :  
                         root->right;  
   
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else  
            *root = *temp;  
                         
            free(temp);  
        }  
        else
        {  

            error_code = minGet(root->right, &temp);  
  

            root->num = temp->num;  
  
            error_code = deleteNode(root->right, temp->num, &(root->right));
 
        }  
    }  
   
    if (root == NULL)  
    *new_root=root;
    return 0;  

    root->height = 1 + max(height(root->left),  
                           height(root->right));  
 
    int balance = balanceAVL(root);


    if (balance > 1 &&  
        balanceAVL(root->left) >= 0)  
        return rightRotate(root, new_root);


    if (balance > 1 &&  
        balanceAVL(root->left) < 0)  
    {  
        error_code = leftRotate(root->left, &(root->left));  
        return rightRotate(root, new_root);  
    }  

    if (balance < -1 &&  
        balanceAVL(root->right) <= 0)  
        return leftRotate(root, new_root);  

    if (balance < -1 &&  
        balanceAVL(root->right) > 0)  
    {  
        error_code = rightRotate(root->right, &(root->right));  
        return leftRotate(root, new_root);  
    }  
    
    *new_root=root;

    return 0;  
}  


int search(Node * root, float num_searched, Node ** nodo){
    if (root==NULL) {
        return -4;
    }
    else if (root->num==num_searched){
        *nodo=root;
        return 1;
    }
    else if (num_searched > root->num) {
        return search(root->right, num_searched, nodo);
    }
    else if (num_searched < root->num){
        return search(root->left, num_searched, nodo);
    }

    return -4;
}


int create(float* list, Node ** root){

    for (int i = 0; i < (int)sizeof(list); i++) {
        insert(*root,  list[i], root);
    }

    return 1;
}


int minGet(Node* node, Node** min)
{
    Node* current=node;
    while (current->left != NULL)
    {
        current= current->left;
    }
        
    *min=current;
    return 1;
}


int maxGet(Node* node, Node** max)
{
    Node* current=node;
    while (current->right != NULL)
    {
        current= current->right;
    }    

    *max=current;
    return 1;
}


int height(Node *node)
{
    if (node == NULL)
        return 0;

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


int balanceAVL(Node *node){
    int balance;
    if (node == NULL)
    {
        balance= 0;

    } else 
    {
        balance=height(node->left) - height(node->right);
    }
    
    return balance;
}


int insert(Node* node, float num, Node** root)
{

    int return_val=0;
    Node* nuevo = new Node();
    //Caso en que el nodo este vacio
    if (node == NULL){

        nuevo->num = num;
        nuevo->left = NULL;
        nuevo->right = NULL;
        nuevo->height = 1;
        *root=nuevo;
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
    int balance = balanceAVL(node);


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

    *root=node;
    return return_val;


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
