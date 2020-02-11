#include <iostream>
using namespace std;

int main() {
	long A, limit, init_A;
	int cas = 1, terms;
	while(true) {
		cin >> A >> limit;
		if (A == -1 && limit == -1) break;
		terms = 1;
		init_A = A;
		while(A != 1) {
			if (A % 2 == 0) A/=2;
			else A = A*3+1;
			if (A > limit) break;
			terms++;
		}
		cout << "Case " << cas << ": A = " << init_A << ", limit = " << limit << ", number of terms = " << terms << endl;
		cas++;
	}
	return 0;
}
