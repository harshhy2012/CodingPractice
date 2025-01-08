#include<bits/stdc++.h>

using namespace std;

class ListNode{
    public:
        int data;
        ListNode*next;

        ListNode(int data){
            this->data;
            this->next = NULL;
        }
};

bool checkCircular(ListNode* head){
    unordered_map<ListNode*, bool> vis;
    ListNode*temp = head;

    while(!temp){
        if(vis.find(temp) != vis.end()){
            vis[temp] = true;
        }
        else{
            return true;
        }
    }
    return false;
}

int main(){
    
    return 0;
}