#include <iostream>
#include <vector>
#include <iomanip>
#include <unordered_map>
using namespace std;

vector<vector<int>> adj_list;
unordered_map<int, int> dict;

int main() {
	cout << fixed << setprecision(3);
	vector<int> empt;
	int A, B, plusINF = 100000000, N;
	int t = 1;
	while(true) {
		cin >> A >> B;
		if (!(A||B)) break;
		N = 0;
		adj_list.clear();
		dict.clear();
		if (dict.find(A) == dict.end()) {
			dict[A] = N;
			adj_list.push_back(empt);
			N++;
		}
		if (dict.find(B) == dict.end()) {
			dict[B] = N;
			adj_list.push_back(empt);
			N++;
		}
		adj_list[dict[A]].push_back(dict[B]);
		while(true) {
			cin >> A >> B;
			if (!(A||B)) break;
			if (dict.find(A) == dict.end()) {
				dict[A] = N;
				adj_list.push_back(empt);
				N++;
			}
			if (dict.find(B) == dict.end()) {
				dict[B] = N;
				adj_list.push_back(empt);
				N++;
			}
			adj_list[dict[A]].push_back(dict[B]);
		}
		vector<vector<int>> adj_matrix(N, vector<int>(N, plusINF));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < adj_list[i].size(); j++) {
				adj_matrix[i][adj_list[i][j]] = 1;
			}
		}
		for (int k = 0; k < N; k++) {
			adj_matrix[k][k] = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k] + adj_matrix[k][j]);
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				sum += adj_matrix[i][j];
			}
		}
		double avg = ((double) sum) / ((double) (N*(N-1)));
		cout << "Case " << t << ": average length between pages = " << avg << " clicks\n";
		t++;
	}
	return 0;
}
