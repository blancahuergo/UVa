#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int C, S;
	double aver, dif;
	vector<int> B;
	int t = 1;
	while(scanf("%d", &C) != EOF) {
		scanf("%d", &S);
		B.assign(2*C, 0);
		aver = 0;
		for (int s = 0; s < S; s++) {
			scanf("%d", &B[s]);
			aver += B[s];
		}
		aver /= C;
		sort(B.begin(), B.end());
		printf("Set #%d\n", t++);
		dif = 0;
		for (int i = 0; i < C; i++) {
			printf(" %d:", i);
			if (B[i]) printf(" %d", B[i]);
			if (B[2*C - i - 1]) printf(" %d", B[2*C - i - 1]);
			printf("\n");
			dif += abs(aver - (B[i] + B[2*C - i - 1]));
		}
		printf("IMBALANCE = %.5lf\n\n", dif);
	}
	return 0;
}
