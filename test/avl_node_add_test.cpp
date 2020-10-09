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
        // Se sobre escribe en length un valor aleatorio entre 100 y 100000
        length = 100+rand() % (100001-100);

        root = NULL;

        // Bucle para crear el árbol
        int j = 0;
        while (j < length)
        {
            num = rand() % (2*length);

            // En caso de que sea la primer iteración
            if (j == 0)
            {
                float seed[] = {num};
                avl_create(1, seed, &root);
                j++;
            }
            // Para todos las demás iteraciones
            status = avl_node_add(root, num, &root);

            // Si se logra agregar el valor al árbol (no es un valor repetido)
            if (status == 0)
            {
                j++;
            }
        }

        // Numero aleatorio en el mismo rango pero no entero. Asegura que la
        // inserción no falle, porque el número es diferente a los otros 
        num = (rand() % (2*length)) + 0.1;
        // Se toma el tiempo antes de llamar a la función
        t0 = clock();

            status = avl_node_add(root, num, &root);
        // Se toma el tiempo después de llamar a la función
        t1 = clock();
        // Se obtiene el tiempo en segundos
        time = (double(t1-t0)/CLOCKS_PER_SEC);

        fprintf(archivo, "%d,", length);
        fprintf(archivo, "%f\n", time);

    }

    fclose(archivo);
}
