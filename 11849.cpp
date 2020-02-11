#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	int N, M, cur;
	unordered_set<int> CDs;
	while(true) {
		cin >> N >> M;
		if (!(M || N)) break;
		CDs.clear();
		for (int i = 0; i < N+M; i++) {
			cin >> cur;
			CDs.insert(cur);
		}
		cout << ((N+M)-CDs.size()) << endl;
	}
	return 0;
}
