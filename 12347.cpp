#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, int> tree;
vector<int> nodes;

void buildTree(int left, int right, int t_ind) {
	if (left > right) return;
	tree[t_ind] = nodes[left];
	int i;
	for (i = left+1; i <= right; i++) if (nodes[i] > nodes[left]) break;
	buildTree(left+1, i-1, t_ind*2);
	buildTree(i, right, t_ind*2+1);
}

void postOrder(int t) {
	if (tree.find(t) == tree.end()) return;
	postOrder(2*t);
	postOrder(2*t+1);
	cout << tree[t] << endl;
}

int main() {
	int N;
	while(cin >> N) nodes.push_back(N);
	buildTree(0, nodes.size()-1, 1);
	postOrder(1);
	return 0;
}
