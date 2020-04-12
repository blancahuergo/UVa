#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long int ll;
vector<vector<ll>> DP;

ll trib(int n, int back) {
	if (n <= 1) return 1;
	if (DP[n][back] != 0) return DP[n][back];
	ll sum = 1;
	for(int i = 1; i <= back; i++)
		sum += trib(n-i,back);
	return DP[n][back] = sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, back, cas=1;
	DP.assign(62, vector<ll>(62, 0));
	while(true) {
		cin >> N >> back;
		if (N > 60) break;
		cout << "Case " << cas << ": " << trib(N, back) << "\n";
		cas++;
	}
	return 0;
}
