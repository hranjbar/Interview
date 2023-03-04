/*

A tree is considered a binary search tree (BST) if for each of its nodes the following is true:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and the right subtrees must also be binary search trees.
Removing a value x from a BST t is done in the following way:

If there is no x in t, nothing happens;
Otherwise, let t' be a subtree of t such that t'.value = x.
If t' has a left subtree, remove the rightmost node from it and put it at the root of t';
Otherwise, remove the root of t' and its right subtree becomes the new t's root.
*/

// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

int rightMost(Tree<int> *root){
    Tree<int> *parent = root;
    Tree<int> *rmost = root->left;
    if(!rmost->right){
        root->left = rmost->left;
        return rmost->value;
    }
    while(rmost && rmost -> right){
        parent = rmost;
        rmost = rmost->right;
    }
    parent->right = rmost->left;
    return rmost->value;
}
Tree<int>* deleteFromBST(Tree<int> *root, int val){
    if (root == nullptr) return nullptr;
    if (root -> value == val){   
        if(!root->left && !root->right) return nullptr;
        else if(root->left) root->value = rightMost(root);
        else return root->right;
    }
    else if(root->value > val) root->left = deleteFromBST(root->left, val);
    else root->right = deleteFromBST(root->right, val);
    return root;
}
Tree<int> * solution(Tree<int> * t, vector<int> queries) {
    for (int & q : queries) t = deleteFromBST(t, q);
    return t;
}
