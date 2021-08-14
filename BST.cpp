#include<iostream>
using namespace std;

struct TreeNode{
    int key;
    TreeNode* left;
    TreeNode *right;
    TreeNode(int k): key(k) {}
};

class BSTree{
    TreeNode *root = NULL;
    public:
    void insert(int val){
        root = _insert(root, val);
    }
    TreeNode *_insert(TreeNode *node, int val){
        if(node == NULL)
        {
            return new TreeNode(val);
        }
        if(val < node->key) node->left = _insert(node->left, val);
        else if(val > node->key) node->right = _insert(node->right, val);
        else {}
        return node;
    }
    void inOrder(){
        _inOrder(root);
    }
    void _inOrder(TreeNode *node){
        if(node){
            _inOrder(node->left);
            cout<<node->key<<" ";
            _inOrder(node->right);
        }
    }


};

int main(){
    BSTree tree;
    for(int i=1;i<10;i++){
        tree.insert(i);
    }
    tree.inOrder();

    return 0;
}