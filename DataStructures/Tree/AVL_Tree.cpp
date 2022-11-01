// TOPIC: AVL Tree (Adelson, Velski & Landis)

// Prerequisite is BST;

// NOTES:
// 1. AVL tree is height balancing BST OR self balancing BST.
// 2. Why BST was not enough? and we needed balancing BST (AVL Tree)
//    a. Normal BST is having issue when data is sorted or almost sorted (skewed Binary tree).
//    b. Using AVL tree we keep balancing when it becomes non balanced while inserting data.
// 3. AVL tree take the height of left and right sub tree and find the difference (L-R) and it should be either of {-1,0,1}.
// 4. This difference is called Balance Factor.
// 5. If the balance factor of left and right sub tree is not either of {-1,0,1} then tree is balanced using rotation techniques.
//    A. left left     ==>> Right Rotation 
//    B. left right    ==>> Left and Right Rotation
//    C. right left    ==>> Right and Left Rotation
//    D. right right   ==>> Left 


// PROGRAM from CppNut
#include <iostream> 
using namespace std;

// An AVL tree node  
class Node
{
public:
    int key;
    Node* left;
    Node* right;
    int height;
};
int max(int a, int b) {
    return (a > b) ? a : b;
}
int height(Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node is initially 
    // added at leaf  
    return(node);
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation  
    x->right = y;
    y->left = T2;

    // Update heights  
    y->height = max(height(y->left),
        height(y->right)) + 1;
    x->height = max(height(x->left),
        height(x->right)) + 1;

    // Return new root  
    return x;
}
Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation  
    y->left = x;
    x->right = T2;

    // Update heights  
    x->height = max(height(x->left),
        height(x->right)) + 1;
    y->height = max(height(y->left),
        height(y->right)) + 1;

    // Return new root  
    return y;
}

// Get Balance factor of node N  
int getBalance(Node* N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key)
{
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST  
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
        height(node->right));

    /* 3. Get the balance factor of this ancestor node to check whether this node became unbalanced */
    int balance = getBalance(node);

    // Left Left Case  
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case  
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case  
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case  
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;  /* return the (unchanged) node pointer */
}
void preOrder(Node* root) {
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    cout << "Preorder traversal of the "
        "constructed AVL tree is \n";
    preOrder(root);

    return 0;
}