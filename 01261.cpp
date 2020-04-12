#include <iostream>
#include <set>
using namespace std;

set<string> visited;
bool res;

void recur(string W) {
	if (res) return;
	if (W.length() == 0) {
		res = true;
		return;
	}
	if (visited.find(W) != visited.end()) return;
	visited.insert(W);
	int i = 0, j;
	while(i < (int) (W.length() - 1)) {
		for (j = i+1; j < (int) W.length(); j++) {
			if (W[j] != W[i]) {
				i = j;
				break;
			}
			recur(W.substr(0, i) + W.substr(j+1));
		}
		if (i == 0) {
			res = true;
			break;
		}
		if (j >= (int) W.length() - 1) break;
	}
}

int main() {
	int T;
	string W;
	cin >> T;
	while(T--) {
		cin >> W;
		res = false;
		visited.clear();
		recur(W);
		if (res) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
