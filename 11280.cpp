#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<pair<int, long long>>> adj_list;
unordered_map<string, int> dict;
vector<vector<long long>> dist;
long long plusINF = 2000000000000000, minusINF = -2000000000000000;

void BellmanFord(int N, int x) {
	vector<long long> empt1(x+1, plusINF);
	dist.assign(N, empt1); // dist[U][edges]
	dist[dict["Calgary"]][0] = 0LL;
	for(int i = 0; i < N-1; i++) {
		for (int u = 0; u < N; u++) {
			for (int j = 0; j < adj_list[u].size(); j++) {
				pair<int, long long> v = adj_list[u][j];
				for (int ed = 0; ed < x; ed++) {
					if (dist[u][ed] != plusINF && dist[u][ed] + v.second < dist[v.first][ed+1]) {
						dist[v.first][ed+1] = dist[u][ed] + v.second;
					}
				}
			}
		}
	}
	long long ans = plusINF;
	int D = dict["Fredericton"];
	for (int i = 1; i <= x; i++) ans = min(ans, dist[D][i]);
	if (ans != plusINF) cout << "Total cost of flight(s) is $" << ans << "\n";
	else cout << "No satisfactory flights\n";
}

int main() {
	int T, N, M, C, Q, x;
	string name, A, B;
	vector<pair<int, long long>> empt;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		adj_list.assign(N, empt);
		dict.clear();
		for (int n = 0; n < N; n++) {
			cin >> name;
			dict[name] = n;
		}
		cin >> M;
		while(M--) {
			cin >> A >> B >> C;
			adj_list[dict[A]].push_back({dict[B], C});
		}
		cin >> Q;
		if (t > 1) cout << "\n";
		cout << "Scenario #" << t << "\n";
		while(Q--) {
			cin >> x;
			BellmanFord(N, x+1);
		}
	}
	return 0;
}
