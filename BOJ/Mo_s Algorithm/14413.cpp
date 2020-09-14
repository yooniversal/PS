//14413

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
#define INF 1000000001
#define MAX 500001
#define MAXV 500001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int sqrtN;
int A[MAX];
int cnt[MAXV];
int ret[MAX];

struct Zip {
	int v, n;
	Zip(int a, int b) : v(a), n(b) {}
	bool operator<(const Zip& z) const {
		return v < z.v;
	}
};

struct QueryNode {
	int s, e, n;
	QueryNode() : QueryNode(0, 0, -1) {}
	QueryNode(int s1, int e1, int n1) : s(s1), e(e1), n(n1) {}
	bool operator<(const QueryNode& O) const {
		if (s / sqrtN != O.s / sqrtN) return (s / sqrtN < O.s / sqrtN);
		return (e < O.e);
	}
};

QueryNode Q[MAX];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	sqrtN = sqrt(n);
	vector<Zip> zip; //ÁÂÇ¥ ¾ÐÃà
	for (int i = 0; i < n; i++) {
		int v; cin >> v;
		zip.push_back(Zip(v, i));
	}
	sort(zip.begin(), zip.end());
	int num = 0;
	for (int i = 1; i < n; i++) {
		if (zip[i - 1].v == zip[i].v)
			zip[i - 1].v = num;
		else 
			zip[i - 1].v = num++;
	}
	zip[n - 1].v = num;

	for (int i = 0; i < n; i++)
		A[zip[i].n] = zip[i].v;

	for (int i = 0; i < m; i++) {
		int l, r; cin >> l >> r;
		Q[i] = QueryNode(l-1, r-1, i);
	}
	sort(Q, Q + m);

	int cur = 0;
	int s = Q[0].s, e = Q[0].e;
	for (int i = s; i <= e; i++) {
		if (cnt[A[i]] == 2) cur--;
		if (++cnt[A[i]] == 2) cur++;
	}
	ret[Q[0].n] = cur;

	for (int i = 1; i < m; i++) {
		while (Q[i].s < s) {
			if (cnt[A[--s]] == 2) cur--;
			if (++cnt[A[s]] == 2) cur++;
		}
		while (e < Q[i].e) {
			if (cnt[A[++e]] == 2) cur--;
			if (++cnt[A[e]] == 2) cur++;
		}
		while (Q[i].s > s) {
			if (cnt[A[s]] == 2) cur--;
			if (--cnt[A[s++]] == 2) cur++;
		}
		while (e > Q[i].e) {
			if (cnt[A[e]] == 2) cur--;
			if (--cnt[A[e--]] == 2) cur++;
		}
		ret[Q[i].n] = cur;
	}

	for (int i = 0; i < m; i++)
		cout << ret[i] << '\n';

	return 0;
}