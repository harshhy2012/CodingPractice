#include<bits/stdc++.h>

using namespace std;

class Stack2{
    int size;
    int top1;
    int top2;
    int*arr;  

    Stack2(int size){
        arr = new int[size];
        top1 = -1;
        top2 = size+1;
        this->size = size;
    }

    void push1(int data){
        if(top2 - top1 == 1){
            top1++;
            arr[top1] = data;
        } else{
            cout<<"OverFlow\n";
        }
    }
    
    void push2(int data){
        if(top2 - top1 ==1){
            top2--;
            arr[top2] = data;
        } else{
            cout<<"OverFlow\n";
        }
    }

    void pop1(){
        if(top1!=-1){
            top1--;
        } else{
            cout<<"UnderFlow\n";
        }
    }
    
    void pop2(){
        if(top2==size+1){
            cout<<"UnderFlow\n";
        } else{
            top2++;
        }
    }

};

int main(){
    
    return 0;
}





