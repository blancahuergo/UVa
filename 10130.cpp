#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int cases, N, G, maxW, familyVal;
	cin >> cases;
	for (int u = 0; u < cases; u++) {
		cin >> N;
		int values[N], weights[N];
		for (int n = 0; n < N; n++) {
			cin >> values[n] >> weights[n];
		}
		cin >> G;
		familyVal = 0;
		for (int g = 0; g < G; g++) {
			cin >> maxW;
			int DP[N+1][maxW+1];
			memset(DP, 0, sizeof DP);
			for (int obj = 0; obj < N; obj++) {
				for (int w = 0; w <= maxW; w++) {
					if (w >= weights[obj]) {
						DP[obj+1][w] = max(DP[obj][w], DP[obj][w - weights[obj]] + values[obj]);
						if (w > 0)
							DP[obj+1][w] = max(DP[obj+1][w], DP[obj+1][w-1]);
					} else {
						if (w > 0)
							DP[obj+1][w] = max(DP[obj][w], DP[obj+1][w-1]);
						else
							DP[obj+1][w] = DP[obj][w];
					}
				}
			}
			familyVal += DP[N][maxW];
		}
		cout << familyVal << endl;
	}
	return 0;
}
