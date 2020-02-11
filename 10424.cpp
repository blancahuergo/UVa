#include <iostream>
#include <iomanip>
using namespace std;

int calc(string s) {
	int tot = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			tot += (int(s[i])+1-int('A'));
		} else if (s[i] >= 'a' && s[i] <= 'z') {
			tot += (int(s[i])+1-int('a'));
		}
	}
	string k;
	while(true) {
		k = to_string(tot);
		tot = 0;
		for (int u = 0; u < k.length(); u++) {
			tot += k[u] - '0';
		}
		if (tot == tot % 10) {
			break;
		}
	}
	return tot;
}

int main() {
	string first, sec;
	int a, b;
	double res;
	while(getline(cin, first)) {
		getline(cin, sec);
		a = calc(first);
		b = calc(sec);
		res = (100*min(a, b))/(double)max(a, b);
		cout << fixed << setprecision(2) << res << " %" << endl;
	}
	return 0;
}
