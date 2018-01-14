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
// -----------------------------------------------------------------------------------------------------------------------------------------------
//   remove tests
//  -----------------------------------------------------------------------------------------------------------------------------------------------

TEST(AVLTestRemoveRoot, OneElement) {
    auto tree = new AVLTree();
    tree->insert(4);
    tree->remove(4);
    EXPECT_TRUE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 0);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemoveRoot, TwoElements_left) {
    auto tree = new AVLTree();
    tree->insert(4);
    tree->insert(3);
    tree->remove(4);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 1);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemoveRoot, TwoElements_right) {
    auto tree = new AVLTree();
    tree->insert(3);
    tree->insert(4);
    tree->remove(3);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 1);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemoveRoot, TwoElements_both) {
    auto tree = new AVLTree();
    tree->insert(3);
    tree->insert(4);
    tree->insert(2);
    tree->remove(3);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 2);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemoveRootWithRotation, rotateLeft) {
    auto tree = new AVLTree();
    tree->insert(3);
    tree->insert(2);
    tree->insert(4);
    tree->insert(1);
    tree->remove(3);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 2);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemoveRootWithRotation, rotateRight) {
    auto tree = new AVLTree();
    tree->insert(2);
    tree->insert(1);
    tree->insert(3);
    tree->insert(4);
    tree->remove(2);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 2);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemoveRootWithRotation, rotateLeftRight) {
    auto tree = new AVLTree();
    tree->insert(3);
    tree->insert(1);
    tree->insert(4);
    tree->insert(2);
    tree->remove(3);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 2);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemoveRootWithRotation, rotateRightLeft) {
    auto tree = new AVLTree();
    tree->insert(2);
    tree->insert(1);
    tree->insert(4);
    tree->insert(3);
    tree->remove(2);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 2);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemove_Without_Rotation, NoChildren_hasBrother) {
    auto tree = new AVLTree();
    tree->insert(2);
    tree->insert(1);
    tree->insert(3);
    tree->remove(1);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 2);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemove_Without_Rotation, NoChildren_NoBrother) {
    auto tree = new AVLTree();
    tree->insert(2);
    tree->insert(1);
    tree->insert(3);
    tree->insert(4);
    tree->remove(4);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 2);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemove_Without_Rotation, OneChild_left) {
    auto tree = new AVLTree();
    tree->insert(3);
    tree->insert(2);
    tree->insert(4);
    tree->insert(1);
    tree->remove(2);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 2);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemove_Without_Rotation, OneChild_right) {
    auto tree = new AVLTree();
    tree->insert(4);
    tree->insert(2);
    tree->insert(5);
    tree->insert(1);
    tree->insert(3);
    tree->insert(6);
    tree->remove(5);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 3);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemove_Without_Rotation, TwoChildren_small) {
    auto tree = new AVLTree();
    tree->insert(4);
    tree->insert(2);
    tree->insert(5);
    tree->insert(1);
    tree->insert(3);
    tree->remove(2);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 3);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemove_Without_Rotation, TwoChildren) {
    auto tree = new AVLTree();
    tree->insert(9);
    tree->insert(4);
    tree->insert(11);
    tree->insert(2);
    tree->insert(7);
    tree->insert(10);
    tree->insert(12);
    tree->insert(1);
    tree->insert(3);
    tree->insert(5);
    tree->insert(8);
    tree->insert(13);
    tree->insert(6);
    tree->remove(4);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 4);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemove_With_Rotation, NoChildren_RotateLeft) {
    auto tree = new AVLTree();
    tree->insert(3);
    tree->insert(2);
    tree->insert(5);
    tree->insert(1);
    tree->insert(4);
    tree->insert(6);
    tree->insert(7);
    tree->remove(1);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 3);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemove_With_Rotation, NoChildren_RotateRight) {
    auto tree = new AVLTree();
    tree->insert(5);
    tree->insert(3);
    tree->insert(6);
    tree->insert(2);
    tree->insert(4);
    tree->insert(7);
    tree->insert(1);
    tree->remove(7);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 3);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemove_With_Rotation, NoChildren_RotateRightLeft) {
    auto tree = new AVLTree();
    tree->insert(3);
    tree->insert(2);
    tree->insert(6);
    tree->insert(1);
    tree->insert(4);
    tree->insert(7);
    tree->insert(5);
    tree->remove(1);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 3);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemove_With_Rotation, NoChildren_RotateLeftRight) {
    auto tree = new AVLTree();
    tree->insert(5);
    tree->insert(2);
    tree->insert(6);
    tree->insert(1);
    tree->insert(4);
    tree->insert(7);
    tree->insert(3);
    tree->remove(7);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 3);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemove_With_Rotation, OneChild_RotateLeft) {
    auto tree = new AVLTree();
    tree->insert(3);
    tree->insert(2);
    tree->insert(5);
    tree->insert(1);
    tree->insert(4);
    tree->insert(6);
    tree->insert(7);
    tree->remove(2);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 3);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemove_With_Rotation,OneChild_RotateRight) {
    auto tree = new AVLTree();
    tree->insert(5);
    tree->insert(3);
    tree->insert(6);
    tree->insert(2);
    tree->insert(4);
    tree->insert(7);
    tree->insert(1);
    tree->remove(6);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 3);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemove_With_Rotation, OneChild_RotateRightLeft) {
    auto tree = new AVLTree();
    tree->insert(3);
    tree->insert(2);
    tree->insert(6);
    tree->insert(1);
    tree->insert(4);
    tree->insert(7);
    tree->insert(5);
    tree->remove(2);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 3);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemove_With_Rotation, OneChild_RotateLeftRight) {
    auto tree = new AVLTree();
    tree->insert(5);
    tree->insert(2);
    tree->insert(6);
    tree->insert(1);
    tree->insert(4);
    tree->insert(7);
    tree->insert(3);
    tree->remove(6);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_EQ(tree->getHeight(), 3);
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemove_With_Rotation, TwoChildren_RotateLeft) {
    auto tree = new AVLTree();
    tree->insert(5);
    tree->insert(2);
    tree->insert(8);
    tree->insert(1);
    tree->insert(4);
    tree->insert(7);
    tree->insert(10);
    tree->insert(3);
    tree->insert(6);
    tree->insert(9);
    tree->insert(11);
    tree->insert(12);
    tree->remove(2);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemove_With_Rotation, TwoChildren_RotateRight) {
    auto tree = new AVLTree();
    tree->insert(8);
    tree->insert(5);
    tree->insert(10);
    tree->insert(3);
    tree->insert(6);
    tree->insert(9);
    tree->insert(12);
    tree->insert(2);
    tree->insert(4);
    tree->insert(7);
    tree->insert(11);
    tree->insert(1);
    tree->remove(10);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemove_With_Rotation, TwoChildren_RotateLeftRight) {
    auto tree = new AVLTree();
    tree->insert(5);
    tree->insert(2);
    tree->insert(10);
    tree->insert(1);
    tree->insert(4);
    tree->insert(7);
    tree->insert(11);
    tree->insert(3);
    tree->insert(6);
    tree->insert(8);
    tree->insert(12);
    tree->insert(9);
    tree->remove(2);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRemove_With_Rotation, TwoChildren_RotateRightLeft) {
    auto tree = new AVLTree();
    tree->insert(8);
    tree->insert(3);
    tree->insert(10);
    tree->insert(2);
    tree->insert(6);
    tree->insert(9);
    tree->insert(12);
    tree->insert(1);
    tree->insert(4);
    tree->insert(7);
    tree->insert(11);
    tree->insert(5);
    tree->remove(10);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestRandom, 100Elements) {
    auto tree = new AVLTree();
    int i;
    for(i=0;i<100;i++){
        tree->insert(i);
    }
    tree->remove(5);
    tree->remove(73);
    tree->remove(6);
    tree->remove(24);
    tree->remove(87);
    tree->remove(50);
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}

TEST(AVLTestSearch, Search) {
    auto tree = new AVLTree();
    int i;
    for(i=0;i<100;i++){
        tree->insert(i);
    }
    for(i=0;i<100;i++){
        EXPECT_TRUE(tree->search(i));
    }
    tree->remove(5);
    tree->remove(73);
    tree->remove(6);
    tree->remove(24);
    tree->remove(87);
    tree->remove(50);
    EXPECT_FALSE(tree->search(5));
    EXPECT_FALSE(tree->search(73));
    EXPECT_FALSE(tree->search(6));
    EXPECT_FALSE(tree->search(24));
    EXPECT_FALSE(tree->search(87));
    EXPECT_FALSE(tree->search(50));
    EXPECT_FALSE(tree->isEmpty());
    EXPECT_TRUE(tree->isBalanced());
    EXPECT_TRUE(tree->isSorted());
    delete tree;
}
