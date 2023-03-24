#include <bits/stdc++.h>

using namespace std;

bool meow(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string correct = "meow";
    int i = 0, j = 0;
    while (i < s.size() && j < correct.size())
    {
        if (s[i] == correct[j])
        {
            j++;
        }
        i++;
        if(j==s.size()-1 && s[i]!='m'){
            return false;
        }
    }
    // cout<<"j : "<<j<<endl;
    if (j == correct.size())
        return true;
    else
        return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (meow(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}