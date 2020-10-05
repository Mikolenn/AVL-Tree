#include "functions.h"

int avl_node_remove(Node* in_root, float num, Node** new_root)  
{  
    Node* temp = new Node();
    int error_code=-4;
      
    if (in_root == NULL){
        *new_root=in_root;  
        return error_code; 
    } 
  
    // Si el valor buscado es
    //menor, se va a la izquierda 
    if ( num < in_root->num )  

        error_code = avl_node_remove(in_root->left, num, &(in_root->left));  
   
    else if( num > in_root->num )

        error_code = avl_node_remove(in_root->right, num, &(in_root->right));

    else if(num != in_root->num){

        *new_root = in_root;
        return -4;
    }
 
    else
    {  
 
        if( (in_root->left == NULL) || 
            (in_root->right == NULL) )  
        {  
            temp = in_root->left ?  
                         in_root->left :  
                         in_root->right;  
   
            if (temp == NULL)  
            {  
                temp = in_root;  
                in_root = NULL;  
            }  
            else  
            *in_root = *temp;  
                         
            free(temp);  
        }  
        else
        {  

            error_code = avl_min_get(in_root->right, &temp);  
  

            in_root->num = temp->num;  
  
            error_code = avl_node_remove(in_root->right, temp->num, &(in_root->right));
 
        }  
    }  
   
    if (in_root == NULL)  
    *new_root=in_root;
    return 0;  

    in_root->height = 1 + max(height(in_root->left),  
                           height(in_root->right));  
 
    int balance = balanceAVL(in_root);


    if (balance > 1 &&  
        balanceAVL(in_root->left) >= 0)  
        return rightRotate(in_root, new_root);


    if (balance > 1 &&  
        balanceAVL(in_root->left) < 0)  
    {  
        error_code = leftRotate(in_root->left, &(in_root->left));  
        return rightRotate(in_root, new_root);  
    }  

    if (balance < -1 &&  
        balanceAVL(in_root->right) <= 0)  
        return leftRotate(in_root, new_root);  

    if (balance < -1 &&  
        balanceAVL(in_root->right) > 0)  
    {  
        error_code = rightRotate(in_root->right, &(in_root->right));  
        return leftRotate(in_root, new_root);  
    }  
    
    *new_root=in_root;

    return 0;  
}  


int avl_search(Node * root, float num_searched, Node ** nodo){

    if (root == NULL) {

        return -4;
    }
    else if (root->num == num_searched){

        *nodo=root;
        return 0;
    }
    else if (num_searched > root->num) {

        return avl_search(root->right, num_searched, nodo);
    }
    else if (num_searched < root->num){

        return avl_search(root->left, num_searched, nodo);
    }

    return -1;
}


int avl_create(int size, float* list, Node ** new_root){

    int error_code = 0;

    for (int i = 0; i < size; i++) {
        error_code = avl_node_add(*new_root,  list[i], new_root);
    }

    return error_code;
}


int avl_min_get(Node* root, Node** min_node)
{
    Node* current=root;
    while (current->left != NULL)
    {
        current= current->left;
    }
        
    *min_node=current;
    return 0;
}


int avl_max_get(Node* root, Node** max_node)
{
    Node* current=root;
    while (current->right != NULL)
    {
        current= current->right;
    }    

    *max_node=current;
    return 0;
}


int height(Node *root)
{
    if (root == NULL)
        return 0;

    return root->height;
}


int rightRotate(Node *y, Node** root )
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


int balanceAVL(Node *root){

    int balance;

    if (root == NULL)
    {
        balance= 0;

    } else 
    {
        balance=height(root->left) - height(root->right);
    }
    
    return balance;
}


int avl_node_add(Node* in_root, float num, Node** new_root)
{

    int error_code=0;
    Node* nuevo = new Node();
    //Caso en que el nodo este vacio
    if (in_root == NULL){

        nuevo->num = num;
        nuevo->left = NULL;
        nuevo->right = NULL;
        nuevo->height = 1;
        *new_root=nuevo;

        return error_code;
    }

    if (num > in_root->num)
    {
        error_code = avl_node_add(in_root->right, num, &in_root->right);
    }
    else if (num <= in_root->num)
    {
        error_code = avl_node_add(in_root->left, num, &in_root->left);
    }
    else {// No se pueden numeros iguales

        return -1;
    }

    // Actualizamos las alturas

    in_root->height = 1 + max(height(in_root->left),
                           height(in_root->right));

    // Encuentra el balance, y si no es adecuado, lo balancea, retorna el puntero a la raiz
    int balance = balanceAVL(in_root);


    // Left Left Case
    if (balance > 1 && num < in_root->left->num)
        return rightRotate(in_root, new_root);

    // Right Right Case
    if (balance < -1 && num > in_root->right->num)
        return leftRotate(in_root, new_root);

    // Left Right Case
    if (balance > 1 && num > in_root->left->num)
    {
        error_code = leftRotate(in_root->left, &in_root->left);
        return rightRotate(in_root, new_root);
    }

    // Right Left Case
    if (balance < -1 && num < in_root->right->num)
    {
        error_code = rightRotate(in_root->right, &in_root->right);
        return leftRotate(in_root, new_root);
    }

    return error_code;
}


int avl_print(Node *root)
{
    if(root != NULL)
    {
        cout << root->num << " ";
        avl_print(root->left);
        avl_print(root->right);
    }
    return 0;
}
