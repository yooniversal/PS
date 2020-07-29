//14725

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

struct Node {
	string val;
	vector<Node> next;

	Node() {}
	Node(string val) : val(val) {}
};

vector<Node> tree;
int k;

void makeLink(vector<Node>& parent, vector<string> s, int pi, int si) {
	//����
	if (si == k) {
		return;
	}

	//�ڽ� Ž��
	for (int i = 0; i < parent.size(); i++) {
		if (s[si] == parent[i].val) {
			pi = i;
			Node child;
			if (si < s.size() - 1) {
				child.val = s[si + 1];
				
				//�ߺ�üũ
				bool chk = false;
				for (int j = 0; j < parent[pi].next.size(); j++) {
					if (parent[pi].next[j].val == child.val) {
						chk = true;
						break;
					}
				}
				if(!chk) parent[pi].next.push_back(child);
			}
			break;
		}
	}
	
	makeLink(parent[pi].next, s, pi, si + 1);
}

bool compare(Node a, Node b) {
	return a.val < b.val;
}

void prt(vector<Node> parent, int hier) {
	sort(parent.begin(), parent.end(), compare);

	for (int i = 0; i < parent.size(); i++) {
		for (int j = 0; j < 2 * hier; j++) cout << '-';
		cout << parent[i].val << '\n';
		prt(parent[i].next, hier + 1);
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		cin >> k;
		vector<string> tmp;
		for(int i=0; i<k; i++) {
			string food; cin >> food;
			tmp.push_back(food);
		}

		//�ߺ� üũ
		bool chk = false;
		for (int i = 0; i < tree.size(); i++) {
			if (tree[i].val == tmp[0]) {
				chk = true;
				break;
			}
		}
		if(!chk) tree.push_back({ tmp[0] });
		makeLink(tree, tmp, -1, 0);
	}

	prt(tree, 0);

	return 0;
}