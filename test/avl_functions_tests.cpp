#include <functions.h>
#include <gtest/gtest.h>
#include <time.h>
#include<iostream>
#include<algorithm>



TEST(avl_create, positive){

    int status = 0;
    // Valores ingresados para la prueba
    Node *root = NULL;
    float arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (int)sizeof(arr)/sizeof(float);

    status = avl_create(size, arr, &root);

    avl_print(root);
    cout<<endl;

    EXPECT_EQ(status, 0);
}


TEST(avl_node_add, positive){

    int status = 0;
    // Valores ingresados para la prueba
    Node *root = NULL;
    float arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (int)sizeof(arr)/sizeof(float);

    status = avl_create(size, arr, &root);
    // Valor por agregar nuevo
    float num = 11;
    status = avl_node_add(root, num, &root);

    avl_print(root);
    cout<<endl;

    EXPECT_EQ(status, 0);
}


TEST(avl_node_add, negative){

    int status = 0;
    // Valores ingresados para la prueba
    Node *root = NULL;
    float arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (int)sizeof(arr)/sizeof(float);

    status = avl_create(size, arr, &root);
    // Valor por agregar repetido
    float num = 3;
    status = avl_node_add(root, num, &root);

    avl_print(root);
    cout<<endl;

    EXPECT_EQ(status, -1);
}


TEST(avl_node_remove, positive){

    int status = 0;
    // Valores ingresados para la prueba
    Node *root = NULL;
    float arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (int)sizeof(arr)/sizeof(float);

    status = avl_create(size, arr, &root);
    // Valor por remover que existe dentro del árbol
    float num = 5;
    status = avl_node_remove(root, num, &root);

    avl_print(root);
    cout<<endl;

    EXPECT_EQ(status, 0);
}


TEST(avl_node_remove, negative){

    int status = 0;
    // Valores ingresados para la prueba
    Node *root = NULL;
    float arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (int)sizeof(arr)/sizeof(float);

    status = avl_create(size, arr, &root);
    // Valor por remover que no existe dentro del árbol
    float num = 15;
    status = avl_node_remove(root, num, &root);

    avl_print(root);
    cout<<endl;

    EXPECT_EQ(status, -4);
}


TEST(avl_search, positive){

    int status = 0;
    // Valores ingresados para la prueba
    Node *root = NULL;
    float arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (int)sizeof(arr)/sizeof(float);
    status = avl_create(size, arr, &root);
    // Valor por buscar, existente dentro del árbol
    float num = 5;
    status = avl_search(root, num, &root);

    EXPECT_EQ(status, 0);
}


TEST(avl_search, negative){

    int status = 0;
    // Valores ingresados para la prueba
    Node *root = NULL;
    float arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (int)sizeof(arr)/sizeof(float);
    status = avl_create(size, arr, &root);
    // Valor por buscar inexistente dentro del árbol
    float num = 15;
    status = avl_search(root, num, &root);

    EXPECT_EQ(status, -4);
}


TEST(avl_max_get, positive){

    int status = 0;

    Node *root = NULL;
    Node *max_node = NULL;
    // Valores ingresados para la prueba
    float arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (int)sizeof(arr)/sizeof(float);
    status = avl_create(size, arr, &root);

    avl_max_get(root, &max_node);

    EXPECT_EQ(status, 0);
}


TEST(avl_min_get, positive){

    int status = 0;

    Node *root = NULL;
    Node *min_node = NULL;
    // Valores ingresados para la prueba
    float arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (int)sizeof(arr)/sizeof(float);
    status = avl_create(size, arr, &root);

    avl_min_get(root, &min_node);

    EXPECT_EQ(status, 0);
}


TEST(rightRotate, positive){

    int status = 0;

    Node *root = NULL;
    // Valores ingresados para la prueba
    float arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (int)sizeof(arr)/sizeof(float);
    status = avl_create(size, arr, &root);

    rightRotate(root, &root);

    avl_print(root);
    cout<<endl;

    EXPECT_EQ(status, 0);
}


TEST(leftRotate, positive){

    int status = 0;

    Node *root = NULL;
    // Valores ingresados para la prueba
    float arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (int)sizeof(arr)/sizeof(float);
    status = avl_create(size, arr, &root);

    leftRotate(root, &root);

    avl_print(root);
    cout<<endl;

    EXPECT_EQ(status, 0);
}


TEST(avl_print, positive){

    int status = 0;

    Node *root = NULL;
    // Valores ingresados para la prueba
    float arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (int)sizeof(arr)/sizeof(float);
    status = avl_create(size, arr, &root);

    avl_print(root);
    cout<<endl;

    EXPECT_EQ(status, 0);
}

// Funcion main que ejecuta todos los TEST
int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
