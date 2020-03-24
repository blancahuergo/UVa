#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj_list;

void BFS(int S, int N) {
	int rec = 0, rec_day = 0;
	vector<int> days;
	vector<int> dist;
	dist.assign(N, -1);
	dist[S] = 0;
	days.push_back(1);
	queue<int> Q;
	Q.push(S);
	while(!Q.empty()) {
		S = Q.front();
		Q.pop();
		for (int i = 0; i < adj_list[S].size(); i++) {
			if (dist[adj_list[S][i]] == -1) {
				dist[adj_list[S][i]] = dist[S]+1;
				if (days.size() == dist[S]+1)
					days.push_back(1);
				else
					days[dist[S]+1]++;
				if (days[dist[S]+1] > rec) {
					rec = days[dist[S]+1];
					rec_day = dist[S]+1;
				}
				Q.push(adj_list[S][i]);
			}
		}
	}
	if (rec == 0) cout << "0\n";
	else cout << rec << " " << rec_day << "\n";
}

int main() {
	int N, F, other, Q, S;
	vector<int> empt;
	cin >> N;
	adj_list.assign(N, empt);
	for (int n = 0; n < N; n++) {
		cin >> F;
		while(F--) {
			cin >> other;
			adj_list[n].push_back(other);
		}
	}
	cin >> Q;
	while(Q--) {
		cin >> S;
		BFS(S, N);
	}
	return 0;
}
