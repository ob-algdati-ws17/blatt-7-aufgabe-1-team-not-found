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
        int key;
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
        void upin(Node * calling);
        void upout(); // 0 = called by Left, 1 = called by right
        bool insert(int);

        bool remove(int);
        bool remove0Child();
        bool remove1Child();
        bool remove2Child();
        vector<int> *preorder() const;  // Hauptreihenfolge (© Prof. Dr. Oliver Braun)
        vector<int> *inorder() const;   // Symmetrische Reihenfolge (© Prof. Dr. Oliver Braun)
        vector<int> *postorder() const; // Nebenreihenfolge (© Prof. Dr. Oliver Braun)

    };
    Node *root = nullptr;

public:
    ~AVLTree();
    bool search(int);
    bool insert(int);
    bool remove(int);
    // test methods (kriege das graphische zeug nicht zum laufen...):
    bool isEmpty();
    bool isSorted();
    bool isSorted(Node * current);
    int getHeight();
    int getHeight(Node * current);
    bool isBalanced();
    bool isBalanced(Node * current);
    vector<int> *preorder() const;      // Hauptreihenfolge (© Prof. Dr. Oliver Braun)
    vector<int> *inorder() const;       // Symmetrische Reihenfolge (© Prof. Dr. Oliver Braun)
    vector<int> *postorder() const; // Nebenreihenfolge (© Prof. Dr. Oliver Braun)

    friend std::ostream &operator<<(std::ostream &, const AVLTree &);
};

#endif //BLATT_7_AUFGABE_1_TEAM_NOT_FOUND_AVLTREE_H