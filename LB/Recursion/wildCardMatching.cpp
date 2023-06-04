#include<bits/stdc++.h>

using namespace std;

bool isMatchHelper(string& s, string& p, int si, int pi){
    if(si == s.size() && pi == p.size())
        return true;
    if(si == s.size() && pi < p.size()){
        while(pi<p.size()){
            if(p[pi]!='*'){
                return false;
            }
            pi++;
        }
        return true;
    }

    if(s[si] == p[pi] || p[pi] == '?'){
        return isMatchHelper(s,p,si+1, pi+1);
    }

    if(p[pi] == '*'){
        
        // * consumes null character
        bool case1 = isMatchHelper(s,p,si+1, pi);
        bool case2 = isMatchHelper(s,p,si,pi+1);

        return case1 || case2;
    }
    return false;
}

bool isMatch(string s, string p){
    int si = 0, pi = 0;

    return isMatchHelper(s, p, si, pi);
}

int main(){
    string s,p;
    cin>>s>>p;

    if(isMatch(s,p)){
        cout<<"MATCHED\n";
    }
    else{
        cout<<"NOT FOUND!\n";
    }

    return 0;
}