#include<bits/stdc++.h>

using namespace std;

class TreeNode{
  public:
    int val;
    TreeNode*left;
    TreeNode*right;

    TreeNode(int d){
        this->val = d;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* buildTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    } 
    TreeNode* root = new TreeNode(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void inOrder(TreeNode* root){
    //LNR
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

void preOrder(TreeNode* root){
    //NLR
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}


void postOrder(TreeNode* root){
    //LRN
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
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


TreeNode* createTreeFromTraversals(vector<int> &inO, vector<int> &preO, int &pi, int inOStart, int inOEnd){
    if(inOStart>inOEnd|| pi>=preO.size()){
        return NULL;
    }
    TreeNode* root = new TreeNode(preO[pi]);
    int posi =  find(inO.begin(), inO.end(), preO[pi]) - inO.begin();   
    pi++;
    root->left = createTreeFromTraversals(inO, preO, pi, inOStart, posi-1);
    root->right = createTreeFromTraversals(inO, preO, pi, posi+1, inOEnd);
    return root;
}

int main(){
    vector<int> inO = {20, 10, 40, 30, 50};
    vector<int> preO = {10, 20, 30, 40, 50};
    int pi = 0;  

    TreeNode* root = createTreeFromTraversals(inO, preO, pi, 0, inO.size()-1);
    cout<<"INORDER: ";inOrder(root);
    cout<<endl;
    cout<<"PREORDER: ";preOrder(root);
    cout<<endl;
    cout<<"POSTORDER: ";postOrder(root);
    cout<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    return 0;
} 
