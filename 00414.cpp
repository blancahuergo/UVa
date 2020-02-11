#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, l, r, min_dist, cur_dist, total;
	string line;
	vector<int> space;
	while(true) {
		cin >> n;
		if (!n) break;
		min_dist = 26;
		space.clear();
		cin.ignore();
		for (int i = 0; i < n; i++) {
			getline(cin, line);
			cur_dist = 0;
			for (int l = 0; l < line.length(); l++) {
				if (line[l] != 'X') cur_dist++;
			}
			space.push_back(cur_dist);
			if (cur_dist < min_dist) min_dist = cur_dist;
		}
		total = 0;
		for (int i = 0; i < n; i++) {
			total += (space[i] - min_dist);
		}
		cout << total << endl;
	}
	return 0;
}
