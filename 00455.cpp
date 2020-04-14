#include <iostream>
#include <vector>
using namespace std;

string text, pattern;
int tLen, pLen, record, occ;
vector<int> backT;

void processPat() {
	pLen = pattern.length();
	backT.assign(pLen+1, 0);
	backT[0] = -1;
	int j = -1;
	for (int i = 0; i < pLen; i++) {
		while(j >= 0) {
			if (pattern[i] == pattern[j]) break;
			j = backT[j];
		}
		backT[i+1] = ++j;
	}
}

void KMP() {
	occ = 0;
	int last = -1;
	tLen = text.length();
	int j = 0;
	for (int i = 0; i < tLen; i++) {
		while(j >= 0) {
			if (text[i] == pattern[j]) break;
			j = backT[j];
		}
		j++;
		if (j == pLen) {
			occ++;
			if (last != -1 && i + 1 - j - last != pLen) {
				occ = -1;
				return;
			}
			last = i + 1 - j;
			j = backT[j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, orig;
	cin >> T;
	while(T--) {
		cin >> text;
		orig = (int) text.length();
		pattern = "";
		record = orig;
		for (int i = 0; i < orig-1; i++) {
			pattern += text[i];
			if (orig % (i+1) != 0) continue;
			processPat();
			KMP();
			if (occ == orig/pLen) record = min(record, pLen);
		}
		cout << record << "\n";
		if (T) cout << "\n";
	}
	return 0;
}
