
// TOPIC: Binary Tree  ( IT IS NOT BINARY SEARCH TREE )

// NOTES:
// 0. A tree whose nodes can have at most two children is called binary tree.
// 1. As there can only be two children of a node we call them left and right child.

// TYPES OF BINARY TREE:
// 0. FULL BINARY TREE / STRICTLY BINARY TREE
//    Every node must have two children, except the leaf nodes.
// 1. INCOMPLETE BINARY TREE / ALMOST COMPLETE BINARY TREE
//    Every node must have two childrens in all levels except second last level and should be filled from left to right.
// 2. COMPLETE BINARY TREE / PERFECT BINARY TREE
//    Every node must have two childrens in all the levels (Each level there should be 2^L where L is level)
// 3. LEFT SKEWED BINARY TREE
//    Every node should have only left children.
// 4. RIGHT SKEWED BINARY TREE
//    Every node should have only right children.


// Watch this to understand the code: https://www.youtube.com/watch?v=5NiXlPrLslg&list=PLDzeHZWIZsTo87y1ytEAqp7wYlEP3nner
#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->left) {
            q.push(temp->left);
        }

        if (temp->right) {
            q.push(temp->right);
        }
    }
}

void inorder(Node* root) {
    //base case
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}

void preorder(Node* root) {
    //base case
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root) {
    //base case
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";

}

void buildFromLevelOrder(Node*& root) {
    queue<Node*> q;

    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new Node(data);

    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}


int main() {

    Node* root = NULL;

    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    /*
    //creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //level order
    cout << "Printing the level order tracersal output " << endl;
    levelOrderTraversal(root);
    cout << "inorder traversal is:  ";
    inorder(root);
    cout << endl << "preorder traversal is:  ";
    preorder(root);
    cout << endl << "postorder traversal is:  ";
    postorder(root);
    */


    return 0;
}