#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int> pos;
unordered_map<int, char> tree;
string inord, preord;
int preIndex;

void buildTree(int ind, int inStrt, int inEnd)
{
	if (inStrt > inEnd) return;

	char curr = preord[preIndex];
	preIndex++;
	tree[ind] = curr;

	if (inStrt == inEnd) return;

	buildTree(2*ind, inStrt, pos[curr] - 1);
	buildTree(2*ind + 1, pos[curr] + 1, inEnd);
}

void PostOrder(int ind) {
	if (tree.find(ind) == tree.end()) return;
	PostOrder(2*ind);
	PostOrder(2*ind+1);
	cout << tree[ind];
}

int main() {
	while(cin >> preord >> inord) {
		pos.clear();
		tree.clear();
		for (int i = 0; i < (int) inord.length(); i++) {
			pos[inord[i]] = i;
		}
		preIndex = 0;
		buildTree(1, 0, preord.length()-1);
		PostOrder(1);
		cout << "\n";
	}
	return 0;
}
