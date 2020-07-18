//1197

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

class triple {
public:
	int dist;
	int s;
	int e;
	
	triple() {}
	triple(int dist, int s, int e) : dist(dist), s(s), e(e) {}

	//정렬 기준 : dist
	bool operator <(triple& triple) {
		return this->dist < triple.dist;
	}
};

int uni[10001];

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

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int V, E;
	cin >> V >> E;

	vector<triple> mst;

	while (E--) {
		int a, b, dist;
		cin >> a >> b >> dist;
		mst.push_back({ dist, a, b });
	}

	sort(mst.begin(), mst.end());

	//union-find initialize
	for (int i = 0; i <= V; i++) uni[i] = i;

	int ans = 0, pchk = 0;
	for (int i = 0; i < mst.size(); i++) {
		if (pchk == V) continue;	//모든 노드를 거쳤다면 무시
		if (find_parent(mst[i].s) == find_parent(mst[i].e)) continue;	//같은 집합이면 무시
		int bs = mst[i].s, be = mst[i].e;
		make_union(mst[i].s, mst[i].e);
		if (bs != mst[i].s && mst[i].s == 1) pchk++;
		if (be != mst[i].e && mst[i].e == 1) pchk++;
		ans += mst[i].dist;
	}

	cout << ans;

	return 0;
}