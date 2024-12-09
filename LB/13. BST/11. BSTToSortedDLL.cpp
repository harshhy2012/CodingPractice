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
    while(data != -1){
        root = createBST(root, data);
        cin>>data;

    }
}

void levelOrderTraversal(TreeNode*root){
    if(!root){
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if(!temp){
            cout<<"\n";
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

void BSTtoSortedDLL(TreeNode*root, TreeNode*&head){
    if(!root){
        return;
    }
    BSTtoSortedDLL(root->right, head);
    root->right = head;
    if(head){
        head->left = root;
    }

    head = root;
    BSTtoSortedDLL(root->left, head);
}

void printLinkedList(TreeNode* head){
    while(head){ 
        cout<<head->val<<" ";
        head = head->right;
    }
    cout<<endl;
}

void preOrder(TreeNode* root){
    if(!root){
        return;
    }
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode* root){
    if(!root){
        return;
    }
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

void postOrder(TreeNode* root){
    if(!root){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
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
    
    TreeNode* head = NULL;
    BSTtoSortedDLL(root, head);
    cout<<endl;
    cout<<"LL: ";
    printLinkedList(head);
    cout<<endl;

    return 0;
}