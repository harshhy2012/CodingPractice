#include<bits/stdc++.h>

using namespace std;

class node{
    public: 
        int data;
        node* left;
        node* right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* createTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node* root = new node(d);
    root->left = createTree();
    root->right = createTree();
    return root;
}

void printPre(node*root){
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    printPre(root->left);
    printPre(root->right);
}

void printIn(node*root){
    if(!root){
        return;
    }
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}

void printPost(node*root){
    if(!root){
        return;
    }
    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
}

void printNthLevel(node*root, int level){
    if(!root){
        return; 
    }
    if(level == 1){
        cout<<root->data<<" ";
    }
    printNthLevel(root->left, level-1);
    printNthLevel(root->right, level-1);
}

int treeHeight(node*root){
    if(!root){
        return 0;
    }
    int left = treeHeight(root->left);
    int right = treeHeight(root->right);
    return max(left, right)+1;
}

void levelOrderTraversal(node*root){
    int H = treeHeight(root);

    for(int i=1;i<=H;i++){
        printNthLevel(root, i);
        cout<<endl;
    }
}

void BFS1(node*root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* f = q.front();
        q.pop();
        cout<<f->data<<" ";
        if(f->left!=NULL)
            q.push(f->left);
        if(f->right!=NULL){
           q.push(f->right);
        }
    }
}

void BFS2(node*root){
    queue<node*> q;
    q.push(root);
    node* x = NULL;
    q.push(x);
    while(!q.empty()){
        node* f = q.front();
        q.pop();
        if(!f){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<" ";
            if(f->left!=NULL)
                q.push(f->left);
            if(f->right!=NULL)
                q.push(f->right);
        }
    }
}

void replaceWithSum(node*root){
     if(!root){
        return;
    }
    if(!root->left && !root->right){
        return;
    }
    cout<<"Before: "<<root->data<<endl;
    if(!root->left){
        root->data = root->right->data;
    }
    else if(!root->right){
         root->data = root->right->data;
    }
    else{
         root->data = root->left->data + root->right->data;
    }
    cout<<"After: "<<root->data<<endl;
    
    replaceWithSum(root->left);
    replaceWithSum(root->right);
}

void replaceWithSumPost(node*root){
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        return;
    }
    replaceWithSumPost(root->left);
    replaceWithSumPost(root->right);
    cout<<"Before: "<<root->data<<endl;
    if(!root->left){
        root->data = root->right->data;
    }
    else if(!root->right){
         root->data = root->right->data;
    }
    else{
         root->data = root->left->data + root->right->data;
    }
    cout<<"After: "<<root->data<<endl;
    return;
}


int main(){
    
    node* root = createTree();
    BFS2(root);
    cout<<endl;
    replaceWithSum(root);
    BFS2(root);
    return 0;
}