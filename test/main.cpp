#include "functions.h"
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    Node *root = NULL;
    Node *min= NULL;
    Node *max= NULL;
    Node *searched= NULL;

    float arr[]={1,2,3,4,5,6,7,8,9,10};
    avl_create(arr,&root);
    avl_print(root);
    cout<<endl;

    for (int i = 0; i < 5; i++)
    {
        avl_node_add(root, 10+i, &root);
    }
    

    avl_min_get(root, &min);
    avl_max_get(root, &max);
    cout<<"El menor nodo es "<<min->num<<endl;
    cout<<"El mayor nodo es "<<max->num<<endl;

    float num=20;

    cout<<"Buscamos el num: "<<num<<endl;
    cout<< avl_search(root, num, &searched)<<endl;

    cout<<"Borramos el num: "<<avl_node_remove(root,14,&root)<<endl;
    avl_print(root);
    cout<<endl;

// for (int i = 0; i < (int)(sizeof(arr)/sizeof(float)); i++)
// {
//     cout<<avl_node_remove(root,arr[i],&root)<<endl;
//     avl_print(root);
//     cout<<endl;
// }

    return 0;
}