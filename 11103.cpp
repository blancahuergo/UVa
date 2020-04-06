#include <iostream>
#include <unordered_map>
using namespace std;

string srt(string T) {
	unordered_map<int, int> count;
	for (int i = 0; i <= 9; i++) count[i]=0;
	for (int i = 0; i < (int) T.length(); i++) {
		if (T[i] == 'p') count[0]++;
		if (T[i] == 'q') count[1]++;
		if (T[i] == 'r') count[2]++;
		if (T[i] == 's') count[3]++;
		if (T[i] == 't') count[4]++;
		if (T[i] == 'K') count[5]++;
		if (T[i] == 'A') count[6]++;
		if (T[i] == 'N') count[7]++;
		if (T[i] == 'C') count[8]++;
		if (T[i] == 'E') count[9]++;
	}
	string ret = "";
	while(count[0]--) ret += 'p';
	while(count[1]--) ret += 'q';
	while(count[2]--) ret += 'r';
	while(count[3]--) ret += 's';
	while(count[4]--) ret += 't';
	while(count[7]--) ret += 'N';
	while(count[5]--) ret += 'K';
	while(count[6]--) ret += 'A';
	while(count[8]--) ret += 'C';
	while(count[9]--) ret += 'E';
	return ret;
}

string conc (char A, string ans) {
	string ret = "";
	ret += A;
	ret += ans;
	return ret;
}

int main() {
	string T, ans;
	int lowInd, capInd, nBegin, N;
	while(true) {
		cin >> T;
		if (T[0] == '0') break;
		T = srt(T);
		N = (int) T.length();
		ans = "";
		if (T[0] >= 'a' && T[0] <= 'z') {
			nBegin = -1;
			capInd = -1;
			for (int i = 1; i < N; i++) {
				if (T[i] == 'N' && nBegin == -1) nBegin = i;
				if (T[i] >= 'A' && T[i] <= 'Z' && T[i] != 'N') {
					capInd = i;
					break;
				}
			}
			if (nBegin >= 1) { // there are 'N's
				if (capInd != -1) {
					ans = "";
					for (int i = nBegin; i < capInd; i++) ans += 'N';
					ans += T[0];
					lowInd = 1;
					while(lowInd < nBegin && capInd < N) {
						ans = conc(T[capInd], ans);
						ans += T[lowInd];
						lowInd++;
						capInd++;
					}
				} else {
					ans = "";
					for (int i = nBegin; i < N; i++) ans += 'N';
					ans += T[0];
				}
				cout << ans << "\n";
			} else {
				ans = "";
				if (capInd == -1) {
					ans += T[0];
					cout << ans << "\n";
				} else {
					if (capInd > 1) {
						ans += T[0];
						lowInd = 1;
						int high = capInd;
						while(lowInd < capInd && high < N) {
							ans = conc(T[high], ans);
							ans += T[lowInd];
							lowInd++;
							high++;
						}
						cout << ans << "\n";
					} else {
						ans += T[0];
						cout << ans << "\n";
					}
				}
			}
		} else {
			cout << "no WFF possible\n";
		}
	}
	return 0;
}
