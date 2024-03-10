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

void postOrder(TreeNode* root){
    //NLR
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
TreeNode* createTreeFromTraversals(vector<int> &inO, vector<int> &postO, int &pi, int inOStart, int inOEnd){
    if(inOStart>inOEnd|| pi>=0){
        return NULL;
    }
    TreeNode* root = new TreeNode(postO[pi]);
    int posi =  find(inO.begin(), inO.end(), postO[pi]) - inO.begin();   
    pi--;
    root->right = createTreeFromTraversals(inO, postO, pi, posi+1, inOEnd);
    root->left = createTreeFromTraversals(inO, postO, pi, inOStart, posi-1);
    return root;
}

int main(){
    vector<int> inO = {40, 20, 10, 50, 30, 60};
    vector<int> postO = {40, 20, 50, 60, 30, 10};
    int pi = postO.size()-1;  

    TreeNode* root = createTreeFromTraversals(inO, postO, pi, 0, inO.size()-1);
    cout<<"INORDER: ";inOrder(root);
    cout<<endl;
    cout<<"POSTORDER: ";postOrder(root);
    cout<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    return 0;
} 
