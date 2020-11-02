//10277
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 4587525
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

class lazySeg {
private:
    vi mintree, maxtree, minlazy, maxlazy;

    void MINlazy_update(int node, int ns, int ne) {
        if (minlazy[node]) {
            mintree[node] += minlazy[node];
            if (ns != ne) {
                minlazy[node * 2] += minlazy[node];
                minlazy[node * 2 + 1] += minlazy[node];
            }
            minlazy[node] = 0;
        }
    }

    void MAXlazy_update(int node, int ns, int ne) {
        if (maxlazy[node]) {
            maxtree[node] += maxlazy[node];
            if (ns != ne) {
                maxlazy[node * 2] += maxlazy[node];
                maxlazy[node * 2 + 1] += maxlazy[node];
            }
            maxlazy[node] = 0;
        }
    }

    int MINupdate(int node, int ns, int ne, int l, int r, int val) {
        MINlazy_update(node, ns, ne);
        if (r < ns || ne < l) return mintree[node];
        if (l <= ns && ne <= r) {
            if (ns != ne) {
                minlazy[node * 2] += val;
                minlazy[node * 2 + 1] += val;
            }
            return mintree[node] += val;
        }
        int m = (ns + ne) / 2;
        return mintree[node] = min(MINupdate(node * 2, ns, m, l, r, val), MINupdate(node * 2 + 1, m + 1, ne, l, r, val));
    }

    int MAXupdate(int node, int ns, int ne, int l, int r, int val) {
        MAXlazy_update(node, ns, ne);
        if (r < ns || ne < l) return maxtree[node];
        if (l <= ns && ne <= r) {
            if (ns != ne) {
                maxlazy[node * 2] += val;
                maxlazy[node * 2 + 1] += val;
            }
            return maxtree[node] += val;
        }
        int m = (ns + ne) / 2;
        return maxtree[node] = max(MAXupdate(node * 2, ns, m, l, r, val), MAXupdate(node * 2 + 1, m + 1, ne, l, r, val));
    }

    int _minfind(int node, int ns, int ne, int l, int r) {
        MINlazy_update(node, ns, ne);
        if (r < ns || ne < l) return INF;
        if (l <= ns && ne <= r) return mintree[node];
        int m = (ns + ne) / 2;
        return min(_minfind(node * 2, ns, m, l, r), _minfind(node * 2 + 1, m + 1, ne, l, r));
    }

    int _maxfind(int node, int ns, int ne, int l, int r) {
        MAXlazy_update(node, ns, ne);
        if (r < ns || ne < l) return 0;
        if (l <= ns && ne <= r) return maxtree[node];
        int m = (ns + ne) / 2;
        return max(_maxfind(node * 2, ns, m, l, r), _maxfind(node * 2 + 1, m + 1, ne, l, r));
    }

    int _find(int node, int ns, int ne, int idx) {
        MAXlazy_update(node, ns, ne);
        if (idx < ns || ne < idx) return 0;
        if (ns == ne) return maxtree[node];
        int m = (ns + ne) / 2;
        return max(_find(node * 2, ns, m, idx), _find(node * 2 + 1, m + 1, ne, idx));
    }

public:
    lazySeg() {
        mintree.resize(MAX * 4, 0);
        maxtree.resize(MAX * 4, 0);
        minlazy.resize(MAX * 4, 0);
        maxlazy.resize(MAX * 4, 0);
    }
    void update(int l, int r, ll val) { 
        MINupdate(1, 0, MAX - 1, l, r, val);
        MAXupdate(1, 0, MAX - 1, l, r, val);
    }
    int minfind(int l, int r) { return _minfind(1, 0, MAX - 1, l, r); }
    int maxfind(int l, int r) { return _maxfind(1, 0, MAX - 1, l, r); }
    int find(int idx) { return _find(1, 0, MAX - 1, idx); }
};

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    lazySeg Seg;
    int C, N, O; cin >> C >> N >> O;
    while (O--) {
        string mode; cin >> mode;
        if (mode == "state") {
            int idx; cin >> idx;
            cout << Seg.find(idx) << '\n';
        }
        else if (mode == "change") {
            int idx, v; cin >> idx >> v;
            int cur = Seg.find(idx);
            if (cur + v > N) {
                Seg.update(idx, idx, N - cur);
                cout << N - cur << '\n';
            }
            else if (cur + v < 0) {
                Seg.update(idx, idx, -cur);
                cout << -cur << '\n';
            }
            else {
                Seg.update(idx, idx, v);
                cout << v << '\n';
            }
        }
        else {
            int l, r, v; cin >> l >> r >> v;
            int MAXcur = Seg.maxfind(l, r);
            int MINcur = Seg.minfind(l, r);
            if (v >= 0) {
                if (MAXcur + v >= N) {
                    Seg.update(l, r, N - MAXcur);
                    cout << N - MAXcur << '\n';
                }
                else {
                    Seg.update(l, r, v);
                    cout << v << '\n';
                }
            }
            else {
                if (MINcur + v < 0) {
                    Seg.update(l, r, -MINcur);
                    cout << -MINcur << '\n';
                }
                else {
                    Seg.update(l, r, v);
                    cout << v << '\n';
                }
            }
        }
    }

	return 0;
}