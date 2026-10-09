#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

class BST {
    Node* root;

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        else
            cout << "Duplicate value ignored." << endl;

        return node;
    }

    bool search(Node* node, int key) {
        if (!node) return false;

        if (key == node->data)
            return true;

        if (key < node->data)
            return search(node->left, key);

        return search(node->right, key);
    }

    Node* findMin(Node* node) {
        while (node->left)
            node = node->left;

        return node;
    }

    Node* remove(Node* node, int key) {
        if (!node) return nullptr;

        if (key < node->data)
            node->left = remove(node->left, key);

        else if (key > node->data)
            node->right = remove(node->right, key);

        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* succ = findMin(node->right); // in-order successor
            node->data = succ->data;
            node->right = remove(node->right, succ->data);
        }

        return node;
    }

    void inorder(Node* node) {
        if (!node) return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }

    bool search(int key) {
        return search(root, key);
    }

    void remove(int key) {
        root = remove(root, key);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int choice, val;

    cout << "Menu:" << endl;
    cout << "1. Insert" << endl;
    cout << "2. Search" << endl;
    cout << "3. Delete" << endl;
    cout << "4. Display (In-order)" << endl;
    cout << "5. Quit" << endl;

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter element to insert: ";
            cin >> val;

            tree.insert(val);
            cout << "Inserted " << val << endl;
            break;

        case 2:
            cout << "Enter element to search: ";
            cin >> val;

            if (tree.search(val))
                cout << "Element " << val << " found in the BST." << endl;
            else
                cout << "Element " << val << " not found in the BST." << endl;

            break;

        case 3:
            cout << "Enter element to delete: ";
            cin >> val;

            if (tree.search(val)) {
                tree.remove(val);
                cout << "Deleted " << val << endl;
            }
            else {
                cout << "Element " << val << " not found in the BST." << endl;
            }

            break;

        case 4:
            cout << "In-order: ";
            tree.display();
            break;

        case 5:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}