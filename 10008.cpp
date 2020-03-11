#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int N;
	char str[1000], c;
	scanf("%d", &N);
	getchar();
	int count[26];
	for (int i = 0; i < 26; i++) count[i] = 0;
	while(N--) {
		gets(str);
		for (int i = 0; i < strlen(str); i++) {
			c = str[i];
			if (c >= 'A' && c <= 'Z') {
				count[c - 'A']++;
			} else if (c >= 'a' && c <= 'z') {
				count[c - 'a']++;
			}
		}
	}
	int found = 0, max, max_ind;
	while (found < 26) {
		max = -1;
		for (int i = 0; i < 26; i++) {
			if (count[i] > max) {
				max = count[i];
				max_ind = i;
			}
		}
		if (max == 0) break;
		cout << (char) ('A' + max_ind) << " " << count[max_ind] << endl;
		count[max_ind] = -1;
		found++;
	}
	return 0;
}
