//10775

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

int uni[100001], ans;
bool chk[100001];

//부모 노드 반환
int find_parent(int a) {
	if (uni[a] == a) {
		return a;
	}
	return uni[a] = find_parent(uni[a]);
}

//같은 집합으로 만들어주기
void make_union(int a, int b) {
	int pa = find_parent(a);
	int pb = find_parent(b);
	if (pa != pb) {
		if (pa < pb) {
			uni[pb] = pa;
		}
		else {
			uni[pa] = pb;
		}
	}
}

void process(int num) {
	if (!chk[num]) {
		chk[num] = true;
		make_union(num, num - 1);
		ans++;
	}
	else {
		if (find_parent(num) == 0) return;
		process(find_parent(num));
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int G, P, num;
	cin >> G >> P;

	for (int i = 0; i <= G; i++)
		uni[i] = i;

	int close = 0;
	while (P--) {
		cin >> num;
		if (close) continue;
		if (find_parent(num) == 0) {
			close = 1;
			continue;
		}
		process(num);
	}
	

	cout << ans;

	return 0;
}