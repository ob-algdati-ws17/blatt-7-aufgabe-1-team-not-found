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
            while(root->prev != nullptr){
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
        if(root->key == key) { //root is being removed.
            if (root->left == nullptr && root->right == nullptr) {
                success = root->remove(key);
                root = nullptr;
            } else {
                Node *tmp;
                if (root->left != nullptr) {
                    tmp = root->left;
                } else {
                    tmp = root->right;
                }
                success = root->remove(key);
                while (tmp->prev != nullptr) {
                    tmp = tmp->prev;
                }
                root = tmp;
            }
        }else{
            success = root->remove(key);
            while (root->prev != nullptr) {
                root = root->prev;
            }
        }
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
                    calling ->balance = 0;
                    balance = 0;
                }else{
                    Node * tmp = calling->right;
                    rotateLeftRight();
                    if(tmp->balance == -1){
                        balance = 1;
                        calling->balance = 0;
                    }else{
                        balance = 0;
                        if(tmp->balance == 1){
                            calling->balance = -1;
                        }else{
                            calling->balance = 0;
                        }
                    }
                    tmp->balance = 0;
                }
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
                    balance = 0;
                    calling ->balance = 0;
                }else{
                    Node * tmp = calling->left;
                    rotateRightLeft();
                    if(tmp->balance == 1){
                        balance = -1;
                        calling->balance = 0;
                    }else{
                        balance = 0;
                        if(tmp->balance == -1){
                            calling->balance = 1;
                        }else{
                            calling->balance = 0;
                        }
                    }
                    tmp->balance = 0;

                }

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
bool AVLTree::Node::remove(int key) {
    if(key < this->key){
        return left->remove(key);
    }
    if(key > this->key){
        return right->remove(key);
    }
    //wenn ich hierhin komme bin ich das zu entfernende Element.
    if(left == nullptr && right == nullptr){
        return remove0Child();
    }
    if(left == nullptr || right == nullptr){
        return remove1Child();
    }else{
        return remove2Child();
    }
}
bool  AVLTree::Node::remove0Child(){
    bool success = false;
    if(prev != nullptr){ // es wird ein innerer Knoten entfernt
        if(this == prev->left){ // ich bin linker nachfolger
            prev->left = nullptr;
            switch(prev->balance){
                case -1:
                    prev->balance = 0; // höhe hat sich verändert!
                    prev->upout();
                    break;
                case 0:
                    prev->balance = 1;
                    break;
                case 1:
                    prev->balance = 2; // rotate notwendig - upout wid das erledigen.
                    prev->upout();
                    break;
                default:
                    cout << "balance was " << balance << " at upout!"<<endl;
                    break;
            }
        }else{ //ich bin rechter nachfolger
            prev->right = nullptr;
            switch(prev->balance){
                case -1:
                    prev->balance = -2; // rotate notwendig - upout wid das erledigen.
                    prev->upout();
                    break;
                case 0:
                    prev->balance = -1;
                    break;
                case 1:
                    prev->balance = 0; // höhe hat sich verändert!
                    prev->upout();
                    break;
                default:
                    cout << "balance was " << balance << " at upout!"<<endl;
                    break;
            }
        }
        success = true;
    }else{ // wurzel wird entfernt
        success = true;
    }
    delete this;
    return success;
}

bool  AVLTree::Node::remove1Child(){
    bool success = false;
    if(prev != nullptr){ // not root
        Node * newChild;
        if(left == nullptr){
            right->prev=prev;
            newChild = right;
        }else{
            left->prev=prev;
            newChild = left;
        }
        if(this == prev->left){ //ich bin links
            prev->left = newChild;
            switch(prev->balance){
                case -1:
                    prev->balance = 0;
                    prev->upout();
                    break;
                case 0:
                    prev->balance = 1;
                    break;
                case 1:
                    prev->balance = 2;
                    prev->upout();
                    break;
                default:
                    cout << "balance was " << balance << " at upout!"<<endl;
                    break;
            }
        }else{ //ich bin rechts
            prev->right = newChild;
            switch(prev->balance){
                case -1:
                    prev->balance = -2;
                    prev->upout();
                    break;
                case 0:
                    prev->balance = 1;
                    break;
                case 1:
                    prev->balance = 0;
                    prev->upout();
                    break;
                default:
                    cout << "balance was " << balance << " at upout!"<<endl;
                    break;
            }
        }
    }else{ // root
        success = true;
    }
    delete this;
    return success;
}
bool  AVLTree::Node::remove2Child(){
    Node * symmetrischerNachfolger = right;
    while(symmetrischerNachfolger->left != nullptr){
        symmetrischerNachfolger = symmetrischerNachfolger->left;
    }
    int tmp_key = symmetrischerNachfolger->key;
    remove(tmp_key);
    key = tmp_key;
}
void AVLTree::Node::upout() {
    Node * tmp;
    switch(balance){
        case 0:
            if(prev != nullptr){ //wenn root ist der baum balanciert
                if(prev->left == this){ //i am left
                    switch(prev->balance){
                        case -1:
                            prev->balance = 0;
                            prev->upout();
                            break;
                        case 0:
                            prev->balance = 1;
                            break;
                        case 1:
                            prev->balance = 2;
                            prev->upout();
                            break;
                        default:
                            cout << "balance was " << balance << " at upout(inner1)!"<<endl;
                            break;
                    }
                }else{ //i am right
                    if(prev->right != this){cout<<"im not my fathers child!"<< endl;}
                    switch(prev->balance){
                        case -1:
                            prev->balance = -2;
                            prev->upout();
                            break;
                        case 0:
                            prev->balance = -1;
                            break;
                        case 1:
                            prev->balance = 0;
                            prev->upout();
                            break;
                        default:
                            cout << "balance was " << balance << " at upout/(inner2)!"<<endl;
                            break;
                    }
                }
            }
            break;
        case 2:
            switch(right->balance){
                case -1:
                    tmp = prev;
                    balance = 0;
                    right->balance = 0;
                    if(right->left->balance == 1){
                        balance = -1;
                    }
                    if(right->left->balance == -1){
                        right->balance = 1;
                    }
                    right->left->balance = 0;
                    rotateRightLeft();
                    if(tmp != nullptr){
                        tmp->upout();
                    }
                    break;
                case 0:
                    right->balance = -1;
                    balance = 1;
                    rotateLeft();
                    break;
                case 1:
                    tmp = prev;
                    right->balance = 0;
                    balance = 0;
                    rotateLeft();
                    if(tmp != nullptr){
                        tmp->upout();
                    }
                    break;
            }
            break;
        case -2:
            switch(left->balance){
                case -1:
                    tmp = prev;
                    balance = 0;
                    left->balance = 0;
                    if(left->right->balance == -1){
                        balance = 1;
                    }
                    if(left->right->balance == 1){
                        left->balance = -1;
                    }
                    left->right->balance = 0;
                    rotateLeftRight();
                    if(tmp != nullptr){
                        tmp->upout();
                    }
                    break;
                case 0:
                    left->balance = 1;
                    balance = -1;
                    rotateRight();
                    break;
                case 1:
                    tmp = prev;
                    left->balance = 0;
                    balance = 0;
                    rotateRight();
                    if(tmp != nullptr){
                        tmp->upout();
                    }
                    break;
            }
            break;
        default:
            cout << "balance was " << balance << " at upout!"<<endl;
            break;
    }
}