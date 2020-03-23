#include <iostream>
#include <vector>
using namespace std;

int numSets;
vector<int> parent;
vector<int> size;

int root(int a) {
	if (parent[a] != a) parent[a] = root(parent[a]);
	return parent[a];
}

bool isSameSet(int a, int b) {
	return root(a) == root(b);
}

void mergeBySize(int a, int b) {
	int r_a, r_b;
	r_a = root(a);
	r_b = root(b);
	if (r_a == r_b) return;
	numSets--;
	if (size[r_a] > size[r_b]) {
		parent[r_b] = r_a;
		size[r_a] += size[r_b];
	} else {
		parent[r_a] = r_b;
		size[r_b] += size[r_a];
	}
}

int main() {
	int A, B, count;
	parent.assign(100002, 0);
	while(cin >> A) {
		if (A == -1) continue;
		count = 0;
		size.assign(100002, 1);
		for (int n = 0; n < 100002; n++) parent[n] = n;
		cin >> B;
		mergeBySize(A, B);
		while(cin >> A) {
			if (A == -1) break;
			cin >> B;
			if (isSameSet(A, B)) {
				count++;
				continue;
			}
			mergeBySize(A, B);
		}
		cout << count << endl;
	}
}
