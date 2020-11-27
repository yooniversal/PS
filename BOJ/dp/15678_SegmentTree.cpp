//15678
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 100005
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

class maxSeg {
private:
    vector<ll> tree;

    ll update(int start, int end, int node, int index, ll value) {
        if (index < start || end < index) return tree[node];
        if (start == end) return tree[node] = value;
        int mid = (start + end) / 2;
        ll leftValue = update(start, mid, 2 * node, index, value);
        ll rightValue = update(mid + 1, end, 2 * node + 1, index, value);
        return tree[node] = max(leftValue, rightValue);
    }

    ll _find(int start, int end, int node, int left, int right) {
        if (left > end || right < start) return -INF;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return max(_find(start, mid, 2 * node, left, right), _find(mid + 1, end, 2 * node + 1, left, right));
    }

public:
    maxSeg() {
        tree.resize(MAX * 4, 0);
    }
    ll update(int idx, ll val) { return update(0, MAX-1, 1, idx, val); }
    ll find(int l, int r) { return _find(0, MAX-1, 1, l, r); }
};


ll dp[100001];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    maxSeg Seg;
	int n, d; cin >> n >> d;
	vi a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) {
		ll prev = max(0LL, Seg.find(max(0, i - d), i - 1));
		dp[i] = max(0LL, prev) + a[i];
        Seg.update(i, dp[i]);
        //printf("dp[%d]:%lld\n", i, dp[i]);
	}

    //for (int i = 0; i < n; ++i) printf("find[%d]:%lld\n", i, Seg.find(i, i));
    cout << Seg.find(0, n - 1) << '\n';

	return 0;
}