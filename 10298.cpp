#include <iostream>
#include <vector>
using namespace std;

string text;
int tLen, pLen, record, occ;
vector<int> backT;

void processPat() {
	pLen = text.length();
	backT.assign(pLen+1, 0);
	backT[0] = -1;
	int j = -1;
	for (int i = 0; i < pLen; i++) {
		while(j >= 0) {
			if (text[i] == text[j]) break;
			j = backT[j];
		}
		backT[i+1] = ++j;
	}
}

void KMP(int curP) {
	occ = 0;
	int last = -1;
	tLen = text.length();
	int j = 0;
	for (int i = 0; i < tLen; i++) {
		while(j >= 0) {
			if (text[i] == text[j]) break;
			j = backT[j];
		}
		j++;
		if (j == curP) {
			occ++;
			if (last != -1 && i + 1 - j - last != curP) {
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
	int orig;
	while(true) {
		cin >> text;
		if (text == ".") break;
		orig = (int) text.length();
		record = 1;
		processPat();
		for (int i = 0; i < orig/2; i++) {
			if (orig % (i+1) != 0) continue;
			KMP(i+1);
			if (occ == orig/(i+1)) {
				record = occ;
				break;
			}
		}
		cout << record << "\n";
	}
	return 0;
}
