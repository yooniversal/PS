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
#define INF 987654321
#define MAX 200001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

class maxSeg {
private:
    vector<int> tree;
    int size;

    int init(int* a, int start, int end, int node) {
        int mid = (start + end) / 2;
        //리프 노드
        if (start == end) return tree[node] = a[start];
        else {
            return tree[node] = max(init(a, start, mid, 2 * node), init(a, mid + 1, end, 2 * node + 1));
        }
    }

    int update(int start, int end, int node, int index, ll value) {
        if (index < start || end < index) return tree[node];
        int mid = (start + end) / 2;
        if (start == end) return tree[node] = value;
        else {
            ll leftValue = update(start, mid, 2 * node, index, value);
            ll rightValue = update(mid + 1, end, 2 * node + 1, index, value);
            return tree[node] = max(leftValue, rightValue);
        }
    }

    int _find(int start, int end, int node, int left, int right) {
        if (left > end || right < start) return 0;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return max(_find(start, mid, 2 * node, left, right), _find(mid + 1, end, 2 * node + 1, left, right));
    }

public:
    maxSeg(int* a, int n) {
        size = n;
        tree.resize(MAX * 8, 0);
        init(a, 0, size - 1, 1);
    }
    int update(int idx, ll val) { return update(0, size - 1, 1, idx, val); }
    int find(int l, int r) { return _find(0, size - 1, 1, l, r); }
};

int cache[MAX];
int n, k;

int f(int cur, const vi& x) {
	if (cur >= n) return 0;
	//cout << "cur:" << cur << '\n';
	int& ret = cache[cur];
	if (ret != -1) return ret;
	for (int i = cur; i < n; i++) {
		int idx = upper_bound(x.begin(), x.end(), x[i] + k) - x.begin();
		if (idx <= n) {
			ret = max(ret, f(idx, x)+idx-i);
		}
		//printf("[%d]:: i:%d ret:%d\n",cur, i, ret);
	}
	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		memset(cache, 0, sizeof(cache));
		cin >> n >> k;
		vi x(n);
		for (int i = 0; i < n; i++) cin >> x[i];
		for (int i = 0; i < n; i++) { int tmp; cin >> tmp; }
		sort(x.begin(), x.end());

        for (int i = 0; i < n; i++) {
            int idx = upper_bound(x.begin(), x.end(), x[i] + k) - x.begin();
            cache[i] = idx - i;
        }

        int ret = 0;
        maxSeg Seg(cache, n);
        for (int i = 0; i < n; i++) {
            int idx = upper_bound(x.begin(), x.end(), x[i] + k) - x.begin();
            ret = max(ret, cache[i] + Seg.find(idx, n - 1));
        }
        cout << ret << '\n';
		//for (int i = 0; i < n; i++) printf("f(%d, x):%d\n", i, cache[i]);
		//cout << f(0, x) << '\n';
	}

	return 0;
}