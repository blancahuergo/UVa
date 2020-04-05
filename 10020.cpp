#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T, M, A, B;
	vector<pair<int, int>> pairs;
	vector<int> used;
	cin >> T;
	while(T--) {
		cin >> M;
		pairs.clear();
		while(true) {
			cin >> A >> B;
			if (!(A||B)) break;
			pairs.push_back(make_pair(A, B));
		}
		sort(pairs.begin(), pairs.end());
		used.clear();
		int cur=0, nxt, i = 0, ind;
		while(cur < M) {
			nxt = cur;
			while(i < (int) pairs.size()) {
				if (pairs[i].first > cur) break;
				if (pairs[i].second > nxt) {
					nxt = pairs[i].second;
					ind = i;
				}
				i++;
			}
			if (nxt == cur) {
				used.clear();
				break;
			}
			used.push_back(ind);
			cur = nxt;
		}
		cout << used.size() << "\n";
		for (int i = 0; i < (int) used.size(); i++) {
			cout << pairs[used[i]].first << " " << pairs[used[i]].second << "\n";
		}
		if (T) cout << "\n";
	}
	return 0;
}
