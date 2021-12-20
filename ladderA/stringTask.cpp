#include<bits/stdc++.h>

using namespace std;

bool isVowel(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y')
        return true;
    return false;
}

int main(){
    // ifstream cin("stringTask.txt");
    // if(cin.fail())
    // cout<<"Input from file failed";
    string petya;
    cin>>petya;
    transform(petya.begin(), petya.end(), petya.begin(), ::tolower);
    for(int i=0;i<petya.size();i++){
        if(isVowel(petya[i]))
            petya.erase(i,1);
    }
    for(int i=0;i<petya.size();i++){
        if(!isVowel(petya[i]))
            cout<<"."<<petya[i];
    }
    cout<<endl;
    // cin.close();
    return 0;
}