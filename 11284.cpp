#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
using namespace std;

int N, cost_matrix[51][51], savings[51], DP[1<<12][12], minusINF = -0x3f3f3f3f;

vector<int> shops;

void fill_shortest() {
	for (int i = 0; i < N; i++)
	    cost_matrix[i][i] = 0;
	for (int k = 0; k < N; k++)
	    for (int i = 0; i < N; i++)
	        for (int j = 0; j < N; j++)
	            cost_matrix[i][j] = min(cost_matrix[i][j], cost_matrix[i][k] + cost_matrix[k][j]);
}

int TSP() {
	int u, v, real_N = shops.size();
	vector< pair<int, int> > masks;
	for (int i = 0; i < (1<<real_N); i++) {
	    for (int j = 0; j < real_N; j++)
	        DP[i][j] = minusINF;
	    masks.push_back(make_pair(__builtin_popcount(i), i));
	}

	int ret = minusINF;
	for (int i = 0; i < real_N; i++) {
		u = shops[i];
		DP[1<<i][i] = -cost_matrix[0][u] + savings[u];
	}
	sort(masks.begin(), masks.end());
	for (int i = 0; i < masks.size(); i++) {
		int state = masks[i].second;
		for (int j = 0; j < real_N; j++) {
		    if (DP[state][j] == minusINF) continue;
			u = shops[j];
			ret = max(ret, DP[state][j] - cost_matrix[u][0]);
			for (int k = 0; k < real_N; k++) {
				if ((state>>k)&1) continue;
		        v = shops[k];
		        DP[state|(1<<k)][k] = max(DP[state|(1<<k)][k], DP[state][j] - cost_matrix[u][v] + savings[v]);
		    }
		}
	}
	return ret;
}

int main() {
	int T, M, P, u, v, a, b;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &N, &M);
		N++;
		memset(savings, 0, sizeof savings);
		memset(cost_matrix, 0x3f, sizeof cost_matrix);
		for (int i = 0; i < M; i++) {
		    scanf("%d %d %d.%d", &u, &v, &a, &b);
		    cost_matrix[u][v] = min(cost_matrix[u][v], a * 100 + b);
		    cost_matrix[v][u] = min(cost_matrix[v][u], a * 100 + b);
		}
		scanf("%d", &P);
		while (P--) {
			scanf("%d %d.%d", &u, &a, &b);
			savings[u] += 100*a + b;
		}

		fill_shortest();

		shops.clear();
		for (int i = 0; i < N; i++) {
			if (savings[i] > 0) shops.push_back(i);
		}

		int ret = TSP();
		if (ret > 0) {
			printf("Daniel can save $%d.%02d\n", ret/100, ret%100);
		}
		else printf("Don't leave the house\n");
	}
	return 0;
}
