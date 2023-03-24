#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* createList(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node* root = new node(d);
    root->left = createList();
    root->right = createList();
    return root;
}

void printPre(node* root){
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

int treeHeight(node*root){
    if(!root){
        return 0;
    }
    return max(treeHeight(root->left), treeHeight(root->right)) + 1; 
}

int numOfNodes(node*root){
    if(!root){
        return 0;
    }
    return treeHeight(root->left) + treeHeight(root->right) + 1; 
}

int sumOfNodes(node*root){
    if(!root){
        return 0;
    }
    return treeHeight(root->left) + treeHeight(root->right) + root->data; 
}

void printNthLevel(node*root, int h){
    if(!root){
        return;
    }
    if(h==1){
        cout<<root->data<<" ";
    }
    printNthLevel(root->left, h-1);
    printNthLevel(root->right, h-1);
}

void levelOrderTraversal(node*root){
    int H = treeHeight(root);
    for(int i=1;i<=H;i++){
        printNthLevel(root, i);
    }
}

void BFS(node*root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node*f = q.front();
        q.pop();
        if(!f){
            cout<<"\n";
            q.pop();
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<f->data<<" ";
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
        }
    }
}

int diameter(node*root){
    if(!root){
        return 0;
    }
    int h1 = treeHeight(root->left);
    int h2 = treeHeight(root->right);
    
    int op1 = h1+h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1,max(op2,op3));
}

pair<int, int> diameterOptimized(node*root){
    // bottom up approach
    // D = max(op1,max(op2,op3))
    // calculating height = O(n), n number of times which made top down approach O(n^2)
    if(!root){
        pair<int,int> ans = {0,0};
        return ans;
    }
    pair<int, int> leftAns, rightAns;
    leftAns = diameterOptimized(root->left);
    rightAns = diameterOptimized(root->right);

    pair<int, int> ans;
    ans.first = max(leftAns.first, rightAns.first) + 1;
    ans.second = max(leftAns.first+rightAns.first,max(leftAns.second, rightAns.second));
    return ans;
}

int nodeSum(node*root){
    if(!root->left && !root->right){
        return root->data;
    }
    int leftSum = nodeSum(root->left);
    int rightSum = nodeSum(root->right);
    int temp = root->data;
    root->data = leftSum+rightSum;
    return temp + root->data;

}


int main(){
    node* root = createList();
    BFS(root);
    printPre(root);
    cout<<endl;
    printIn(root);
    cout<<endl;
    printPost(root);
    cout<<endl;
    cout<<"Number of nodes: "<<numOfNodes(root)<<endl;
    cout<<"Sum of nodes: "<<sumOfNodes(root)<<endl;
    cout<<"Height of tree: "<<treeHeight(root)<<endl;
    cout<<"Diameter of tree: "<<diameter(root)<<endl;
    cout<<"Diameter of tree(optimized): "<<diameterOptimized(root).second<<"| Height of tree: "<<diameterOptimized(root).first<<endl;
    return 0;
}