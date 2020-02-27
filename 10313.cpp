#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std;

vector<vector<long long>> posChange;

void buildDP() {
	vector<long long> empty;
	empty.assign(301, 0);
	posChange.assign(301, empty);
	posChange[0][0] = 1;
	for (int coin = 1; coin <= 300; coin++) {
		for (int am = coin; am <= 300; am++) {
			for (int num_c = 1; num_c <= am; num_c++) {
				posChange[am][num_c] += posChange[am - coin][num_c - 1];
			}
		}
	}
}

int main() {
	int N, L1, L2;
	long long total;
	char inp[1000];
	int nums[3];
	buildDP();
	while(gets(inp)) {
		L2 = -1;
		L1 = -1;
		int n = 0;
		stringstream sin(inp);
		while(sin >> nums[n]) {
			n++;
		}
		N = nums[0];
		if (n == 3) {
			L2 = nums[2];
			L1 = nums[1];
		} else if (n == 2) {
			L1 = 0;
			L2 = nums[1];
		} else {
			L1 = 0;
			L2 = N;
		}
		total = 0;
		for (int i = L1; i <= min(N, L2); i++) {
			total += posChange[N][i];
		}
		cout << total << endl;
	}
	return 0;
}
