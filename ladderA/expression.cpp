#include<bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    
    int ans=INT_MIN;

    vector<int> answers;

    answers.push_back(a+b+c);
    answers.push_back((a+b)*c);
    answers.push_back(a*(b+c));
    answers.push_back((a*b)+c);
    answers.push_back(a+(b*c));
    answers.push_back(a*b*c);

    for(int i=0;i<answers.size();i++){
        if(ans<answers[i])
            ans = answers[i];
    }

    cout<<ans<<endl;

    return 0;
}