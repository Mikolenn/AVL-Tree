
#include "functions.h"
#include<iostream>
#include<algorithm>
using namespace std;



int main()
{
Node *root = NULL;
Node *min= NULL;
Node *max= NULL;




    insert(root, 10, &root);
    insert(root, 4, &root);
    insert(root, 3, &root);
    insert(root, 2, &root);
    insert(root, 1, &root);
    insert(root, 7, &root);
    // insert(root, -4, &root);
    insert(root, 20, &root);
    insert(root,  24, &root);
    insert(root,  6, &root);



    printAVL(root);

    cout<<endl;

    minGet(root, &min);
    maxGet(root, &max);
    cout<<"El menor nodo es "<<min->num<<endl;
    cout<<"El mayor nodo es "<<max->num<<endl;






    return 0;
}
