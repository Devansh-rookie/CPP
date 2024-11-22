#include <iostream>
using namespace std;

// Definition of a Binary Search Tree node
struct Node {
    int key;
    Node* left;
    Node* right;
    
    Node(int data) {
        key = data;
        left = right = nullptr;
    }
};

// Class for Binary Search Tree
class BST {
public:
    Node* root;
    
    BST() {
        root = nullptr;
    }

    // Insert a node in the BST
    Node* insert(Node* node, int key) {
        if (node == nullptr) return new Node(key);
        
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);

        return node;
    }

    // Search a key in the BST
    bool search(Node* node, int key) {
        if (node == nullptr) return false;
        
        if (node->key == key) return true;
        else if (key < node->key) return search(node->left, key);
        else return search(node->right, key);
    }

    // In-order traversal of the BST
    void inorder(Node* node) {
        if (node == nullptr) return;
        
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }

    // Find the minimum node in a subtree
    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    // Delete a node from the BST
    Node* deleteNode(Node* root, int key) {
        if (root == nullptr) return root;
        
        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = findMin(root->right);
            
            // Copy the inorder successor's content to this node
            root->key = temp->key;
            
            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }
};

int main() {
    BST tree;
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "Inorder traversal of the BST: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "\nDeleting 20\n";
    tree.root = tree.deleteNode(tree.root, 20);
    cout << "Inorder traversal after deleting 20: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "\nDeleting 30\n";
    tree.root = tree.deleteNode(tree.root, 30);
    cout << "Inorder traversal after deleting 30: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "\nDeleting 50\n";
    tree.root = tree.deleteNode(tree.root, 50);
    cout << "Inorder traversal after deleting 50: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}
