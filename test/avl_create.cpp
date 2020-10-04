#include "functions.h"
#include "gtest/gtest.h"

TEST(avlcreate, positive){

    int status = 0;

    Node* root=NULL;
    float arr[]= {1,2,3,4,5,6};

    status = avl_create(arr, &root);

    EXPECT_EQ(status, 0);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}