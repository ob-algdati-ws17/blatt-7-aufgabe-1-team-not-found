#include "AVLTree.h"
#include <iomanip>
#include <functional>

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
//----------------------------------------------------------------------------
// Tree
//----------------------------------------------------------------------------

// insert
bool AVLTree::insert(int key) {
    bool success = false;
    if(root == nullptr){
        root = new AVLTree::Node(key);
        return true;
    } else{
        if(!search(key)){
            success = root -> insert(key);
            if(root->prev != nullptr){
                root = root->prev;
            }
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

//stuff for testing only:

bool AVLTree::isEmpty() {
    return root == nullptr;
}

bool AVLTree::isSorted(){
    return isSorted(root);
}
bool AVLTree::isSorted(Node * current){
    if(current == nullptr){
        return true;
    } else{
        //wenn rechts vorhanden prüfe ob current > rechts --> return false.
        if(current->right != nullptr && current->key > current->right->key){
            return false;
        }
        //wenn links vorhanden prüfe ob current < links --> return false.
        if(current->left != nullptr && current->key < current->left->key){
            return false;
        }
        return (isSorted(current->left) && isSorted(current->right));
        //wenn beides kein problem ergab rufe isSorted auf beiden auf.
    }
}
int AVLTree::getHeight(){
    return getHeight(root);
}
int AVLTree::getHeight(Node * current){
    int left;
    int right;
    if(current == nullptr){
        return 0;
    }else{
        left = getHeight(current->left);
        right = getHeight(current->right);
        if(left>right){
            return left+1;
        }else{
            return right+1;
        }
    }
}
bool AVLTree::isBalanced(){
    return isBalanced(root);
}
bool AVLTree::isBalanced(Node * current){
    if(current == nullptr){
        return true;
    }else{
        int dif = getHeight(current->right)-getHeight(current->left);
        if(dif != current->balance ||  dif < -1 || dif > 1){
            return false;
        }else{
            return (isBalanced(current->left) && isBalanced(current->right));
        }
    }
}

/********************************************************************
 * Traversal
 *******************************************************************/
// © Prof. Dr. Oliver Braun
// The following code is extracted from the solution to the assignment Blatt 6
vector<int> *AVLTree::preorder() const {
    if (root == nullptr)
        return nullptr;
    return root->preorder();
}

// © Prof. Dr. Oliver Braun
// The following code is extracted from the solution to the assignment Blatt 6
vector<int> *AVLTree::Node::preorder() const {
    auto vec = new vector<int>();
    // Wurzel in vec
    vec->push_back(key);
    // linken Nachfolger in vec
    if (left != nullptr) {
        auto left_vec = left->preorder();
        vec->insert(vec->end(), left_vec->begin(), left_vec->end());
    }
    // rechten Nachfolger in vec
    if (right != nullptr) {
        auto right_vec = right->preorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }
    return vec;
}

// © Prof. Dr. Oliver Braun
// The following code is extracted from the solution to the assignment Blatt 6
vector<int> *AVLTree::inorder() const {
    if (root == nullptr)
        return nullptr;
    return root->inorder();
}

// © Prof. Dr. Oliver Braun
// The following code is extracted from the solution to the assignment Blatt 6
vector<int> *AVLTree::Node::inorder() const {
    auto vec = new vector<int>();
    // linken Nachfolger in vec
    if (left != nullptr) {
        auto left_vec = left->inorder();
        vec->insert(vec->end(), left_vec->begin(), left_vec->end());
    }
    // Wurzel in vec
    vec->push_back(key);
    // rechten Nachfolger in vec
    if (right != nullptr) {
        auto right_vec = right->inorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }
    return vec;
}

// © Prof. Dr. Oliver Braun
// The following code is extracted from the solution to the assignment Blatt 6
vector<int> *AVLTree::postorder() const {
    if (root == nullptr)
        return nullptr;
    return root->postorder();
}

// © Prof. Dr. Oliver Braun
// The following code is extracted from the solution to the assignment Blatt 6
vector<int> *AVLTree::Node::postorder() const {
    auto vec = new vector<int>();
    // linken Nachfolger in vec
    if (left != nullptr) {
        auto left_vec = left->postorder();
        vec->insert(vec->end(), left_vec->begin(), left_vec->end());
    }
    // rechten Nachfolger in vec
    if (right != nullptr) {
        auto right_vec = right->postorder();
        vec->insert(vec->end(), right_vec->begin(), right_vec->end());
    }
    // Wurzel in vec
    vec->push_back(key);
    return vec;
}
/********************************************************************
 * operator<<
 *******************************************************************/
// © Prof. Dr. Oliver Braun
// The following code is extracted from the solution to the assignment Blatt 6
std::ostream &operator<<(std::ostream &os, const AVLTree &tree) {
    function<void(std::ostream &, const int, const AVLTree::Node *, const string)> printToOs
            = [&](std::ostream &os, const int value, const AVLTree::Node *node, const string l) {

                static int nullcount = 0;

                if (node == nullptr) {
                    os << "    null" << nullcount << "[shape=point];" << endl;
                    os << "    " << value << " -> null" << nullcount
                       << " [label=\"" << l << "\"];" << endl;
                    nullcount++;
                } else {
                    os << "    " << value << " -> " << node->key
                       << " [label=\"" << l << "\"];" << endl;

                    printToOs(os, node->key, node->left, "l");
                    printToOs(os, node->key, node->right, "r");
                }
            };
    os << "digraph tree {" << endl;
    if (tree.root == nullptr) {
        os << "    null " << "[shape=point];" << endl;
    } else {
        printToOs(os, tree.root->key, tree.root->left, "l");
        printToOs(os, tree.root->key, tree.root->right, "r");
    }
    os << "}" << endl;
    return os;
}
// -------------------------------------------------------------------------
// Node
// -------------------------------------------------------------------------

// rotations
void AVLTree::Node::rotateLeft() {
    if(prev != nullptr){
        if(prev->left == this){ //ich bin linker nachfolger
            prev->left = right;
        }else{ // ich bin rechter nachfolger
            prev->right = right;
        }
    }
    Node * oldPrev = prev;
    prev = right;
    prev->prev = oldPrev;
    right = right->left;
    prev->left = this; // prev is now the old right one.
}
void AVLTree::Node::rotateRight() {
    if(prev != nullptr){
        if(prev->left == this){ //ich bin linker nachfolger
            prev->left = left;
        }else{ // ich bin rechter nachfolger
            prev->right = left;
        }
    }
    Node * oldPrev = prev;
    prev = left;
    prev->prev = oldPrev;
    left = left->right;
    prev->right = this; // prev is now the old left one.

}
void AVLTree::Node::rotateLeftRight() {
    left->rotateLeft();
    rotateRight();
}
void AVLTree::Node::rotateRightLeft() {
    right->rotateRight();
    rotateLeft();
}
// balancing
void AVLTree::Node::upin(Node * calling) {
    if(calling == left){
        switch(balance){
            case -1:
                if(left->balance == -1){
                    rotateRight();
                }else{
                    rotateLeftRight();
                }
                balance = 0;
                calling ->balance = 0;
                //if(prev != nullptr){
                //    prev->upin(this);
                //}
                break;
            case 0:
                balance = -1;
                if(prev != nullptr){
                    prev->upin(this);
                }
                break;
            case 1:
                balance = 0;
                break;
        }
    } else{ // calling must be right
        if(calling != right){
            cout<< "was neither left nor right!" << endl;
        }
        switch(balance){
            case 1:
                if(right->balance == 1){
                    rotateLeft();
                }else{
                    rotateRightLeft();
                }
                balance = 0;
                calling ->balance = 0;
                //if(prev != nullptr){
                 //   prev->upin(this);
                //}
                break;
            case 0:
                balance = 1;
                if(prev != nullptr){
                    prev->upin(this);
                }
                break;
            case -1:
                balance = 0;
                break;
        }
    }
}
void AVLTree::Node::upout() {}
// insert
bool AVLTree::Node::insert(int key) {
    if(key < this->key){
        if(left != nullptr){
            left->insert(key);
        }else{
            switch(balance){
                case 0: // beide kinder sind Blätter
                    left = new Node(key,this);
                    balance = -1;
                    if(prev != nullptr){
                        prev->upin(this);
                    }
                    return true;
                case 1: // rechtes Kind existiert, linkes ist Blatt.
                    left = new Node(key,this);
                    balance = 0;
                    return true;
                case -1: // linkes kind blatt und balance -1 widerspricht sich!
                    cout << "this case should nt exist!" << endl;
                    break;
            }
        }
    } else{
        if(right != nullptr){
            right->insert(key);
        }else{
            switch(balance){
                case 0:
                    right = new Node(key,this);
                    balance = 1;
                    if(prev != nullptr){
                        prev->upin(this);
                    }
                    return true;
                case -1:
                    right = new Node(key,this);
                    balance = 0;
                    return true;
                case 1:
                    cout << "this case should nt exist!" << endl;
                    break;
            }
        }
    }
    return false;
}
// search
bool AVLTree::Node::search(int key) {
    if(this->key == key){
        return true;
    }else{
        if(key < this->key){
            if(left != nullptr){
                return left->search(key);
            }
        } else{
            if(right != nullptr){
                return right->search(key);
            }
        }
    }
    return false;
}
// remove
bool AVLTree::Node::remove(int key) {}