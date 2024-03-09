#include<bits/stdc++.h>

using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    Node*root=new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void preOrder(Node*root){
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node*root){
    if(!root){
        return;
    }
    preOrder(root->left);
    cout<<root->data<<" ";
    preOrder(root->right);
}

void postOrder(Node*root){
    if(!root){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void printQ(queue<Node*> q){
    while(!q.empty()){
        Node*temp = q.front();
        if(temp==NULL){
            cout<<"N ";
        } else{
            cout<<temp->data<<" ";
        }
        q.pop();
    }
    cout<<endl;
}
void levelOrderTraversal(Node*root){
    if(!root){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(!temp){
            cout<<"\n";
            if(!q.empty()){
                q.push(NULL);
            }
        } else{
            cout<<temp->data<<" ";
            if(temp->left)
             q.push(temp->left);
            
            if(temp->right)
                q.push(temp->right);
        }
        
    }
} 

int height(Node*root){
    if(!root){
        return 0;
    }
    int lH = height(root->left);
    int rH = height(root->right);
    return 1+max(lH, rH);
}

int diameter(Node*root){
    if(!root){
        return 0;
    }
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left)+height(root->right);

    return max(op1, max(op2, op3));
}

pair<int, int> optimizedDiameter(Node*root){
        // bottom up approach
    // D = max(op1,max(op2,op3))
    // calculating height = O(n), n number of times which made top down approach O(n^2)
    if(!root){
        pair<int,int> ans = {0,0};
        return ans;
    }
    pair<int, int> leftAns, rightAns;
    leftAns = optimizedDiameter(root->left);
    rightAns = optimizedDiameter(root->right);

    pair<int, int> ans;
    ans.first = max(leftAns.first, rightAns.first) + 1;
    ans.second = max(leftAns.first+rightAns.first,max(leftAns.second, rightAns.second));
    return ans;
}



int main(){

    Node* root = buildTree();
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"Height of tree: "<<height(root)<<endl;
    cout<<"Diameter of tree: "<<diameter(root)<<endl;
    cout<<"Diameter of tree(optimized): "<<optimizedDiameter(root).second<<"| Height of tree: "<<optimizedDiameter(root).first<<endl;
    return 0;
}