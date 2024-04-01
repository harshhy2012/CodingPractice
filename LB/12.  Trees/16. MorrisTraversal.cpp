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

vector<int> morrisTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode*curr = root;
        while(curr){
            if(!curr->left){
                ans.push_back(curr->val);
                curr = curr->right;
            } else{
                //find inorder predecessor
                TreeNode*pred = curr->left;
                while(pred->right != curr && pred->right){
                    pred = pred->right;
                }

                if(!pred->right){
                    pred->right = curr;
                    curr = curr->left;
                } else{
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }        
            }
        }
        return ans;
    }

int main(){
    TreeNode* root = createTree();
    int targetSum;
    cin>>targetSum;
    vector<int> ans = morrisTraversal(root);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}