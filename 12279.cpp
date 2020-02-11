#include <iostream>
using namespace std;

int main() {
	int N, cur, tot, cas;
	cas = 1;
	while(scanf("%d", &N), N) {
		tot = 0;
		for(int u = 0; u < N; u++) {
			scanf("%d", &cur);
			if (cur == 0) {
				tot--;
			} else {
				tot++;
			}
		}
		cout << "Case " << cas << ": " << tot << endl;
		cas++;
	}
	return 0;
}
