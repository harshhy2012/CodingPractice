#include<bits/stdc++.h>

using namespace std;


int countPalindrome(string s, int left, int right){
    int count = 0;
    while(left>=0 && right<=s.size()-1 && s[left] == s[right]){
        count++;
        left--;
        right++;
    }

    return count;
}


int palinSubstr(string s){
    int n = s.size();
    int oddCount = 0, evenCount = 0, finalCount = 0;

    for(int center = 0;center<=n;center++){
        oddCount += countPalindrome(s, center, center);
        evenCount += countPalindrome(s, center, center+1);
    }

    finalCount = oddCount+evenCount;
    return finalCount;
}

int main(){
    string s;
    cin>>s;
    cout<<palinSubstr(s)<<endl;
    return 0;
}