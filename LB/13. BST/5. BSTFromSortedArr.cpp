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
TreeNode* sortedArrayToBSTHelper(vector<int>&nums, int s, int e){
    if(s>e){
        return NULL;
    }
    int mid = s+(e-s)/2;
    TreeNode*root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBSTHelper(nums, s, mid-1);
    root->right = sortedArrayToBSTHelper(nums, mid+1, e);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {\
    int s = 0, e = nums.size();
    TreeNode* root = sortedArrayToBSTHelper(nums, s, e);
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

   

    
