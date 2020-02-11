#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	int n, m, cur, pos;
	unordered_map<int, vector<int>> occs;
	while(cin >> n) {
		cin >> m;
		for (int i = 1; i <= n; i++) {
			cin >> cur;
			if (occs.find(cur) != occs.end()) {
				occs[cur].push_back(i);
			} else {
				vector<int> v;
				v.push_back(i);
				occs[cur] = v;
			}
		}
		for(int j = 0; j < m; j++) {
			cin >> pos >> cur;
			pos--;
			if (occs.find(cur) == occs.end() || pos >= occs[cur].size()) {
				cout << "0" << endl;
			} else {
				cout << occs[cur][pos] << endl;
			}
		}
	}
	return 0;
}
