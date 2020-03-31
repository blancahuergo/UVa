#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	int NC, NE, c, NM, plusINF = 1000000000;
	string last, cur;
	vector<pair<int, int>> edges, conc;
	unordered_map<string, int> dict;
	unordered_map<int, string> dict_inv;
	int t = 1;
	while(true) {
		cin >> NC;
		if (!NC) break;
		edges.clear();
		dict.clear();
		c = 0;
		for (int n = 0; n < NC; n++) {
			cin >> NE;
			cin >> last;
			if (dict.find(last) == dict.end()) {
				dict[last] = c;
				dict_inv[c] = last;
				c++;
			}
			NE--;
			while(NE--) {
				cin >> cur;
				if (dict.find(cur) == dict.end()) {
					dict[cur] = c;
					dict_inv[c] = cur;
					c++;
				}
				edges.push_back({dict[last], dict[cur]});
				last = cur;
			}
		}
		cin >> NM;
		while(NM--) {
			cin >> last >> cur;
			edges.push_back({dict[last], dict[cur]});
		}
		int adj_matrix[c][c];
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < c; j++) {
				adj_matrix[i][j] = plusINF;
			}
			adj_matrix[i][i] = 0;
		}
		for (int i = 0; i < (int) edges.size(); i++) adj_matrix[edges[i].first][edges[i].second] = 1;
		for (int k = 0; k < c; k++) {
			for (int i = 0; i < c; i++) {
				for (int j = 0; j < c; j++) {
					adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k]+adj_matrix[k][j]);
				}
			}
		}
		conc.clear();
		for (int i = 0; i < c; i++) {
			for (int j = i+1; j < c; j++) {
				if (adj_matrix[i][j] == plusINF && adj_matrix[j][i] == plusINF) conc.push_back({i, j});
			}
		}
		if (conc.size() == 0) cout << "Case " << t << ", no concurrent events.\n";
		else {
			cout << "Case " << t << ", " << conc.size() << " concurrent events:\n";
			cout << "(" << dict_inv[conc[0].first] << "," << dict_inv[conc[0].second] << ")";
			for (int i = 1; i < min(2, (int) conc.size()); i++) {
				cout << " (" << dict_inv[conc[i].first] << "," << dict_inv[conc[i].second] << ")";
			}
			cout << " \n";
		}
		t++;
	}
	return 0;
}
