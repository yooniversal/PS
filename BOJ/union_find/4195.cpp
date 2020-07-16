//4195

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

int uni[1000001];
int usize[1000001];

//부모 노드 반환
int find_parent(int a) {
	if (uni[a] == a) return a;
	return uni[a] = find_parent(uni[a]);
}

//같은 집합으로 만들어주기
void make_union(int a, int b) {
	int pa = find_parent(a);
	int pb = find_parent(b);
	if (pa != pb) {
		if (pa < pb) {
			uni[pb] = pa;
			usize[pa] += usize[pb];
			usize[pb] = 0;
		}
		else {
			uni[pa] = pb;
			usize[pb] += usize[pa];
			usize[pa] = 0;
		}
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int num, idx = 1;
		string p1, p2;
		map<string, int> name;
		cin >> num;
		

		for (int i = 1; i <= num * 2; i++) {
			uni[i] = i;
			usize[i] = 1;
		}
		while (num--) {
			cin >> p1 >> p2;
			if (name[p1] == 0) {
				name[p1] = idx;
				idx++;
			}
			if (name[p2] == 0) {
				name[p2] = idx;
				idx++;
			}

			make_union(name[p1], name[p2]);
			
			//answer
			cout << usize[find_parent(name[p1])] << '\n';
		}
	}

	return 0;
}