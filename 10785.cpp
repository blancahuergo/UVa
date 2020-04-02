#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string name(int N) {
	char vowels[] = {'A', 'U', 'E', 'O', 'I'};
	char cons[] = {'J', 'S', 'B', 'K', 'T', 'C', 'L', 'D', 'M', 'V', 'N', 'W', 'F', 'X', 'G', 'P', 'Y', 'H', 'Q', 'Z', 'R'};
	vector<char> vUsed, cUsed;
	int curV=0, curVC=0, curC=0, curCC=0;
	bool V;
	string name = "";
	V = true;
	int n = 0;
	while(n < N) {
		if (V) {
			vUsed.push_back(vowels[curV]);
			curVC++;
			if (curVC == 21) {
				curV++;
				curVC = 0;
			}
		} else {
			cUsed.push_back(cons[curC]);
			curCC++;
			if (curCC == 5) {
				curC++;
				curCC = 0;
			}
		}
		V = !V;
		n++;
	}
	sort(vUsed.begin(), vUsed.end());
	sort(cUsed.begin(), cUsed.end());
	for (int i = 0; i < (int) (vUsed.size() + cUsed.size()); i++) {
		if (i % 2 == 0) {
			name += vUsed[i/2];
		} else name += cUsed[i/2];
	}
	return name;
}

int main() {
	int T, N;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		cout << "Case " << t << ": " << name(N) << "\n";
	}
	return 0;
}
