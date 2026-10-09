#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct Node {
int data;
Node *left, *right;
Node(int v) : data(v), left(nullptr), right(nullptr) {}
};
class BinaryTree {
Node* root;
int height(Node* node) {
if (!node) return 0;
return 1 + max(height(node->left), height(node->right));
}
int countNodes(Node* node) {
if (!node) return 0;
return 1 + countNodes(node->left) + countNodes(node->right);
}
int countLeaves(Node* node) {
if (!node) return 0;
if (!node->left && !node->right) return 1;
return countLeaves(node->left) + countLeaves(node->right);
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
void levelOrder() {
if (!root) return;
queue<Node*> q;
q.push(root);
while (!q.empty()) {
Node* cur = q.front();
q.pop();
cout << cur->data << " ";
if (cur->left) q.push(cur->left);
if (cur->right) q.push(cur->right);
}
cout << endl;
}
int height()
{ return height(root); }
int countNodes() { return countNodes(root); }
int countLeaves(){ return countLeaves(root); }
};
int main() {
int n, val;
BinaryTree tree;
cout << "Enter number of nodes: ";
cin >> n;
cout << "Enter the node values: ";
for (int i = 0; i < n; i++) {
cin >> val;
tree.insert(val);
}
cout << "Level-order: ";
tree.levelOrder();
cout << "Height: " << tree.height() << endl;
cout << "Total nodes: " << tree.countNodes() << endl;
cout << "Leaf nodes: " << tree.countLeaves() << endl;
return 0;
}