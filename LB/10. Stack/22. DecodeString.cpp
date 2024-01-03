#include<bits/stdc++.h>

using namespace std;

void print(stack<char> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

bool onlyChar(stack<char> st){
    if(st.empty())
        return false;
    while(!st.empty()){
        if(st.top()<'a' && st.top()>'z')
            return false;
        st.pop();
    }
    return true;
}

int getNum(string&s){
    reverse(s.begin(),s.end());
    int num = 0;
    for(auto ch: s){
        int dig = ch-'0';
        num+=dig;
        num*=10;
    }
    return num/10;
} 

string genAns(int n, string part){
    reverse(part.begin(), part.end());
    cout<<"PART: "<<part<<" || num: "<<n<<endl;
    string ret = "";
    for(int i=0;i<n;i++){
        ret+=part;
    }
    if(n==0){
        ret+=part;
    }
    return ret;
}

string decodeString(string&s) {
    stack<char> st;
    string part = "", num = "", ans = "", finAns;
    for(auto ch: s){
        if(ch==']'){
            while(!st.empty() && !(st.top()>='0' && st.top()<='9')){
                if(st.top()!='[')
                    part.push_back(st.top());
                st.pop();
            }
            while((!st.empty() && st.top()>='0' && st.top()<='9')){
                cout<<st.top()<<endl;
                num.push_back(st.top());
                st.pop();
            }

            int n = getNum(num);
            
            ans+=genAns(n, part);

            if(st.empty() || onlyChar(st)){
                finAns += genAns(n, part);
            }

            part = ""; num = "";

            if(!st.empty())
                for(auto newCh: ans)
                    st.push(newCh);
                
        } else{
            st.push(ch);
        }
        
    // cout<<ans<<endl;
    }
    if(onlyChar(st)){
            string end = "";
            while(!st.empty()){
                end.push_back(st.top());
                st.pop();
            }
            reverse(end.begin(), end.end());
            finAns+=end;
        }
    return finAns ;
}

int main(){
    string encode;
    cin>>encode;
    cout<<decodeString(encode)<<endl;
    return 0;
}