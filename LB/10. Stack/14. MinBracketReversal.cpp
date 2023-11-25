#include<bits/stdc++.h>

using namespace std;

bool isBalanced(string s){
    bool flag = true;
    int count=0;
    
    for(int i=0;i<s.size();i++){
        if(s[i] == '{')
            count++;
        else    
            count--;
        
        if(count<0){
            flag = false;
            break;
        }
    }

    if(count!=0){
        flag = false;
    }
    return flag;
}

void recFunc(string s, int iter, int change, int&ans){
    if(isBalanced(s)){
        ans = min(ans, change);
    }
    if(iter == s.size()){
        return;
    }

    recFunc(s, iter+1, change, ans);

    if(s[iter]=='{'){
        s[iter] = '}';
    } else{
        s[iter] = '{';
    }

    recFunc(s, iter+1, change+1, ans);
}

int minBracketRev(string s){
  
    int iter = 0;
    int change = 0;
    int ans = INT_MAX;
  
    if(s.size()&1){
        return -1;
    } else{
        recFunc(s, iter, change, ans);
    }
    return ans;
}

int minBracketRev2(string s){
    stack<char> st;
    int ans = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='{'){
            st.push('{');
        } else{
            if(!st.empty()){
                st.pop();
            } else{
                st.push('{');
                ans++;
            }
        }
    }
    if(st.size()%2!=0){
        return -1;
    } 
    ans+=st.size()/2;

    return ans;
}

int main(){
    string s;
    cin>>s;

    cout<<minBracketRev2(s)<<endl;

    return 0;
}