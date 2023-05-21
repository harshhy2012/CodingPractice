#include<bits/stdc++.h>

using namespace std;

int compress(vector<char> &chars){
    int count = 1, index=0;
    char prev = chars[0];
    for(int i=1;i<chars.size();i++){
        if(prev==chars[i])
            count++;
        else{
            chars[index++] = prev;
            if(count>1){
                int x = index;
                while(count>0){
                    int dig = count%10;
                    chars[index++] = char(dig+'0');
                    count/=10;
                }
                reverse(chars.begin()+x, chars.begin()+index);
            }
            prev = chars[i];
            count = 1;
        }
    }

    chars[index++] = prev;
    if(count>1){
        int x = index;
        while(count>0){
            int dig = count%10;
            chars[index++] = char(dig+'0');
            count/=10;
            }
        reverse(chars.begin()+x, chars.begin()+index);
    }
    return index;
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