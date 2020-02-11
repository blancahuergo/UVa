#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, max_r, rank;
	string web;
	vector<string> webs;
	cin >> N;
	for (int u = 0; u < N; u++) {
		webs.clear();
		max_r = -1;
		for (int i = 0; i < 10; i++) {
			cin >> web >> rank;
			if (rank > max_r) {
				webs.clear();
				webs.push_back(web);
				max_r = rank;
			} else if (rank == max_r) {
				webs.push_back(web);
			}
		}
		cout << "Case #" << u+1 << ":" << endl;
		for (int i = 0; i < webs.size(); i++) {
			cout << webs[i] << endl;
		}
	}
	return 0;
}
