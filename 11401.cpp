#include <iostream>
using namespace std;

int main() {
	long long int N;
	while(true) {
		cin >> N;
		if (!N) break;
		cout << (N-2)*N*(2*N-5)/24 << "\n";
	}
	return 0;
}
