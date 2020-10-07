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

    FILE* archivo;
    archivo= fopen(
        "/home/mikolen/laboDeProgra/AVL-Tree/doc/avl_node_add.txt",
        "w");

    for (int i = 0; i < 100; i++)
    {

        int length = 100+rand()%(10001-100);
        Node* root = NULL;
        int status = 0;
        unsigned t0, t1;

        int j = 0;
        while (j < length)
        {
            float num = rand() % (2*length);

            if (j == 0)
            {
                float seed[] = {num};
                avl_create(1, seed, &root);
                j++;
            }

        int status = avl_node_add(root, num, &root);

            if ( status == 0)
            {
                j++;
            }       
        }

        t0=clock();

        do
        {
            float num = rand() % (2*length);
            status = avl_node_add(root, num, &root);

        } while (status != 0);
            
        t1 = clock();

    
        double time = (double(t1-t0)/CLOCKS_PER_SEC);

        cout << "Tamaño actual de la estructura: " << length << endl;
        cout << "Execution Time: " << time << endl;

        fprintf(archivo, "%d,", length);
        fprintf(archivo, "%f\n", time);
    
    }
    fclose(archivo);
}
