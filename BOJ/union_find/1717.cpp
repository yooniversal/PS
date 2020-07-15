//1717

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
using namespace std;

int n, m;
int uni[1000005];

int find_parent(int a) {
	if (uni[a] == a) return a;
	return uni[a] = find_parent(uni[a]);
}

void make_union(int a, int b) {
	int pa = find_parent(a);
	int pb = find_parent(b);
	if (pa != pb) {
		if (pa < pb) uni[pb] = pa;
		else uni[pa] = pb;
	}
}

void check_union(int a, int b) {
	if (find_parent(a) == find_parent(b)) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main() {
	
	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	//부모 노드를 가리키도록 초기화
	for (int i = 0; i <= n; i++)
		uni[i] = i;

	while(m--){
		int mode, a, b;
		cin >> mode >> a >> b;
		if (mode == 0) {
			make_union(a, b);
		}
		else {
			check_union(a, b);
		}
	}

	return 0;
}