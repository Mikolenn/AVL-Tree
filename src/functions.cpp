#include "functions.h"

int avl_create(int size, float* list, Node ** new_root){

    int error_code = 0;

    for (int i = 0; i < size; i++) {
        error_code = avl_node_add(*new_root, list[i], new_root);
    }

    return error_code;
}


int avl_node_add(Node* in_root, float num, Node** new_root)
{

    int error_code=0;
    Node* nuevo = new Node();
    // Caso en que el nodo este vacio
    if (in_root == NULL){

        nuevo->num = num;
        nuevo->left = NULL;
        nuevo->right = NULL;
        nuevo->height = 1;
        *new_root=nuevo;

        return error_code;
    }
    // Este bloque hace recursión de la función para buscar la posición
    // que le corresponde al nuevo nodo.
    if (num > in_root->num)
    {
        error_code = avl_node_add(in_root->right, num, &in_root->right);
    }
    else if (num < in_root->num)
    {
        error_code = avl_node_add(in_root->left, num, &in_root->left);
    }
    else { // No se pueden numeros iguales

        return -1;
    }

    // Actualizamos las alturas

    in_root->height = 1 + max(height(in_root->left),
                           height(in_root->right));

    // Encuentra el balance, y si no es adecuado, lo balancea,
    // retorna el puntero a la raiz
    int balance = balanceAVL(in_root);


    // Caso Izquierda-Izquierda
    if (balance > 1 && num < in_root->left->num)
        return rightRotate(in_root, new_root);

    // Caso Derecha-Derecha
    if (balance < -1 && num > in_root->right->num)
        return leftRotate(in_root, new_root);

    // Caso Izquierda-Derecha
    if (balance > 1 && num > in_root->left->num)
    {
        error_code = leftRotate(in_root->left, &in_root->left);
        return rightRotate(in_root, new_root);
    }

    // Caso Derecha-Izquierda
    if (balance < -1 && num < in_root->right->num)
    {
        error_code = rightRotate(in_root->right, &in_root->right);
        return leftRotate(in_root, new_root);
    }

    *new_root = in_root;
    return error_code;
}


int avl_node_remove(Node* in_root, float num, Node** new_root)
{
    Node* temp = new Node();
    int error_code=0;

    if (in_root == NULL){
        *new_root=in_root;
        return -4;
    }

    // Si el valor buscado es
    //menor, se va a la izquierda
    if ( num < in_root->num )

        error_code = avl_node_remove(in_root->left, num, &(in_root->left));

    // Si el valor buscado es
    //mayor, se va a la derecha
    else if( num > in_root->num )

        error_code = avl_node_remove(in_root->right, num, &(in_root->right));

    else
    {
        // Si el nodo no tiene hijos, se deshace ese nodo
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
        {   // Se intercambian los valores de num entre nodos

            error_code = avl_min_get(in_root->right, &temp);


            in_root->num = temp->num;

            error_code = avl_node_remove(in_root->right, temp->num, &(in_root->right));

        }
    }

    if (in_root == NULL)
    {
        *new_root=in_root;
        return 0;
    }


    in_root->height = 1 + max(height(in_root->left),
                           height(in_root->right));

    // Mismo bloque para revisar el balance que en avl_node_add
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
    return error_code;
}


int avl_search(Node * root, float num_searched, Node ** nodo){
    // Evalúa el nodo que se quiere buscar

    if (root == NULL) {
        *nodo = NULL;
        return -4;
    } // Cuando encuentra el nodo
    else if (root->num == num_searched){

        *nodo=root;
        return 0;
    } // Busca el nodo en el arbol
    else if (num_searched > root->num) {

        return avl_search(root->right, num_searched, nodo);
    }
    else if (num_searched < root->num){

        return avl_search(root->left, num_searched, nodo);
    }
    // Si no encuentra el nodo
    return -1;
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

    // Procedimiento para rotación derecha
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

    // Procedimiento para rotación izquierda
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
