//2887

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

class triple {
public:
	ll dist;
	int s;
	int e;

	triple() {}
	triple(ll dist, int s, int e) : dist(dist), s(s), e(e) {}

	//정렬 기준 : dist
	bool operator<(triple& triple) {
		return this->dist < triple.dist;
	}
};

class xyz {
public:
	int x, y, z, idx;

	xyz() {}
	xyz(int x, int y, int z, int idx) : x(x), y(y), z(z), idx(idx) {}
};

int uni[100001];

bool cmp_x(xyz& a, xyz& b) { return a.x < b.x; }
bool cmp_y(xyz& a, xyz& b) { return a.y < b.y; }
bool cmp_z(xyz& a, xyz& b) { return a.z < b.z; }

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
		if (pa < pb) uni[pb] = pa;
		else uni[pa] = pb;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int V;
	cin >> V;

	vector<xyz> tmp;
	vector<triple> mst;

	//input
	for (int i = 0; i < V; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tmp.push_back({x, y, z, i+1});
	}

	//union-find initialize
	for (int i = 0; i <= V; i++) uni[i] = i;

	sort(tmp.begin(), tmp.end(), cmp_x);
	for (int i = 1; i < V; i++) {
		mst.push_back({ abs(tmp[i-1].x - tmp[i].x), tmp[i-1].idx, tmp[i].idx });
	}

	sort(tmp.begin(), tmp.end(), cmp_y);
	for (int i = 1; i < V; i++) {
		mst.push_back({ abs(tmp[i - 1].y - tmp[i].y), tmp[i - 1].idx, tmp[i].idx });
	}

	sort(tmp.begin(), tmp.end(), cmp_z);
	for (int i = 1; i < V; i++) {
		mst.push_back({ abs(tmp[i - 1].z - tmp[i].z), tmp[i - 1].idx, tmp[i].idx });
	}

	sort(mst.begin(), mst.end());

	ll answer = 0;
	for (int i = 0; i < mst.size(); i++) {
		//부모가 다르면 같은 집합으로 합쳐주기
		if (find_parent(mst[i].s) != find_parent(mst[i].e)) {
			make_union(mst[i].s, mst[i].e);
			answer += mst[i].dist;
		}
	}
	cout << answer;

	return 0;
}