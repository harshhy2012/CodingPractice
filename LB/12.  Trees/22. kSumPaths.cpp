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
    int d;
    cin>>d;
    if(d==-1)
        return NULL;
    
    TreeNode * root = new TreeNode(d);
    root->left = createTree();
    root->right = createTree();
    return root;
}

void preOrder(TreeNode* root){
    if(!root)
        return;
    
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode* root){
    if(!root)
        return;
    
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

void postOrder(TreeNode* root){
    if(!root)
        return;

    postOrder(root->left);
    postOrder(root->right);

    cout<<root->val<<" ";
}

void levelOrder(TreeNode*root){
    if(!root)
        return;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode * temp = q.front();
        if(!temp){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        } else{
            cout<<temp->val<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

int ans = 0;
void pathFromOneRoot(TreeNode*root, long long sum){
    if(!root)
        return;
    if(sum == root->val){
        ++ans;
    }
    pathFromOneRoot(root->left, sum-root->val);
    pathFromOneRoot(root->right, sum-root->val);
}

int kPathSum(TreeNode* root, long long targetSum){
    if(root){
        pathFromOneRoot(root, targetSum);
        kPathSum(root->left, targetSum);
        kPathSum(root->right, targetSum);
    }
    
    
    return ans;
}

int main(){
    TreeNode* root = createTree();
    int targetSum;
    cin>>targetSum;
    kPathSum(root, targetSum);
    return 0;
}