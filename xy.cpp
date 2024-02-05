#include <iostream>
using namespace std;

// class Shape {
//     public:
//         virtual double area() = 0;
//         virtual void display() = 0;
// };

// class Rectangle : public Shape {
//     private:
//         double length;
//         double width;
//     public:
//         Rectangle(double l, double w) {
//             length = l;
//             width = w;
//         }
//         double area() {
//             return length * width;
//         }
//         void display() {
//             cout << "Rectangle with length " << length << " and width " << width << endl;
//         }
// };

//Function to check that expression is balanced or not
bool isBalanced(string expr)
{
    // Initialising Variables
    bool flag = true;
    int count = 0;
  
    // Traversing the Expression
    for (int i = 0; i < expr.length(); i++) {
  
        if (expr[i] == '{') {
            count++;
        }
        else {
            // It is a closing bracket
            count--;
        }
        if (count < 0) {
            // This means there are more Closing brackets
            // than opening ones
            flag = false;
            break;
        }
    }
  
    // If count is not zero,
    // It means there are
    // more opening brackets
    if (count != 0) {
        flag = false;
    }
  
    return flag;
}
 
 
//Recursive Function for finding 
//Number of reversals
void recur(string expr,int n,int ind,int change,int &ans){
    //When generated expression is balanced
    if(isBalanced(expr)){ans=min(ans,change);}
     
    //When we covered whole string
    if(ind==n){return;}
     
    //Keep bracket as it is
    recur(expr,n,ind+1,change,ans);
     
    //Reverse the bracket
    if(expr[ind]=='{'){expr[ind]='}';}
    else{expr[ind]='{';}
    recur(expr,n,ind+1,change+1,ans);
}
 
 
 
 
// Returns count of minimum reversals for making
// expr balanced. Returns -1 if expr cannot be
// balanced.
int countMinReversals(string expr)
{
    //Length of expression
    int n = expr.length();
     
    //To store answer
    int ans=INT_MAX;
     
    //When total number of brackets are odd
    if(n%2==1){
        return -1;
    }else{
        //Function call for finding answer
        recur(expr,n,0,0,ans);
        return ans;
    }
}
 

int main() {
    string s;
    cin>>s;

    cout<<countMinReversals(s)<<endl;

}