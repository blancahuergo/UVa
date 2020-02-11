#include <iostream>
using namespace std;

int main() {
	int N, f, size, anim, env, premium;
	cin >> N;
	for (int u = 0; u < N; u++) {
		cin >> f;
		premium = 0;
		for (int i = 0; i < f; i++) {
			cin >> size >> anim >> env;
			premium += size*env;
		}
		cout << premium << endl;
	}
	return 0;
}
