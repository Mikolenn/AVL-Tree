
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

  cout<<deleteNode(root,245,&root)<<endl;
  printAVL(root);
  cout<<endl;

  cout<<deleteNode(root,4,&root)<<endl;
  printAVL(root);
  cout<<endl;

  cout<<deleteNode(root,2,&root)<<endl;
  printAVL(root);
  cout<<endl;

  cout<<deleteNode(root,20,&root)<<endl;
  printAVL(root);
  cout<<endl;



    return 0;
}
