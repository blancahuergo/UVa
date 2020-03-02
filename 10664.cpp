#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

int main() {
	int m, num, sum_W, max_W, bag;
	vector<int> bag_weights;
	string line;
	getline(cin, line);
	m = stoi(line);
	while(m--) {
		bag_weights.clear();
		getline(cin, line);
		istringstream is(line);
		sum_W = 0;
		while(is>>num) {
			bag_weights.push_back(num);
			sum_W += num;
		}
		if (sum_W % 2 == 1) {
			cout << "NO\n";
			continue;
		}
		max_W = sum_W / 2;
		int DP[bag_weights.size()+1][max_W+1];
		memset(DP, 0, sizeof DP);
		for (int b = 1; b <= bag_weights.size(); b++) {
			bag = bag_weights[b-1];
			for (int w = 0; w <= max_W; w++) {
				if (w >= bag) {
					DP[b][w] = max(DP[b-1][w], DP[b-1][w-bag]+bag);
					if (w > 0) DP[b][w] = max(DP[b][w], DP[b][w-1]);
				} else {
					if (w == 0) DP[b][w] = DP[b-1][w];
					else DP[b][w] = max(DP[b-1][w], DP[b][w-1]);
				}
			}
		}
		if (DP[bag_weights.size()][max_W] == max_W) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
