#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, n, t, maxS, tim, S;
	cin >> T;
	vector<int> songs, DP;
	for (int cas = 1; cas <= T; cas++) {
		cin >> n >> t;
		songs.assign(n+1, 0);
		S = 678;
		for (int i = 0; i < n; i++) {
			cin >> songs[i];
			S += songs[i];
		}
		songs[n] = 678;
		n++;
		DP.assign(S+1, 0);
		for (int s = 0; s < n; s++) {
			for (int sec = S; sec >= songs[s]; sec--) {
				if ((DP[sec - songs[s]] > 0 && (sec - songs[s] < t)) || sec == songs[s]) DP[sec] = max(DP[sec], DP[sec - songs[s]]+1);
			}
		}
		maxS = 0;
		tim = 0;
		for (int sec = S; sec > 0; sec--) {
			if (DP[sec] > maxS) {
				maxS = DP[sec];
				tim = sec;
			}
		}
		cout << "Case " << cas << ": " << maxS << " " << tim << "\n";
	}
	return 0;
}
