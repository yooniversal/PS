//2162

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
typedef pair<ll, ll> xy;
struct line {
	xy s;
	xy e;
	
	line(ll a, ll b, ll c, ll d) : s({ a, b }), e({ c, d }) {}
};

int uni[3005], group[3005];
vector<line> node;

ll CCW(xy a, xy b, xy c) {
	ll tmp = a.first * b.second + b.first * c.second + c.first * a.second;
	tmp -= a.second * b.first + b.second * c.first + c.second * a.first;
	if (tmp > 0) return 1;
	else if (tmp < 0) return -1;
	else return 0;
}

ll process(line l1, line l2) {
	xy a = l1.s, b = l1.e, c = l2.s, d = l2.e;
	ll t1 = CCW(a, b, c) * CCW(a, b, d);
	ll t2 = CCW(c, d, a) * CCW(c, d, b);
	//일직선
	if (t1 == 0 && t2 == 0) {
		if (a > b)	swap(a, b);
		if (c > d) swap(c, d);
		if (a <= d && c <= b) return 1;
		else return 0;
	}
	//교차
	if (t1 <= 0 && t2 <= 0) return 1;
	else return 0;
}

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

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		node.push_back({ x1, y1, x2, y2 });
	}

	//union initialize
	for (int i = 0; i <= n; i++) uni[i] = i;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (process(node[i], node[j]))
				make_union(i+1, j+1);
		}
	}

	for (int i = 1; i <= n; i++)
		group[find_parent(i)]++;

	int m = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (m < group[i]) m = group[i];
		if (group[i]) cnt++;
	}

	cout << cnt << '\n';
	cout << m;

	return 0;
}