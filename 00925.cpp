#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T, N, M, numPre, plusINF = 1000000000;
	unordered_map<string, int> dict;
	unordered_map<int, string> dict_inv;
	vector<string> courses;
	string course, prereq;
	cin >> T;
	while(T--) {
		cin >> N;
		dict.clear();
		dict_inv.clear();
		courses.clear();
		for (int n = 0; n < N; n++) {
			cin >> course;
			dict[course] = n;
			dict_inv[n] = course;
			courses.push_back(course);
		}
		int adj_matrix[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) adj_matrix[i][i] = 0;
				else adj_matrix[i][j] = plusINF;
			}
		}
		cin >> M;
		while(M--) {
			cin >> course >> numPre;
			while(numPre--) {
				cin >> prereq;
				adj_matrix[dict[prereq]][dict[course]] = 1;
			}
		}
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k] + adj_matrix[k][j]);
				}
			}
		}
		sort(courses.begin(), courses.end());
		int count, cur;
		vector<string> seq;
		bool skip;
		for (int u = 0; u < N; u++) {
			cur = dict[courses[u]];
			count = 0;
			seq.clear();
			for (int i = 0; i < N; i++) {
				if (adj_matrix[i][cur] == plusINF || i == cur) continue;
				skip = false;
				for (int j = 0; j < N; j++) {
					if (i == j || adj_matrix[j][cur] == plusINF || j == cur) continue;
					if (adj_matrix[i][j] != plusINF) {
						skip = true;
					}
				}
				if (!skip) {
					count++;
					seq.push_back(dict_inv[i]);
				}
			}
			if (count == 0) continue;
			sort(seq.begin(), seq.end());
			cout << courses[u] << " " << count;
			for (int i = 0; i < seq.size(); i++) cout << " " << seq[i];
			cout << "\n";
		}
	}
	return 0;
}
