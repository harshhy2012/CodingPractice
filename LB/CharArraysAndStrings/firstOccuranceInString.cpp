#include<bits/stdc++.h>

using namespace std;

int firstOcc(string haystack, string needle){
    if(needle.size()> haystack.size())
            return -1;
    if(needle.size() == haystack.size())
        if(haystack == needle)
            return 0;
        else
            return -1;
        
int winSize = needle.size()-1;
    int i=0, j = i+winSize;
    
    while(i<haystack.size() && j<haystack.size()){
        if(haystack[i] == needle[0] && haystack[j] == needle[winSize]){
            bool found = true;
            if(i==j){
                return i;
            }
            for(int x = i+1;x<j;x++){
                if(haystack[x]!=needle[x-i])
                    found = false;
            }
            if(found)
                return i;
        }
        i++;j++;
    }
    return -1;
}

int main(){
    string s,x;
    cin>>s>>x;
    cout<<firstOcc(s,x)<<endl;
    return 0;
}