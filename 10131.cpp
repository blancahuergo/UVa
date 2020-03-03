#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool custom_sort(vector<int> a, vector<int> b) {
	return (a[0] < b[0]) || (a[0] == b[0] && a[1] > b[1]);
}

void longest(vector<vector<int>> E) {
	int LIS[E.size()], cur_max, tot_max=1, predec[E.size()], max_ind = 0;
	LIS[0] = 1;
	predec[0] = 0;
	for (int i = 1; i < E.size(); i++) {
		cur_max = 1;
		predec[i] = i;
		for (int j = 0; j < i; j++) {
			if (E[i][1] < E[j][1] && E[i][0] > E[j][0] && cur_max < LIS[j]+1) {
				cur_max = LIS[j]+1;
				predec[i] = j;
			}
		}
		LIS[i] = cur_max;
		if (LIS[i] > tot_max) {
			tot_max = LIS[i];
			max_ind = i;
		}
	}
	stack<int> final_ls;
	int ind = max_ind;
	final_ls.push(max_ind);
	while (ind != predec[ind]) {
		ind = predec[ind];
		final_ls.push(ind);
	}
	cout << final_ls.size() << endl;
	while(!final_ls.empty()) {
		cout << E[final_ls.top()][2] << endl;
		final_ls.pop();
	}
}

int main() {
	int num1, num2;
	vector<vector<int>> elephants;
	int i = 1;
	while(cin >> num1 >> num2) {
		elephants.push_back({num1, num2, i});
		i++;
	}
	sort(elephants.begin(), elephants.end(), custom_sort);
	longest(elephants);
	return 0;
}
