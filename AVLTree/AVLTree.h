//
// Created by Robert on 08.01.2018.
//

#ifndef BLATT_7_AUFGABE_1_TEAM_NOT_FOUND_AVLTREE_H
#define BLATT_7_AUFGABE_1_TEAM_NOT_FOUND_AVLTREE_H



#include <iostream>
#include <vector>

using namespace std;

class AVLTree{
private:
    struct Node{
        //attributes.
        int balance = 0;
        const int key;
        Node *left = nullptr;
        Node *right = nullptr;
        Node *prev = nullptr;

        //Konstruktoren
        Node(int);
        Node(int, Node *prev);
        Node(int, Node *prev, Node *left, Node *right);
        ~Node();
        //Methoden
        bool search(int);
        void rotateLeft();
        void rotateRight();
        void rotateLeftRight();
        void rotateRightLeft();
        void upin();
        void upout();
        bool insert(int);
        bool remove(int);

    };
    Node *root = nullptr;

public:
    ~AVLTree();
    bool search(int);
    void insert(int);
    void remove(int);
    bool isEmpty();
};

#endif //BLATT_7_AUFGABE_1_TEAM_NOT_FOUND_AVLTREE_H