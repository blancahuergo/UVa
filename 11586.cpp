#include <iostream>
using namespace std;

int main() {
	int cases, m, f, m_r, f_r, non_space;
	scanf("%d\n", &cases);
	string s;
	for (int y = 0; y < cases; y++) {
		getline(cin, s);
		m = 0;
		f = 0;
		m_r = 0;
		f_r = 0;
		non_space = 0;
		for (int u = 0; u < s.length(); u ++) {
			if (s[u] != ' ') {
				non_space++;
				if (s[u] == 'M') {
					m++;
				} else {
					f++;
				}
				if (s[u+1] == 'M') {
					m_r++;
				} else {
					f_r++;
				}
				u++;
			}
		}
		if ((m == f_r || f == m_r) && non_space > 1) {
			cout << "LOOP" << endl;
		} else {
			cout << "NO LOOP" << endl;
		}
	}
	return 0;
}
