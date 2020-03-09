#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

vector<vector<int>> boxes;

bool compareVecs(vector<int> first, vector<int> second) {
	for (int i = 0; i < first.size(); i++) {
		if (first[i] < second[i]) return true;
		else if (first[i] > second[i]) return false;
	}
	return true;
}

int comp(int i, int j, int N) {
	// returns 1 if boxes[i] fits in boxes[j]
	// returns 2 if boxes[j] fits in boxes[i]
	// returns 3 if otherwise
	if (boxes[i][0] < boxes[j][0]) {
		for (int n = 1; n < N; n++) {
			if (boxes[i][n] >= boxes[j][n]) return 3;
		}
		return 1;
	} else if (boxes[j][0] < boxes[i][0]) {
		for (int n = 1; n < N; n++) {
			if (boxes[j][n] >= boxes[i][n]) return 3;
		}
		return 2;
	} else return 3;
}

void LIS(int N, int K) {
	int predec[K], max_seq=1, max_ind=0, cur_max, LIS[K], comparation;
	LIS[0] = 1;
	predec[0] = 0;
	for (int i = 1; i < K; i++) {
		cur_max = 1;
		predec[i] = i;
		for (int j = 0; j < i; j++) {
			comparation = comp(j, i, N);
			if (comparation == 1 && LIS[j]+1 >= cur_max) {
				predec[i] = j;
				cur_max = LIS[j]+1;
			}
		}
		LIS[i] = cur_max;
		if (cur_max > max_seq) {
			max_seq = LIS[i];
			max_ind = i;
		}
	}
	stack<int> indices;
	int ind = max_ind;
	indices.push(boxes[ind].back());
	while(predec[ind] != ind) {
		ind = predec[ind];
		indices.push(boxes[ind].back());
	}
	cout << indices.size() << endl;
	cout << indices.top();
	indices.pop();
	while(!indices.empty()) {
		cout << " " << indices.top();
		indices.pop();
	}
	cout << "\n";
}

int main() {
	int K, N, c;
	vector<int> cur;
	while(cin >> K >> N) {
		boxes.clear();
		for (int k = 0; k < K; k++) {
			cur.assign(N, 0);
			for (int n = 0; n < N; n++) {
				cin >> c;
				cur[n] = c;
			}
			sort(cur.begin(), cur.end());
			cur.push_back(k+1);
			boxes.push_back(cur);
		}
		sort(boxes.begin(), boxes.end(), compareVecs);
		LIS(N, K);
	}
	return 0;
}
