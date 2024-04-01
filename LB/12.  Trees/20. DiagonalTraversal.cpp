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

TreeNode* buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    TreeNode* root = new TreeNode(d);
    root->left = buildTree();
    root->right = buildTree();
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

void levelOrderTraversal(TreeNode* root){
    if(!root)
        return;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode*temp = q.front();
        q.pop();
        if(!temp){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        } else{
            cout<<temp->val<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void diagonalHelper(TreeNode* root, map<int, vector<int>>& ans, int lvl){
    if(!root){
        return;
    }
    if(ans.find(lvl)==ans.end()){
        ans[lvl] = {root->val};
    } else{
        ans[lvl].push_back(root->val);
    }
    diagonalHelper(root->left, ans, lvl+1);
    diagonalHelper(root->right, ans, lvl);
}

void diagonalTraversal(TreeNode*root){
    if(!root)
        return;
    map<int, vector<int>> ans;
    diagonalHelper(root, ans, 0);
    for(auto i: ans){
        cout<<"Diag No "<<i.first<<" :   ";
        for(auto j: i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}


vector<int> diagonalTraversalNoMap(TreeNode*root){
    vector<int> ans;
    if(!root)
        return ans;
    
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        while(temp){
            ans.push_back(temp->val);
            
            if(temp->left){
                q.push(temp->left);
            }
            temp = temp->right;    
        }
    }
    return ans;
}



int main(){
    TreeNode * root = buildTree();
    cout<<endl;
    cout<<"PreOrder: ";preOrder(root);cout<<endl;
    cout<<"InOrder: ";inOrder(root);cout<<endl;
    cout<<"PostOrder: ";postOrder(root);cout<<endl;
    cout<<"LevelOrder: \n";levelOrderTraversal(root);cout<<endl;
    cout<<"DiagonalTraversal: \n";diagonalTraversal(root);cout<<endl;
    cout<<"DiagonalTraversalNoMap: \n";
    for(auto i: diagonalTraversalNoMap(root)){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}