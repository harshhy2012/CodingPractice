#include<bits/stdc++.h>

using namespace std;

class node{
    public:
        char letter;
        int count;

        node(char l, int c){
            this->letter = l;
            this->count = c;
        }
};

class compare{
    public:
        bool operator()(node a, node b){
            return a.count < b.count;
        }
};

string longestDiverseString(int a, int b, int c) {
    string ans = "";
    priority_queue<node, vector<node>, compare> maxHeap;
    node n1('a', a),n2('b', b),n3('c', c);
    if(a>0)maxHeap.push(n1);if(b>0)maxHeap.push(n2);if(c>0)maxHeap.push(n3);
    while(maxHeap.size()>1){
        node first = maxHeap.top();
        maxHeap.pop();
        node second = maxHeap.top();
        maxHeap.pop();
        ans+=first.letter;
        first.count--;
        if(first.count>=1){
            ans+=first.letter;
            first.count--;
        }
        ans+=second.letter;
        second.count--;
        if(second.count>=1){
            ans+=second.letter;
            second.count--;
        }
        if(first.count>0){
            maxHeap.push(first);
        }
        if(second.count>0){
            maxHeap.push(second);
        }
        // cout<<endl<<ans<<endl;
    }

    if(maxHeap.size()==1){
        node top = maxHeap.top();
        ans+=top.letter;
        top.count--;
        if(top.count>=1){
            ans+=top.letter;
            top.count--;
        }
    }
    return ans;

}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<longestDiverseString(a,b,c)<<endl;
    return 0;
}