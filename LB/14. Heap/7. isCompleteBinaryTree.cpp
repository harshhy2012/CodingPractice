#include<bits/stdc++.h>

using namespace std;

class TreeNode{
    public: 
        int val;
        TreeNode*left;
        TreeNode*right;

        TreeNode(int data){
            this->val = data;
            this->left = NULL;
            this->right = NULL;
        }
};

TreeNode* buildTree(){
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    } else{
        TreeNode* newNode = new TreeNode(data);
        newNode->left = buildTree();
        newNode->right = buildTree();
        return newNode;
    }
}

int height(TreeNode* root){
    if(!root){
        return 0;
    }
    return 1+max(height(root->left), height(root->right));
}

pair<int, bool> isComplete(TreeNode* root){
    if(!root || (!root->left && !root->right){
        return {0,true};
    }
    if((!root->left && root->right) || (root->right && !root->left)){
        return {false;
    }
    bool left = isComplete(root->left);
    bool right = isComplete(root->right);
    return left && right;
}
int main(){
    
    return 0;
}