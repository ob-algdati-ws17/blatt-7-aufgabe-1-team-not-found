//
// Created by Robert on 08.01.2018.
//

#include "testAVL.h"

using namespace std;

TEST(AVLTest, 3Elements_test) {
    auto tree = new AVLTree();
    tree->insert(2);
    tree->insert(4);
    tree->insert(3);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 2);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTest, EmptyTest) {
    auto tree = new AVLTree();
    EXPECT_TRUE(tree != nullptr);
    EXPECT_TRUE(tree->isEmpty());
    EXPECT_FALSE(tree->search(1));
    delete tree;
}

TEST(AVLTest, OneElement) {
    auto tree = new AVLTree();
    tree->insert(4);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 1);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTest, TwoElements_left) {
    auto tree = new AVLTree();
    tree->insert(4);
    tree->insert(3);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 2);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTest, TwoElements_right) {
    auto tree = new AVLTree();
    tree->insert(4);
    tree->insert(5);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 2);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTest, 3Elements_balanced) {
    auto tree = new AVLTree();
    tree->insert(4);
    tree->insert(5);
    tree->insert(3);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 2);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}
TEST(AVLTest, 3Elements_list_left) {
    auto tree = new AVLTree();
    tree->insert(3);
    tree->insert(2);
    tree->insert(1);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 2);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTest, 3Elements_list_right) {
    auto tree = new AVLTree();
    tree->insert(1);
    tree->insert(2);
    tree->insert(3);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 2);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTest, 6Elements_singleRotationRight) {
    auto tree = new AVLTree();
    tree->insert(8);
    tree->insert(4);
    tree->insert(12);
    tree->insert(2);
    tree->insert(6);
    tree->insert(1);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 3);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}
TEST(AVLTest, 6Elements_singleRotationLeft) {
    auto tree = new AVLTree();
    tree->insert(2);
    tree->insert(1);
    tree->insert(6);
    tree->insert(4);
    tree->insert(8);
    tree->insert(12);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 3);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTest, rotateLeftRight) {
    auto tree = new AVLTree();
    tree->insert(10);
    tree->insert(5);
    tree->insert(20);
    tree->insert(2);
    tree->insert(7);
    tree->insert(18);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 3);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTest, rotateRightLeft) {
    auto tree = new AVLTree();
    tree->insert(2);
    tree->insert(1);
    tree->insert(6);
    tree->insert(4);
    tree->insert(8);
    tree->insert(12);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 3);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}
