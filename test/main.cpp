
#include "functions.h"
#include<iostream>
#include<algorithm>
using namespace std;



int main()
{
Node *root = NULL;

int h= 0;


    h = insert(root, 10, &root);
    h = insert(root, 4, &root);
    h = insert(root, 3, &root);
    h = insert(root, 2, &root);
    h = insert(root, 1, &root);
    h = insert(root, 7, &root);
    h = insert(root, 20, &root);
    h = insert(root,  24, &root);
    h = insert(root,  6, &root);


    printAVL(root);

    cout<<endl;






    return 0;
}
