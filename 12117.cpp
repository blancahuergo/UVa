#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;

vector<vector<ll>> solutions;
vector<vector<int>> pieces; // {length, bitmask before, bitmask after}

void createDP() {
	solutions.assign(2001, vector<ll>(8, 0ll)); // bitmask: up, middle, down
	pieces.assign(22, vector<int>(3, 0)); // combine 3pieces together to make long two pieces
	// fill in 2pieces
	pieces[0] = {1, 7, 7};
	pieces[1] = {2, 7, 2};
	pieces[2] = {1, 2, 7};
	pieces[3] = {1, 4, 7};
	pieces[4] = {2, 5, 2};
	pieces[5] = {2, 7, 5};
	pieces[6] = {1, 5, 7};
	pieces[7] = {1, 4, 6};
	pieces[8] = {1, 1, 3};
	pieces[9] = {2, 7, 6};
	pieces[10] = {1, 1, 7};
	pieces[11] = {2, 7, 4};
	pieces[12] = {1, 3, 7};
	pieces[13] = {2, 7, 1};
	pieces[14] = {1, 6, 7};
	pieces[15] = {2, 3, 4};
	pieces[16] = {2, 6, 1};
	pieces[17] = {2, 7, 3};
	// fill in 3pieces
	pieces[18] = {3, 4, 6};
	pieces[19] = {3, 1, 3};
	solutions[0][7] = 1ll;
	int bef, aft, len;
	for (int n = 1; n <= 2000; n++) {
		for (int p = 0; p < (int) pieces.size(); p++) {
			len = pieces[p][0];
			if (n - len < 0) continue;
			bef = pieces[p][1];
			aft = pieces[p][2];
			solutions[n][aft] += solutions[n - len][bef];
			solutions[n][aft] %= 1000000000000ll;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, cas = 1;
	createDP();
	while(true) {
		cin >> N;
		if (!N) break;
		cout << "Case " << cas++ << ": " << solutions[N][7] << "\n";
	}
	return 0;
}
