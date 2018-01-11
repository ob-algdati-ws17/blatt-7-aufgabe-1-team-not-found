//
// Created by Robert on 08.01.2018.
//

#include "testAVL.h"

using namespace std;

TEST(AVLTest, EmptyTest) {
    auto tree = new AVLTree();
    EXPECT_TRUE(tree != nullptr);
    EXPECT_TRUE(tree->isEmpty());
    EXPECT_FALSE(tree->search(1));
    delete tree;
}

TEST(AVLTestInsert, OneElement) {
    auto tree = new AVLTree();
    tree->insert(4);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 1);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestInsert, TwoElements_left) {
    auto tree = new AVLTree();
    tree->insert(4);
    tree->insert(3);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 2);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestInsert, TwoElements_right) {
    auto tree = new AVLTree();
    tree->insert(4);
    tree->insert(5);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 2);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestInsert, third_element_left) {
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

TEST(AVLTestInsert, third_element_right) {
    auto tree = new AVLTree();
    tree->insert(4);
    tree->insert(3);
    tree->insert(5);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 2);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestUpinNoRotation, vather1_leftGrew_simple) {
    auto tree = new AVLTree();
    tree->insert(5);
    tree->insert(3);
    tree->insert(9);
    tree->insert(11);
    tree->insert(1);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 3);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestUpinNoRotation, vatherPlus1_leftGrew_complex) {
    auto tree = new AVLTree();
    tree->insert(5);
    tree->insert(3);
    tree->insert(9);
    tree->insert(2);
    tree->insert(7);
    tree->insert(4);
    tree->insert(11);
    tree->insert(6);
    tree->insert(7);
    tree->insert(10);
    tree->insert(12);
    tree->insert(1);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 4);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestUpinNoRotation, vatherMinus1_rightGrew_simple) {
    auto tree = new AVLTree();
    tree->insert(8);
    tree->insert(4);
    tree->insert(10);
    tree->insert(1);
    tree->insert(11);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 3);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestUpinNoRotation, vatherMinus1_rightGrew_complex) {
    auto tree = new AVLTree();
    tree->insert(8);
    tree->insert(4);
    tree->insert(10);
    tree->insert(2);
    tree->insert(6);
    tree->insert(9);
    tree->insert(11);
    tree->insert(1);
    tree->insert(3);
    tree->insert(5);
    tree->insert(7);
    tree->insert(12);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 4);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}



TEST(AVLTestUpinSimpleRotation, RotateLeft_simple) {
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

TEST(AVLTestUpinSimpleRotation, RotateLeft_belowRoot) {
    auto tree = new AVLTree();
    tree->insert(2);
    tree->insert(1);
    tree->insert(3);
    tree->insert(4);
    tree->insert(5);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 3);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestUpinSimpleRotation, RotateLeft_complex) {
    auto tree = new AVLTree();
    tree->insert(4);
    tree->insert(2);
    tree->insert(8);
    tree->insert(1);
    tree->insert(3);
    tree->insert(6);
    tree->insert(10);
    tree->insert(5);
    tree->insert(7);
    tree->insert(9);
    tree->insert(11);
    tree->insert(12);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 4);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestUpinSimpleRotation, RotateRight_simple) {
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

TEST(AVLTestUpinSimpleRotation, RotateRight_belowRoot) {
    auto tree = new AVLTree();
    tree->insert(4);
    tree->insert(3);
    tree->insert(5);
    tree->insert(2);
    tree->insert(1);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 3);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestUpinSimpleRotation, RotateRight_complex) {
    auto tree = new AVLTree();
    tree->insert(9);
    tree->insert(5);
    tree->insert(11);
    tree->insert(3);
    tree->insert(7);
    tree->insert(10);
    tree->insert(12);
    tree->insert(2);
    tree->insert(4);
    tree->insert(6);
    tree->insert(8);
    tree->insert(1);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 4);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestUpinDoubleRotation, Left_Right_Simple) {
    auto tree = new AVLTree();
    tree->insert(3);
    tree->insert(1);
    tree->insert(2);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 2);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}
TEST(AVLTestUpinDoubleRotation, Left_Right_belowRoot) {
    auto tree = new AVLTree();
    tree->insert(4);
    tree->insert(3);
    tree->insert(6);
    tree->insert(1);
    tree->insert(5);
    tree->insert(7);
    tree->insert(2);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 3);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}
TEST(AVLTestUpinDoubleRotation, Left_Right_complex_belowRoot) {
    auto tree = new AVLTree();
    tree->insert(13);
    tree->insert(9);
    tree->insert(17);
    tree->insert(4);
    tree->insert(11);
    tree->insert(15);
    tree->insert(19);
    tree->insert(2);
    tree->insert(6);
    tree->insert(10);
    tree->insert(12);
    tree->insert(14);
    tree->insert(16);
    tree->insert(18);
    tree->insert(20);
    tree->insert(1);
    tree->insert(3);
    tree->insert(5);
    tree->insert(7);
    tree->insert(8);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 5);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestUpinDoubleRotation, Left_Right_complex) {
    auto tree = new AVLTree();
    tree->insert(9);
    tree->insert(4);
    tree->insert(11);
    tree->insert(2);
    tree->insert(6);
    tree->insert(10);
    tree->insert(12);
    tree->insert(1);
    tree->insert(3);
    tree->insert(5);
    tree->insert(7);
    tree->insert(8);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 4);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}


TEST(AVLTestUpinDoubleRotation, Right_Left_Simple) {
    auto tree = new AVLTree();
    tree->insert(1);
    tree->insert(3);
    tree->insert(2);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 2);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}
TEST(AVLTestUpinDoubleRotation, Right_Left_belowRoot) {
    auto tree = new AVLTree();
    tree->insert(4);
    tree->insert(2);
    tree->insert(5);
    tree->insert(1);
    tree->insert(3);
    tree->insert(7);
    tree->insert(6);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 3);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}
TEST(AVLTestUpinDoubleRotation, Right_Left_complex) {
    auto tree = new AVLTree();
    tree->insert(4);
    tree->insert(2);
    tree->insert(9);
    tree->insert(1);
    tree->insert(3);
    tree->insert(7);
    tree->insert(11);
    tree->insert(6);
    tree->insert(8);
    tree->insert(10);
    tree->insert(12);
    tree->insert(5);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 4);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestUpinDoubleRotation, Right_Left_complex_belowRoot) {
    auto tree = new AVLTree();
    tree->insert(8);
    tree->insert(4);
    tree->insert(12);
    tree->insert(2);
    tree->insert(6);
    tree->insert(10);
    tree->insert(17);
    tree->insert(1);
    tree->insert(3);
    tree->insert(5);
    tree->insert(7);
    tree->insert(9);
    tree->insert(11);
    tree->insert(15);
    tree->insert(19);
    tree->insert(13);
    tree->insert(16);
    tree->insert(18);
    tree->insert(20);
    tree->insert(14);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 5);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

