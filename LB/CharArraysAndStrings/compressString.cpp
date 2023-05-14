#include<bits/stdc++.h>

using namespace std;

int revNum(int x){
    int ans = 0;
    while(x){
        int dig = x%10;
        ans+=dig;
        ans*=10;
        x/=10;
    }
    return ans/10;
}

int compress(vector<char> &chars){
    int n = chars.size();
    int count = 1;
    int i=1;
    while(i<chars.size()){
        if(chars[i-1]==chars[i])
            count++;
        else{
            if(count>1){
                chars.erase(chars.begin()+i-count+1, chars.begin()+i);
                int x = i;
                count = revNum(count);
                while(count>0){
                    int dig = count%10;
                    chars.insert(chars.begin()+x, count+'0');
                    x++;
                    count/=10;
                }
                count = 1;
            }
        }
    }
    int maxE = INT_MIN;
    int num = 0;
    for(int i=0;i<chars.size();i++){
        
        if(chars[i] >= '0' && chars[i] <= '9'){
            num+=chars[i]-'0';
            num*=10;
        }
        else{
            maxE = max(num/10, maxE);
            num = 0;
        }
    }
    return maxE;
}

int main(){
    int n;
    cin>>n;
    vector<char> chars(n);
    for(auto &ch: chars){
        cin>>ch;
    }
    cout<<compress(chars)<<endl;

    return 0;
}