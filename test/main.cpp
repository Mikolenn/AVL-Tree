
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

  float arr[]={10.5,4,3,2,1,7,20,245,6};
  create(arr,&root);
  printAVL(root);
  cout<<endl;

  minGet(root, &min);
  maxGet(root, &max);
  cout<<"El menor nodo es "<<min->num<<endl;
  cout<<"El mayor nodo es "<<max->num<<endl;

  float num=20;


  cout<<"Buscamos el num: "<<num<<endl;
  cout<< search(root, num, &searched)<<endl;

for (int i = 0; i < sizeof(arr)/sizeof(float); i++)
{
  cout<<deleteNode(root,arr[i],&root)<<endl;
  printAVL(root);
  cout<<endl;
}


    return 0;
}
