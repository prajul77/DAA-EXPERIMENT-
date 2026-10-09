#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    Node* root;

    void postorder(Node* node) {
        if (!node) return;

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);

        if (!root) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();

            if (!cur->left) {
                cur->left = newNode;
                return;
            }

            q.push(cur->left);

            if (!cur->right) {
                cur->right = newNode;
                return;
            }

            q.push(cur->right);
        }
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }
};

int main() {
    int n, val;
    BinaryTree tree;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter the node values (level order): ";

    for (int i = 0; i < n; i++) {
        cin >> val;
        tree.insert(val);
    }

    cout << "Post-order traversal: ";
    tree.postorder();

    return 0;
}