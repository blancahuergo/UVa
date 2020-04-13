#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> C;
string varA, varB;
int pow;

long long comb(int n, int r) {
	if (n == 0 || r == 0 || n == r) return 1;
	if (C[n][r] != -1) return C[n][r];
	long long ans = comb(n-1, r-1) + comb(n-1, r);
	return C[n][n-r] = C[n][r] = ans;
}

void process(string line) {
	int i = 1;
	varA = "";
	while(line[i] != '+') {
		varA += line[i];
		i++;
	}
	i++;
	varB = "";
	while(line[i] != ')') {
		varB += line[i];
		i++;
	}
	i += 2;
	pow = stoi(line.substr(i));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	C.assign(51, vector<long long>(51, -1));
	int T;
	long long coef;
	cin >> T;
	string line;
	for (int t = 1; t <= T; t++) {
		cin >> line;
		process(line);
		cout << "Case " << t << ": ";
		for (int p = pow; p >= 0; p--) {
			if (p < pow) cout << "+";
			coef = comb(pow, p);
			if (coef > 1) cout << coef;
			if (p > 0) {
				if (coef > 1) cout << '*';
				cout << varA;
				if (p > 1) cout << "^" << p;
			}
			if (pow - p > 0) {
				if (p > 0) cout << '*';
				cout << varB;
				if (pow - p > 1) cout << "^" << pow-p;
			}
		}
		cout << '\n';
	}
	return 0;
}
