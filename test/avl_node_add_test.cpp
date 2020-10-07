#include <functions.h>
#include <gtest/gtest.h>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));

    int length;
    float num = 0.0;
    int status = 0;
    unsigned t0, t1;
    double time;

    Node* root = new Node;

    FILE* archivo;

    //Colocar ruta absoluta donde se desea guardar el archivo
    archivo= fopen(
        "/home/mikolen/laboDeProgra/AVL-Tree/doc/avl_node_add.txt",
        "w");

    for (int i = 0; i < 100; i++)
    {

        length = 100+rand() % (100001-100);
        
        root = NULL;

        int j = 0;
        while (j < length)
        {
            num = rand() % (2*length);

            if (j == 0)
            {
                float seed[] = {num};
                avl_create(1, seed, &root);
                j++;
            }

        status = avl_node_add(root, num, &root);

            if (status == 0)
            {
                j++;
            }       
        }
        
        t0 = clock();

            status = avl_node_add(root, 210000, &root);
            
        t1 = clock();

    
        time = (double(t1-t0)/CLOCKS_PER_SEC);

        cout << "Tamaño actual de la estructura: " << length << endl;
        cout << "Execution Time: " << time << endl;
        cout << "Contador: " << i << endl;

        fprintf(archivo, "%d,", length);
        fprintf(archivo, "%f\n", time);
    
    }
    fclose(archivo);
}
