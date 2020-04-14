#include <iostream>
using namespace std;

int main() {
	long long int N;
	while(true) {
		cin >> N;
		if (N < 0) break;
		cout << N*(N+1)/2 + 1 << "\n";
	}
	return 0;
}
