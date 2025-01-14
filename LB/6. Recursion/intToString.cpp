#include<bits/stdc++.h>

using namespace std;

        vector<pair<int, string>> numMap = {
            {1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, {100, "Hundred"}, {90,"Ninety"}, {80, "Eighty"}, {70, "Seventy"},
            {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19,"Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"},
            {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"},
            {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}
        };

string intToString(int num){
    if(num==0){
        return "Zero";
    }
    int i=0;
    for(;i<numMap.size();i++){
        if(num>=numMap[i].first){
            string a = "";  
            if(num>=100){
                a = intToString(num/numMap[i].first)+" ";
            }
            string b = numMap[i].second;
            string c = "";
            if(num%numMap[i].first){
                c = " " + intToString(num%numMap[i].first);
            }  
            return a+b+c;
        }
    }
    return "";
}

int main(){
    int num;
    cin>>num;
    cout<<intToString(num)<<endl;
    return 0;
}