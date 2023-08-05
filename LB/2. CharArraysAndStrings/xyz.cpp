#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n) {
	vector<bool> prime(n,true);
    prime[0] = prime[1] = false;
	for (int p = 2; p * p <= n; p++) {
		if (prime[p]) {
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	for (int p = 2; p <= n; p++)
		if (prime[p])
			cout << p << " ";
}

int find(int x, int *py, int **ppz){
	int y, z;
	**ppz += 1;
	z = **ppz;
	*py += 2;
	y = *py;
	x+=3;
	return x + y + z;
}

int main() {
	// int n = 50;
	// SieveOfEratosthenes(n);
	int c, *b, **a;
	c = 4;
	b = &c;
	a = &b;
	cout<<find(c, b, a);
	return 0;
}