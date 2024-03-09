#include<bits/stdc++.h>

using namespace std;


void printQueue(queue<char> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

string firstNonRepeating(string&s){
    int n = s.size();
    queue<char> q;

    string ans = "";
    vector<int> count(26,0);
    for(int i=0;i<n;i++){
        q.push(s[i]);
        count[s[i]-'a']++;

        while(!q.empty()){
            if(count[s[q.front()]-'a']>1){
                q.pop();
            }
            else{
                ans+=q.front();
                break;
            }
        }
        printQueue(q);  

        if(q.empty()){
            ans+='#';
        }
        
    }
    return ans;
}

int main(){
    string s;
    cin>>s;

    cout<<firstNonRepeating(s)<<endl;
    return 0;
}