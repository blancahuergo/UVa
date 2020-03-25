#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int newlock(int A, int B) {
	return (A+B)%10000;
}

int main() {
	int t = 1;
	bool found;
	int L, U, R, S, RV, newL;
	vector<int> buttons;
	unordered_set<int> visited;
	unordered_map<int, int> dist;
	while(cin >> L >> U >> R) {
		if (!(L||U||R)) break;
		buttons.clear();
		for (int r = 0; r < R; r++) {
			cin >> RV;
			buttons.push_back(RV);
		}
		queue<int> Q;
		Q.push(L);
		visited.clear();
		visited.insert(L);
		found = false;
		dist[L] = 0;
		while(!Q.empty()) {
			S = Q.front();
			if (S == U) {
				found = true;
				break;
			}
			Q.pop();
			for (int i = 0; i < R; i++) {
				newL = newlock(S, buttons[i]);
				if (visited.find(newL) == visited.end()) {
					Q.push(newL);
					visited.insert(newL);
					dist[newL] = dist[S]+1;
				}
			}
		}
		cout << "Case " << t << ": ";
		if (found) cout << dist[U] << "\n";
		else cout << "Permanently Locked\n";
		t++;
	}
	return 0;
}
