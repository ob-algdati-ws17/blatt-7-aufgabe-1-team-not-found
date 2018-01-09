#include "AVLTree.h"

// Konstruktoren:

AVLTree::Node::Node(int key) : key(key) {}

AVLTree::Node::Node(int key, Node *prev) : key(key),prev(prev) {}

AVLTree::Node::Node(int key, Node *prev, Node *left, Node *right) : key(key),prev(prev),left(left),right(right) {}

// Destruktoren:
AVLTree::Node::~Node(){
    delete left;
    delete right;
}

AVLTree::~AVLTree() {
    delete root;
}

// Tree
// insert
bool AVLTree::insert(int key) {
    bool success = false;
    if(root == nullptr){
        root = new AVLTree::Node(key);
        return true;
    } else{
        success = root -> insert(key);
        if(root->prev != nullptr){
            root = root->prev;
        }
        return success;
    }
}

// search

bool AVLTree::search(int key) {
    if(root == nullptr){
        return false;
    }else{
        return root -> search(key);
    }
}

// remove

bool AVLTree::remove(int key) {
    bool success = false;
    if(search(key)){
        success = root->remove(key);
    }
    return success;
}

// Node

// rotations
void AVLTree::Node::rotateLeft() {}
void AVLTree::Node::rotateRight() {}
void AVLTree::Node::rotateLeftRight() {}
void AVLTree::Node::rotateRightLeft() {}
// balancing
void AVLTree::Node::upin() {}
void AVLTree::Node::upout() {}
// insert
bool AVLTree::Node::insert(int key) {}
// search
bool AVLTree::Node::search(int key) {}
// remove
bool AVLTree::Node::remove(int key) {}