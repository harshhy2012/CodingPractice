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
 
TreeNode* createTreeRoot(vector<int> &inO, vector<int> &preO){
    if(inO.size() == 1);
    {
        TreeNode* root = new TreeNode(preO[0]);
        return root;
    }
    TreeNode* root = new TreeNode(preO[0]);
    vector<int> inOLeft (inO.begin(), find(inO.begin(), inO.end(), preO[0])-1);
    for(auto i: inOLeft){
        cout<<i<<" ";
    } cout<<endl;
    vector<int> inORight (find(inO.begin(), inO.end(), preO[0])+1, inO.end());
    for(auto i: inORight){
        cout<<i<<" ";
    } cout<<endl;

    root->left = createTreeFromTraversals(inOLeft, inORight, preO, 1);
    root->right = createTreeFromTraversals(inO preO, pi, );
    return root;
}

TreeNode* createTreeFromTraversals(vector<int> &inOLeft, vector<int> inORight, vector<int> &preO, int pi){
    if(inO.size()==0 || pi>=preO.size()){
        return NULL;
    }
    TreeNode* root = new TreeNode(preO[pi]);
    inO find(inO.begin(), inO.end(), preO[pi]) - inO.begin();
      
    inO = 
    pi++;
    root->left = createTreeFromTraversals(inO, preO, pi, );
    root->right = createTreeFromTraversals(inO, preO, pi, );
    return root;
}

int main(){
    TreeNode* root = buildTree();
    cout<<"INORDER: ";inOrder(root);
    cout<<endl;
    cout<<"PREORDER: ";preOrder(root);
    cout<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    return 0;
} 
