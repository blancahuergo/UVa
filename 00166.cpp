#include <iostream>
#include <vector>
using namespace std;

vector<int> coin_totals;
vector<int> coin_vals = {5, 10, 20, 50, 100, 200};
vector<int> posChange;
int maxSum;

void buildDP() {
	int coin;
	posChange.clear();
	maxSum = 5*coin_totals[0] + 10*coin_totals[1] + 20*coin_totals[2] + 50*coin_totals[3] + 100*coin_totals[4] + 200*coin_totals[5];
	posChange.assign(maxSum+1, 0);
	for (int i = 0; i < coin_totals.size(); i++) {
		coin = coin_vals[i];
		for (int k = 0; k < coin_totals[i]; k++) {
			for (int j = maxSum; j > coin; j--) {
				if (posChange[j-coin] > 0) {
					if (posChange[j] > 0) posChange[j] = min(posChange[j], posChange[j-coin]+1);
					else posChange[j] = posChange[j-coin]+1;
				}
			}
			posChange[coin] = 1;
		}
	}
}

int greedy(int N) {
	if (N == 0) return 0;
	int tot_coins = N/200;
	N %= 200;
	tot_coins += N/100;
	N %= 100;
	tot_coins += N/50;
	N %= 50;
	tot_coins += N/20;
	N %= 20;
	tot_coins += N/10;
	N %= 10;
	tot_coins += N/5;
	return tot_coins;
}

int calcDP(int N) {
	int cur_sum, min_tot = 2*maxSum;
	for (int j = N; j < posChange.size(); j++) {
		if (posChange[j] == 0) continue;
		cur_sum = posChange[j] + greedy(j - N);
		min_tot = min(min_tot, cur_sum);
	}
	return min_tot;
}

int main() {
	double M;
	int N;
	string ans;
	while(true) {
		coin_totals.assign(6, 0);
		cin >> coin_totals[0] >> coin_totals[1] >> coin_totals[2] >> coin_totals[3] >> coin_totals[4] >> coin_totals[5];
		if (!(coin_totals[0] || coin_totals[1] || coin_totals[2] || coin_totals[3] || coin_totals[4] || coin_totals[5])) break;
		cin >> M;
		N = M*100;
		if (N == 0) {
			cout << "0\n";
			continue;
		}
		buildDP();
		printf("%3d\n", calcDP(N));
	}
	return 0;
}
