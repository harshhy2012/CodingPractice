#include<bits/stdc++.h>

using namespace std;

string add2NumInArray(vector<int> arr1, vector<int> arr2){
    int i=arr1.size()-1, j=arr2.size()-1;
    int carry = 0;
    string ans="";
    while(i>=0 && j>=0){
        int x = arr1[i]+arr2[j]+carry;
        int digit = x%10;
        char c = digit+'0';
        ans.push_back(c);
        carry = x/10;
        i--;j--;
         cout<<ans<<endl;
    }
    while(i>=0){
        int x = arr1[i]+carry;
        int digit = x%10;
        char c = digit+'0';
        ans.push_back(c);
        carry = x/10;
        i--;
    }
    while(j>=0){
        int x = arr2[j]+carry;
        int digit = x%10;
        char c = digit+'0';
        ans.push_back(c);
        carry = x/10;
        j--;
    }
    while(ans[ans.size()-1]=='0'){
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main(){
    vector<int> arr = {0,9,0,0,3,5}, brr = {2,2,7};
    cout<<add2NumInArray(arr,brr); 
    return 0;
}