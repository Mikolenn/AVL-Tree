
#include "functions.h"
#include<iostream>
#include<algorithm>
using namespace std;



int main()
{
Node *root = NULL;


    root = insert(root, 10);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, -4);
    root = insert(root, -5);
    root = insert(root,  20);
    root = insert(root,  -6);


    printAVL(root);

    cout<<endl;






    return 0;
}
