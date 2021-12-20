#include<bits/stdc++.h>

using namespace std;

void rotateby90(vector<vector<int>>&img){
    for(int i=0;i<img.size();i++){
        for(int j=0;img[i].size();i++){

        }
    }
}

void trasnposeAndMirror(vector<vector<int>>&img){
    for(auto &i: img){
        reverse(i.begin(), i.end());
    }
    for(auto i: img){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<img.size();i++){
        for(int j=i;j<img[i].size();j++){
            int temp = 0;
            temp = img[i][j];
            img[i][j] = img[j][i];
            img[j][i] = temp;
        }
    }
}

int main(){
    ifstream cin("imageRotate.txt");
    if(cin.fail())
    cout<<"Input from file failed";
    int n,m;
    cin>>n>>m;
    vector<vector<int>> img(n, vector<int> (m));
    for(auto &i: img){
        for(auto &j: i){
            cin>>j;
        }
    }
    trasnposeAndMirror(img);
    for(auto i: img){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    vector<int> arr;
    cout<<arr.max_size()<<endl;

    cin.close();
    return 0;
}