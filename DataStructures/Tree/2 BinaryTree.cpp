
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

struct Node {
public:
    int data;
    Node* left;
    Node* right;
    Node() : data(0), left(NULL), right(NULL) {}
    Node(int x) : data(x), left(NULL), right(NULL) {}
    Node(int x, Node* left, Node* right) : data(x), left(left), right(right) {}
};

Node* buildTree(Node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    root = new Node(data);

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
        root = q.front();
        cout << root->data << " ";
        q.pop();

        if (root->left != NULL) {
            q.push(root->left);
        }

        if (root->right != NULL) {
            q.push(root->right);
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

//Find height/depth of tree
int getHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    //return std::max(leftHeight, rightHeight) + 1;

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    }
    else {
        return rightHeight + 1;
    }
}


//Returns the count of leaf nodes in a binary tree
void traverse(Node* root, int& count) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " "; //prints the leaf nodes
        count++;
    }

    traverse(root->left, count);
    traverse(root->right, count);
}

int countLeafNodes(Node* root) {
    int count = 0;

    //Doing inorder traversal. You can do any traversal
    traverse(root, count);
    return count;
}


//Another approach to return the count of leaf nodes in a binary tree
int countLeafNodes1(Node* root) {
    if (root == NULL) {
        return 0;
    }

    //Check for leaf node
    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " "; //prints the leaf node
        return 1;
    }

    //For internal nodes, return the sum of leaf nodes in left and right sub-tree 
    return countLeafNodes1(root->left) + countLeafNodes1(root->right);
}


int main() {

//            1
//
//        3        5
//
//     7   11   17


    Node* root = NULL;

    //creating a Tree
    root = buildTree(root); // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "\nLevel order traversal is: ";
    levelOrderTraversal(root); // 1 3 5 7 11 17
    cout << endl;

    cout << "In order traversal is: ";
    inorder(root); // 7 3 11 1 17 5
    cout << endl;

    cout << "Pre order traversal is: ";
    preorder(root); // 1 3 7 11 5 17
    cout << endl;

    cout << "Post order traversal is: ";
    postorder(root); // 7 11 3 17 5 1
    cout << endl;

    cout << "Leaf nodes are: ";
    int count = countLeafNodes(root); // 7 11 17
    cout << endl << "No of Leaf nodes: " << count << endl;

    ////Build from Level Order Traversal
    //Node* root1 = NULL; 
    //buildFromLevelOrder(root1); //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    //levelOrderTraversal(root1);
    
    return 0;
}