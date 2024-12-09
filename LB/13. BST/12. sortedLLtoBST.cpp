#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

TreeNode *createBST(TreeNode *&root, int data)
{
    if (!root)
    {
        root = new TreeNode(data);
        return root;
    }
    if (root->val > data)
    {
        createBST(root->left, data);
    }
    else
    {
        createBST(root->right, data);
    }
    return root;
}

void inputData(TreeNode *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = createBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (!temp)
        {
            cout << "\n";
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->val << " ";
            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

ListNode *midPt(ListNode *&head)
{
    ListNode*slow = head;
    ListNode*fast = head->next;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

TreeNode *sortedLLtoBST(ListNode *&head)
{
    if (!head)
    {
        return NULL; 
    }
    TreeNode* leftSubTree = sortedLLtoBST(head);
    TreeNode* root = new TreeNode(head->val);
    root->left =  leftSubTree;

    head = head->next;
    
    root->right = sortedLLtoBST(head);
    
    return root;
}

TreeNode *sortedListToBST(ListNode *head)
{
    return sortedLLtoBST(head);
}

void printLinkedList(TreeNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->right;
    }
    cout << endl;
}

void preOrder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void postOrder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

void printLinkedList(ListNode *l)
{
    while (l)
    {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
}

int main()
{
    // TreeNode* root = NULL;
    // inputData(root);
    // cout<<endl;
    // cout<<"Level order: \n";levelOrderTraversal(root);
    // cout<<endl;
    // cout<<"PreOrder: ";preOrder(root);
    // cout<<endl;
    // cout<<"InOrder: ";inOrder(root);
    // cout<<endl;
    // cout<<"PostOrder: ";postOrder(root);
    // cout<<endl;

    TreeNode *head = NULL;
    ListNode *l1 = new ListNode(-10);
    ListNode *l2 = new ListNode(-3);
    ListNode *l3 = new ListNode(0);
    ListNode *l4 = new ListNode(5);
    ListNode *l5 = new ListNode(9);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = NULL;

    printLinkedList(l1);
    cout << endl;

    TreeNode *ans = sortedListToBST(l1);

    cout << endl;
    cout << "Level order: \n";
    levelOrderTraversal(ans);
    cout << endl;
    cout << "PreOrder: ";
    preOrder(ans);
    cout << endl;
    cout << "InOrder: ";
    inOrder(ans);
    cout << endl;
    cout << "PostOrder: ";
    postOrder(ans);
    cout << endl;

    // cout<<endl;
    // cout<<"LL: ";
    // printLinkedList(head);
    // cout<<endl;

    return 0;
}