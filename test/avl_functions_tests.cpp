#include <functions.h>
#include <gtest/gtest.h>
#include <time.h>

TEST(avl_create, positive){

    int status = 0;

    Node* root=NULL;
    float arr[]= {1,2,3,4,5,6};

    status = avl_create(arr, &root);

    EXPECT_EQ(status, 0);
}

TEST(avl_node_add, positive){

    int status = 0;

    Node* root=NULL;
    float arr[]= {1,2,3,4,5,6};

    status = avl_create(arr, &root);

    float num = 7;
    status = avl_node_add(root, num, &root);

    avl_print(root);
    cout<<endl;
    
    EXPECT_EQ(status, 0);
}

TEST(avl_node_add, negative){

    int status = 0;

    Node* root=NULL;
    float arr[]= {1,2,3,4,5,6};

    status = avl_create(arr, &root);

    float num = 3;
    status = avl_node_add(root, num, &root);

    EXPECT_EQ(status, -1);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}