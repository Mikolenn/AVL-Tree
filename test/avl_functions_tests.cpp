#include <functions.h>
#include <gtest/gtest.h>
#include <time.h>
#include<iostream>
#include<algorithm>

TEST(avl_create, positive){

    int status = 0;

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

    Node *root = NULL;
    float arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (int)sizeof(arr)/sizeof(float);

    status = avl_create(size, arr, &root);

    float num = 11;
    status = avl_node_add(root, num, &root);

    avl_print(root);
    cout<<endl;
    
    EXPECT_EQ(status, 0);
}

TEST(avl_node_add, negative){

    int status = 0;

    Node *root = NULL;
    float arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (int)sizeof(arr)/sizeof(float);

    status = avl_create(size, arr, &root);

    float num = 3;
    status = avl_node_add(root, num, &root);

    EXPECT_EQ(status, -1);
}

// Test para la funcion remove
TEST(avl_node_remove, positive){

    int status = 0;

    Node *root = NULL;
    float arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (int)sizeof(arr)/sizeof(float);

    status = avl_create(size, arr, &root);

    status = avl_node_remove(root, 3, &root);

    avl_print(root);
    cout<<endl;

    EXPECT_EQ(status, 0);
}
// esta está teniendo problemas por lo mismo que
// el otro negative que se pierde el valor del return
TEST(avl_node_remove, negative){

    int status = 0;

    Node *root = NULL;
    float arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (int)sizeof(arr)/sizeof(float);

    status = avl_create(size, arr, &root);

    float num = 15 ;
    status = avl_node_remove(root, num, &root);

    avl_print(root);
    cout<<endl;

    EXPECT_EQ(status, -4);
}


// Test para el search
TEST(avl_search, positive){

    int status = 0;

    Node *root = NULL;
    float arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (int)sizeof(arr)/sizeof(float);
    status = avl_create(size, arr, &root);

    status = avl_search(root, 5, &root);

    avl_print(root);
    cout<<endl;

    EXPECT_EQ(status, 0);
}

TEST(avl_search, negative){

    int status = 0;

    Node *root = NULL;
    float arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (int)sizeof(arr)/sizeof(float);
    status = avl_create(size, arr, &root);

    status = avl_search(root, 15, &root);

    avl_print(root);
    cout<<endl;

    EXPECT_EQ(status, -4);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}