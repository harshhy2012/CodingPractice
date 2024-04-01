#include<bits/stdc++.h>

using namespace std;

class TreeNode{
  public: 

    int val;

    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* createTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    TreeNode* root = new TreeNode(data);
    root->left = createTree();
    root->right = createTree();
    return root;
}

void preOrder(TreeNode*root){
    if(!root)
        return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}   

void inOrder(TreeNode*root){
    if(!root)
        return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}   

void postOrder(TreeNode*root){
    if(!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}   

void levelOrderTraversal(TreeNode*root){
    if(!root)
        return;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if(!temp){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        } else{
            cout<<temp->val<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

    void stringGen(string s, int data){

    }

    void binaryTreePathHelper(TreeNode* root, vector<string> ans, string s){
        if(!root){
            return;    
        }
        if(!root->left && !root->right){
            stringGen(s, root->val);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s;
        binaryTreePathHelper(root, ans, s);
    }

int main(){
    TreeNode* root = createTree();

    return 0;
}