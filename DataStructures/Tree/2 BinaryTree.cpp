
// TOPIC: Binary Tree  ( IT IS NOT BINARY SEARCH TREE )

// NOTES:
// 0. A tree whose nodes can have at most two children is called binary tree.
// 1. As there can only be two children of a node we call them left and right child.

// TYPES OF BINARY TREE:
// 0. FULL BINARY TREE / STRICTLY BINARY TREE
//    Every node must have two children, except the leaf nodes.
// 1. PERFECT BINARY TREE
//    All levels are completely filled. At each level there should be 2^L nodes where L is level
// 2. COMPLETE BINARY TREE
//    All levels except the last one are completely filled and the last level is filled from left to right.
// 3. LEFT SKEWED BINARY TREE
//    Every node should have only left children.
// 4. RIGHT SKEWED BINARY TREE
//    Every node should have only right children. 
// 
// Note: In some books, above PERFECT BINARY TREE definition is called COMPLETE BINARY TREE. 
// Above COMPLETE BINARY TREE definition is called ALMOST COMPLETE BINARY TREE


// Watch this to understand the code: https://www.youtube.com/watch?v=5NiXlPrLslg&list=PLDzeHZWIZsTo87y1ytEAqp7wYlEP3nner
#include<iostream>
#include<queue>
#include<stack>
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

//Check if 2 trees are identical or not
bool isSameTree(Node* p, Node* q) {
    if (p == NULL || q == NULL) {
        return (p == q);
    }

    return (p->data == q->data) 
        && isSameTree(p->left, q->left) 
        && isSameTree(p->right, q->right);
}


// Zig Zag Level Order Traversal 
// Striver: https://takeuforward.org/data-structure/zig-zag-traversal-of-binary-tree/
// Time Complexity: O(N)   
// Space Complexity : O(N)

vector <vector<int>> zigZagTraversal(Node* root) {
    vector<vector<int>> result;
    if (root == NULL) {
        return result;
    }

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector <int> row(size); //Notice, the vector needs a size here

        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();

            // find position to fill node's value
            //int index = (leftToRight) ? i : (size - 1 - i);
            //row[index] = node->data;

            if (leftToRight == true) {
                row[i] = node->data;
            }
            else {
                row[size - 1 - i] = node->data;
            }

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        // after this level
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}



// https://www.youtube.com/watch?v=xtuhK-a18is
// https://www.geeksforgeeks.org/zigzag-tree-traversal/
//Time Complexity: O(n) 
//Space Complexity : O(n) + (n) = O(n)

void zigZagTraversal1(Node* root) {
    if (root == NULL) 
        return;

    stack<Node*> currLevel;
    stack<Node*> nextLevel;

    bool leftToRight = true;

    currLevel.push(root);

    while (!currLevel.empty()) {
        Node* temp = currLevel.top();
        currLevel.pop();

        if (temp) {
            cout << temp->data << " ";

            if (leftToRight) {
                if (temp->left) {
                    nextLevel.push(temp->left);
                }
                if (temp->right) {
                    nextLevel.push(temp->right);
                }
            }
            else { //RightToLeft
                if (temp->right) {
                    nextLevel.push(temp->right);
                }
                if (temp->left) {
                    nextLevel.push(temp->left);
                }
            }
        }

        if (currLevel.empty()) {
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
}

// For the above solution, you can just perform the simple level order traversal.Considering 1 based indexing
//If level is odd then then just print the elements.
//If level is even just use a stack and push the elements into it and once level is traversed start popping and print the values. You will get values in reverse order because of LIFO nature of Stack.
//And finally check at the end if stack still contains elements, empty the stack and print the element.
vector<int> zigZagTraversal2(Node* root) {
    queue<Node*> q;
    stack<int> st;
    vector<int> ans;
    q.push(root);
    q.push(NULL);
    int level = 1;

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp != NULL) {
            if (level % 2 == 1) {
                ans.push_back(temp->data);
            }
            else {
                st.push(temp->data);
            }

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
        else if (!q.empty()) {
            q.push(NULL);
            while (!st.empty()) {
                ans.push_back(st.top());
                st.pop();
            }
            level++;
        }
    }

    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}


int main() {

//             1
//
//        3         5
//
//     7    11   17


    //creating a Tree
    
    //Node* root = NULL;
    //root = buildTree(root); // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(11);
    root->right->right = new Node(17);

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

    cout << "Zig Zag traversal is: " << endl;
    for (auto vec : zigZagTraversal(root)) {
        for (auto e : vec) {
            cout << e << " ";
        }
        cout << endl;
    }

    cout << "Zig Zag traversal is: ";
    zigZagTraversal1(root); // 1 5 3 7 11 17
    cout << endl;

    cout << "Zig Zag traversal is: ";
    for (auto e : zigZagTraversal2(root)) {
            cout << e << " ";
    }
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