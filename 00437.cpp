#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> blocks;

bool vecComp(vector<int> v1, vector<int> v2) {
	if (v1[0] > v2[0]) return true;
	else if (v1[0] < v2[0]) return false;
	if (v1[1] > v2[1]) return true;
	else if (v1[1] < v2[1]) return false;
	if (v1[2] > v2[2]) return true;
	else return false;
}

int maxHeight() {
	int N = blocks.size();
	int maxH[N], tot_max = blocks[0][2];
	maxH[0] = blocks[0][2];
	for (int i = 1; i < N; i++) {
		maxH[i] = blocks[i][2];
		for (int j = 0; j < i; j++) {
			if (blocks[i][0] < blocks[j][0] && blocks[i][1] < blocks[j][1])
				maxH[i] = max(maxH[i], maxH[j]+blocks[i][2]);
		}
		tot_max = max(tot_max, maxH[i]);
	}
	return tot_max;
}

int main() {
	int N, a, b, c;
	int cas = 1;
	while(true) {
		cin >> N;
		if (!N) break;
		blocks.clear();
		for (int n = 0; n < N; n++) {
			cin >> a >> b >> c;
			if (a < b)
				blocks.push_back({a, b, c});
			else
				blocks.push_back({b, a, c});
			if (b < c)
				blocks.push_back({b, c, a});
			else
				blocks.push_back({c, b, a});
			if (a < c)
				blocks.push_back({a, c, b});
			else
				blocks.push_back({c, a, b});
		}
		sort(blocks.begin(), blocks.end(), vecComp);
		cout << "Case " << cas << ": maximum height = " << maxHeight() << endl;
		cas++;
	}
	return 0;
}
