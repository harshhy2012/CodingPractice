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

TreeNode* createBST(TreeNode*&root, int data){
    if(!root){
        root = new TreeNode(data);
        return root;
    }
    if(root->val > data){
        createBST(root->left, data);
    } else{
        createBST(root->right, data);
    }
    return root;
}

void inputData(TreeNode*&root){
    int data;
    cin>>data;
    while(data!=-1){
        root = createBST(root, data);
        cin>>data;
    }
}

bool validate(TreeNode*root, long long lowerBound, long long upperBound){
    if(!root){
        return true;
    }
    if(lowerBound <= root->val && root ->val <= upperBound ){
        bool leftAns = validate(root->left, lowerBound, root->val);
        bool rightAns = validate(root->right, root->val, upperBound);
        return leftAns && rightAns;
    }
    else{
        return false;
    }
}

bool validateBST(TreeNode*root){
    if(!root){
        return true;
    }
    if(!root->left && !root->right){
        return true;
    }
    long long lowerBound = -4294967296;
    long long upperBound = 4294967296;
    return validate(root, lowerBound, upperBound);
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
            if(temp->right)
                q.push(temp->right);
        }
    }
}

int main(){
    TreeNode* root = NULL;
    inputData(root);
    if(validateBST){
        cout<<"BST SAI HAI!\n";
    }
    else{
        cout<<"BST NI HAI YE :O\n";
    }
    cout<<endl;
    cout<<"Level order: \n";levelOrderTraversal(root);
    cout<<endl;
    cout<<"PreOrder: ";preOrder(root);
    cout<<endl;
    cout<<"InOrder: ";inOrder(root);
    cout<<endl;
    cout<<"PostOrder: ";postOrder(root);
    cout<<endl;

    return 0;
}