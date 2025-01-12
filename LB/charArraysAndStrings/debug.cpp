#include<bits/stdc++.h>

using namespace std;

char *removeDuplicate(char str[], int n) {
  // str is character array and n is the lenght of the character array
	int index = 0;
	for (int i=0; i<n; i++) {
		int j;
		for (j=0; j<i; j++)
			if (str[i] == str[j])
				break;
                if(i == j) str[index++] = str[j];
	}

	cout<<str<<endl;
	return str;
}

int main(){
    int n;
    cin>>n;
    char s[100];
    cin.getline(s, n);
    char * str = removeDuplicate(s, n);
    cout<<str<<endl;
    return 0;
}