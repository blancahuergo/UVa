#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> dict;
unordered_map<int, string> dict_inv;
vector<vector<int>> adj_list;
vector<vector<int>> into_v;
vector<int> TS;
vector<bool> deleted;

bool source(int S) {
	if (deleted[S]) return false;
	int u;
	for (int i = 0; i < into_v[S].size(); i++) {
		u = into_v[S][i];
		if (!deleted[u]) return false;
	}
	return true;
}

int main() {
	int cas = 1, N, M;
	vector<int> empt;
	string bev, fir, sec;
	while(cin >> N) {
		adj_list.assign(N, empt);
		into_v.assign(N, empt);
		for (int n = 0; n < N; n++) {
			cin >> bev;
			dict[bev] = n;
			dict_inv[n] = bev;
		}
		cin >> M;
		for (int m = 0; m < M; m++) {
			cin >> fir >> sec;
			adj_list[dict[fir]].push_back(dict[sec]);
			into_v[dict[sec]].push_back(dict[fir]);
		}
		deleted.assign(N, false);
		int del = 0;
		TS.clear();
		while(del < N) {
			for (int i = 0; i < N; i++) {
				if (source(i)) {
					TS.push_back(i);
					deleted[i] = true;
					del++;
					break;
				}
			}
		}
		cout << "Case #" << cas << ": Dilbert should drink beverages in this order:";
		for (int l = 0; l < TS.size(); l++) {
			cout << " " << dict_inv[TS[l]];
		}
		cout << ".\n\n";
		cas++;
	}
	return 0;
}
