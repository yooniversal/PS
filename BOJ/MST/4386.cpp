//4386

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
	double dist;
	int s;
	int e;

	triple() {}
	triple(double dist, int s, int e) : dist(dist), s(s), e(e) {}

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

double getdist(pair<double, double> a, pair<double, double> b) {
	double dx = abs(a.first - b.first);
	double dy = abs(a.second - b.second);
	return sqrt(dx * dx + dy * dy);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	int V;
	scanf("%d", &V);

	vector<pair<double, double>> tmp;
	vector<triple> mst;

	for(int i=0; i<V; i++) {
		double x, y;
		scanf("%lf %lf", &x, &y);
		tmp.push_back({x, y});
	}

	for (int i = 0; i < tmp.size()-1; i++) {
		for (int j = i + 1; j < tmp.size(); j++) {
			mst.push_back({ getdist(tmp[i], tmp[j]), i, j });
		}
	}

	sort(mst.begin(), mst.end());

	//union-find initialize
	for (int i = 0; i <= V; i++) uni[i] = i;

	for (int i = 0; i < mst.size(); i++) {

	}

	double ans = 0.0;
	int pchk = 0;
	for (int i = 0; i < mst.size(); i++) {
		if (pchk == V) continue;
		if (find_parent(mst[i].s) == find_parent(mst[i].e)) continue;
		int bs = mst[i].s, be = mst[i].e;
		make_union(mst[i].s, mst[i].e);
		if (bs != mst[i].s && mst[i].s == 1) pchk++;
		if (be != mst[i].e && mst[i].e == 1) pchk++;
		ans += mst[i].dist;
	}
	printf("%.2lf", ans);

	return 0;
}