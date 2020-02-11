#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	long long a, b;
	while(scanf("%lld %lld", &a, &b) != EOF) {
		if (b > a) cout << b-a << endl;
		else cout << a-b << endl;
	}
	return 0;
}
