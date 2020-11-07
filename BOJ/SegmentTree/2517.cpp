//2517
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 500005
#define MOD 1000000
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

class SumSeg {
private:
    vector<ll> tree;

    ll update(int start, int end, int node, int index, ll value) {
        if (index < start || end < index) return tree[node];
        if (start == end) return tree[node] = value;
        int mid = (start + end) / 2;
        ll leftValue = update(start, mid, 2 * node, index, value);
        ll rightValue = update(mid + 1, end, 2 * node + 1, index, value);
        return tree[node] = leftValue + rightValue;
    }

    ll _find(int start, int end, int node, int left, int right) {
        if (left > end || right < start) return 0;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return _find(start, mid, 2 * node, left, right) + _find(mid + 1, end, 2 * node + 1, left, right);
    }

public:
    SumSeg() {
        tree.resize(MAX * 4, 0);
    }
    ll update(int idx, ll val) { return update(1, MAX, 1, idx, val); }
    ll find(int l, int r) { return _find(1, MAX, 1, l, r); }
};

struct player{
    int n, i;
    player(int a, int b) : n(a), i(b) {}
    player() { player(0, 0); }
    bool operator<(player& p) {
        return n < p.n;
    }
};

int main() {

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<player> players(n);
    for (int i = 0; i < n; ++i) {
        cin >> players[i].n;
        players[i].i = i + 1;
    }
    sort(players.begin(), players.end());

    //°ª ¾ÐÃà
    for (int i = 0; i < n; ++i)
        players[i].n = i + 1;

    vi skill(n+1);
    for (int i = 0; i < n; ++i)
        skill[players[i].i] = players[i].n;

    SumSeg Seg;
    for (int i = 1; i <= n; ++i) {
        Seg.update(skill[i], 1);
        cout << Seg.find(skill[i], n) << '\n';
    }

    return 0;
}