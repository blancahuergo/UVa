#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long find_n(long k, long d) {
	long tot = 0;
	long coe = 1;
	while(true) {
		tot += d*coe;
		if (tot >= k) break;
		coe++;
	}
	return coe;
}

int main() {
	int cas, deg;
	long d, k;
	double n;
	vector<int> coefs;
	cin >> cas;
	while(cas--) {
		cin >> deg;
		coefs.clear();
		coefs.assign(deg+1, 0);
		for (int u = 0; u <= deg; u++) {
			cin >> coefs[u];
		}
		cin >> d;
		cin >> k;
		n = find_n(k, d);
		long val = 0;
		for (int h = 0; h <= deg; h++) {
			val += pow(n, h)*coefs[h];
		}
		cout << val << endl;
	}
	return 0;
}
